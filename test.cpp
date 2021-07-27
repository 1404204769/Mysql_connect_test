#include "DBS.h"
#include <iostream>
#include <string>
using namespace mysqlpp;

int main() {
	
	mysqlpp::Connection con(false);//定义了mysql连接对象；
	con.set_option(new SetCharsetNameOption("gbk"));//设置字符编码为uft8
	if (!con.connect("test", "localhost", "root", "root", 3306)) {
		cout << "数据库链接失败" << endl;
		return 0;
	}
	int nchoice = 1;
	string strAccount, strDelAccount, strNewAccount;
	while (nchoice){
		system("cls");
		cout << "请选择你想要的功能" << endl;
		cout << "0.退出" << endl;
		cout << "1.新建账户" << endl;
		cout << "2.查询所有" << endl;
		cout << "3.删除用户" << endl;
		cout << "4.修改账户" << endl;
		cout << "5.查找账户" << endl;
		cin >> nchoice;
		switch (nchoice){
		case 0:
			return  0; break;
		case 1: {
			cout << "请输入要新建的账号名" << endl;
			cin >> strAccount;
			InsertAccount(con, strAccount);
		}break;
		case 2: {
			SearchInTest(con);
		}break;
		case 3: {
			cout << "请输入要删除的账号名" << endl;
			cin >> strDelAccount;
			DeleteByAccount(con, strDelAccount);
		}break;
		case 4: {
			cout << "请输入要修改的账号名" << endl;
			cin >> strAccount;
			cout << "请输入修改后的账号名" << endl;
			cin >> strNewAccount;
			UpdateByAccount(con, strNewAccount, strAccount);
		}break; 
		case 5: {
			cout << "请输入要查找的账号名" << endl;
			cin >> strAccount;
			if (!SearchByColumnData(con, "account", strAccount)) {
				cout << "查无此人" << endl;
			}
		}break;
		default: {
			cout << "功能选择失败，请重新选择" << endl;
		}break;
		}

		system("pause");
	}
	return 0;
}

/*
mysqlpp::SetCharsetNameOption opt = new mysqlpp::SetCharsetNameOption("utf8");
on.set_option(opt);
//创建SetCharsetNameOption堆对象，con结束自动释放opt，不允许delete opt;
*/
/*
mysqlpp::Connection::Connection(const char* db, const char* server = 0, const char* user = 0, const char* password = 0; unsigned in port = 0)
参数：数据库名称、数据库所在主机地址、用户名、密码、
*/

/*Query Connection::query(const string & qstr);*/
//Query query = con.query("select * from d_test;");
//StoreQueryResult  res = query.store(); //query.store()函数执行查询，并且将查询结果保存到res对象
//if (!res){
//	cout << "查无记录？请检查程序中query语句是不是写错了！" << endl;
//	return -1;
//}
//cout << "一共返回" << res.num_rows() << "行数据" << endl;//返回查询结果记录行数
/*

Mysql++是官方发布的、一个为MySQL设计的C++语言的API。Mysql++为Mysql的C-Api的再次封装，
它用STL(Standard Template Language)开发并编写，并为C++开发者提供像操作STL容器一样方便的操作数据库的一套机制。
其官方API介绍：MySQL++ Reference Manual与JDBC一样，先建立连接Connection，创建Query，执行操作获得结果。
SimpleResult Query::store()进行更新、删除、创建等操作，SimpleResult代表执行状态，查询是否成功、影响了多少行。
StoreQueryResult Query::store():最常用。StoreQueryResult继承vector<:row>，Row类似于vector，表示一行中各列的数据。使用可以result[1][4]或result[2]["price"]。
UseQueryResult Query::use()，大结果查询，UserQueryResult是iterator，一次只能获得一个行结果，不停地next直到结束为止。

MySql++支持三种查询： Query::execute(), Query::store(), Query::use()

1）execute( )接口
用于不返回数据的查询，该函数返回一个SimpleResult对象。

2）exec( )接口
它返回一个bool值，标示执行成功与否；如果只要成功与否的标识，可以使用该接口。

3）store() 接口
用于用服务器获取数据，该函数返回一个StoreQueryResult对象。对象包含了整个查询结果，使用stl::map方式从里面取数据即可。

4）use()接口
同样用于从服务器获取数据，不过该函数返回UseQueryResult对象。相比store()而言更节省内存，该对象类似StoreQueryResult,但是不提供随机访问的特性。use查询会让服务器一次返回结果集的一行。
Query对象的errnum()返回上次执行对应的错误代码，error()返回错误信息，affected_rows()返回受影响的行数。

*/