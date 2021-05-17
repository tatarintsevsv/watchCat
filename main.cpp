#include <QCoreApplication>
#include <QTimer>
#include <QSettings>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QTextStream>
#include <QCommandLineParser>
#include "watchcat.h"
// run me as su
// apt install libqt5serialport5

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    watchcat* wc = new watchcat();

    QCommandLineParser parser;
    QCommandLineOption port_param(QStringList()<<"p"<<"port","Set watchdog port","port_name");
    QCommandLineOption response_param(QStringList()<<"r"<<"response","Response timeout (sec)","sec");
    QCommandLineOption timer_param(QStringList()<<"t"<<"timeout","Watchdog timeout","sec");
    QCommandLineOption verbose_param(QStringList()<<"v"<<"verbose","Verbose output","");
    QCommandLineOption portinfo_param(QStringList()<<"pi"<<"portinfo","Get avail port list","");

    parser.addOption(port_param);
    parser.addOption(response_param);
    parser.addOption(timer_param);
    parser.addOption(verbose_param);
    parser.addOption(portinfo_param);
    parser.addHelpOption();

    parser.process(a);
    if(parser.isSet(portinfo_param)){
        wc->getPortInfo();
        return 0;
    }
    if(!parser.isSet(port_param)||
       !parser.isSet(timer_param)||
       !parser.isSet(response_param))
        parser.showHelp(0);
    wc->init(parser.value(port_param),parser.value(response_param).toInt(),parser.value(timer_param).toInt(),parser.isSet(verbose_param));

    return a.exec();
}
