#include "TUsers.h"

#include "TestUtilities.h"

#include "UsersDatabase.h"

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

    QTest::newRow("simple") << (Users()
                                << User())
                            << Users()
                            << (Users()
                                << User());\

    QTest::newRow("name-user-1") << (Users()
                                     << User().setName("name"))
                                 << Users()
                                 << (Users()
                                     << User().setName("name"));

    QTest::newRow("name-user-2") << (Users()
                                     << User().setName("name1"))
                                 << (Users()
                                     << User().setName("name2"))
                                 << (Users()
                                     << User().setName("name1")
                                     << User().setName("name2"));

    QTest::newRow("name-user-Cyrillic") << (Users()
                                            << User().setName("Имя1"))
                                        << (Users()
                                            << User().setName("Имя2"))
                                        << (Users()
                                            << User().setName("Имя1")
                                            << User().setName("Имя2"));

    QTest::newRow("login-password-user-1") << (Users()
                                               << User()
                                               .setLogin("login")
                                               .setPassword("password"))
                                           << Users()
                                           << (Users()
                                               << User()
                                               .setLogin("login")
                                               .setPassword("password"));

    QTest::newRow("all") << (Users()
                             << User()
                             .setLogin("login1")
                             .setPassword("password")
                             .setName("Александр"))
                         << (Users()
                             << User()
                             .setLogin("login2")
                             .setPassword("password")
                             .setName("Viktor"))
                         << (Users()
                             << User()
                             .setLogin("login1")
                             .setPassword("password")
                             .setName("Александр")

                             << User()
                             .setLogin("login2")
                             .setPassword("password")
                             .setName("Viktor"));
}

void TUsers::TestWriteReadUsers()
{
    QFETCH(Users, initUsers);
    QFETCH(Users, additionalUsers);
    QFETCH(Users, expectedUsers);

    const QString dataBaseName(QString(QTest::currentDataTag()) + ".db");
    PREPARE_TEST_DATABASE(dataBaseName, "can't prepare test database");

    UsersWriter writer(dataBaseName);
    UsersReader reader(dataBaseName);

    {
        const Users actual = reader.readUsers();
        EQUALS(actual, Users());
    }

    {
        writer.addUsers(initUsers);
        const Users actual = reader.readUsers();
        EQUALS(actual, initUsers);
    }

    {
        writer.addUsers(additionalUsers);
        const Users actual = reader.readUsers();
        EQUALS(actual, expectedUsers);
    }
}
