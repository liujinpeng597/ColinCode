#include "csqlite.h"

CSqlite::CSqlite()
{
    //数据库
    qDebug() << QSqlDatabase::drivers();
    //查看输出是否含有 SQLITECIPHER

    //加密数据库 装驱动
    m_db = QSqlDatabase::addDatabase("SQLITECIPHER");

    assert( m_db.driver() );
}

CSqlite::~CSqlite()
{
    DisConnect();
}

void CSqlite::DisConnect()
{
    m_db.close();
}

bool CSqlite::ConnectDataBase(QString db , QString passwd)
{
    m_db.setDatabaseName(db); //传路径
    m_db.setPassword( passwd );

    if (!m_db.open()) {
        qDebug() << "Can not open connection:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}

bool CSqlite::CreateDataBase(QString db, QString passwd)
{
    m_db.setDatabaseName(db); //传路径

    m_db.setConnectOptions("QSQLITE_CREATE_KEY");
    m_db.setPassword( passwd );
    if (!m_db.open()) {
        qDebug() << "Can not create database:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}

bool CSqlite::ConnectDataBaseNoPasswd(QString db)
{
    m_db.setDatabaseName(db); //传路径

    if (!m_db.open()) {
        qDebug() << "Can not create database:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}

bool CSqlite::ChangeDataBasePassword(QString newpasswd )
{

    QString config = QString("QSQLITE_UPDATE_KEY=%1").arg(newpasswd);

    m_db.setConnectOptions(config);

    if (!m_db.open()) {
        qDebug() << "Can not create database:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}

bool CSqlite::RemoveDataBasePassword()
{

    QString config = QString("QSQLITE_REMOVE_KEY");

    m_db.setConnectOptions(config);

    if (!m_db.open()) {
        qDebug() << "Can not create database:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}

bool CSqlite::SetPassword(QString newpasswd)
{
    m_db.setConnectOptions("QSQLITE_CREATE_KEY");
    m_db.setPassword( newpasswd );
    if (!m_db.open()) {
        qDebug() << "Can not create database:"<< m_db.lastError().driverText();
        return false;
    }
    return true;
}




//查询
bool CSqlite::SelectSql(QString sqlStr , int nColumn , QStringList & list)
{
    std::lock_guard<std::mutex> lck(m_mutex);
    bool success ;
    QSqlQuery query;
    query.prepare( sqlStr );
    success = query.exec();
    if(!success)
    {
        qDebug()<< QString("SelectData Error:") << m_db.lastError().driverText();
        return false;
    }else
    {
        for( ; query.next() ;)
        {
            for(int i= 0; i<nColumn ; i++)
            {
                list.append( query.value(i).toString() );
            }
        }
    }
    qDebug()<< QString("SelectData success") ;
    return true;
}


//更新: 删除, 插入 , 修改
bool CSqlite::UpdateSql(QString sqlStr)
{
    std::lock_guard<std::mutex> lck(m_mutex);
    bool success ;
    QSqlQuery query;
    query.prepare( sqlStr );
    success = query.exec();
    if(!success)
    {
        qDebug()<< QString("UpdateData Error:") << m_db.lastError().driverText();
        return false;
    }
    qDebug()<< QString("UpdateData success") ;
    return true;
}

bool CSqlite::UpdateSpecialSql(QString sqlStr, QStringList &list)
{
    std::lock_guard<std::mutex> lck(m_mutex);
    bool success ;
    QSqlQuery query;
    query.prepare( sqlStr );

    for( int i = 0 ; i < list.size() ; ++i){
        QVariantList tmp;
        tmp << list.at(i);
        query.addBindValue( tmp );
    }

    success = query.execBatch();
    if(!success)
    {
        qDebug()<< QString("UpdateData Error:") << m_db.lastError().driverText();
        return false;
    }

    qDebug()<< QString("UpdateData success") ;
    return true;
}



