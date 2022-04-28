#include "employee.h"
#include"page_login.h"
#include <QApplication>
#include"empsql.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    employee w;
    empSql sql;
    return a.exec();
}

