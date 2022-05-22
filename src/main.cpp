#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QBoxLayout>
#include "chartview.h"

int main(int argc, char *argv[]){
  QApplication appli(argc, argv);
  QMainWindow window;

  // Organize layout
  QWidget *widget = new QWidget();
  QVBoxLayout *vbox = new QVBoxLayout;
  widget->setLayout(vbox);

  // Point coordinates position label.
  QLabel *lab = new QLabel();

  // Chart area
  ChartView *chart = new ChartView();
  chart->connectPointLabel(lab); // Connect chart to label for updates.

  vbox->addWidget(lab);
  vbox->addWidget(chart);

  window.setCentralWidget(widget);
  window.resize(800, 600);
  window.show();

  return appli.exec();
}
