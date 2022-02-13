#include "QDetachTabWidget.h"
#include <QApplication>
#include <QTableWidget>
#include <QLabel>

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    QDetachTabWidget* tabWidget = new QDetachTabWidget;
    tabWidget->setMovable(true);
    tabWidget->setTabsClosable(true);

    for (int i=1; i<11; i++) {
        QString tabName=QString("t_%1").arg(i);

        auto tbl = new QTableWidget;
        tbl->setRowCount(i);
        tbl->setColumnCount(i);

        tabWidget->addTab(tbl, tabName);
    }

    tabWidget->resize(800,500);
    tabWidget->show();

    return a.exec();
}

