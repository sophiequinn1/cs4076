#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QRadioButton>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRecipe();



    void on_recipeButton_clicked();

private:
    Ui::MainWindow *ui;
    QCheckBox *chinese_check;
    QCheckBox *italian_check;
    QCheckBox *mexican_check;

    QRadioButton *yes_radio;
    QRadioButton *no_radio;

    QPushButton *recipeButton;

    QLabel *mainLabel;
    QLabel *vegLabel;
    QLabel *cuisineLabel;

    QSlider *slider;


};
#endif // MAINWINDOW_H
