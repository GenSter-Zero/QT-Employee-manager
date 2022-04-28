#include "employee.h"
#include "ui_employee.h"

employee::employee(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::employee)
    ,m_ptrEmpSql(nullptr)
{
    ui->setupUi(this);

    QFile z;
    z.setFileName(":/main.css");
    z.open(QIODevice::ReadOnly);
    QString strQss = z.readAll();
    this->setStyleSheet(strQss);


    m_dlglogin.show();
    auto f = [&]()//auto在qt中的作用为自动给出变量的声明
    {
      QString ptrname = m_dlglogin.name;
      ui->lb_name->setText(QString("%1").arg(ptrname));
      this->show();
    };
    connect(&m_dlglogin,&page_login::sendLoginSuccess,this,f);//槽的使用，登录成功则完成发送成功函数

    ui->treeWidget->setColumnCount(1);
    QStringList l;//string数据
    l<<"公司考勤管理系统";
    QTreeWidgetItem *pf= new QTreeWidgetItem(ui->treeWidget,l);//树形控件的其中一个节点，作用为创建一个新节点，设置节点中包含的string数据，将该节点添加至树内
    ui->treeWidget->addTopLevelItem(pf);//添加顶层节点

    l.clear();
    l<<"员工管理";
    QTreeWidgetItem *p1= new QTreeWidgetItem(pf,l);

    pf->addChild(p1);//加入子节点

    ui->treeWidget->expandAll();//展示全部节点

    ui->stackedWidget->setCurrentIndex(0);//使用户一次只能看到一个界面
    ui->tableWidget_2->setFrameShape(QFrame::NoFrame);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ptrEmpSql = empSql::getinstance();//初始化指针
    m_ptrEmpSql->OpenDatabase();//打开数据库

    QString ptrname = m_dlglogin.name;


    m_lNames<<"钟离厉";
    m_lNames<<"公良莆莺";
    m_lNames<<"东剑愁";
    m_lNames<<"巫运家";
    m_lNames<<"申屠元驹";
    m_lNames<<"霍千愁";
    m_lNames<<"王栾";
    m_lNames<<"郝衫姒";
    m_lNames<<"危葶契";
    m_lNames<<"夏娩香";
    m_lNames<<"方芙卿";
    m_lNames<<"姚乐荷";
    m_lNames<<"汝笙彤";
    m_lNames<<"牟栾";
    m_lNames<<"聂师";
    m_lNames<<"屠师";
    m_lNames<<"暴念寒";
    m_lNames<<"须颦";
    m_lNames<<"钭蓉丝";
    m_lNames<<"荣襄穆";
    m_lNames<<"费康";
    m_lNames<<"吕雯琦";
    m_lNames<<"长孙鞅";
    m_lNames<<"能嫣";
    m_lNames<<"唐浩歌";
    m_lNames<<"袁若南";
    m_lNames<<"经刚蹇";
    m_lNames<<"奚沅";
    m_lNames<<"须铭怡";
    m_lNames<<"刘鑫炳";
    m_lNames<<"田听白";
    m_lNames<<"须豁";
    m_lNames<<"禄严泫";
    m_lNames<<"田靖珍";
    m_lNames<<"鄂襄";
    m_lNames<<"林紊";
    m_lNames<<"广萧";
    m_lNames<<"谢耷樱";
    m_lNames<<"云傻姑";
    m_lNames<<"毕涫涫";
    m_lNames<<"伯囧";
    m_lNames<<"索富芸";
    m_lNames<<"谷悒";
    m_lNames<<"单于愫愫";
    m_lNames<<"蔺黎明";
    m_lNames<<"须勒彤";
    m_lNames<<"付勒清";
    m_lNames<<"虞霸";
    m_lNames<<"水忻莹";
    m_lNames<<"郎惠";
    m_lNames<<"满刚";
    m_lNames<<"蒋败萤";
    m_lNames<<"党珩卿";
    m_lNames<<"薄芷天";
    m_lNames<<"年绮茈";
    m_lNames<<"寇钧";
    m_lNames<<"燕颜嫣";
    m_lNames<<"福绯";
    m_lNames<<"蒲珺娅";
    m_lNames<<"扶明轩";
    m_lNames<<"贡灵凡";
    m_lNames<<"车笙筝";
    m_lNames<<"吴焦青";
    m_lNames<<"云樱蹇";
    m_lNames<<"宫宛愫";
    m_lNames<<"弓达皋";
    m_lNames<<"逯垣鞯";
    m_lNames<<"颛孙伊颦";
    m_lNames<<"公羊鲂兰";
    m_lNames<<"谢柔芹";
    m_lNames<<"谷绫荠";
    m_lNames<<"温莆";
    m_lNames<<"宗卿";
    m_lNames<<"昌述华";
    m_lNames<<"郁逊耷";
    m_lNames<<"宓垣伊";
    m_lNames<<"訾苠丝";
    m_lNames<<"蒯绮";
    m_lNames<<"文经艺";
    m_lNames<<"习乾";
    m_lNames<<"融葶璎";
    m_lNames<<"成仰斌";
    m_lNames<<"从瑛";
    m_lNames<<"景和裕";
    m_lNames<<"匡泗彤";
    m_lNames<<"宓鹰羿";
    m_lNames<<"阮忻秋";
    m_lNames<<"史捕捕";
    m_lNames<<"郗囧衣";
    m_lNames<<"濮剀维";
    m_lNames<<"卓飞兰";
    m_lNames<<"黄娩琳";
    m_lNames<<"冀储";
    m_lNames<<"于宏峻";
    m_lNames<<"钱丽雅";
    m_lNames<<"汝琦";
    m_lNames<<"蔡怡忻";
    m_lNames<<"蒯茗莆";
    m_lNames<<"郁珈树";
    m_lNames<<"益紊姝";
    updateTable();


}

