#include "TTVShow.h"

#include <TestUtilities.h>

void TTVShow::TestReadInputData_data()
{

}

void TTVShow::TestReadInputData()
{
    const QString fileName = QString(QTest::currentTestFunction());

    PREPARE_TEST_FILE(fileName, "can't prepare testFile");
}
