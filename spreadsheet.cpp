#include <QtGui>

#include "cell.h"
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(QWidget *parent)
        ： QTableWidget(parent)
{
    autoRecalc = true;

    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),
            this SLOT(somethingChanged()));

    clear();
}

void Spreadsheet::clear()
{
    setRowcount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i< ColumnCount; ++i){
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString (Qcar('A' + i)));
        setHorizontalHeaderItem(i, item);

    }

    setCurrentCell(0, 0);
}