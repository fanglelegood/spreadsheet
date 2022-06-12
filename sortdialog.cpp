#include <QtGui>

#include "sortdialog.h"
#include "spreadsheet.h"

SortDialog::SortDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    
    setColumnRange('A', 'Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));
    primaryColumnCombo->setMinimumSize(
        secondaryColumnCombo->sizeHint()
    );

    QChar ch = first;
    while (ch <= last)
    {
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
    
}

bool SpreadsheetCompare::operator()(const QStringList &row1,
                                const QStringList &row2) const
{
    for (int i=0; i < KeyCount; ++i) {
        int column = keys[i];
        if (column != -1) {
            if (row1[column] != row2[column]) {
                if  (ascending[i]) {
                    return row1[column] < row2[column];
                }else{
                    return row1[column] > row2[column];
                }
            }
        }
    }
    return false;
}