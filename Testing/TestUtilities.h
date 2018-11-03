#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QFile>
#include <QTest>

#include "DatabaseInterface.h"

#define PREPARE_TEST_FILE(fileName, failMessage)\
    if(QFile::exists(fileName))\
    if(!QFile::remove(fileName))QFAIL(failMessage);

#define PREPATE_TEST_DATABASE(dataBaseName, failMessage)\
    if(DatabaseInterface::exists(dataBaseName))\
    if(!DatabaseInterface::remove(dataBaseName))QFAIL(failMessage);


template<class T>
auto anyToString_imp(const T &object, int)
->decltype ( object.toString() )
{
    return object.toString();
}

template<class T>
QString anyToString_imp(const T &object, long)
{
    ///если возникает ошибка,
    ///  значит нужно переопределить у object метод toString()
    return QString("%1").arg(object);
}

template<class T>
QString anyToString(const T &object)
{
    return anyToString_imp(object, 0);
}

const char* ConsolePrintable(const QString &str);

QString compareMessage(const QString &actual, const QString &expected);

#define EQUALS(actual, expected)\
    if(actual == expected)\
    QVERIFY(true);\
    else\
    QFAIL(ConsolePrintable(compareMessage(anyToString(actual), anyToString(expected))));


#endif // TESTUTILITIES_H
