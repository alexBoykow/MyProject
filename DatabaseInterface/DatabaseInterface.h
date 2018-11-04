#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class SQLQuery : public QSqlQuery
{
public:
    SQLQuery(const QSqlDatabase &database);
};

class DatabaseInterface
{
protected:
    DatabaseInterface(const QString &dataBaseName);
    void open();

    const QSqlDatabase &database() const;

public:
    static bool exists(const QString &dataBaseName);
    static bool remove(const QString &dataBaseName);
    static void create(const QString &dataBaseName);

protected:
    QString dataBaseName_;

private:
    QSqlDatabase database_;

    static const QString typeDatabase();
};

#endif // DATABASEINTERFACE_H
