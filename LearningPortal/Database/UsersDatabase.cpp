#include "UsersDatabase.h"

#include <QtSql/QSqlError>
#include <QVariant>

UsersWriter::UsersWriter(const QString &dataBaseName)
    :UsersDatabaseInterface(dataBaseName)
{
}

void UsersWriter::addUsers(const QList<User> &users)
{
    if(!users.isEmpty())
    {
        QString queryStr(insertQueryUsers());
        const int sizeUsers = users.size();

        for(int i=0; i < sizeUsers-1; i++)
        {
            queryStr+= QString("('%1','%2','%3'), ")
                    .arg(users[i].name())
                    .arg(users[i].login())
                    .arg(users[i].password());
        }

        queryStr+= QString("('%1','%2','%3')")
                .arg(users.last().name())
                .arg(users.last().login())
                .arg(users.last().password());

        SQLQuery query(database());
        query.exec(queryStr);
    }
}

void UsersWriter::addUser(const User &user)
{
    if(!user.login().isEmpty())
    {
        const QSet<QString> allLogins =
                UsersReader(dataBaseName_).readAllLogins();

        if(!allLogins.contains(user.login()))
        {
            SQLQuery query(database());

            query.prepare(QString("INSERT INTO %1 (name, login, password)"
                                  " VALUES(:name,:login,:password)")
                          .arg(tableName_));

            query.bindValue(":name", user.name());
            query.bindValue(":login", user.login());
            query.bindValue(":password", user.password());

            query.exec();
        }
    }
}

const QString UsersWriter::insertQueryUsers() const
{
    return QString("INSERT INTO %1 (name,login,password) VALUES ")
            .arg(tableName_);
}

UsersReader::UsersReader(const QString &dataBaseName)
    :UsersDatabaseInterface(dataBaseName)
{

}

QList<User> UsersReader::readUsers() const
{
    QList<User> users;

    SQLQuery query(database());
    query.exec(selectAllUsersQuery());

    while(query.next())
    {
        users << User()
                 .setName(query.value(0).toString())
                 .setLogin(query.value(1).toString())
                 .setPassword(query.value(2).toString());
    }

    return users;
}

const QString UsersReader::selectAllUsersQuery() const
{
    return QString("SELECT name,login,password FROM %1").arg(tableName_);
}

const QString UsersReader::selectAllLoginsQuery() const
{
    return QString("SELECT login FROM %1").arg(tableName_);
}

const QSet<QString> UsersReader::readAllLogins() const
{
    SQLQuery query(database());
    query.exec(selectAllLoginsQuery());

    QSet<QString> logins;

    while(query.next())
    {
        logins << query.value(0).toString();
    }

    return logins;
}

UsersDatabaseInterface::UsersDatabaseInterface(const QString &dataBaseName)
    :DatabaseInterface(dataBaseName)
{
    createTableIfNotExists();
}

void UsersDatabaseInterface::createTableIfNotExists() const
{
    SQLQuery query(database());
    query.exec(createTableQuery());
}

const QString UsersDatabaseInterface::createTableQuery() const
{
    return QString("CREATE TABLE IF NOT EXISTS %1 "
                   "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "name VARCHAR(255),"
                   "login VARCHAR(255),"
                   "password VARCHAR(255))")
            .arg(tableName_);
}
