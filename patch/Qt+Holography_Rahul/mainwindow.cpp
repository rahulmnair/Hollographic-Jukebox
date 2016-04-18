////////////////////////////////////////////////////////////////////////////////
//Author : Arun Jayan
//Email ID : arunjayan32@gmail.com
////////////////////////////////////////////////////////////////////////////////
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTimer>
mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");

    timerv = new QTimer(this);//timerv
    connect(timerv,SIGNAL(timeout()),this,SLOT(updateUI()));
    timerv->start(20);

    //setStyleSheet("QLabel { background-color : red; color : blue; }");
    ui->label_3->setStyleSheet("QLabel { background-color : red; color : blue; }");
    ui->label_2->setStyleSheet("QLabel { background-color : red; color : blue; }");
    ui->label_5->setStyleSheet("QLabel { background-color : red; color : blue; }");
    ui->label_6->setStyleSheet("QLabel { background-color : red; color : blue; }");
    camera = false;
}

mainwindow::~mainwindow()
{
    delete ui;
}


void mainwindow::on_pushButton_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(
                this,
                tr("Open File"));
    filename = fileNames.toUtf8().constData();
    cap.open(filename);

    camera = true;
\
}
void mainwindow::updateUI()
{
    cv::Mat black(400,400,CV_8UC3,cv::Scalar(255,0,0));
    cv::Mat frame1,frame2,frame3,frame4;
    frame = black.clone();
    frame1 = black.clone();
    frame2 = black.clone();
    frame3 = black.clone();
    frame4 = black.clone();

    //cap.set(CV_CAP_PROP_FRAME_WIDTH, 200);
    //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 200);
    if(camera==true)
    {
    cap.read(frame);

    frame1 = frame.clone();
    frame2 = rotate(frame,90.0);
    frame3 = rotate(frame,180);
    frame4 = rotate(frame,270);

    //cv::resize(frame,frame,cv::Size(200,200));
    }
    cv::cvtColor(frame1,frame1,CV_BGR2RGB);
    cv::cvtColor(frame2,frame2,CV_BGR2RGB);
    cv::cvtColor(frame3,frame3,CV_BGR2RGB);
    cv::cvtColor(frame4,frame4,CV_BGR2RGB);
    cv::resize(frame1,frame1,cv::Size(200,200));
    cv::resize(frame2,frame2,cv::Size(200,200));
    cv::resize(frame3,frame3,cv::Size(200,200));
    cv::resize(frame4,frame4,cv::Size(200,200));
    QImage org1((uchar*)frame1.data,frame1.cols,frame1.rows,frame1.step,QImage::Format_RGB888);
    QImage org2((uchar*)frame2.data,frame2.cols,frame2.rows,frame2.step,QImage::Format_RGB888);
    QImage org3((uchar*)frame3.data,frame3.cols,frame3.rows,frame3.step,QImage::Format_RGB888);
    QImage org4((uchar*)frame4.data,frame4.cols,frame4.rows,frame4.step,QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(org1));
    ui->label_3->setPixmap(QPixmap::fromImage(org3));
    ui->label_5->setPixmap(QPixmap::fromImage(org2));
    ui->label_6->setPixmap(QPixmap::fromImage(org4));

}

cv::Mat mainwindow::rotate(cv::Mat src, double angle)
{
    cv::Mat dst;
    cv::Point2f pt(src.cols/2., src.rows/2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
    cv::warpAffine(src, dst, r, cv::Size(src.cols, src.rows));
    return dst;
}
