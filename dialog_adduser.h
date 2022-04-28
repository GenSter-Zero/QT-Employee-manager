#ifndef DIALOG_ADDUSER_H
#define DIALOG_ADDUSER_H

#include <QDialog>
#include"empsql.h"
namespace Ui {
class dialog_adduser;
}

class dialog_adduser : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_adduser(QWidget *parent = nullptr);
    ~dialog_adduser();

private slots:
    void on_btn_register_clicked();

    void on_btn_exit_clicked();

private:
    Ui::dialog_adduser *ui;
    UserInfo m_info;
    empSql m_db;
};

#endif // DIALOG_ADDUSER_H
