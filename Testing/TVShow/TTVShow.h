#ifndef TTVSHOW_H
#define TTVSHOW_H

#include <QObject>

class TTVShow : public QObject
{
    Q_OBJECT
private slots:
    void TestReadInputData_data();
    void TestReadInputData();
};

#endif // TTVSHOW_H
