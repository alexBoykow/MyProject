#include "DatabaseInterface.h"

#include <QString>

bool DatabaseInterface::exists(const QString &dataBaseName)
{
    Q_UNUSED(dataBaseName);

    return false;
}

bool DatabaseInterface::remove(const QString &dataBaseName)
{
    Q_UNUSED(dataBaseName);

    return false;
}
