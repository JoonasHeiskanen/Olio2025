#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connectionit napeille
    connect(ui->N0, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);

    connect(ui->add0, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub1, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul2, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div3, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->enter, &QPushButton::clicked,
            this, &MainWindow::enterClickHandler);

    connect(ui->clear, &QPushButton::clicked,
            this, &MainWindow::clearLineEdits);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{   //sender() palauttaa osoittimen objektiin, joka laukaisi signaalin (eli painettu nappi).
    //qobject_cast<QPushButton *> muuntaa tämän osoittimen QPushButton-tyyppiseksi
    //Lopputuloksena saadaan osoitin button, joka osoittaa juuri siihen QPushButton-painikkeeseen, jota käyttäjä painoi.
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    qDebug()<<numberName.at(1);

    if (state == 0){    //otetaan vastaan ensimmäistä numeroa
        ui->num1->setText((ui->num1->text()+numberName.at(1)));
        number1 = ui->num1->text();
    }
    else{   //otetaan vastaan toista numeroa
        ui->num2->setText(ui->num2->text()+numberName.at(1));
        number2 = ui->num2->text();
    }
}

void MainWindow::enterClickHandler()
{   //muutetaan number1 ja 2 qstringistä floatiksi jotta voidaan suorittaa laskutoimitus
    float n1 = number1.toFloat();
    float n2 = number2.toFloat();

    switch(operand){
    case 1:
        result = n1 + n2;
        qDebug()<< "Case 1";
        break;

    case 2:
        result = n1 - n2;
        qDebug()<< "Case 2";
        break;

    case 3:
        result = n1 * n2;
        qDebug()<< "Case 3";
        break;

    case 4:
        result = n1 / n2;
        qDebug()<< "Case 4";
        break;

    default:
        qDebug()<<"Wrong operand";
    }
    ui->Result->setText(QString::number(result)); //muutetaan saatu tulos floatista->QStringiin
    state = 0;                                    //ja tulostetaan laskimessa saatu tulos result ruudulle
}


void MainWindow::clearLineEdits() //tämä funktio nollaa kaikki qline editit laskimessa
{

    ui->num1->clear();  //nollataan laskimen qline edit num1
    ui->num2->clear();  //nollataan laskimen qline edit num2
    ui->Result->clear();    //nollataan laskimen qline edit Result
    number1 = 0;    //nollataan number1 QString muuttuja
    number2 = 0;    //nollataan number2 QString muuttuja
    result = 0.0;     //nollataan result float muuttuja
    state = 0;      //asetetaan state takaisin 0, jotta laskimen käyttöä
                    //voidaan jatkaa normaalisti clear napin painalluksen jälkeen
}

void MainWindow::addSubMulDivClickHandler()
{
    state = 1;
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString operandName = button->objectName();
    qDebug()<< "Operand chosen =" <<operandName;

    if (operandName == "add0"){
        operand = 1;
    }else if (operandName == "sub1"){
        operand = 2;
    }else if (operandName == "mul2"){
        operand = 3;
    }else if (operandName == "div3"){
        operand = 4;
    }else {
        qDebug()<< "Invalid operand";
    }
}

/*void MainWindow::handleClick()
{
    counter ++;
    QString teksti = QString::number(counter);
    ui->num1->setText(teksti);
}*/

