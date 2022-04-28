#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H
#include "empsql.h"
#include <QFile>
#include <QWidget>
#include"dialog_adduser.h"
namespace Ui {
class page_login;
}

class page_login : public QWidget
{
    Q_OBJECT

public:
    explicit page_login(QWidget *parent = nullptr);
    ~page_login();

    QString name;
private slots:
    void on_btn_login_clicked();//登录按钮函数

    void on_btn_quit_clicked();//退出按钮函数

    void on_btn_addu_clicked();

signals:
    void sendLoginSuccess();//返回信息函数

private:
    Ui::page_login *ui;
    empSql m_db;
    QString username;
    QString userpassword;
    dialog_adduser m_dljAdduser;
};

#endif // PAGE_LOGIN_H
