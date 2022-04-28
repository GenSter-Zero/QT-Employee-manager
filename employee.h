#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"empsql.h"
#include <QMainWindow>
#include"page_login.h"
#include <QKeyEvent>
#include <QFile>
#include<QRandomGenerator>
#include"dialog_addemp.h"
#include<typeinfo>
#include"emptime.h"
QT_BEGIN_NAMESPACE
namespace Ui { class employee; }
QT_END_NAMESPACE

class employee : public QMainWindow
{
    Q_OBJECT

public:
    employee(QWidget *parent = nullptr);
    ~employee();

    virtual void keyPressEvent(QKeyEvent *event);//刷新按钮

    void dpm_one();
    void dpm_two();
private slots:
    void on_exit_btn_clicked();//退出按钮

    void on_btn_simulation_clicked();//模拟数据按钮

    void on_btn_add_clicked();//增加按钮

    void on_btn_empty_clicked();//清空按钮

    void on_btn_delete_clicked();//删除按钮

    void on_btn_update_clicked();//刷新按钮

    void on_btn_find_clicked();

    void on_btn_refresh_clicked();

private:
    Ui::employee *ui;
    page_login m_dlglogin;
    empSql *m_ptrEmpSql;
    QStringList m_lNames;
    Dialog_AddEmp m_dlgAddEmp;
    empTime m_emptime;
    void updateTable();
};
#endif // EMPLOYEE_H
