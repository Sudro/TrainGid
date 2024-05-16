#include "DatabaseManager.h"

DatabaseManager::DatabaseManager()
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setUserName("postgres");
    m_db.setPassword("12345");
    m_db.setDatabaseName("train");
    m_db.setHostName("localhost");
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
