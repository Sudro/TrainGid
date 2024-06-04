#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() : currentRole(User)
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    //m_db.setUserName("postgres");
    //m_db.setPassword("12345");
    m_db.setDatabaseName("train");
    m_db.setHostName("localhost");
    setUserRole(User); // Устанавливаем начальную роль
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::openDatabase()
{
    if (!m_db.isOpen()) {
        if (m_db.open()) {
            qDebug() << "Connected to database";
            return true;
        } else {
            qDebug() << "Failed to connect to database: " << m_db.lastError().text();
            return false;
        }
    }
    return true;
}

QSqlDatabase DatabaseManager::database() const
{
    return m_db;
}

void DatabaseManager::setUserRole(UserRole role)
{
    currentRole = role;
    if (role == User) {
        m_db.setUserName("read_user");
        m_db.setPassword("12345");
        currentUser = "read_user";
        qDebug() << "Connecting as read_user";
    } else if (role == Admin) {
        m_db.setUserName("edit_user");
        m_db.setPassword("12345");
        currentUser = "edit_user";
        qDebug() << "Connecting as edit_user";
    }
    if (m_db.isOpen()) {
        m_db.close();
    }
    m_db.open();
}

QString DatabaseManager::currentUserName() const
{
    return currentUser;
}
