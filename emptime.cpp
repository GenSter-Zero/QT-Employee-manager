#include "emptime.h"

empTime::empTime()
{

}

double empTime::days(double i)//转化天数
{
    double j = 0;
    if (i <= 24)
    {
        j = i / 8;
    }
    return j;
}

double empTime::hours(double i)//转化小时
{
    double j = 0;
    if (i <= 3)
    {
        j = i*8;
    }
    return j;
}
