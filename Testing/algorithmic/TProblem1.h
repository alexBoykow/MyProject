#ifndef TPROBLEM1_H
#define TPROBLEM1_H

#include <QObject>

class TProblem1 : public QObject
{
    Q_OBJECT

private slots:
    void TestCalcInversionCount_data();
    void TestCalcInversionCount();
};

#endif // TPROBLEM1_H
