#include "User.h"

User &User::setName(const QString &name)
{
    name_ = name;
    return *this;
}

const QString &User::name() const
{
    return name_;
}

User &User::setLogin(const QString &login)
{
    login_ = login;
    return *this;
}

const QString &User::login() const
{
    return login_;
}

User &User::setPassword(const QString &password)
{
    password_ = password;
    return *this;
}

const QString &User::password() const
{
    return password_;
}

bool User::operator==(const User &otherUser) const
{
    return name_ == otherUser.name_
            && login_ == otherUser.login_
            && password_ == otherUser.password_;
}

QString User::toString() const
{
    return QString("Name: %1\n"
                   "Login: %2\n"
                   "Password: %3")
            .arg(name_)
            .arg(login_)
            .arg(password_);
}
