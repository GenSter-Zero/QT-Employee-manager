#include "dialog_addemp.h"
#include "ui_dialog_addemp.h"
#include"emptime.h"
Dialog_AddEmp::Dialog_AddEmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddEmp)
{
    ui->setupUi(this);
}

Dialog_AddEmp::~Dialog_AddEmp()
{
    delete ui;
}

void Dialog_AddEmp::setType(bool isAdd,EmpInfo info)//判断增加还是修改
{
    m_isAdd = isAdd;
    m_info = info;
    ui->le_eid->setText(m_info.employeeid);//员工号
    ui->le_name->setText(m_info.name);//姓名
    ui->cb_sex->setCurrentText(m_info.sex);//性别
    ui->sb_age->setValue(m_info.age);//年龄
    ui->cb_dpm->setCurrentText(m_info.department);//部门
    ui->cb_level->setCurrentText(m_info.level);//级别
    ui->sb_mrest->setValue(m_info.moneyrest);//带薪
    ui->sb_nrest->setValue(m_info.rest);//病假
    ui->le_wages->setText(QString::number(m_info.wages));//工资
    ui->le_phone->setText(m_info.phone);//电话

}

void Dialog_AddEmp::on_btn_save_clicked()//保存槽
{
    EmpInfo info;
    auto ptr = empSql::getinstance();//初始化指针

    info.name=ui->le_name->text();
    info.sex=ui->cb_sex->currentText();
    info.age=ui->sb_age->text().toUInt();
    info.department=ui->cb_dpm->currentText();
    info.level=ui->cb_level->currentText();
    info.moneyrest=ui->sb_mrest->text().toUInt();
    info.rest=ui->sb_nrest->text().toUInt();
    info.wages=ui->le_wages->text().toUInt();
    info.phone=ui->le_phone->text();

    if(m_isAdd)
    {
        QString streid = ui->le_eid->text();
        if(m_db.eisExit(streid))
        {
            QMessageBox::information(nullptr,"警告","员工编号重复！");
        }
        else
        {
        info.employeeid=ui->le_eid->text();
        ptr->addEmp(info);
        QMessageBox::information(nullptr,"信息","存储成功");
        }
    }
    else
    {
        if(ui->le_eid->text()!= m_info.employeeid)
        {
            QMessageBox::information(nullptr,"警告","不允许更改员工编号！");
        }
        else
        {
            info.employeeid = m_info.employeeid;
            ptr->UpdateEmpInfo(info);
            QMessageBox::information(nullptr,"信息","修改成功");
        }
    }
    this->hide();
}

void Dialog_AddEmp::on_btn_cancel_clicked()//退出槽
{
    this->hide();
}

