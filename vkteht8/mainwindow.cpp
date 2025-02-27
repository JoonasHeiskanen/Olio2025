#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);

    connect(pQTimer, &QTimer::timeout,
            this, &MainWindow::timeOutHandler);

    connect(ui->startGame, &QPushButton::clicked,
            this, &MainWindow::startGameHandler);

    connect(ui->stopGame, &QPushButton::clicked,
            this, &MainWindow::stopGameHandler);

    connect(ui->player1, &QPushButton::clicked,
            this, &MainWindow::switchPlayerHandler);
    connect(ui->player2, &QPushButton::clicked,
            this, &MainWindow::switchPlayerHandler);

    connect(ui->game2Min, &QPushButton::clicked,
            this, &MainWindow::chooseGameLengthHandler);
    connect(ui->game5Min, &QPushButton::clicked,
            this, &MainWindow::chooseGameLengthHandler);
    setGameInfoText("Select playtime and start the game!",12);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeOutHandler()
{
    if (currentPlayer == 1 && player1Time > 0){
        player1Time--;  //vähennetään player2Timeä 1 per 1sekunti(pQtimer = 1000ms)
        gameTime--;     //vähennetään player2Timeä 1 per 1sekunti(pQtimer = 1000ms)
        ui->player1Bar->setValue(player1Time); //päivitetään player1 aikaa progressbariin
    }
    else if (currentPlayer == 2 && player2Time > 0){
        player2Time--;  //vähennetään player2Timeä 1 per 1sekunti(pQtimer = 1000ms)
        gameTime--;     //vähennetään gametimeä 1 per 1sekunti(pQtimer = 1000ms)
        ui->player2Bar->setValue(player2Time); //päivitetään player2 aikaa progressbariin
    }
    if (player1Time == 0){
        setGameInfoText("Player 2 WON!",25);
        pQTimer->stop(); //pysäytetään timer
    }
    if (player2Time == 0){
        pQTimer->stop(); //pysäytetään timer
        setGameInfoText("Player 1 WON!",25);
    }
    qDebug()<< "p1   p2   gtime";
    qDebug()<< player1Time << "" << player2Time << "" << gameTime;
}

void MainWindow::setGameInfoText(QString txt, short font)
{
    ui->label->setText(txt); //asetetaan teksti qlabeliin joka on ui:ssa
    ui->label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->label->setFixedHeight(35);
    ui->label->QLabel::setStyleSheet
    (QString("font-size: %1px; font-weight: bold; color: red;").arg(font)); //asetetaan fontin koko
}

void MainWindow::startGameHandler()
{
    setGameInfoText("Game started", 12);
    currentPlayer = 1; //pelaaja 1 aloittaa pelin
    pQTimer->start(1000); //alustetaan timer -> antaa keskeytyksiä 1sekunnin välein
}

void MainWindow::stopGameHandler()
{
    pQTimer->stop(); //pysäytetään timer
    ui->player1Bar->reset(); //resetoidaan eli nollataan player1Bar
    ui->player2Bar->reset(); //resetoidaan eli nollataan player2Bar
    setGameInfoText("Game finished! Start new game",12);
}

void MainWindow::switchPlayerHandler()

{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString toBeSwitched = button->objectName();
    if (toBeSwitched == "player1"){
        currentPlayer = 2; //tätä arvoa käytetään valitsemaan
        //kummalta pelaajalta vähennetään aikaa timeOutHandler() funktiossa
        setGameInfoText("Player2 turn!",12);
    }
    if (toBeSwitched == "player2"){
        currentPlayer = 1; //tätä arvoa käytetään valitsemaan
        //kummalta pelaajalta vähennetään aikaa timeOutHandler() funktiossa
        setGameInfoText("Player1 turn!",12);
    }

}

void MainWindow::chooseGameLengthHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString gameLength = button->objectName();
    //tässä funktiossa alustetaan game ja playertime muuttujat
    //ja asetetaan playerbar min ja max arvot +
    //playerbareihin playertime arvo
    if (gameLength == "game2Min"){ //2min peli
        gameTime = 120;
        player1Time = 120;
        player2Time = 120;
        ui->player1Bar->setRange(0,player1Time);
        ui->player1Bar->setValue(player1Time);
        ui->player2Bar->setRange(0,player2Time);
        ui->player2Bar->setValue(player2Time);
        setGameInfoText("Selected game: 2min",12);
    }
    else if (gameLength == "game5Min"){ //5min peli
        gameTime = 300;
        player1Time = 300;
        player2Time = 300;
        ui->player1Bar->setRange(0,player1Time);
        ui->player1Bar->setValue(player1Time);
        ui->player2Bar->setRange(0,player2Time);
        ui->player2Bar->setValue(player2Time);
        setGameInfoText("Selected game: 5min",12);
    }
}
