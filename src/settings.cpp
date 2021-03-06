#include "settings.h"
#include "platform.h"
#include "theme.h"

#include <QSettings>
#include <QDir>

Settings::Settings(QObject *parent) :
    QObject(parent), mSettings("kylinos.cn", "KylinIpmsg"){
}

// 获取当前接收文件路径
QString Settings::currentPath()
{
    // Retrieve the last saved path (if any)
    QString path = mSettings.value("DestPath", "").toString();

    // Check if exists
    if ((path != "") && (QDir(path).exists()))
            return path;

    // Else return the default path for this platform
    path = Platform::getDefaultPath();
    if (QDir(path).exists() == false){
        QDir qdir;
        qdir.mkdir(path);
    }

    return path;
}

// 保存接收文件路径
void Settings::savePath(QString path)
{
    // Save the new path
    mSettings.setValue("DestPath", path);
    mSettings.sync();
}

// 保存窗口位置
//void Settings::saveWindowGeometry(QByteArray geo)
//{
//    mSettings.setValue("WindowPosAndSize", geo);
//    mSettings.sync();
//}

void Settings::saveWindowGeometry(QRect geo)
{
    mSettings.setValue("WindowPosAndSize", geo);
    mSettings.sync();
}

// 获取窗口位置
QRect Settings::windowGeometry()
{
    return (mSettings.value("WindowPosAndSize")).toRect();
}

// 保存主题颜色
void Settings::saveThemeColor(QString color)
{
    mSettings.setValue("ThemeColor", color);
    mSettings.sync();
}

// 获取主题颜色
QString Settings::themeColor()
{
    return mSettings.value("ThemeColor", Theme::DEFAULT_THEME_COLOR).toString();
}

/*
* Summary: get friend name
* Return : friend name
*/
QString Settings::buddyName()
{
    // Retrieve the last saved name (if any)
    return mSettings.value("BuddyName", "User").toString();

}

/*
* Summary: save friend name
* Parameters:
*   name: new friend name
* Return :
*/
void Settings::saveBuddyName(QString name)
{
    // Save the new name
    mSettings.setValue("BuddyName", name);
    mSettings.sync();
}

// 保存昵称和备注
/*
* Summary: save nickname
* Parameters:
*   ip: my mac or friend's mac
*   nickname: my nickname or friend's nickname
* Return :
*/
void Settings::saveNickname(QString mac, QString nickname)
{
    mSettings.setValue(mac, nickname);
    mSettings.sync();
}

// 获取昵称和备注
/*
* Summary: save nickname
* Parameters:
*   ip: my mac or friend's mac
* Return :
*   nickname: my nickname or friend's nickname
*/
QString Settings::nickname(QString mac)
{
    // 昵称默认"error"
    return mSettings.value(mac, "error").toString();
}

// 保存图标路径
void Settings::saveIconPath(QString path)
{
    mSettings.setValue("IconPath", path);
}

// 获取图标路径
QString Settings::iconPath()
{
    // 路径默认""
    return mSettings.value("IconPath", "").toString();
}
