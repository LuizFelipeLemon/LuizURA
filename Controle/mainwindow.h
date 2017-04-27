#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QtWidgets>
#include <QPainter>

#include <iostream>
#include <ctime>
#include <cstdlib>

#define TEMPO_ATUALIZACAO 100

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerEvent(QTimerEvent *event);

    //Variaveis de construção de gráfico
    double t = 0;
    int contPontos = 0;
    int tempoAcumulado = 20;
    int maxPontos = tempoAcumulado * (1/(TEMPO_ATUALIZACAO/1000.0));
    float maiorGrafico1 = 0;
    float maiorGrafico2 = 0;

    //Variaveis para as series de dados
    QLineSeries *setPoint;          //0
    QLineSeries *leituraControle;   //1 Grafico 01
    QLineSeries *sinalGerado;       //2
    QLineSeries *sinalErro;         //3

    QLineSeries *leituraTq1;        //4
    QLineSeries *leituraTq2;        //5 Grafico 02
    QLineSeries *sinalEnviado;      //6

    //Variaveis para o gráfico
    QChart *grafico1;
    QChartView *chartView1;
    QChart *grafico2;
    QChartView *chartView2;

    //Funcoes auxiliares
    void configuraSeries();
    void configuraGraficos();
    void configuraTemas();
    void atualizaGrafico(int g, int x, int y);

public slots:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
