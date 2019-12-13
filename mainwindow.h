#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Calcular_clicked();
    void on_pushButton_ACA_Agregar_clicked();
    void on_pushButton_ACA_Eliminar_clicked();

    void on_pushButton_BorrarDatos_clicked();

private:
    Ui::MainWindow *ui;

    // Algorithms
    void algorithm_CuadradosMedios();
    void algorithm_ProductosMedios();
    void algorithm_MultiplicarConstante();
    void algorithm_Lineal();
    void algorithm_ConguencialMultiplicativo();
    void algorithm_CongruencialAditivo();
};

#endif // MAINWINDOW_H
