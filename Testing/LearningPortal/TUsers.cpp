#include "TUsers.h"

#include "TestUtilities.h"
#include "User.h"

using Users = QList<User>;
Q_DECLARE_METATYPE(Users)

void TUsers::TestWriteReadUsers_data()
{
    QTest::addColumn<Users>("initUsers");
    QTest::addColumn<Users>("additionalUsers");
    QTest::addColumn<Users>("expectedUsers");

    QTest::newRow("empty") << Users()
                           << Users()
                           << Users();
}

void TUsers::TestWriteReadUsers()
{
    QFETCH(Users, initUsers);
    QFETCH(Users, additionalUsers);
    QFETCH(Users, expectedUsers);

    const QString dataBaseName(QString(QTest::currentDataTag()) + ".db");
    PREPATE_TEST_DATABASE(dataBaseName, "can't prepare test database");
}
