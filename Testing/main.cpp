#ifdef ALGORITHMIC
#include "algorithmic/TProblem1.h"
#endif

#ifdef TV_SHOW
#include "TVShow/TTVShow.h"
#endif

#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    int returnCode = 0;

#ifdef TV_SHOW

#ifdef ALL_TESTS
    TTVShow tTVShow;
    returnCode+= QTest::qExec(&tTVShow, argc, argv);
#endif

#endif

#ifdef ALGORITHMIC

#ifdef ALL_TESTS
    TProblem1 tProblem1;
    returnCode+= QTest::qExec(&tProblem1, argc, argv);
#endif

#endif

    return returnCode;
}
