#include "dialog_adduser.h"
#include "ui_dialog_adduser.h"

dialog_adduser::dialog_adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_adduser)
{
    ui->setupUi(this);
}

dialog_adduser::~dialog_adduser()
{
    delete ui;
}

void dialog_adduser::on_btn_register_clicked()//注册槽
{
    UserInfo info;
    auto ptr = empSql::getinstance();//初始化指针
    info.username=ui->le_username->text();
    info.password=ui->le_password->text();
    QString struser = ui->le_username->text();
    if(m_db.isExitUser(struser))
    {
        QMessageBox::information(nullptr,"警告","账号重复");
    }
    else
    {
        if(ui->le_password->text()==ui->le_ispw->text())
        {
        ptr->AddUser(info);
        QMessageBox::information(nullptr,"信息","存储成功");
        this->hide();
        }
        else
        {
            QMessageBox::information(nullptr,"警告","两次密码不同！");
        }
    }
}

void dialog_adduser::on_btn_exit_clicked()//退出槽
{
    this->hide();
}

