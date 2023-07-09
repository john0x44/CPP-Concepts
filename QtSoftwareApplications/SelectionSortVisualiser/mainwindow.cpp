/*
    Name: mainwindow
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Selection sort visually implemented
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <ctime>
#include <iostream>
#include <vector>
#include <QCoreApplication>
#include "RectangeClass.h"

// Create a vector to store Rect objects
std::vector<Rect> rectVector;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setWindowTitle("SelectionSortVisual");
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(Qt::black);
    srand(time(0));
    int squareSize = 4;
    int sceneWidth = static_cast<int>(this->width());
    int sceneHeight = static_cast<int>(this->height());
    int numSquares = sceneWidth / squareSize;

    // Calculate a random square height
    int yPosition = (sceneHeight - squareSize) / 2;
    for (int i = 0; i < numSquares; i++) {
        QGraphicsRectItem* rectItem = new QGraphicsRectItem(0, sceneHeight / 2, squareSize, -(rand() % 550 + 1));
        rectItem->setBrush(Qt::red);
        scene->addItem(rectItem);
        rectItem->setPos(i * squareSize, yPosition);
        Rect newRect(rectItem);
        rectVector.push_back(newRect);
    }
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Selection sort aglorithm
void SelectionSort(QGraphicsView* view) {
    int size = rectVector.size();
    for (int startScan = 0; startScan < (size - 1); startScan++) {
        int minIndex = startScan;
        int minValue = rectVector[startScan].getYH();
        for (int index = startScan + 1; index < size; index++) {
            if (rectVector[index].getYH() < minValue) {
                minValue = rectVector[index].getYH();
                minIndex = index;
            }
        }
        // Swap the Rect objects
        std::swap(rectVector[startScan], rectVector[minIndex]);
        int x1 = rectVector[startScan].getX();
        int y1 = rectVector[startScan].getY();
        int x2 = rectVector[minIndex].getX();
        int y2 = rectVector[minIndex].getY();
        rectVector[startScan].setPos(x2, y2);
        rectVector[minIndex].setPos(x1, y1);
        view->scene()->update();
        QCoreApplication::processEvents();
    }
}

// Handle client button press
void MainWindow::on_sortButton_clicked()
{
    SelectionSort(ui->graphicsView);
}
