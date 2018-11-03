#ifndef TDATABASEINTERFACE_H
#define TDATABASEINTERFACE_H

#include <QObject>

class TDatabaseInterface : public QObject
{
    Q_OBJECT

private slots:
    void TestCreateExistsRemoveDatabase();
};

#endif // TDATABASEINTERFACE_H
