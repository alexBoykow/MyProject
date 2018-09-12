#include "TTVShow.h"

#include <TestUtilities.h>

class TestObject
{
public:
    TestObject(const QString &str,
               const int value):
        str_(str),
        value_(value)
    {

    }

    bool operator==(const TestObject &other) const
    {
        return str_ == other.str_
                && value_ == other.value_;
    }

    const QString toString() const
    {
        return QString("Str: %1..."
                       "Value: %2")
                .arg(str_)
                .arg(value_);
    }

private:
    QString str_;
    int value_;
};

void TTVShow::TestMacrosTestUtilities()
{
    const QString fileName = QString(QTest::currentTestFunction());

    QFile file(fileName);
    QVERIFY(file.open(QIODevice::WriteOnly));
    file.close();
    QVERIFY(QFile::exists(fileName));

    PREPARE_TEST_FILE(fileName, "can't prepare testFile");
    QVERIFY(!QFile::exists(fileName));

    bool x = true;
    bool y = true;
    QCOMPARE(x, y);

    int x_int = 10;
    int y_int = 10;
    QCOMPARE(x_int, y_int);

    double x_double = 10.2;
    double y_double = 10.2;
    QCOMPARE(x_double, y_double);

    TestObject testObject_1(tr("Мама"), 2);
    TestObject testObject_2(tr("Папа"), 2);

    EQUALS(testObject_1, testObject_2);

}
