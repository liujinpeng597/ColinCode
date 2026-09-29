#ifndef CSQLITEACCESS_H
#define CSQLITEACCESS_H

#include"csqlite.h"

class CSqliteAccess
{
public:
    CSqliteAccess( QString path , QString passwd);
    //供测试使用
    CSqliteAccess( QString path );
    //供测试使用
    bool setPasswd( QString passwd );

    bool changePasswd( QString passwd );

    bool removePasswd();

    /// 以下内容 不同项目 使用的函数不同, 根据情况修改
    /// 写一些例子
    /// eg: 写一个音乐播放器 数据库
    /// 创建数据库
    /// 数据库 t_musicList( music , musicPath )
    bool createDataBase();

    bool insertMusic( QString music , QString path );

    bool deleteMusic( QString path );

    bool selectMusicList( QStringList& musicList , QStringList & musicPathList);

private:
    CSqlite m_sql;

};

#endif // CSQLITEACCESS_H
