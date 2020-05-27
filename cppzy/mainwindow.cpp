#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("房贷计算器");
    fangshi=0;
    chushihua();
    ui->label_7->setAlignment(Qt::AlignRight);
    ui->label_42->setAlignment(Qt::AlignRight);
    ui->label_45->setAlignment(Qt::AlignRight);
    ui->label_46->setAlignment(Qt::AlignRight);
    ui->label_47->setAlignment(Qt::AlignRight);
    gengxin();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::gengxin()
{
    chushihua();
    ui->label_55->setNum(0);
    ui->label_56->setNum(0);
    ui->label_58->setNum(0);
    ui->label_60->setNum(0);
    ui->label_65->setNum(0);
    ui->label_66->setNum(0);
    ui->label_70->setNum(0);
    ui->label_67->setNum(0);
    ui->label_68->setNum(0);
    ui->lineEdit->setPlaceholderText(tr("请输入房屋单价"));
    ui->lineEdit_2->setPlaceholderText(tr("请输入房屋面积"));         //当输入值非法时更新输入和输出面板
    ui->lineEdit_20->setPlaceholderText(tr("请输入按揭成数"));
    ui->lineEdit_3->setPlaceholderText(tr("请输入按揭年数"));
    ui->lineEdit_4->setPlaceholderText(tr("请输入贷款利率(小数)"));
    ui->lineEdit_5->setPlaceholderText(tr("请输入贷款总额"));
    ui->lineEdit_6->setPlaceholderText(tr("请输入按揭年数"));
    ui->lineEdit_7->setPlaceholderText(tr("请输入贷款利率(小数)"));
    ui->lineEdit_8->setPlaceholderText(tr("请输入房屋单价"));
    ui->lineEdit_9->setPlaceholderText(tr("请输入房屋面积"));
    ui->lineEdit_22->setPlaceholderText(tr("请输入按揭成数"));
    ui->lineEdit_10->setPlaceholderText(tr("请输入按揭年数"));
    ui->lineEdit_11->setPlaceholderText(tr("请输入贷款利率(小数)"));
    ui->lineEdit_12->setPlaceholderText(tr("请输入贷款总额"));
    ui->lineEdit_13->setPlaceholderText(tr("请输入按揭年数"));
    ui->lineEdit_14->setPlaceholderText(tr("请输入贷款利率(小数)"));
    ui->lineEdit_15->setPlaceholderText(tr("请输入商业贷款额"));
    ui->lineEdit_16->setPlaceholderText(tr("请输入商贷利率(小数)"));
    ui->lineEdit_18->setPlaceholderText(tr("请输入公积金贷款额"));
    ui->lineEdit_17->setPlaceholderText(tr("请输入公积金利率(小数)"));
    ui->lineEdit_19->setPlaceholderText(tr("请输入按揭年数"));

}

void MainWindow::chushihua()
{
    danjia1=0;
    mianji1=0;
    chengshu1=0;
    nianshu=0;
    nianshu1=0;
    gongdaie=0;
    shangdaie=0;
    result=0;
    lilv1=0;
    glilv=0;
    slilv=0;
    zonge1=0;                                              //初始化所有变量的值
    lixi=0;
    zonge=0;
    dijian=0;
    fangshi=0;
    ui->radioButton_3->setChecked(true);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_5->setChecked(true);
    ui->radioButton_6->setChecked(false);
    ui->radioButton_7->setChecked(true);
    ui->radioButton_8->setChecked(false);
    ui->radioButton_9->setChecked(true);
    ui->radioButton_10->setChecked(false);
    ui->radioButton_13->setChecked(true);
    ui->radioButton_14->setChecked(false);
}
//当用户选择不同计算方式时切换页面
void MainWindow::on_radioButton_1_clicked(bool checked)
{
    if(checked)
    {
        ui->stackedWidge_1->setCurrentIndex(0);
        ui->radioButton_2->setChecked(false);
    }
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked)
    {
        ui->stackedWidge_1->setCurrentIndex(1);
        ui->radioButton_1->setChecked(false);
    }
}

void MainWindow::on_radioButton_11_clicked(bool checked)
{
    if(checked)
    {
        ui->stackedWidge_2->setCurrentIndex(0);
        ui->radioButton_12->setChecked(false);
    }
}

