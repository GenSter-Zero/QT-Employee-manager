#ifndef EMPSQL_H
#define EMPSQL_H

#include <QObject>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlQuery>
#include<QCoreApplication>
#include"emptime.h"
struct EmpInfo//emp的属性
{
    int id;
    QString employeeid;
    QString name;
    QString sex;
    quint8  age;
    QString department;
    QString level;
    quint8  moneyrest;
    quint8  rest;
    quint32 wages;
    QString phone;
};

struct UserInfo//user的属性
{
    QString username;
    QString password;
    QString auth;
};

class empSql : public QObject
{
    Q_OBJECT
public:
    explicit empSql(QObject *parent = nullptr);

    static empSql *ptrempSql;//声明静态指针
    static empSql *getinstance()
    {
        if(nullptr == ptrempSql)
        {
            ptrempSql = new empSql;
        }
        return ptrempSql;
    }//初始化静态指针

    //打开数据库
    void OpenDatabase();

    //查询所有雇员数量
    quint32 getEmpCnt();

    //查询第几页雇员那个数据
    QList<EmpInfo> getPageEmp(quint32 page,quint32 uiCnt);

    //增加雇员
    bool addEmp(EmpInfo info);
    bool addEmpex(QList<EmpInfo> l);

    //删除雇员
    bool delEmp(int id);

    //清空雇员表
    bool claerEmpTable();

    //查询员工
    bool eisExit(QString strUser);

    //修改雇员信息
    bool UpdateEmpInfo(EmpInfo info);

    //查询所有用户,页数从0开始
    QList<UserInfo> getAllUser();

    //修改用户权限
    bool changeuserAut(UserInfo info);

    //查询用户是否存在
    bool isExitUser(QString strUser,QString strpw);

    //添加单个用户
    bool AddUser(UserInfo info);

    //删除单个用户
    bool delUser(QString strUserName);

    //查找用户名
    bool isExitUser(QString strUser);
signals:

private:
    QSqlDatabase m_db;
};

#endif // EMPSQL_H
