#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <sstream>
#include <QWebEngineView>
#include <graphbuilder.h>
#include <QWebChannel>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Q_INVOKABLE void updateLatLong(const QString& ltlng);
    Q_INVOKABLE int returnCounter();
    void loadMap();
private slots:
    void on_compute_clicked();
    void on_action_run_triggered();

private:
    void setUpWebengine();
    void setUpComboBox();
    void display(double value);
    void bfs();
private:
    Ui::MainWindow *ui;
    int counter;
    int setUpUI= 1;
    QWebEngineView *webView;
    QWebEnginePage *page;
    QWebChannel* channel;
    QString source;
    QString destination;
    GraphBuilder GB =  GraphBuilder("airlinesRevised.txt","airportsRevised.txt","GraphRevised.txt");
};

#endif // MAINWINDOW_H