void MainWindow::on_radioButton_12_clicked(bool checked)
{
    if(checked)
    {
        ui->stackedWidge_2->setCurrentIndex(1);
        ui->radioButton_11->setChecked(false);
    }
}
//由用户输入的年数显示贷款总期数
void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
       ui->label_7->setNum(arg1.toDouble()*12);

}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->label_42->setNum(arg1.toDouble()*12);
}
void MainWindow::on_lineEdit_13_textChanged(const QString &arg1)
{
   ui->label_45->setNum(arg1.toDouble()*12);
}

void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
   ui->label_47->setNum(arg1.toDouble()*12);
}



//根据用户的选择来判断是等额本金还是等额本息，等额本息则fangshi值为0，等额本金值为1；
void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if(checked)
    {
        fangshi=0;
    }
    ui->radioButton_4->setChecked(false);
}

void MainWindow::on_radioButton_4_clicked(bool checked)
{
    if(checked)
    {
        fangshi=1;
    }
    ui->radioButton_3->setChecked(false);
}

void MainWindow::on_radioButton_5_clicked(bool checked)
{
    if(checked)
    {
        fangshi=0;
    }
    ui->radioButton_6->setChecked(false);
}

void MainWindow::on_radioButton_6_clicked(bool checked)
{
    if(checked)
    {
        fangshi=1;
    }
    ui->radioButton_5->setChecked(false);
}

void MainWindow::on_radioButton_9_clicked(bool checked)
{
    if(checked)
    {
        fangshi=0;
    }
    ui->radioButton_10->setChecked(false);
}

void MainWindow::on_radioButton_10_clicked(bool checked)
{
    if(checked)
    {
        fangshi=1;
    }
    ui->radioButton_9->setChecked(false);
}

void MainWindow::on_radioButton_7_clicked(bool checked)
{
    if(checked)
    {
        fangshi=0;
    }
    ui->radioButton_8->setChecked(false);
}

void MainWindow::on_radioButton_8_clicked(bool checked)
{
    if(checked)
    {
        fangshi=1;
    }
    ui->radioButton_7->setChecked(false);
}

void MainWindow::on_radioButton_13_clicked(bool checked)
{
    if(checked)
    {
        fangshi=0;
    }
    ui->radioButton_14->setChecked(false);
}

void MainWindow::on_radioButton_14_clicked(bool checked)
{
    if(checked)
    {
        fangshi=1;
    }
    ui->radioButton_13->setChecked(false);
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    ui->label_46->setNum(arg1.toDouble()*12);
}

