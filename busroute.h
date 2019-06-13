#ifndef BUSROUTE_H
#define BUSROUTE_H

#include <QString>
#include <QTime>
#include <QStringList>
#include <QTextStream>
#include "definitions.h"
#include <memory>


class BusRoute
{
private:
    QString busComp;
    QTime depTime;
    QTime arrTime;
    void parseRoute(const QString &);
    QTime parseTime(const QString &);
public:
    BusRoute();
    BusRoute(const QString &);
    ~BusRoute();
    bool fasterThan();
    int calcTime();
    QString toString();
    QString getBusComp() const;
    QTime getDepTime() const;
    QTime getArrTime() const;
    bool operator==(const BusRoute &);
    bool operator>(BusRoute &);
    bool operator<(BusRoute &);
};

QTextStream & operator<<(QTextStream& stream, const BusRoute &);

#endif // ROUTE_H
