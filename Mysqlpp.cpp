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
		cout << "��ѡ�����¹���֮һ" << endl;
		cout << "0.�˳�" << endl;
		cout << "1.�½��˺�" << endl;
		cout << "2.��ѯ" << endl;
		cout << "3.ɾ��" << endl;
		cout << "4.�޸�" << endl;
		cin >> nchoice;
		getchar();
		switch (nchoice)
		{
		case 0: break;
		case 1: {
			cout << "������һ��Ҫ�½����˺�" << endl;
			gets_s(query);
			db.InsertDB(table, query);
		}break;
		case 2: {
			cout << "�������ѯ���(select * from y where a=z)" << endl;
			gets_s(query);
			//cout << query;
			cout << "��ʼ�������" << endl;
			db.QueryDB(query);
			cout << "�����������" << endl;
		}break;
		case 3: {
			cout << "������ɾ�����(����=ֵ)" << endl;
			gets_s(query);
			db.DeleteDB(table, query);
		}break; case 4: {
			cout << "�������ѯ���(update table set x=y,..,x#=y# where a=b)" << endl;
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
		cout << "��ѡ�����¹���֮һ" << endl;
		cout << "0.�˳�" << endl;
		cout << "1.�½��˺�" << endl;
		cout << "2.��ѯ" << endl;
		cin >> nchoice;
		switch (nchoice)
		{
		case 0: {
			db.~DB();
			return 0;
		}break;
		case 1: {
			cout << "������һ��Ҫ�½����˺�" << endl;
			cin >> query;
			db.InsertDB(query);
		}break;
		case 2: {
			cout << "�������ѯ���(select x from y where a=z)" << endl;
			cin >> query;
			cout << "��ʼ�������" << endl;
			db.QueryDB(query);
			cout << "�����������" << endl;
		}break;
		default: {
			db.~DB();
			return 0;
		}break;
		}
	}
*/