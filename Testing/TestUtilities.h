#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QFile>
#include <QTest>

#define PREPARE_TEST_FILE(fileName, failMessage)\
    if(QFile::exists(fileName))\
    if(!QFile::remove(fileName))QFAIL(failMessage);


template<class T>
QString anyToString(const T &actual,
                    const T &expected)
{
    return QString("\nACTUAL:\n"
                   "%1\n"
                   "EXPECTED:\n"
                   "%2")
            .arg(actual.toString())
            .arg(expected.toString());
}

#define EQUALS(actual, expected)\
    if((actual == expected) == false)QFAIL(anyToString(actual, expected).toUtf8().data());


#endif // TESTUTILITIES_H
