#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

class QString;

class DatabaseInterface
{
public:
    static bool exists(const QString &dataBaseName);
    static bool remove(const QString &dataBaseName);
};

#endif // DATABASEINTERFACE_H
