#ifndef BITCOINWATCHER_H
#define BITCOINWATCHER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QTimer>

/*!
 * \brief The BitcoinWatcher class
 */
class BitcoinWatcher : public QObject
{
    Q_OBJECT

public:
    BitcoinWatcher(QObject *parent = 0);

signals:
    /*!
     * \brief Formatted Bitcoin2Euro value
     */
    void bitcoin2EurStr(QString newValueStr);

    /*!
     * \brief Formatted date of conversion value (see bitcoin2EurStr)
     */
    void datetimeStr(QString bewDatetime);

public slots:
    /*!
     * \brief Starts value update
     */
    void start();

    /*!
     * \brief Stops value update
     */
    void stop();

public:
    /*!
     * \brief Returns true if the value update is active
     */
    bool isActive() const;

private:
    // Used by start() and executeQuery() to start a http request
    void executeQueryImpl();

private slots:
    // called by timer, it calls executeQueryImpl()
    void executeQuery();

    // called by networkAccessManager when it receive data
    void processResult (QNetworkReply *reply);

private:
    QNetworkAccessManager networkAccessManager;
    QTimer timer;
    QUrl url;
};

#endif // BITCOINWATCHER_H
