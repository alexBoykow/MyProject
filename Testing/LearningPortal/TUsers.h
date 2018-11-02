#ifndef TUSERS_H
#define TUSERS_H

#include <QObject>

class TUsers : public QObject
{
    Q_OBJECT
private slots:
    void TestWriteReadUsers_data();
    void TestWriteReadUsers();
};

#endif // TUSERS_H
