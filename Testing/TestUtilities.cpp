#include "TestUtilities.h"
#include <QTextCodec>

const char *ConsolePrintable(const QString &str)
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
