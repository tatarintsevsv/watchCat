#include "watchcat.h"
watchcat::watchcat(QObject *parent) : QObject(parent)
{
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(timerTimeout()));
}

void watchcat::getPortInfo(){
    QTextStream out(stdout);
    out << "avail ports:\n";
    foreach(QSerialPortInfo port,QSerialPortInfo::availablePorts()){
        out << QString("(%1) %2: %3\n").arg(port.portName()).arg(port.description()).arg(port.portName());
    }

}

void watchcat::portWrite(char data){
    int res=0;
    if(port.open(QSerialPort::WriteOnly))
        res = port.write(&data,1);
    if(res!=1||!port.isOpen()){
        QTextStream out(stdout);
        out << QString("[%1] failed open port/write data\n").arg(QTime::currentTime().toString("hh:mm:ss"));
    }
    port.waitForBytesWritten(300);
    port.close();
}

void watchcat::timerTimeout()
{
    if(verbose){
        QTextStream out(stdout);
        out<< QString("[%1] Meow!\n").arg(QTime::currentTime().toString("hh:mm:ss"));
    }
    portWrite(timeout);
}
void watchcat::init(QString p,int r,int t,bool v){
    port.setPortName(p);
//    port.setPort(QSerialPortInfo::availablePorts().last());
//    bool dd = port.open(QIODevice::ReadOnly);
    timeout = (char)t;
    verbose = v;
    timer.setInterval(r*1000);
    timer.setSingleShot(false);
    timer.start();

}

