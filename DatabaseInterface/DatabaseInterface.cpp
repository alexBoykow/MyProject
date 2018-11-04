#include "DatabaseInterface.h"

#include <QFile>
#include <QUuid>

DatabaseInterface::DatabaseInterface(const QString &dataBaseName)
    :dataBaseName_(dataBaseName)
{
    create(dataBaseName);
    open();
}

void DatabaseInterface::open()
{
    const QString idConnection(QUuid::createUuid().toString());

    if(QSqlDatabase::connectionNames().contains(idConnection))
    {
        QSqlDatabase::removeDatabase(idConnection);
    }

    database_ = QSqlDatabase::addDatabase(typeDatabase(), idConnection);
    database_.setDatabaseName(dataBaseName_);
    database_.open();
}

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
    if(!exists(dataBaseName))
    {
#ifdef SQLITE
        QFile file(dataBaseName);
        file.open(QIODevice::WriteOnly);
        file.close();
#endif
    }

}

const QSqlDatabase &DatabaseInterface::database() const
{
    return database_;
}

const QString DatabaseInterface::typeDatabase()
{
#ifdef SQLITE
    return "QSQLITE";
#endif
}

SQLQuery::SQLQuery(const QSqlDatabase &database)
    :QSqlQuery(database)
{

}