employee::~employee()
{
    delete ui;
}

void employee::keyPressEvent(QKeyEvent *event)//刷新键
{
    if(event->key()==Qt::Key_F5)//刷新
    {
        updateTable();
    }
}

void employee::on_exit_btn_clicked()//主界面退出按钮
{
 exit(0);
}

void employee::on_btn_simulation_clicked()//模拟数据按钮
{
    //制作100条数据

    QList<EmpInfo> l;
    for(int i=0;i<m_lNames.size();i++)
    {

        EmpInfo info;
        info.name = m_lNames[i];
        if(i%3)
        {
            info.age = 16;
            info.department ="技术部门";
            info.level="经理";
        }
        if(i%2)
        {
            info.age = 26;
            info.department ="技术部门";
            info.level="员工";
        }
        if(i%7)
        {
            info.age = 36;
            info.department ="销售部门";
            info.level="员工";
        }

        info.employeeid=QString::number(i+1);
        info.moneyrest = 12;
        info.rest = 2;
        info.wages = 3000;
        l.append(info);
    }
    m_ptrEmpSql->addEmpex(l);
    updateTable();
}

void employee::on_btn_add_clicked()//添加按钮
{
    m_dlgAddEmp.setType(true);
    m_dlgAddEmp.exec();//模块对话
    updateTable();
}

void employee::on_btn_empty_clicked()//清空按钮
{
    m_ptrEmpSql->claerEmpTable();
    updateTable();
}

void employee::updateTable()//刷新操作
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(11);//总共有几列
    QStringList l;
    l<<"序号"<<"员工号"<<"姓名"<<"性别"<<"年龄"<<"部门"<<"级别"<<"带薪假"<<"病假"<<"工资"<<"电话";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);//每列属性
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//选中多行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//每个选项不可编辑

    auto cnt = m_ptrEmpSql->getEmpCnt();//统计
    ui->lb_cnt->setText(QString("人数:%1").arg(cnt));//更改label文字，统计计数
    QList<EmpInfo> lEmployees = m_ptrEmpSql->getPageEmp(0,cnt);//获取全部雇员
    ui->tableWidget_2->setRowCount(cnt);//行数

    for(int i=0;i<lEmployees.size();i++)
    {
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));//第0列
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(lEmployees[i].employeeid));//第1列
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(lEmployees[i].name));//第2列
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(lEmployees[i].sex));//第3列
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(QString::number(lEmployees[i].age)));//第4列
        ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(lEmployees[i].department));//第5列
        ui->tableWidget_2->setItem(i,6,new QTableWidgetItem(lEmployees[i].level));//第6列
        ui->tableWidget_2->setItem(i,7,new QTableWidgetItem(QString::number(m_emptime.days(lEmployees[i].moneyrest))));//第7列
        ui->tableWidget_2->setItem(i,8,new QTableWidgetItem(QString::number(m_emptime.days(lEmployees[i].rest))));//第8列
        ui->tableWidget_2->setItem(i,9,new QTableWidgetItem(QString::number(lEmployees[i].wages)));//第9列
        ui->tableWidget_2->setItem(i,10,new QTableWidgetItem(lEmployees[i].phone));//第10列
    }
    dpm_one();
    dpm_two();
    ui->lb_cnt->setText(QString("人数:%1").arg(cnt));//更改label文字，统计计数
}

void employee::on_btn_delete_clicked()//删除按钮
{
    int i = ui->tableWidget_2->currentRow();
    if(i>=0)
    {
        int id = ui->tableWidget_2->item(i,1)->text().toUInt();
        m_ptrEmpSql->delEmp(id);
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }

}

