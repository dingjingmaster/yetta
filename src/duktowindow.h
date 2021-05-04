#ifndef DUKTOWINDOW_H
#define DUKTOWINDOW_H

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDebug>
#include <QQuickWindow>
#include <QtWidgets/QMainWindow>
#include <QCloseEvent>
#include <QRect>
#include <QScreen>

#include "qmlapplicationviewer/qmlapplicationviewer.h"
#include "daemonipcdbus.h"

class GuiBehind;

class DuktoWindow : public QmlApplicationViewer
{
    Q_OBJECT

public:
    explicit DuktoWindow(QWindow *parent = 0);
    void setGuiBehindReference(GuiBehind* ref);

protected:
    void closeEvent(QCloseEvent *event);

signals:

public slots:

    void keyPressEvent(QKeyEvent *event);

private:
    GuiBehind *mGuiBehind;
    DaemonIpcDbus *mDaemonIpcDbus;
};

#endif // DUKTOWINDOW_H
