#include <QCoreApplication>
#include <iostream>
#include "binderclass.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Program start." << std::endl;
    BinderClass obj;
    obj.fillRouteList();
    obj.sortRoutes();
    obj.divideRoutes();
    obj.writeListToFile(Posh);
    obj.writeListToFile(Grotty);
    std::cout << "Program finished. The output files could be found in the application build directory" << std::endl;
    std::cout << "In my case: ..\\build-BusStop-Desktop_Qt_5_12_3_MinGW_64_bit-Debug" << std::endl;
    return a.exec();
}
