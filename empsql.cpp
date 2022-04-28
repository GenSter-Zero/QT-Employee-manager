#include "empsql.h"

#include <QSqlError>

empSql * empSql::ptrempSql = nullptr;//访问静态变态并给予空值

empSql::empSql(QObject *parent)
    : QObject{parent}
{
}

void empSql::OpenDatabase()//打开数据库
{
    if (QSqlDatabase::drivers().isEmpty())
    qDebug()<<"No database drivers found";//报错
    m_db = QSqlDatabase::addDatabase("QSQLITE");//引擎选择，其中ODBC为sql server
    QString str = QCoreApplication::applicationDirPath()+"/data.db";
    qDebug()<<str;
    m_db.setDatabaseName(str);//文件地址
    if (!m_db.open())
        qDebug()<<"db not open";//报错
}

quint32 empSql::getEmpCnt()//获取全部
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from employee;");//通过id查询数量
    quint32 uiCnt = 0;
    while(sql.next())//读取
    {
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<EmpInfo> empSql::getPageEmp(quint32 page, quint32 uiCnt)//读取页面
{
    QList<EmpInfo> l;
    QSqlQuery sql(m_db);
    QString strsql=QString("select * from employee order by id limit %1 offset %2")
            .arg(uiCnt)//一页xx个
            .arg(page*uiCnt);//offset代表从第几条之后开始查询，limit表示查询多少条结果
    sql.exec(strsql);

    EmpInfo info;
    while(sql.next())//读取
    {
        info.id = sql.value(0).toUInt();
        info.employeeid = sql.value(1).toString();
        info.name = sql.value(2).toString();
        info.sex = sql.value(3).toString();
        info.age = sql.value(4).toUInt();
        info.department = sql.value(5).toString();
        info.level = sql.value(6).toString();
        info.moneyrest = sql.value(7).toUInt();
        info.rest = sql.value(8).toUInt();
        info.wages = sql.value(9).toUInt();
        info.phone = sql.value(10).toString();
        l.push_back(info);
    }
    return l;
}

bool empSql::addEmp(EmpInfo info)//加入雇员
{
    QSqlQuery sql(m_db);
    QString strsql = QString("insert into employee values(null,'%1','%2','%3',%4,'%5','%6',%7,%8,%9,'%10')")
            .arg(info.employeeid)
            .arg(info.name)
            .arg(info.sex)
            .arg(info.age)
            .arg(info.department)
            .arg(info.level)
            .arg(info.moneyrest)
            .arg(info.rest)
            .arg(info.wages)
            .arg(info.phone);
    return sql.exec(strsql);
}

bool empSql::addEmpex(QList<EmpInfo> l)//模拟数据的add
{
    QSqlQuery sql(m_db);
    m_db.transaction();
    for(auto info:l)
    {
        QString strsql = QString("insert into employee values(null,'%1','%2','%3',%4,'%5','%6',%7,%8,%9,'%10')")
                .arg(info.employeeid)
                .arg(info.name)
                .arg(info.sex)
                .arg(info.age)
                .arg(info.department)
                .arg(info.level)
                .arg(info.moneyrest)
                .arg(info.rest)
                .arg(info.wages)
                .arg(info.phone);
        sql.exec(strsql);
    }
    m_db.commit();
    return true;
}

bool empSql::delEmp(int id)//删除雇员
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from employee where employeeid = '%1'").arg(id));
}

bool empSql::claerEmpTable()//清空雇员表
{
    QSqlQuery sql(m_db);
    sql.exec("delete from employee");
    return sql.exec("delete from sqlite_sequence where name ='employee'");
}

bool empSql::UpdateEmpInfo(EmpInfo info)//更改雇员
{
    QSqlQuery sql(m_db);
    QString strsql = QString("update employee set name='%1',sex='%2',age=%3,department='%4',level='%5',moneyrest=%6,rest=%7,wages=%8,phone='%9' where employeeid='%10'")
            .arg(info.name)
            .arg(info.sex)
            .arg(info.age)
            .arg(info.department)
            .arg(info.level)
            .arg(info.moneyrest)
            .arg(info.rest)
            .arg(info.wages)
            .arg(info.phone)
            .arg(info.employeeid);
    bool ret = sql.exec(strsql);

    return ret;
}

bool empSql::eisExit(QString strUser)//查询雇员
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from employee where employeeid='%1'").arg(strUser));
    return sql.next();
}

QList<UserInfo> empSql::getAllUser()//获取用户
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from user");

    UserInfo info;
    while(sql.next())//读取
    {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.auth = sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

bool empSql::changeuserAut(UserInfo info)//更改用户权限
{
    QSqlQuery sql(m_db);
    QString strsql = QString("update user set password='%1',auth='%2' where username='%3'")
            .arg(info.password)
            .arg(info.auth)
            .arg(info.username);
    bool ret = sql.exec(strsql);
    QSqlError e = sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

bool empSql::isExitUser(QString strUser,QString strpw)//查询用户与密码
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from user where username='%1' and password='%2'").arg(strUser).arg(strpw));
    return sql.next();
}

bool empSql::isExitUser(QString strUser)//查找用户名
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from user where username='%1'").arg(strUser));
    return sql.next();
}

bool empSql::AddUser(UserInfo info)//增加用户
{
    QSqlQuery sql(m_db);
    QString strsql = QString("insert into user values('%1','%2','%3')")
            .arg(info.username)
            .arg(info.password)
            .arg("view");
    return sql.exec(strsql);
}

bool empSql::delUser(QString strUserName)//删除用户
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from user where username='%1'").arg(strUserName));

}

