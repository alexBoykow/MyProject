#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User& setName(const QString &name);
    const QString& name() const;

    User& setLogin(const QString &login);
    const QString& login() const;

    User& setPassword(const QString &password);
    const QString& password() const;

    bool operator==(const User &otherUser) const;
    QString toString() const;

private:
    QString name_;
    QString login_;
    QString password_;
};

#endif // USER_H
