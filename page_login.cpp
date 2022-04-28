#include "page_login.h"
#include "ui_page_login.h"
#include <QSqlTableModel>


page_login::page_login(QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::page_login)
{
    ui->setupUi(this);

}

page_login::~page_login()
{
    delete ui;
}

void page_login::on_btn_login_clicked()//登录槽
{
    username=ui->le_user->text();
    userpassword=ui->le_password->text();
    name = ui->le_user->text();
    if(m_db.isExitUser(username,userpassword))
    {
        QMessageBox::information(nullptr,"LOGIN","登录成功");
        emit sendLoginSuccess();
        this->hide();  
    }
    else
    {
        QMessageBox::information(nullptr,"LOGIN","用户名或密码输入错误，请重新输入！");
        ui->le_user->clear();
        ui->le_password->clear();
    }
}

void page_login::on_btn_quit_clicked()//退出槽
{
    exit(0);//退出
}

void page_login::on_btn_addu_clicked()//注册槽
{
    m_dljAdduser.exec();
}

