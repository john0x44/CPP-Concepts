/*
    Name: mainwindow
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Listens to recieved messages from a websocket
*/
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWebSockets/QWebSocket>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("K8SPodLogger");

    // Websocket signals
    connect(&m_webSocket, &QWebSocket::connected, this, [&]() {
        qDebug() << "WebSocket connected";
    });

    connect(&m_webSocket, &QWebSocket::disconnected, this, [&]() {
        qDebug() << "WebSocket disconnected";
    });

    connect(&m_webSocket, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, [&](QAbstractSocket::SocketError error){
        qDebug() << "WebSocket error:" << error;
    });

    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &MainWindow::onTextMessageReceived);
    // listener
    MainWindow::start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start(){
    m_webSocket.open(QUrl(QString("ws://localhost:8080")));
}

void MainWindow::onTextMessageReceived(const QString &message){
    ui->listWidget->addItem(message);
}
