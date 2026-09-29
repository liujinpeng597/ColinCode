#include "csqliteaccess.h"

#include<QFileInfo>

CSqliteAccess::CSqliteAccess/* 初始化列表完成m_sql构造*/
(QString path, QString passwd)
{
    ///根据路径查看是否有该文件
    ///有文件那么连接数据库
    ///否则创建数据库

    QFileInfo info(path);
    if( info.exists() ){
        m_sql.ConnectDataBase( path , passwd);
    }else{
        m_sql.CreateDataBase( path , passwd );
    }

}

CSqliteAccess::CSqliteAccess(QString path)
{
    m_sql.ConnectDataBaseNoPasswd( path );
}

bool CSqliteAccess::setPasswd(QString passwd)
{
    return m_sql.SetPassword( passwd );
}


bool CSqliteAccess::changePasswd(QString passwd)
{
    return m_sql.ChangeDataBasePassword(  passwd );
}

bool CSqliteAccess::removePasswd()
{
    return m_sql.RemoveDataBasePassword( );
}

/// 以下内容 不同项目 使用的函数不同, 根据情况修改
bool CSqliteAccess::createDataBase( )
{
    QString sql = "create table if not exists t_musicList (music varchar(260) ,musicPath varchar(260) );";
    return m_sql.UpdateSql( sql );
}

bool CSqliteAccess::insertMusic(QString music, QString path)
{
    QStringList lst;
    lst << music << path;
    m_sql.UpdateSpecialSql( "insert into t_musicList values(?,?);" , lst );

}

bool CSqliteAccess::deleteMusic( QString path)
{
    QStringList lst;
    lst  << path;
    return m_sql.UpdateSpecialSql( "delete from t_musicList where musicPath like ?;" , lst );
}

bool CSqliteAccess::selectMusicList(QStringList &musicList, QStringList &musicPathList)
{
    QStringList res;
    bool flag = m_sql.SelectSql( "select * from t_musicList;", 2, res );

    while( res.size() >= 2 ){
        musicList << res.front();
        res.pop_front();
        musicPathList << res.front();
        res.pop_front();
    }
    return flag;
}


