#include "file.h"


File::File()
{
    linesList = new QList<QString>();
    inputFile = new QFile(INPUT_FILE_NAME);               //see definitions.h
    outputFile = new QFile();
}

File::~File()
{
    delete linesList;
    delete inputFile;
    delete outputFile;
}

const QList<QString> & File::readInputFile()
{
    if(!inputFile->open(QIODevice::ReadOnly))
    {
        return *linesList;
    }
    QByteArray data = inputFile->readAll();
    QString fileStr = QString::fromStdString(data.toStdString());
    *linesList = fileStr.split('\n');
    inputFile->close();
    return *linesList;
}

void File::writeOutputFile(const QList<QString> & routeList, QString fileName)
{
    outputFile->setFileName(fileName);
    if(outputFile->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(outputFile);
        foreach(BusRoute el, routeList)
        {
            out << el << '\n';
        }
        outputFile->close();
    }
}
