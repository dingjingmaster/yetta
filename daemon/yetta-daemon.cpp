#include "yetta-daemon.h"

#include "globals.h"

#include <QTimer>
#include <QCommandLineParser>

YettaDaemon::YettaDaemon(int &argc, char *argv[], const char *applicationName) : SingleApp (argc, argv, applicationName, false)
{
    setApplicationName(tr("yettad"));
    setApplicationVersion(QString("v %1").arg(YETTA_VERSION));

    // translation

    if (isPrimary()) {
        connect(this, &SingleApp::receivedMessage, [=] (quint32 id, const QByteArray msg) {
            parseCmd(id, msg, true);
        });
    }
}

void YettaDaemon::parseCmd(quint32 id, QByteArray msg, bool isPrimary)
{
    QCommandLineParser parser;

    QCommandLineOption quitOption(QStringList() << "q" << "quit", tr("Close the yettad"));
    parser.addOption(quitOption);

    if (isPrimary) {
        if (mFirstParse) {
            auto helpOption = parser.addHelpOption();
            auto versionOption = parser.addVersionOption();
            mFirstParse = false;
        }

        Q_UNUSED(id)

        const QStringList args = QString(msg).split(' ');

        parser.process(args);
        if (parser.isSet(quitOption)) {
            QTimer::singleShot(1, [=]() {
                qApp->quit();
            });
            return;
        }
    } else {
        auto helpOption = parser.addHelpOption();
        auto versionOption = parser.addVersionOption();

        if (arguments().count() < 2) {
            parser.showHelp();
        }
        parser.process(arguments());

        sendMessage(msg);
    }
}
