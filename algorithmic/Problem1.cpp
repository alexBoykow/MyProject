#include "Problem1.h"

#include <QtGlobal>
#include <QString>
#include <QStringList>

#include <QDebug>

const QString calcInversion(const int N, const int K)
{
    if(N > 1)
    {
        const int countMidPosition = N - 2;

        QStringList resultInversion;
        resultInversion << "1";

        if(K == 0)
        {
            qInfo() << "K == 0";
            for(int i = 2; i <= N; i++)
            {
                qInfo() << "Add";
                resultInversion << QString::number(i);
            }
        }
        else if(K == countMidPosition - 1)
        {

        }

        return resultInversion.join(' ');
    }

    return "-1";
}
