#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(TEMPO_ATUALIZACAO);
    srand(time(NULL));

    configuraSeries();
    configuraGraficos();
    configuraTemas();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    t += TEMPO_ATUALIZACAO/1000.0;

    atualizaGrafico(0,t,    rand()%300/10.0);
    atualizaGrafico(1,t,    rand()%300/10.0);
    atualizaGrafico(2,t,    rand()%300/10.0);
    atualizaGrafico(3,t,    rand()%300/10.0);
    atualizaGrafico(4,t,    rand()%400/100.0);
    atualizaGrafico(5,t,    rand()%300/100.0);
    atualizaGrafico(6,t,    rand()%300/100.0);



    if(contPontos < maxPontos){
        grafico1->axisX()->setRange(0,t);
        grafico2->axisX()->setRange(0,t);

        contPontos ++;
    }else{
        setPoint->remove(0);
        leituraControle->remove(0);
        sinalGerado->remove(0);
        sinalErro->remove(0);

        leituraTq1->remove(0);
        leituraTq2->remove(0);
        sinalEnviado->remove(0);

        grafico1->axisX()->setRange(t-maxPontos*TEMPO_ATUALIZACAO/1000.0,t);
        grafico2->axisX()->setRange(t-maxPontos*TEMPO_ATUALIZACAO/1000.0,t);
    }

}

void MainWindow::configuraSeries(){
    setPoint = new QLineSeries();
    setPoint->setName("Set Point");

    leituraControle = new QLineSeries();
    leituraControle->setName("Leitura (PV)");

    sinalGerado = new QLineSeries();
    sinalGerado->setName("Sinal Gerado");

    sinalErro = new QLineSeries();
    sinalErro->setName("Sinal Erro");

    leituraTq1 = new QLineSeries();
    leituraTq1->setName("Leitura Tanque 1");

    leituraTq2 = new QLineSeries();
    leituraTq2->setName("Leitura Tanque 2");

    sinalEnviado = new QLineSeries();
    sinalEnviado->setName("Sinal Enviado");
}
void MainWindow::configuraGraficos(){
    grafico1 = new QChart();
    //Adicionando series
    grafico1->addSeries(setPoint);
    grafico1->addSeries(leituraControle);
    grafico1->addSeries(sinalGerado);
    grafico1->addSeries(sinalErro);

    grafico1->legend()->setAlignment(Qt::AlignLeft);
    grafico1->createDefaultAxes();

    chartView1 = new QChartView(grafico1);
    chartView1->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout1->addWidget(chartView1);


    grafico2 = new QChart();
    //Adicionando series
    grafico2->addSeries(leituraTq1);
    grafico2->addSeries(leituraTq2);
    grafico2->addSeries(sinalEnviado);


    grafico2->legend()->setAlignment(Qt::AlignLeft);
    grafico2->createDefaultAxes();
    grafico2->axisY()->setRange(-4,4);

    chartView2 = new QChartView(grafico2);
    chartView2->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout2->addWidget(chartView2);
}
void MainWindow::configuraTemas(){
    //    //Plano de fundo com tema Dark
    //    QPalette pal = window()->palette();
    //    pal.setColor(QPalette::Window, QRgb(0x121218));
    //    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
    //    window()->setPalette(pal);

    QChart::ChartTheme theme = (QChart::ChartTheme) QChart::ChartThemeDark;
    chartView1->chart()->setTheme(theme);
    chartView2->chart()->setTheme(theme);
}
void MainWindow::atualizaGrafico(int g, int x, int y){
    switch(g){
    case 0:
        if(y > maiorGrafico1){
            maiorGrafico1 = y;
            grafico1->axisY()->setRange(0,maiorGrafico1+1);
        }
        setPoint->append(x,y);
        break;
    case 1:
        if(y > maiorGrafico1){
            maiorGrafico1 = y;
            grafico1->axisY()->setRange(0,maiorGrafico1+1);
        }
        leituraControle->append(x,y);
        break;
    case 2:
        sinalGerado->append(x,y);
        break;
    case 3:
        if(y > maiorGrafico1){
            maiorGrafico1 = y;
            grafico1->axisY()->setRange(0,maiorGrafico1+1);
        }
        sinalErro->append(x,y);
        break;
    case 4:
        leituraTq1->append(x,y);
        break;
    case 5:
        leituraTq2->append(x,y);
        break;
    case 6:
        sinalEnviado->append(x,y);
        break;
    default:

        break;
    }
}
