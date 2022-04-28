#ifndef DIALOG_ADDEMP_H
#define DIALOG_ADDEMP_H

#include <QDialog>
#include"empsql.h"

namespace Ui {
class Dialog_AddEmp;
}

class Dialog_AddEmp : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddEmp(QWidget *parent = nullptr);
    ~Dialog_AddEmp();

    void setType(bool isAdd,EmpInfo info={});
private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::Dialog_AddEmp *ui;
    bool m_isAdd;
    EmpInfo m_info;
    empSql m_db;
    empTime m_emptime;
};

#endif // DIALOG_ADDEMP_H
