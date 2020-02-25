#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dijsktra.h>
#include <QtWebEngine>
#include <QtWebEngineWidgets>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),counter(0)
{
    ui->setupUi(this);
    setUpComboBox();
    setWindowTitle("Airplane Problem");
    setUpWebengine();
}

void MainWindow::setUpComboBox()
{
    for(pair<int,Airport> elem : GB.getMap())
    {
        ui->sourceAirports->addItem(elem.second.getIata().c_str());
        ui->destinationAirports->addItem(elem.second.getIata().c_str());
    }
    ui->priorities->addItem("Distance");
    ui->priorities->addItem("Stops");
    ui->priorities->addItem("Time");
    ui->priorities->addItem("Cost");

}

int MainWindow::returnCounter()
{
    return counter;
}

void MainWindow::loadMap()
{
    for(pair<int,Airport> elem : GB.getMap())
    {
        QString line = "initializeMap(";
        double toLat = elem.second.lat();
        double toLong = elem.second.lng();
        webView->page()->runJavaScript(line+QString::number(toLat)+','+QString::number(toLong)+");");
    }
}

void MainWindow::setUpWebengine()
{
    webView = new QWebEngineView;
    channel = new QWebChannel(webView->page());
    webView->page()->setWebChannel(channel);
    channel->registerObject("mainWindow",this);
    QUrl url = QUrl("qrc:/map.html");
    ui->verticalLayout->addWidget(webView);
    webView->page()->load(url);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLatLong(const QString &latlng)
{
    //LatLng(34, -120)
    string temp(latlng.toStdString());
    if(counter==0)
    {
        cout<<"over here"<<endl;
        ui->sourceAirports->setCurrentText(temp.c_str());
        counter++;
    }
    else{
        ui->destinationAirports->setCurrentText(temp.c_str());
        counter = 0;
    }
}

void MainWindow::display(double value)
{
    if(ui->priorities->currentIndex()==0)
        ui->lineEdit->setText(QString::number(value)+" miles");
    else if(ui->priorities->currentIndex()==1)
        ui->lineEdit->setText(QString::number(value)+" stops");
    else if(ui->priorities->currentIndex()==2)
        ui->lineEdit->setText(QString::number(value)+" time");
    else
        ui->lineEdit->setText(QString::number(value)+" cost");
}

void MainWindow::bfs()
{
    string source = ui->sourceAirports->currentText().toStdString();
    string destination = ui->destinationAirports->currentText().toStdString();
    BreadthFirstSearch theBfs(GB.getGraph(),GB.retrieveID(destination));
    //clear entire layer
    webView->page()->runJavaScript("clear();");
    for(DirectedEdge e : theBfs.pathTo(GB.retrieveID(destination)))
    {
        ui->lineEdit->setText(QString::number(theBfs.pathTo(GB.retrieveID(destination)).size()));
        QString line = "addCoord(";
        double toLat = GB.getAirport(e.to()).lat();
        double toLong = GB.getAirport(e.to()).lng();
        double fromLat = GB.getAirport(e.from()).lat();
        double fromLong = GB.getAirport(e.from()).lng();
        webView->page()->runJavaScript(line+QString::number(toLat)+','+QString::number(toLong)+");");
        webView->page()->runJavaScript(line+QString::number(fromLat)+','+QString::number(fromLong)+");");
    }
    webView->page()->runJavaScript("plotPoints();");
}

void MainWindow::on_compute_clicked()
{
    string source = ui->sourceAirports->currentText().toStdString();
    string destination = ui->destinationAirports->currentText().toStdString();
    Dijsktra dijsktra(GB.getGraph(),GB.retrieveID(source));
    double scalarTransformation = 1;
    if(ui->priorities->currentIndex()==2)
        scalarTransformation = 575;
    else if(ui->priorities->currentIndex()==3)
        scalarTransformation = 6;
    cout<<ui->priorities->currentIndex()<<endl;
    //clear entire layer
    webView->page()->runJavaScript("clear();");
    for(DirectedEdge e : dijsktra.path(GB.retrieveID(destination)))
    {
        if(ui->priorities->currentIndex()!=1)
            display(dijsktra.distTo(GB.retrieveID(destination))/scalarTransformation);
        else
            display(dijsktra.path(GB.retrieveID(destination)).size());
        QString line = "addCoord(";
        double toLat = GB.getAirport(e.to()).lat();
        double toLong = GB.getAirport(e.to()).lng();
        double fromLat = GB.getAirport(e.from()).lat();
        double fromLong = GB.getAirport(e.from()).lng();
        if(GB.getAirport(e.from()).getIata()==destination)
            webView->page()->runJavaScript(line+QString::number(fromLat)+','+QString::number(fromLong)+");");
        else if(dijsktra.path(GB.retrieveID(destination)).size()==1)
        {
            webView->page()->runJavaScript(line+QString::number(toLat)+','+QString::number(toLong)+");");
            webView->page()->runJavaScript(line+QString::number(fromLat)+','+QString::number(fromLong)+");");
        }
        else
            webView->page()->runJavaScript(line+QString::number(toLat)+','+QString::number(toLong)+");");

        //        webView->page()->runJavaScript(line+QString::number(toLat)+','+QString::number(toLong)+");");
        //          webView->page()->runJavaScript(line+QString::number(fromLat)+','+QString::number(fromLong)+");");
        //webView->page()->runJavaScript(line+QString::number(fromLat)+','+QString::number(fromLong)+");");
    }
    webView->page()->runJavaScript("plotPoints();");
}

void MainWindow::on_action_run_triggered()
{
    loadMap();
}
