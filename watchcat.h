#ifndef WATCHCAT_H
#define WATCHCAT_H

#include <QObject>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QTextStream>

class watchcat : public QObject
{
    Q_OBJECT
public:
    explicit watchcat(QObject *parent = nullptr);    
    void init(QString p, int r, int t, bool v);
    void getPortInfo();
private slots:
    void timerTimeout();

private:
    QTimer timer;
    char timeout;
    bool verbose;
    QSerialPort port;
    void portWrite(char data);

};

#endif // WATCHCAT_H
