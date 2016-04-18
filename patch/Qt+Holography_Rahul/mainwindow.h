#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTime>

namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();


private slots:
    void on_pushButton_clicked();

private:
    Ui::mainwindow *ui;
    std::string filename;
    cv::VideoCapture cap;
    cv::Mat frame;
    QImage org1;
    QImage org2,org3,org4;
    QTimer *timerv;
    bool camera;

public slots:
    void updateUI();
    cv::Mat rotate(cv::Mat src, double angle);

};

#endif // MAINWINDOW_H

