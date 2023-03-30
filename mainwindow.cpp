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
#include <QMessageBox>
#include <QCursor>

//global variables
QCheckBox *chinese_check;
QCheckBox *italian_check;
QCheckBox *mexican_check;
QRadioButton *yes_radio;
QRadioButton *no_radio;


//makes radio boxes, check boxes and ui
//get destroyed when main window is closed
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , chinese_check(new QCheckBox("Chinese", this))
    , italian_check(new QCheckBox("Italian", this))
    , mexican_check(new QCheckBox("Mexican", this))
    , yes_radio(new QRadioButton("Yes", this))
    , no_radio(new QRadioButton("No", this))
    , recipeButton(new QPushButton("Click here!", this))
    , mainLabel(new QLabel("Recipes"))
    , vegLabel(new QLabel("Vegetarian?"))
    , cuisineLabel(new QLabel("Cuisine"))



{
    ui->setupUi(this);
    resize(300, 200);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    labelLayout->addWidget(ui->mainLabel, Qt::AlignCenter);


    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(ui->vegLabel, 0, 0);
    leftLayout->addWidget(ui->yes_radio, 1, 0);
    leftLayout->addWidget(ui->no_radio, 2, 0);

    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(ui->cuisineLabel, 0, 1);
    rightLayout->addWidget(ui->italian_check, 1, 1);
    rightLayout->addWidget(ui->mexican_check, 2, 1);
    rightLayout->addWidget(ui->chinese_check, 3, 1);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addStretch(1);
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);
    topLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(labelLayout);
    mainLayout->addStretch(1);
    mainLayout->addLayout(topLayout);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(ui->recipeButton, 0, Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

    MainWindow::~MainWindow()

{
    delete ui;
    delete chinese_check;
    delete italian_check;
    delete mexican_check;
    delete yes_radio;
    delete no_radio;
}





void MainWindow::showRecipe()
{
    QString chineseRecipe = "<a href='https://www.bbc.co.uk/food/recipes/chickenchowmein_89258'>Chicken Chow Mein</a>";
    QString vchineseRecipe = "<a href='https://www.bbc.co.uk/food/recipes/mushroom_and_broccoli_33092'>Mushroom and Broccoli Stir Fry</a>";
    QString italianRecipe = "<a href='https://www.bbc.co.uk/food/recipes/spaghettiallacarbona_73311'>Spaghetti Carbonara</a>";
    QString vitalianRecipe = "<a href='https://www.bbc.co.uk/food/recipes/aubergine_pasta_bake_51402'>Aubergine Pasta Bake</a>";
    QString mexicanRecipe = "<a href='https://www.bbc.co.uk/food/recipes/chicken_and_bean_18392'>Chicken and Bean Burritos></a>";
    QString vmexicanRecipe = "<a href='https://www.bbc.co.uk/food/recipes/kidney_bean_and_28819'>Kidney bean and sweetcorn quesadillas</a>";

    QString recipe;

    if (ui->yes_radio->isChecked() && ui->chinese_check->isChecked()) {
        recipe = vchineseRecipe;
    } else if (ui->no_radio->isChecked()) {
        recipe = chineseRecipe;
    }

    if (ui->yes_radio->isChecked() && ui->italian_check->isChecked()) {
        recipe = vitalianRecipe;
    } else if (ui->no_radio->isChecked()) {
        recipe = italianRecipe;
    }

    if (ui->yes_radio->isChecked() && ui->mexican_check->isChecked()) {
        recipe = vmexicanRecipe;
    } else if (ui->no_radio->isChecked()) {
        recipe = mexicanRecipe;
    }

    QMessageBox msgBox;
        QFont font("Arial", 10, QFont::Bold);
        msgBox.setFont(font);
        msgBox.setText(recipe);
        msgBox.exec();



}



void MainWindow::on_recipeButton_clicked()
{
    showRecipe();

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 10);
    slider->setTickInterval(1);

    QLabel *sliderLabel = new QLabel("How satisfied are you with the recipe?");
    QFont font("Arial", 10, QFont::Bold);
    sliderLabel->setFont(font);

    QVBoxLayout *sliderLayout = new QVBoxLayout;

    sliderLayout->addWidget(sliderLabel);
    sliderLayout->addWidget(slider);

    QDialog *dialog = new QDialog(this);
    dialog->setLayout(sliderLayout);

    QObject::connect(slider, &QSlider::valueChanged, [=](int value){
    sliderLabel->setText(QString("How satisfied are you with the recipe? %1").arg(value));
    });

    dialog->exec();
}


