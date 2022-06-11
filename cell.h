#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
private:
    QVariant value()  const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str, int &pos) const;
    QVariant evalFactor(const QString &str, int  &pos) const;

    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;

public:
    Cell();

    QTableWidgetItem *clone() const;
    void setDate(int role, const QVariant &value);
    QVariant data (int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();
};

#endif