//当用户按下计算按钮时进行数据获取和计算，并将计算结果显示出来
void MainWindow::on_pushButton_clicked()
{
    danjia1=ui->lineEdit->text().toDouble();
    mianji1=ui->lineEdit_2->text().toDouble();
    nianshu1=ui->lineEdit_3->text().toDouble();
    chengshu1=ui->lineEdit_20->text().toDouble();
    lilv1=ui->lineEdit_4->text().toDouble();
    if(danjia1<=0 || mianji1<=0 ||nianshu1<=0 ||chengshu1 <=0 ||lilv1<=0 ||chengshu1>10)
    {

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_20->clear();
        ui->stackedWidget->setCurrentIndex(2);
        gengxin();
    }
    else
    {
        if(fangshi==0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            result=danjia1*mianji1*chengshu1/10*((lilv1/12)*pow((1+lilv1/12),nianshu1*12))/(pow((1+lilv1/12),nianshu1*12)-1);
            shoufu=(danjia1*mianji1)*(1-chengshu1/10);
            zonge=result*nianshu1*12;
            lixi=zonge-danjia1*mianji1*chengshu1/10;
            ui->label_55->setText(QString::number(result,'f',2));
            ui->label_56->setText(QString::number(shoufu,'f',2));
            ui->label_58->setText(QString::number(lixi,'f',2));
            ui->label_60->setText(QString::number(zonge,'f',2));
            chushihua();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
            shoufu=(danjia1*mianji1)*(1-chengshu1/10);;
            result=(danjia1*mianji1*chengshu1/10/(nianshu1*12))+(danjia1*mianji1*chengshu1/10)*lilv1/12;
            dijian=(danjia1*mianji1*chengshu1/10)/(nianshu1*12)*(lilv1/12);
            zonge=result*(nianshu1*12)-nianshu1*12*(nianshu1*12-1)/2*dijian;
            lixi=zonge-(danjia1*mianji1*chengshu1/10);
            ui->label_65->setText(QString::number(shoufu,'f',2));
            ui->label_66->setText(QString::number(result,'f',2));
            ui->label_70->setText(QString::number(dijian,'f',2));
            ui->label_67->setText(QString::number(lixi,'f',2));
            ui->label_68->setText(QString::number(zonge,'f',2));
            chushihua();
        }
    }


}
void MainWindow::on_pushButton_3_clicked()
{
    zonge1=ui->lineEdit_5->text().toDouble();
    nianshu1=ui->lineEdit_6->text().toDouble();
    lilv1=ui->lineEdit_7->text().toDouble();
    if(zonge1<=0 || nianshu1<=0 || lilv1<=0 )
    {
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->stackedWidget->setCurrentIndex(2);
        gengxin();
    }
    else
    {
        if(fangshi==0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            result=zonge1*((lilv1/12)*pow((1+lilv1/12),nianshu1*12))/(pow((1+lilv1/12),nianshu1*12)-1);
            zonge=result*nianshu1*12;
            lixi=result*nianshu1*12-zonge1;
            ui->label_55->setText(QString::number(result,'f',2));
            ui->label_56->setText("无");
            ui->label_58->setText(QString::number(lixi,'f',2));
            ui->label_60->setText(QString::number(zonge,'f',2));
            chushihua();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
            result=(zonge1/(nianshu1*12))+zonge1*lilv1/12;
            dijian=zonge1/(nianshu1*12)*(lilv1/12);
            zonge=result*(nianshu1*12)-nianshu1*12*(nianshu1*12-1)/2*dijian;
            lixi=zonge-zonge1;
            ui->label_65->setText("无");
            ui->label_66->setText(QString::number(result,'f',2));
            ui->label_70->setText(QString::number(dijian,'f',2));
            ui->label_67->setText(QString::number(lixi,'f',2));
            ui->label_68->setText(QString::number(zonge,'f',2));
            chushihua();
        }
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    danjia1=ui->lineEdit_8->text().toDouble();
    mianji1=ui->lineEdit_9->text().toDouble();
    nianshu1=ui->lineEdit_10->text().toDouble();
    chengshu1=ui->lineEdit_22->text().toDouble();
    lilv1=ui->lineEdit_11->text().toDouble();
    if(danjia1<=0 || mianji1<=0 ||nianshu1<=0 ||chengshu1 <=0 ||lilv1<=0||chengshu1>10)
    {
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_22->clear();
        ui->lineEdit_11->clear();
        ui->stackedWidget->setCurrentIndex(2);
        gengxin();
    }
    else
    {
        if(fangshi==0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            result=danjia1*mianji1*chengshu1/10*((lilv1/12)*pow((1+lilv1/12),nianshu1*12))/(pow((1+lilv1/12),nianshu1*12)-1);
            shoufu=(danjia1*mianji1)*(1-chengshu1/10);
            zonge=result*nianshu1*12;
            lixi=zonge-danjia1*mianji1*chengshu1/10;
            ui->label_55->setText(QString::number(result,'f',2));
            ui->label_56->setText(QString::number(shoufu,'f',2));
            ui->label_58->setText(QString::number(lixi,'f',2));
            ui->label_60->setText(QString::number(zonge,'f',2));
            chushihua();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
            shoufu=(danjia1*mianji1)*(1-chengshu1/10);;
            result=(danjia1*mianji1*chengshu1/10/(nianshu1*12))+(danjia1*mianji1*chengshu1/10)*lilv1/12;
            dijian=(danjia1*mianji1*chengshu1/10)/(nianshu1*12)*(lilv1/12);
            zonge=result*(nianshu1*12)-nianshu1*12*(nianshu1*12-1)/2*dijian;
            lixi=zonge-(danjia1*mianji1*chengshu1/10);
            ui->label_65->setText(QString::number(shoufu,'f',2));
            ui->label_66->setText(QString::number(result,'f',2));
            ui->label_70->setText(QString::number(dijian,'f',2));
            ui->label_67->setText(QString::number(lixi,'f',2));
            ui->label_68->setText(QString::number(zonge,'f',2));
            chushihua();
        }
    }



}

void MainWindow::on_pushButton_2_clicked()
{
    zonge1=ui->lineEdit_12->text().toDouble();
    nianshu1=ui->lineEdit_13->text().toDouble();
    lilv1=ui->lineEdit_14->text().toDouble();
    if(zonge1<=0 || nianshu1<=0 || lilv1<=0)
    {
        ui->lineEdit_12->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_14->clear();
        ui->stackedWidget->setCurrentIndex(2);
        gengxin();
    }
    else
    {
        if(fangshi==0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            result=zonge1*((lilv1/12)*pow((1+lilv1/12),nianshu1*12))/(pow((1+lilv1/12),nianshu1*12)-1);
            zonge=result*nianshu1*12;
            lixi=result*nianshu1*12-zonge1;
            ui->label_55->setText(QString::number(result,'f',2));
            ui->label_56->setText("无");
            ui->label_58->setText(QString::number(lixi,'f',2));
            ui->label_60->setText(QString::number(zonge,'f',2));
            chushihua();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
            result=(zonge1/(nianshu1*12))+zonge1*lilv1/12;
            dijian=zonge1/(nianshu1*12)*(lilv1/12);
            zonge=result*(nianshu1*12)-nianshu1*12*(nianshu1*12-1)/2*dijian;
            lixi=zonge-zonge1;
            ui->label_65->setText("无");
            ui->label_66->setText(QString::number(result,'f',2));
            ui->label_70->setText(QString::number(dijian,'f',2));
            ui->label_67->setText(QString::number(lixi,'f',2));
            ui->label_68->setText(QString::number(zonge,'f',2));
            chushihua();
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    shangdaie=ui->lineEdit_15->text().toDouble();
    slilv=ui->lineEdit_16->text().toDouble();
    gongdaie=ui->lineEdit_18->text().toDouble();
    glilv=ui->lineEdit_17->text().toDouble();
    nianshu1=ui->lineEdit_19->text().toDouble();
    if(shangdaie<=0 || nianshu1<=0 || slilv<=0 ||gongdaie<=0 ||glilv<=0)
    {
        ui->lineEdit_15->clear();
        ui->lineEdit_16->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_17->clear();
        ui->lineEdit_19->clear();
        ui->stackedWidget->setCurrentIndex(2);
        gengxin();
    }
    else
    {
        if(fangshi==0)
        {
            ui->stackedWidget->setCurrentIndex(0);
            result=shangdaie*((slilv/12)*pow((1+slilv/12),nianshu1*12))/(pow((1+slilv/12),nianshu1*12)-1)+gongdaie*((glilv/12)*pow((1+glilv/12),nianshu1*12))/(pow((1+glilv/12),nianshu1*12)-1);
            zonge=result*nianshu1*12;
            lixi=zonge-shangdaie-gongdaie;
            ui->label_55->setText(QString::number(result,'f',2));
            ui->label_56->setText("无");
            ui->label_58->setText(QString::number(lixi,'f',2));
            ui->label_60->setText(QString::number(zonge,'f',2));
            chushihua();
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
            result=(shangdaie/(nianshu1*12))+shangdaie*slilv/12+(gongdaie/(nianshu1*12))+gongdaie*glilv/12;
            dijian=shangdaie/(nianshu1*12)*(slilv/12)+gongdaie/(nianshu1*12)*(glilv/12);
            zonge=result*(nianshu1*12)-nianshu1*12*(nianshu1*12-1)/2*dijian;
            lixi=zonge-shangdaie-gongdaie;
            ui->label_65->setText("无");
            ui->label_66->setText(QString::number(result,'f',2));
            ui->label_70->setText(QString::number(dijian,'f',2));
            ui->label_67->setText(QString::number(lixi,'f',2));
            ui->label_68->setText(QString::number(zonge,'f',2));
            chushihua();
        }
    }

}
