#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <QFile>
#include <QTest>

#define PREPARE_TEST_FILE(fileName, failMessage)\
if(QFile::exists(fileName))if(!QFile::remove(fileName))QFAIL(failMessage);

#endif // TESTUTILITIES_H
