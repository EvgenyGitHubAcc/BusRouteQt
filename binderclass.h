#ifndef BINDERCLASS_H
#define BINDERCLASS_H

#include <QList>
#include <QFile>
#include <memory>
#include "busroute.h"
#include "file.h"

enum ListType {Posh = 1, Grotty};

class BinderClass
{
private:
    QList<BusRoute> routes;
    QList<BusRoute> routesPosh;
    QList<BusRoute> routesGrotty;
    File * fileWork = new File();
public:
    BinderClass();
    ~BinderClass();
    void divideRoutes();
    void sortRoutes();
    void deleteSame();
    void fillRouteList();
    void writeListToFile(enum ListType);
};

#endif // BINDERCLASS_H