void employee::on_btn_update_clicked()//修改按钮
{
    EmpInfo info;
    int i = ui->tableWidget_2->currentRow();
    if(i>=0)
    {
        info.employeeid = ui->tableWidget_2->item(i,1)->text();
        info.name = ui->tableWidget_2->item(i,2)->text();
        info.sex = ui->tableWidget_2->item(i,3)->text();
        info.age = ui->tableWidget_2->item(i,4)->text().toUInt();
        info.department = ui->tableWidget_2->item(i,5)->text();
        info.level = ui->tableWidget_2->item(i,6)->text();
        info.moneyrest = m_emptime.hours(ui->tableWidget_2->item(i,7)->text().toDouble());
        info.rest = m_emptime.hours(ui->tableWidget_2->item(i,8)->text().toDouble());
        info.wages = ui->tableWidget_2->item(i,9)->text().toUInt();
        info.phone= ui->tableWidget_2->item(i,10)->text();
        m_dlgAddEmp.setType(false,info);
        m_dlgAddEmp.exec();//模块对话
    }
    updateTable();
}

void employee::dpm_one()//统计技术部门
    {QString strdpm = "技术部门";
    auto cnt = m_ptrEmpSql->getEmpCnt();//统计

    QList<EmpInfo> lEmployees = m_ptrEmpSql->getPageEmp(0,cnt);//获取全部雇员
    int index = 0;
    for(int i=0;i<lEmployees.size();i++)
    {
        if(!lEmployees[i].department.contains(strdpm))
        {
            continue;
        }
        index++;
    }
    ui->lb_dpm_one->setText(QString("技术部门:%1人").arg(index));
}

void employee::dpm_two()//统计销售部门
    {QString strdpm = "销售部门";
    auto cnt = m_ptrEmpSql->getEmpCnt();//统计

    QList<EmpInfo> lEmployees = m_ptrEmpSql->getPageEmp(0,cnt);//获取全部雇员
    int index = 0;
    for(int i=0;i<lEmployees.size();i++)
    {
        if(!lEmployees[i].department.contains(strdpm))
        {
            continue;
        }
        index++;
    }
    ui->lb_dpm_two->setText(QString("销售部门:%1人").arg(index));
}

void employee::on_btn_find_clicked()//搜索按钮
{
    QString strFind = ui->le_find->text();
    if(strFind.isEmpty())
    {
        QMessageBox::information(nullptr,"警告：","没有进行筛选");
        updateTable();
        return;
    }

    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(11);//总共有几列
    QStringList l;
    l<<"序号"<<"员工号"<<"姓名"<<"性别"<<"年龄"<<"部门"<<"级别"<<"带薪假"<<"病假"<<"工资"<<"电话";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);//每列属性

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//选中多行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//每个选项不可编辑

    auto cnt = m_ptrEmpSql->getEmpCnt();//统计

    QList<EmpInfo> lEmployees = m_ptrEmpSql->getPageEmp(0,cnt);//获取全部雇员

    int index = 0;

    for(int i=0;i<lEmployees.size();i++)
    {
        if(!(lEmployees[i].name.contains(strFind)||lEmployees[i].employeeid.contains(strFind)))
        {
            continue;
        }

        ui->tableWidget_2->setItem(index,0,new QTableWidgetItem(QString::number(index+1)));//第0列
        ui->tableWidget_2->setItem(index,1,new QTableWidgetItem(lEmployees[i].employeeid));//第1列
        ui->tableWidget_2->setItem(index,2,new QTableWidgetItem(lEmployees[i].name));//第2列
        ui->tableWidget_2->setItem(index,3,new QTableWidgetItem(lEmployees[i].sex));//第3列
        ui->tableWidget_2->setItem(index,4,new QTableWidgetItem(QString::number(lEmployees[i].age)));//第4列
        ui->tableWidget_2->setItem(index,5,new QTableWidgetItem(lEmployees[i].department));//第5列
        ui->tableWidget_2->setItem(index,6,new QTableWidgetItem(lEmployees[i].level));//第6列
        ui->tableWidget_2->setItem(i,7,new QTableWidgetItem(QString::number(m_emptime.days(lEmployees[i].moneyrest))));//第7列
        ui->tableWidget_2->setItem(i,8,new QTableWidgetItem(QString::number(m_emptime.days(lEmployees[i].rest))));//第8列
        ui->tableWidget_2->setItem(index,9,new QTableWidgetItem(QString::number(lEmployees[i].wages)));//第9列
        ui->tableWidget_2->setItem(index,10,new QTableWidgetItem(lEmployees[i].phone));//第10列
        index ++;

    }
    ui->tableWidget_2->setRowCount(index);//行数
    ui->lb_cnt->setText(QString("人数:%1").arg(index));//更改label文字，统计计数
    dpm_one();
    dpm_two();
    if(0 == ui->tableWidget_2->rowCount())
    {
        QMessageBox::information(nullptr,"警告：","没有找到该数据");
        updateTable();
        return;
    }
}

void employee::on_btn_refresh_clicked()//刷新按钮
{
    updateTable();
}

