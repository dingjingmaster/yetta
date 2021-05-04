#ifndef BUDDYLISTITEMMODEL_H
#define BUDDYLISTITEMMODEL_H

#include <QStandardItemModel>
#include <QUrl>
#include <QRegExp>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

class Peer;
class QUrl;
class Settings;

class BuddyListItemModel : public QStandardItemModel
{
public:
    BuddyListItemModel();
    void addMeElement(QString text1);
    void addIpElement(QString text1, QString text2);
    void addBuddy(QString ip, qint16 port, QString username, QString system, QString mac, QString platform, QUrl avatarPath);
    void addBuddy(Peer& peer);
    void removeBuddy(QString mac);
    void showSingleBack(int idx);
    void updateMeElement();
    QString buddyNameByIp(QString ip);
    QStandardItem* buddyByIp(QString ip);
    QStandardItem* buddyByMac(QString mac);
    QString fistBuddyIp();

    // 下载头像到本地
    bool downloadUrl(const QString &url, const QString &fileName);

    inline Settings* settings() { return mSettings; }

    enum BuddyRoles {
        Ip = Qt::UserRole + 1,
        Port,
        Iptext,
        Username,
        System,
        Mac,
        Platform,
        GenericAvatar,
        Avatar,
        OsLogo,
        ShowBack,
        ShowMsgAnim,
    };

    /*<"ip mac" , QStandardItem *>*/
    QHash<QString, QStandardItem*> mItemsMap;
    /*<"mac" , "ip mac">*/
    QHash<QString, QString> mIpsMap;
    QStandardItem* mMeItem;

private:
    Settings *mSettings;
};

#endif // BUDDYLISTITEMMODEL_H
