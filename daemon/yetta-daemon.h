#ifndef YETTADAEMON_H
#define YETTADAEMON_H

#include "single-app/single-app.h"

#include <QObject>
#include <QCoreApplication>

/**
 * @brief yetta daemon
 */
class YettaDaemon : public SingleApp
{
    Q_OBJECT
public:
    explicit YettaDaemon (int &argc, char *argv[], const char *applicationName = "yettad");

protected Q_SLOTS:
    void parseCmd (quint32 id, QByteArray msg, bool isPrimary);

private:
    bool            mFirstParse = true;
};

#endif // YETTADAEMON_H
