#include "bitcoinwatcher.h"
#include <QtNetwork/QNetworkRequest>
#include "json.hpp"

using json = nlohmann::json;

BitcoinWatcher::BitcoinWatcher(QObject *parent)
    : QObject(parent)
{
    url = QUrl("https://api.coindesk.com/v1/bpi/currentprice.json");

    connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(processResult(QNetworkReply*)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(executeQuery()));
}

void BitcoinWatcher::start()
{
    if (!timer.isActive())
    {
        executeQueryImpl();
        timer.start(10000);
    }
}

void BitcoinWatcher::stop()
{
    if (timer.isActive())
        timer.stop();
}

bool BitcoinWatcher::isActive() const
{
    return timer.isActive();
}

void BitcoinWatcher::executeQueryImpl()
{
    //qDebug() << "tick";
    networkAccessManager.get(QNetworkRequest(url));
}

void BitcoinWatcher::executeQuery()
{
    executeQueryImpl();
}

void BitcoinWatcher::processResult (QNetworkReply *reply)
{
    auto j = json::parse(reply->readAll().data());

    // stock value
    emit bitcoin2EurStr(QString(j["bpi"]["EUR"]["rate_float"].dump().c_str()));

    // datatime
    emit datetimeStr(QString(j["time"]["updated"].dump().c_str()));

    reply->deleteLater();
}
