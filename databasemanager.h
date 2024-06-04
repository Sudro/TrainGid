#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager
{
public:
    enum UserRole {
        User,
        Admin
    };

    static DatabaseManager& instance();
    bool openDatabase();
    QSqlDatabase database() const;
    void setUserRole(UserRole role);
    QString currentUserName() const; // Новый метод

private:
    DatabaseManager();
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_db;
    UserRole currentRole;
    QString currentUser;
};

#endif // DATABASEMANAGER_H

