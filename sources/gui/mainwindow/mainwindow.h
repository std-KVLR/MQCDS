#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <vector>
#include <array>

#include <QMainWindow>
#include <QLineEdit>

#include "../Serialization/Serialization.h"
#include "../Validation/Validation.h"

#include "../../core/ServerCore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_serverStartButton_clicked();
    void on_confirmButton_clicked();


private:
    Ui::MainWindow *ui;

    static constexpr uint_fast8_t cm_parametersCount = 7;
    std::array<QLineEdit*, cm_parametersCount> editorsContainer;

    validation::Validator fieldsValidator;
    bool validation();
};
#endif // MAINWINDOW_H
