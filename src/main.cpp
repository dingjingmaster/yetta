
#include <QIcon>
#include <QDebug>
#include <qglobal.h>
#include <QTranslator>
#include <QApplication>

#include "guibehind.h"
#include "duktowindow.h"
#include "qtsingleapplication.h"
#include "qmlapplicationviewer.h"


int main(int argc, char *argv[])
{
    /* 适配 4K 屏 */
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    QString id = QString("yetta %1").arg(getenv("DISPLAY"));

    QtSingleApplication app(id, argc, argv);
    app.setApplicationVersion("0.1.0");

    // 国际化

    if (app.isRunning()) {
        app.sendMessage("FOREGROUND");
        return 1;
    }

    DuktoWindow viewer;
    GuiBehind gb(&viewer);
    viewer.showExpanded();
    viewer.raise();
    app.installEventFilter(&gb);

    return app.exec();
}
