#include "TVShow/TTVShow.h"

#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    int returnCode = 0;

#ifdef ALL_TESTS
    TTVShow tTVShow;
    returnCode+= QTest::qExec(&tTVShow, argc, argv);
#endif

    return returnCode;
}
