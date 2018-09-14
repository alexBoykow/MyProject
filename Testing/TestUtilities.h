#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QFile>
#include <QTest>
#include <QTextCodec>

#define PREPARE_TEST_FILE(fileName, failMessage)\
    if(QFile::exists(fileName))\
    if(!QFile::remove(fileName))QFAIL(failMessage);


template<class T>
QString anyToString(const T object)
{
    return QString("%1")
            .arg(object.toString());
}

const char* ConsolePrintable(const QString &str)
{
    return QTextCodec::codecForName("windows-1251")->fromUnicode(str).constData();
}

QString compareMessage(const QString &actual, const QString &expected)
{
    return QString("\nActual:\n"
                   "%1\n\n"
                   "Expected:\n"
                   "%2")
            .arg(actual)
            .arg(expected);
}

#define EQUALS(actual, expected)\
    if(actual == expected)\
    QVERIFY(true);\
    else\
    QFAIL(ConsolePrintable(compareMessage(anyToString(actual), anyToString(expected))));


#endif // TESTUTILITIES_H
