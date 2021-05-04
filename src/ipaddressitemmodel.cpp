#include "ipaddressitemmodel.h"


IpAddressItemModel::IpAddressItemModel() :
    QStandardItemModel(NULL)
{
    QHash<int, QByteArray> roleNames;
    roleNames[Ip] = "ip";
    setItemRoleNames(roleNames);

    refreshIpList();
}

/*
* Summary: add a ip address
* Parameters:
*   ip: ip address
* Return :
*/
void IpAddressItemModel::addIp(QString ip)
{
    QStandardItem* it = new QStandardItem();
    it->setData(ip, IpAddressItemModel::Ip);
    appendRow(it);
}

/*
* Summary: refresh ip list
* Return :
*/
void IpAddressItemModel::refreshIpList()
{
    clear();

    QList<QHostAddress> addrs = QNetworkInterface::allAddresses();
    for (int i = 0; i < addrs.length(); i++)
        if ((addrs[i].protocol() == QAbstractSocket::IPv4Protocol) && (addrs[i].toString() != "127.0.0.1")){
            addIp(addrs[i].toString());

            // 选择正确的局域网IP地址
            if (addrs[i].toString().left(3) == "192") {
                this->myIp = addrs[i].toString();
                break;
            }
            else if (addrs[i].toString().left(3) == "172") {
                this->myIp = addrs[i].toString();
                break;
            }
            else if (addrs[i].toString().left(2) == "10") {
                this->myIp = addrs[i].toString();
                break;
            }
        }
}
