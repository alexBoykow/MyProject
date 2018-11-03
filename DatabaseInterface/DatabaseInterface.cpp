#include "DatabaseInterface.h"

#include <QFile>

bool DatabaseInterface::exists(const QString &dataBaseName)
{
#ifdef SQLITE
    return QFile::exists(dataBaseName);
#endif
}

bool DatabaseInterface::remove(const QString &dataBaseName)
{
    if(exists(dataBaseName))
    {
#ifdef SQLITE
        return QFile::remove(dataBaseName);
#endif
    }

    return true;
}

void DatabaseInterface::create(const QString &dataBaseName)
{
#ifdef SQLITE
    if(!QFile::exists(dataBaseName))
    {
        QFile file(dataBaseName);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
#endif
}
