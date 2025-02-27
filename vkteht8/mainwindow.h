#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeOutHandler();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer; //muuttuja jolla havainnollistetaan kumpi pelaaja on käytössä
    short gameTime;
    QTimer *pQTimer;
    void setGameInfoText(QString, short);

private slots:
    void startGameHandler(); //tämä käsittelee start-nappia ja aloittaa pelin
    void stopGameHandler();  //tämä funktio pysäyttää pelin/timerin ja nollaa pelin arvot
    void switchPlayerHandler(); //tässä funktiossa valitaan/vaihdetaan pelaajan vuoroa
    void chooseGameLengthHandler(); //tässä funktiossa valitaan pelin pituus ja alustetaan pelille arvot
};
#endif // MAINWINDOW_H
