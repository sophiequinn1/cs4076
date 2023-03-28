#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logo("C:/Users/sophi/Downloads/LM121/2ND YEAR/2ND SEMESTER/CS4076/project/logo.png");
    ui->logo_label->setPixmap(logo);

    // Create check boxes for cuisine selection
    QCheckBox *italian_check = new QCheckBox("Italian");
    QCheckBox *mexican_check = new QCheckBox("Mexican");
    QCheckBox *chinese_check = new QCheckBox("Chinese");

    //radio button for veg
    QRadioButton *yes_radio = new QRadioButton("Yes");
    QRadioButton *no_radio = new QRadioButton("No");


    // Create radio buttons for recipe options
    /*QLabel *spaghetti_label = new QLabel("Spaghetti:");
    QRadioButton *spaghetti_option1_radio = new QRadioButton("Option 1");
    QRadioButton *spaghetti_option2_radio = new QRadioButton("Option 2");

    QLabel *taco_label = new QLabel("Tacos:");
    QRadioButton *taco_option1_radio = new QRadioButton("Option 1");
    QRadioButton *taco_option2_radio = new QRadioButton("Option 2");

    QLabel *fried_rice_label = new QLabel("Fried Rice:");
    QRadioButton *fried_rice_option1_radio = new QRadioButton("Option 1");
    QRadioButton *fried_rice_option2_radio = new QRadioButton("Option 2");*/

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(yes_radio);
    leftLayout->addWidget(no_radio);


    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(italian_check);
    rightLayout->addWidget(mexican_check);
    rightLayout->addWidget(chinese_check);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(ui->recipe_button);


    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}




