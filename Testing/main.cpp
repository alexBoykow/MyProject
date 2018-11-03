#include <QtTest/QTest>
#include <QCoreApplication>

#include <LearningPortal/TUsers.h>
#include <DatabaseInterface/TDatabaseInterface.h>

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

#ifdef CURRENT_TESTS
    TUsers tUsers;
    returnCode+= testExec(&tUsers);
#endif

#ifdef TV_SHOW

#ifdef ALL_TESTS
    TTVShow tTVShow;
    returnCode+= testExec(&tTVShow);
#endif

#endif

#ifdef LEARNING_PORTAL

#ifdef ALL_TESTS
    TUsers tUsers;
    returnCode+= testExec(&tUsers);
#endif

#endif

#ifdef ALL_TESTS
    TDatabaseInterface tDatabaseInterface;
    returnCode+= testExec(&tDatabaseInterface);
#endif

    return returnCode;
}
