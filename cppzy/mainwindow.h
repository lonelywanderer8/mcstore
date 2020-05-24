#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void gengxin();
    void chushihua();


private slots:

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_radioButton_1_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_11_clicked(bool checked);

    void on_radioButton_12_clicked(bool checked);

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_lineEdit_19_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void on_radioButton_5_clicked(bool checked);

    void on_radioButton_6_clicked(bool checked);

    void on_radioButton_9_clicked(bool checked);

    void on_radioButton_10_clicked(bool checked);

    void on_radioButton_7_clicked(bool checked);

    void on_radioButton_8_clicked(bool checked);

    void on_radioButton_13_clicked(bool checked);

    void on_radioButton_14_clicked(bool checked);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    double danjia1,mianji1,chengshu1,lilv1,zonge1,nianshu1;
    double shangdaie,slilv,gongdaie,glilv,nianshu;
    double result,shoufu,lixi,zonge,dijian;
    int fangshi;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
