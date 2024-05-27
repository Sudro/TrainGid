#include "CustomSqlTableModel.h"

CustomSqlTableModel::CustomSqlTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

QVariant CustomSqlTableModel::data(const QModelIndex &idx, int role) const
{
    if (role == Qt::DisplayRole && idx.column() == fieldIndex("parent_route_id")) {
        int parentRouteId = QSqlTableModel::data(idx, Qt::DisplayRole).toInt();

        if (parentRouteId == 0) {
            return QVariant();
        }

        QSqlQuery query;
        query.prepare("SELECT departure_point, destination, trip_duration FROM routes WHERE route_id = :id");
        query.bindValue(":id", parentRouteId);
        if (query.exec() && query.next()) {
            QString departurePoint = query.value(0).toString();
            QString destination = query.value(1).toString();
            QString tripDuration = query.value(2).toString();

            if (!tripDuration.contains("час")) {
                tripDuration += " часа";
            }

            return QString("%1 -> %2 (%3)").arg(departurePoint).arg(destination).arg(tripDuration);
        } else {
            qDebug() << "Failed to retrieve parent route data: " << query.lastError().text();
        }
    }

    return QSqlTableModel::data(idx, role);
}
