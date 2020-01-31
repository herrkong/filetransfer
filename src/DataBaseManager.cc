#include "DataBaseManager.h"

bool DataBaseManager::connect(const string & ip ,const string& username , const string&  passwd , const string& databasename )
{
    //初始化mysql
    m_mysql = mysql_init(NULL);
    
    if(!mysql_real_connect(m_mysql,ip.c_str(),username.c_str(),passwd.c_str(),databasename.c_str(),0,NULL,0))
    {
        cout << "connect mysql failed !" << endl;
        return false;
    }
    cout << "connect mysql success " << endl;
    return true;
}

bool DataBaseManager::close()
{
    mysql_close(m_mysql);
}


int main()
{

    string ip = "localhost";
    string username = "root" ;
    string passwd = "040404";
    string databasename = "darwin";

    DataBaseManager obj ;
    obj.connect(ip,username,passwd,databasename);
    return 0 ;
}





