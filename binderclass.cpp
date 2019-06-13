#include "binderclass.h"

BinderClass::BinderClass()
{

}

BinderClass::~BinderClass()
{
    delete fileWork;
}

void BinderClass::divideRoutes()
{
    for(int i = 0; i < routes.size(); ++i)
    {
        if(!routes[i].fasterThan())
        {
            continue;
        }
        if(routes[i].getBusComp() == "Posh")
        {
            routesPosh.append(routes[i]);
        }
        else if (routes[i].getBusComp() == "Grotty")
        {
            routesGrotty.append(routes[i]);
        }
        routes.removeAt(i);
    }
}

void BinderClass::sortRoutes()
{
    std::sort (routes.begin(), routes.end(), [](const BusRoute & left, const BusRoute & right)
    {
        return left.getDepTime() < right.getDepTime();
    });
}


void BinderClass::fillRouteList()
{
    const QList<QString> list = fileWork->readInputFile();
    foreach(QString el, list)
    {
        routes.append(BusRoute(el));
    }
}

void BinderClass::writeListToFile(enum ListType type)
{
    QList<QString> list;
    QString filename;
    if(type == Posh)
    {
        foreach(BusRoute el, routesPosh)
        {
            list.append(el.toString());
        }
        filename = POSH_OUTPUT_FILE_NAME;
    }
    else if(type == Grotty)
    {
        foreach(BusRoute el, routesGrotty)
        {
            list.append(el.toString());
        }
        filename = GROTTY_OUTPUT_FILE_NAME;
    }
    fileWork->writeOutputFile(list, filename);
}
