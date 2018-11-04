#include "TDatabaseInterface.h"

#include <TestUtilities.h>

void TDatabaseInterface::TestCreateExistsRemoveDatabase()
{
    const QString dataBaseName("database.db");
    PREPARE_TEST_DATABASE(dataBaseName, "can't prepare test database");
    QVERIFY(!DatabaseInterface::exists(dataBaseName));

    DatabaseInterface::create(dataBaseName);
    QVERIFY(DatabaseInterface::exists(dataBaseName));

    QVERIFY(DatabaseInterface::remove(dataBaseName));
    QVERIFY(!DatabaseInterface::exists(dataBaseName));
}
