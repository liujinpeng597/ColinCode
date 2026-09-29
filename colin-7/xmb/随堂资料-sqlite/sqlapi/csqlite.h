#ifndef CSQLITE_H
#define CSQLITE_H

#include<QStringList>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlError>
#include<QDebug>
#include<mutex>

class CSqlite
{
public:
    CSqlite();
    ~CSqlite();
    //连接数据库 需要路径和输入密码 用于已经存在的数据库
    bool ConnectDataBase(QString db , QString passwd = "");
    //创建数据库 需要路径并创建密码  用于不存在的数据库
    bool CreateDataBase( QString db , QString passwd = "" );
    //改变数据库密码
    bool ChangeDataBasePassword( QString newpasswd);
    //用于测试 登录没有密码的数据库
    bool ConnectDataBaseNoPasswd(QString db );
    //用于测试 移除数据库密码
    bool RemoveDataBasePassword();
    //用于测试 对已有数据库 登录后 设置密码
    bool SetPassword( QString newpasswd );

    //查询
    bool SelectSql(QString sqlStr , int nColumn , QStringList & list);

    //更新: 删除, 插入 , 修改
    bool UpdateSql(QString sqlStr);

    /// 用于特殊情况的插入
    /// eg: 插入的字段中包含 ' 等特殊字符
    /// 比如 QString("insert into t_musicList values ('%1');").arg("I'm student");
    /// 使用方法:
    /// QStirngList lst; lst << "I'm student";
    /// UpdateSpecialSql("insert into t_musicList valus(?)" ,lst );
    /// 注意 是?  而不是'?'
    bool UpdateSpecialSql(QString sqlStr  , QStringList & list );

private:
    //关闭数据库
    inline void DisConnect();

    QSqlDatabase m_db;
    std::mutex m_mutex;

};

#endif // CSQLITE_H
