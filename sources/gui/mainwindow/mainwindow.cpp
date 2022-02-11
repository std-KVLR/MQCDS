#include "mainwindow.h"
#include "./ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    editorsContainer[0] = ui->le_IPEditor;
    editorsContainer[1] = ui->le_PortEditor;
    editorsContainer[2] = ui->le_SubTopEditor;
    editorsContainer[3] = ui->le_PubTopEditor;
    editorsContainer[4] = ui->le_cIDEditor;
    editorsContainer[5] = ui->le_UnameEditor;
    editorsContainer[6] = ui->le_PwdEditor;

    std::array<QString, cm_parametersCount> defaultValues = {"127.0.0.1", "1883", "topic/deviceInfo",
                                                             "topic/commandCenter", "1", "command_center", "12345"
                                                            };
    for(uint8_t i = 0; i < cm_parametersCount; ++i){
        editorsContainer[i]->setText(defaultValues[i]);
    }
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_serverStartButton_clicked()
{
    static bool onoff;
    onoff = !onoff;
    if(onoff){
        core::Server::Instance().start();
        ui->serverStartButton->setText("STOP");
    }
    else{
        core::Server::Instance().stop();
        ui->serverStartButton->setText("START");
    }
}


void MainWindow::on_confirmButton_clicked()
{
    if(validation()) json_serialization::serialization(editorsContainer);
}

#include <QMessageBox>
bool MainWindow::validation()
{

    QString ipValue(editorsContainer[0]->text());
    QString portValue(editorsContainer[1]->text());

    QString errorMessage;
    if(!fieldsValidator.validateIP(ipValue)){
        errorMessage = "IP address is wrong";
    }
    else if(!fieldsValidator.validatePort(portValue)){
        errorMessage = "Port number is not a number or out of range.";
    }
    if(!errorMessage.isEmpty()){
        QMessageBox errmsg;
        errmsg.setText(errorMessage);
        errmsg.setIcon(QMessageBox::Critical);
        errmsg.exec();
        return false;
   }
   return true;
}

//fields termination

