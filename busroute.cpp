#include "BusRoute.h"

BusRoute::BusRoute()
{

}

BusRoute::BusRoute(const QString & route)
{
    parseRoute(route);
}

QString BusRoute::getBusComp() const
{
    return busComp;
}

QTime BusRoute::getDepTime() const
{
    return depTime;
}

QTime BusRoute::getArrTime() const
{
    return arrTime;
}

bool BusRoute::operator==(const BusRoute & obj)
{
    return (this->getDepTime() == obj.getDepTime()) && (this->getArrTime() == obj.getArrTime());
}

bool BusRoute::operator>(BusRoute & obj)
{
    if(this->getDepTime() == obj.getDepTime() || this->getArrTime() == obj.getArrTime())
    {
        return (this->calcTime() > obj.calcTime());
    }
    return false;
}

bool BusRoute::operator<(BusRoute & obj)
{
    if(this->getDepTime() == obj.getDepTime() || this->getArrTime() == obj.getArrTime())
    {
        return (this->calcTime() < obj.calcTime());
    }
    return false;
}

int BusRoute::calcTime()
{
    int delta;
    delta = (arrTime.hour() - depTime.hour()) * 60 + arrTime.minute() - depTime.minute();
    return delta;
}

void BusRoute::parseRoute(const QString & route)
{
    QStringList strList = route.split(' ');
    busComp = strList[0];
    depTime = parseTime(strList[1]);
    arrTime = parseTime(strList[2]);
}

QTime BusRoute::parseTime(const QString & route)
{
    QStringList strList = route.split(':');
    QTime time = QTime(strList[0].toInt(), strList[1].toInt(), 0);
    return time;
}

BusRoute::~BusRoute()
{

}

bool BusRoute::fasterThan()
{
    return calcTime() < EFF_MEAS_MINUTES;                              //EFF_MEAS_MINUTES see in definitions.h
}

QString BusRoute::toString()
{
    QString str;
    str = busComp;
    str += ' ';
    str += depTime.toString("hh:mm");
    str += ' ';
    str += arrTime.toString("hh:mm");
    return str;
}

QTextStream & operator<<(QTextStream &stream, const BusRoute & obj)
{
    stream << obj.getBusComp() << ' ' << obj.getDepTime().toString("hh:mm") << ' ' << obj.getArrTime().toString("hh:mm");
    return stream;
}
