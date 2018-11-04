#ifndef USERSWRITER_H
#define USERSWRITER_H

#include "DatabaseInterface.h"
#include <QList>
#include <QSet>
#include "Models/User.h"

class UsersDatabaseInterface : public DatabaseInterface
{
public:
    UsersDatabaseInterface(const QString &dataBaseName);

protected:
    void createTableIfNotExists() const;
    const QString tableName_ = "users";

private:
    const QString createTableQuery() const;
};

class UsersWriter : public UsersDatabaseInterface
{
public:
    UsersWriter(const QString &dataBaseName);

    void addUsers(const QList<User> &users);
    void addUser(const User &user);

private:
    const QString insertQueryUsers() const;
};

class UsersReader : public UsersDatabaseInterface
{
public:
    UsersReader(const QString &dataBaseName);

    QList<User> readUsers() const;
    const QSet<QString> readAllLogins() const;

private:
    const QString selectAllUsersQuery() const;
    const QString selectAllLoginsQuery() const;
};

#endif // USERSWRITER_H
