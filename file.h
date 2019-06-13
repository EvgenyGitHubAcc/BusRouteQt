#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include "definitions.h"
#include "busroute.h"

class File
{
private:
    QFile * inputFile;
    QFile * outputFile;
    QList<QString> * linesList;
public:
    File();
    ~File();
    const QList<QString> & readInputFile();
    void writeOutputFile(const QList<QString> &, QString);
};

#endif // FILE_H
