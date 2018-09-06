#include "algorithmic/TProblem1.h"

#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    int returnCode = 0;

#ifdef ALL_TESTS
    TProblem1 tProblem1;
    returnCode+= QTest::qExec(&tProblem1, argc, argv);
#endif

    return returnCode;
}
