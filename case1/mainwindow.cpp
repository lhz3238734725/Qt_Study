#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLatin1String>
#include <QString>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QHBoxLayout* mainlayout = new QHBoxLayout(centralWidget);

    displayStretchFactor(mainlayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createButtonIntoLayout(QLayout* layout, int number){
    for (int var = 0; var < number; ++var) {
        QPushButton* button = new QPushButton;
        button->setText(QLatin1String("Button")+ QString::number(var));
        layout->addWidget(button);
    }
}

void MainWindow::displayMarginAndSpacing(QHBoxLayout *mainLayout){
    mainLayout->setMargin(0);

    mainLayout->setSpacing(0);

    createButtonIntoLayout(mainLayout, 4);
}

void MainWindow::displayStretch(QHBoxLayout* layout){
    createButtonIntoLayout(layout, 4);

    layout->addStretch();
}

void  MainWindow::displayStretchFactor(QHBoxLayout* layout){
    QPushButton* button = new QPushButton(this);
    button->setText("button");
    adjustStretchFactorBySizePolicy(button, 1);
    layout->addWidget(button);

    QLabel* label = new QLabel(this);
    label->setText("you are very very very very very very very very good");
    label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
     adjustStretchFactorBySizePolicy(label, 2);
    layout->addWidget(label);
}

void MainWindow::adjustStretchFactorBySizePolicy(QWidget* widget, int strechFactor){
    QSizePolicy policy = widget->sizePolicy();
    policy.setHorizontalStretch(strechFactor);

    widget->setSizePolicy(policy);
}
