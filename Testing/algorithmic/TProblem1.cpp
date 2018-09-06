#include "TProblem1.h"

#include <Problem1.h>

#include <QTest>

//#include <QDebug>
void TProblem1::TestCalcInversionCount_data()
{
    QTest::addColumn<int>("N");
    QTest::addColumn<int>("K");
    QTest::addColumn<QString>("expectedOutputResult");

    QTest::newRow("zero") << 0
                          << 0
                          << "-1";

    QTest::newRow("simple-1") << 1
                              << 0
                              << "-1";

    QTest::newRow("simple-2") << 2
                              << 0
                              << "1 2";

    QTest::newRow("simple-3") << 3
                              << 0
                              << "1 2 3";

    QTest::newRow("simple-4") << 4
                              << 0
                              << "1 2 3 4";

    QTest::newRow("simple-5") << 4
                              << 1
                              << "1 3 2 4";
}

void TProblem1::TestCalcInversionCount()
{
    QFETCH(int, N);
    QFETCH(int, K);
    QFETCH(QString, expectedOutputResult);

    const QString actualOutputResult = calcInversion(N, K);

    QCOMPARE(actualOutputResult, expectedOutputResult);
}
