/*
    Name: mainWindow
    Copyright: 2023
    Author: John
    Date: 22/06/23 16:31
    Description: Get some Bitcoin price information
*/
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "GetRequest.h"
#include <string>
#include <iostream>
using json = nlohmann::json;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::BitcoinPriceTool){
    ui->setupUi(this);
    this->setWindowTitle("BitcoinPriceTool");
    ui->priceLabel->setText("");
}

MainWindow::~MainWindow(){
    delete ui;
}

// Refresh the price
void MainWindow::on_refreshButton_clicked(){
    string response = GetRequest::getRequest("https://api.coindesk.com/v1/bpi/currentprice.json");
    json data = json::parse(response);
    string price = data["bpi"]["USD"]["rate"];
    string dateUpdated = data["time"]["updated"];

    ui->priceLabel->setText("$"+QString::fromStdString(price));
    ui->titleBar->setText("Bitcoin Price        Last Updated["+QString::fromStdString(dateUpdated)+"]");
}

