#include <mysql++.h>
#include <iostream>
#include "DB.h"
using namespace std;
int main() {
	string table("d_test");
	DB db("test", "root", "root");
	db.ConnectDB();
	char query[100]="";
	int nchoice = 1;
	while (nchoice) {
		cout << "请选择以下功能之一" << endl;
		cout << "0.退出" << endl;
		cout << "1.新建账号" << endl;
		cout << "2.查询" << endl;
		cout << "3.删除" << endl;
		cout << "4.修改" << endl;
		cin >> nchoice;
		getchar();
		switch (nchoice)
		{
		case 0: break;
		case 1: {
			cout << "请输入一个要新建的账号" << endl;
			gets_s(query);
			db.InsertDB(table, query);
		}break;
		case 2: {
			cout << "请输入查询语句(select * from y where a=z)" << endl;
			gets_s(query);
			//cout << query;
			cout << "开始输出数据" << endl;
			db.QueryDB(query);
			cout << "数据输出结束" << endl;
		}break;
		case 3: {
			cout << "请输入删除语句(属性=值)" << endl;
			gets_s(query);
			db.DeleteDB(table, query);
		}break; case 4: {
			cout << "请输入查询语句(update table set x=y,..,x#=y# where a=b)" << endl;
			gets_s(query);
			db.UpdateDB(query);
		}break;
		default: nchoice = 0; break;
		}
	}
}
/*
	mysqlpp::Connection conn(true);
	conn.set_option(new mysqlpp::SetCharsetNameOption("gbk"));
	conn.connect("test", "localhost", "root", "root", 3306);
	char sInput[100];
	cin.getline(sInput,100);
	mysqlpp::Query query = conn.query(sInput);
	mysqlpp::StoreQueryResult res = query.store();
	cout << res.num_rows() << endl;
	cout << "id\taccount\tcreate_time" << endl;
	for (auto i : res) {
		cout << i[0] << "\t" << i[1] << "\t" << i[2] << endl;
	}
*/
/*
mysqlpp::Connection conn(true);
	conn.set_option(new mysqlpp::SetCharsetNameOption("gbk"));
	conn.connect("test", "localhost", "root", "root", 3306);
	mysqlpp::Query query = conn.query();
	query.exec("insert into d_test(account) values ('lzc')");
*/
/*
DB db("test","root","root");
	db.ConnectDB();
	string query;
	int nchoice=1;
	while (nchoice) {
		cout << "请选择以下功能之一" << endl;
		cout << "0.退出" << endl;
		cout << "1.新建账号" << endl;
		cout << "2.查询" << endl;
		cin >> nchoice;
		switch (nchoice)
		{
		case 0: {
			db.~DB();
			return 0;
		}break;
		case 1: {
			cout << "请输入一个要新建的账号" << endl;
			cin >> query;
			db.InsertDB(query);
		}break;
		case 2: {
			cout << "请输入查询语句(select x from y where a=z)" << endl;
			cin >> query;
			cout << "开始输出数据" << endl;
			db.QueryDB(query);
			cout << "数据输出结束" << endl;
		}break;
		default: {
			db.~DB();
			return 0;
		}break;
		}
	}
*/