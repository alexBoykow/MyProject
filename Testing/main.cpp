#ifdef TV_SHOW
#include "TVShow/TTVShow.h"
#endif

#include <QtTest/QTest>
#include <QCoreApplication>

int testExec(QObject *testObject,
             const QStringList &args = QStringList())
{
    return QTest::qExec(testObject,
                        QStringList()
                        << QCoreApplication::arguments().first()
                        << args);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int returnCode = 0;

#ifdef TV_SHOW

#ifdef ALL_TESTS
    TTVShow tTVShow;
    returnCode+= testExec(&tTVShow);
#endif

#endif

    return returnCode;
}
