#ifndef CUSTOMSQLTABLEMODEL_H
#define CUSTOMSQLTABLEMODEL_H

#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

class CustomSqlTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit CustomSqlTableModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());

    QVariant data(const QModelIndex &idx, int role = Qt::DisplayRole) const override;
};

#endif // CUSTOMSQLTABLEMODEL_H
