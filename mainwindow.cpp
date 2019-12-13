#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QDebug>

#include "algoritmos.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Calcular_clicked()
{
    this->ui->listWidget_R->clear();

    // Determine operation
    int tabIndex = this->ui->tabWidget->currentIndex();
    QString tabName = this->ui->tabWidget->tabText(tabIndex);

    // Add title to result set
    this->ui->listWidget_R->addItem(tabName);

    if (tabName == "Algoritmo Congruencial Aditivo") {
        this->algorithm_CongruencialAditivo();
        return;
    }

    if (tabName == "Algoritmo Congruencial Multiplicativo") {
        this->algorithm_ConguencialMultiplicativo();
        return;
    }

    if (tabName == "Cuadrados Medios") {
        this->algorithm_CuadradosMedios();
        return;
    }

    if (tabName == "Algoritmo Lineal") {
        this->algorithm_Lineal();
        return;
    }

    if (tabName == "Multiplicar Constante") {
        this->algorithm_MultiplicarConstante();
        return;
    }

    if (tabName == "Productos Medios") {
        this->algorithm_ProductosMedios();
        return;
    }
}

void MainWindow::on_pushButton_BorrarDatos_clicked()
{
    // Determine tab
    int tabIndex = this->ui->tabWidget->currentIndex();
    QString tabName = this->ui->tabWidget->tabText(tabIndex);

    if (tabName == "Algoritmo Congruencial Aditivo") {
        this->ui->spinBox_ACA_Agregar->setValue(this->ui->spinBox_ACA_Agregar->minimum());
        this->ui->spinBox_ACA_m->setValue(this->ui->spinBox_ACA_m->minimum());
        this->ui->spinBox_ACA_xi->setValue(this->ui->spinBox_ACA_xi->minimum());
        this->ui->listWidget_ACA_Numeros->clear();

        return;
    }

    if (tabName == "Algoritmo Congruencial Multiplicativo") {
        this->ui->spinBox_ACM_k->setValue(this->ui->spinBox_ACM_k->minimum());
        this->ui->spinBox_ACM_m->setValue(this->ui->spinBox_ACM_m->minimum());
        this->ui->spinBox_ACM_x0->setValue(this->ui->spinBox_ACM_x0->minimum());
        return;
    }

    if (tabName == "Cuadrados Medios") {
        this->ui->spinBox_CM_n->setValue(this->ui->spinBox_CM_n->minimum());
        this->ui->spinBox_CM_x0->setValue(this->ui->spinBox_CM_x0->minimum());
        return;
    }

    if (tabName == "Algoritmo Lineal") {
        this->ui->spinBox_AL_a->setValue(this->ui->spinBox_AL_a->minimum());
        this->ui->spinBox_AL_c->setValue(this->ui->spinBox_AL_c->minimum());
        this->ui->spinBox_AL_m->setValue(this->ui->spinBox_AL_m->minimum());
        this->ui->spinBox_AL_n->setValue(this->ui->spinBox_AL_n->minimum());
        this->ui->spinBox_AL_x0->setValue(this->ui->spinBox_AL_x0->minimum());
        return;
    }

    if (tabName == "Multiplicar Constante") {
        this->ui->spinBox_MC_c->setValue(this->ui->spinBox_MC_c->minimum());
        this->ui->spinBox_MC_n->setValue(this->ui->spinBox_MC_n->minimum());
        this->ui->spinBox_MC_x0->setValue(this->ui->spinBox_MC_x0->minimum());
        return;
    }

    if (tabName == "Productos Medios") {
        this->ui->spinBox_PM_n->setValue(this->ui->spinBox_PM_n->minimum());
        this->ui->spinBox_PM_x0->setValue(this->ui->spinBox_PM_x0->minimum());
        this->ui->spinBox_PM_x1->setValue(this->ui->spinBox_PM_x1->minimum());
        return;
    }
}

void MainWindow::algorithm_CongruencialAditivo()
{
    int n = this->ui->listWidget_ACA_Numeros->count();
    int* x = new int[n];

    for (int i = 0; i < n; i++)
        x[i] = this->ui->listWidget_ACA_Numeros->item(i)->text().toInt();

    int xi = this->ui->spinBox_ACA_xi->text().toInt();
    int m = this->ui->spinBox_ACA_m->text().toInt();

    int index = 1;
    for (int i = n + 1; i <= xi; i++) {
        double r = Algoritmos::AlgoritmoCongruencialAditivo(x, n, m, i);
        this->ui->listWidget_R->addItem("r" + QString::number(index++) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::algorithm_ConguencialMultiplicativo()
{
    int x0 = this->ui->spinBox_ACM_x0->text().toInt();
    int k = this->ui->spinBox_ACM_k->text().toInt();
    int m = this->ui->spinBox_ACM_m->text().toInt();

    for (int i = 0; i < m/4; i++) {
        double r = Algoritmos::AlgoritmoCongruencialMultiplicativo(x0, k, m, i + 1);
        this->ui->listWidget_R->addItem("r" + QString::number(i + 1) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::algorithm_CuadradosMedios()
{
    int n = this->ui->spinBox_CM_n->text().toInt();
    int x0 = this->ui->spinBox_CM_x0->text().toInt();

    for (int i = 0; i < n; i++) {
        double r = Algoritmos::CuadradosMedios(x0, i + 1);
        this->ui->listWidget_R->addItem("r" + QString::number(i + 1) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::algorithm_Lineal()
{
    int n = this->ui->spinBox_AL_n->text().toInt();
    int x0 = this->ui->spinBox_AL_x0->text().toInt();
    int a = this->ui->spinBox_AL_a->text().toInt();
    int c = this->ui->spinBox_AL_c->text().toInt();
    int m = this->ui->spinBox_AL_m->text().toInt();

    for (int i = 0; i < n; i++) {
        double r = Algoritmos::AlgoritmoLineal(x0, a, c, m, i + 1);
        this->ui->listWidget_R->addItem("r" + QString::number(i + 1) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::algorithm_MultiplicarConstante()
{
    int n = this->ui->spinBox_MC_n->text().toInt();
    int x0 = this->ui->spinBox_MC_x0->text().toInt();
    int c = this->ui->spinBox_MC_c->text().toInt();

    for (int i = 0; i < n; i++) {
        double r = Algoritmos::MultiplicarConstante(x0, c, i + 1);
        this->ui->listWidget_R->addItem("r" + QString::number(i + 1) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::algorithm_ProductosMedios()
{
    int n = this->ui->spinBox_PM_n->text().toInt();
    int x0 = this->ui->spinBox_PM_x0->text().toInt();
    int x1 = this->ui->spinBox_PM_x1->text().toInt();

    for (int i = 0; i < n; i++) {
        double r = Algoritmos::ProductosMedios(x0, x1, i + 1);
        this->ui->listWidget_R->addItem("r" + QString::number(i + 1) + " = " + QString::number(r));

        // End algorithm
        if (r <= -1)
            return;
    }
}

void MainWindow::on_pushButton_ACA_Agregar_clicked()
{
    int num = this->ui->spinBox_ACA_Agregar->text().toInt();
    this->ui->listWidget_ACA_Numeros->addItem(QString::number(num));
}

void MainWindow::on_pushButton_ACA_Eliminar_clicked()
{
    foreach (QListWidgetItem* item, this->ui->listWidget_ACA_Numeros->selectedItems())
        delete this->ui->listWidget_ACA_Numeros->takeItem(ui->listWidget_ACA_Numeros->row(item));
}


