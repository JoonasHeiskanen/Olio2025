#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


private:
    Ui::MainWindow *ui;
    QString number1, number2;   // QString on kätevä, koska sen voi tulostaa helposti QLineEditiin
    int state=0;    // state-muuttujaa tarvitaan tietämään, kumpi numeroista annetaan laskimessa
    float result;   // tulos lasketaan, kun käyttäjä painaa enteriä
    short operand;  // operaattori tallennetaan, kun käyttäjä painaa +, -, * tai / -painikkeita
    //int counter = 0;

private slots:
    //void handleClick();
    void numberClickedHandler();    // Tämä funktio kutsutaan kaikista numeropainikkeiden (QPushButton) klikkauskäsittelijöistä
    void enterClickHandler();   // Tämä käsittelee enter-painikkeen
    void addSubMulDivClickHandler();    // Lisäksi yksi käsittelijä +, -, *, / -painikkeille
    void clearLineEdits();  // Tämä on kätevä kaikkien kolmen QLineEditin nollaamiseen

};
#endif // MAINWINDOW_H
