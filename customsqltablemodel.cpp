#include "CustomSqlTableModel.h"

CustomSqlTableModel::CustomSqlTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
}

QVariant CustomSqlTableModel::data(const QModelIndex &idx, int role) const
{
    if (role == Qt::DisplayRole) {
        if (idx.column() == fieldIndex("parent_route_id")) {
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
        } else if (idx.column() == fieldIndex("route_id")) {
            int routeId = QSqlTableModel::data(idx, Qt::DisplayRole).toInt();
            QSqlQuery query;
            query.prepare("SELECT departure_point, destination, trip_duration FROM routes WHERE route_id = :id");
            query.bindValue(":id", routeId);
            if (query.exec() && query.next()) {
                QString departurePoint = query.value(0).toString();
                QString destination = query.value(1).toString();
                QString tripDuration = query.value(2).toString();

                if (!tripDuration.contains("час")) {
                    tripDuration += " часа";
                }

                return QString("%1 -> %2 (%3)").arg(departurePoint).arg(destination).arg(tripDuration);
            } else {
                qDebug() << "Failed to retrieve route data: " << query.lastError().text();
            }
        } else if (idx.column() == fieldIndex("station_id")) {
            int stationId = QSqlTableModel::data(idx, Qt::DisplayRole).toInt();
            QSqlQuery query;
            query.prepare("SELECT station_name FROM stations WHERE station_id = :id");
            query.bindValue(":id", stationId);
            if (query.exec() && query.next()) {
                return query.value(0).toString();
            } else {
                qDebug() << "Failed to retrieve station data: " << query.lastError().text();
            }
        }
    }
    return QSqlTableModel::data(idx, role);
}

/*
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
*/
