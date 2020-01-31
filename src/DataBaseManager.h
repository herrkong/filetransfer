#pragma once
#include <mysql/mysql.h>
#include <iostream>

//数据库管理类
//封装mysql的c api 

using namespace std;

class DataBaseManager
{
public:
    DataBaseManager() 
    {
        cout << "DataBaseManager()" <<endl;
    }
    ~DataBaseManager() 
    {
        close();
        cout << "~DataBaseManager()" <<endl;
    }


public:
   //连接数据库
   bool connect(const string & ip ,const string& username , const string&  passwd , const string& databasename );
   //关闭数据库连接
   bool close();


private:
    std::string m_ip;
    std::string m_username;
    std::string m_passwd;
    std::string m_databasename;

private:
    MYSQL * m_mysql ;
    MYSQL_RES * m_mysql_res;
    MYSQL_ROW m_mysql_row;

};

