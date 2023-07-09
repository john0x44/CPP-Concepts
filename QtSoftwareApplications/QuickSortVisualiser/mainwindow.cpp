/*
    Name: mainwindow
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Quick sort visually implemented
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
    this->setWindowTitle("QuickSortVisual");
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
    this->resize(1300,1000);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Partition function for Quick Sort
int partition(std::vector<Rect>& vec, int low, int high, QGraphicsView* view) {
    int pivot = vec[high].getYH();
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (vec[j].getYH() < pivot) {
            i++;
            std::swap(vec[i], vec[j]);
            // Swap the positions of the Rect objects in the scene
            int x1 = vec[i].getX();
            int y1 = vec[i].getY();
            int x2 = vec[j].getX();
            int y2 = vec[j].getY();
            vec[i].setPos(x2, y2);
            vec[j].setPos(x1, y1);
            view->scene()->update();
            QCoreApplication::processEvents();
        }
    }

    // Swap the Rect objects
    std::swap(vec[i + 1], vec[high]);

    // Swap the positions of the Rect objects in the scene
    int x1 = vec[i + 1].getX();
    int y1 = vec[i + 1].getY();
    int x2 = vec[high].getX();
    int y2 = vec[high].getY();
    vec[i + 1].setPos(x2, y2);
    vec[high].setPos(x1, y1);
    view->scene()->update();
    QCoreApplication::processEvents();
    return (i + 1);
}

// QuickSort function
void QuickSort(std::vector<Rect>& vec, int left, int pivot, QGraphicsView* view) {
    if (left < pivot) {
        int pi = partition(vec, left, pivot, view);
        QuickSort(vec, left , pi - 1, view);
        QuickSort(vec, pi + 1, pivot, view);
    }
}

// Handle client button press
void MainWindow::on_sortButton_clicked() {
    QuickSort(rectVector, 0, rectVector.size() - 1, ui->graphicsView);
}
