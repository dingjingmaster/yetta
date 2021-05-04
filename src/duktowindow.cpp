#include "duktowindow.h"
#include "guibehind.h"
#include "platform.h"
#include "settings.h"

DuktoWindow::DuktoWindow(QWindow *parent) :
    QmlApplicationViewer(parent), mGuiBehind(NULL){

    this->setTitle(tr("Yetta"));
//    this->setIcon(QIcon("/usr/share/pixmaps/.png"));

    // 响应用户手册
    mDaemonIpcDbus = new DaemonIpcDbus();

//    this->setWindowTitle(tr("Kylin Ipmsg"));
//    setWindowIcon(QIcon("/usr/share/pixmaps/kylin-ipmsg.png"));
    QString iconPath = "/usr/share/icons/ukui-icon-theme-default/64x64/apps/kylin-ipmsg.png";
    QFileInfo fi(iconPath);
    if (!fi.exists()) {
        iconPath = "/usr/share/icons/kylin-icon-theme/64x64/apps/kylin-ipmsg.png";
        fi.setFile(iconPath);
        if (!fi.exists()) {
            iconPath = "/usr/share/pixmaps/kylin-ipmsg.png";
        }
    }

//    this->setIcon(QIcon(iconPath));
    this->setIcon(QIcon::fromTheme("kylin-ipmsg"));

    setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);

    // 固定窗口大小
    int fixedWidth  = 330;
    int fixedHeight = 600;
    setMaximumWidth(fixedWidth);
    setMinimumWidth(fixedWidth);
    setMaximumHeight(fixedHeight);
    setMinimumHeight(fixedHeight);

    // 固定初始窗口位置到屏幕中央
    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->setGeometry((availableGeometry.width() - fixedWidth)/2, 
                      (availableGeometry.height() - fixedHeight)/2,
                      fixedWidth, fixedHeight);
}

/*
* Summary: set gui reference
* Parameters:
*   ref: gui behind object
* Return :
*/
void DuktoWindow::setGuiBehindReference(GuiBehind* ref){
    mGuiBehind = ref;
}

/*
* Summary:  close event
* Parameters:
*   qt close event
* Return :
*/
void DuktoWindow::closeEvent(QCloseEvent *event){
//    mGuiBehind->settings()->saveWindowGeometry(saveGeometry());
    mGuiBehind->settings()->saveWindowGeometry(frameGeometry());
    mGuiBehind->close();

    qDebug() << "exit(0)exit(0)exit(0)exit(0)exit(0)";
    event->accept();
    exit(0);
}

void DuktoWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_F1:
//        qDebug() << "DuktoWindow keyPressEvent Key_F1" << mDaemonIpcDbus->daemonIsNotRunning();

        if (!mDaemonIpcDbus->daemonIsNotRunning()){
            //增加标题栏帮助菜单、F1快捷键打开用户手册
            mDaemonIpcDbus->showGuide("kylin-ipmsg");
        }
        break;

    default:
        break;
    }
}
