#include "DBS.h"
#include <iostream>
#include <string>
using namespace mysqlpp;

int main() {
	
	mysqlpp::Connection con(false);//������mysql���Ӷ���
	con.set_option(new SetCharsetNameOption("gbk"));//�����ַ�����Ϊuft8
	if (!con.connect("test", "localhost", "root", "root", 3306)) {
		cout << "���ݿ�����ʧ��" << endl;
		return 0;
	}
	int nchoice = 1;
	string strAccount, strDelAccount, strNewAccount;
	while (nchoice){
		system("cls");
		cout << "��ѡ������Ҫ�Ĺ���" << endl;
		cout << "0.�˳�" << endl;
		cout << "1.�½��˻�" << endl;
		cout << "2.��ѯ����" << endl;
		cout << "3.ɾ���û�" << endl;
		cout << "4.�޸��˻�" << endl;
		cout << "5.�����˻�" << endl;
		cin >> nchoice;
		switch (nchoice){
		case 0:
			return  0; break;
		case 1: {
			cout << "������Ҫ�½����˺���" << endl;
			cin >> strAccount;
			InsertAccount(con, strAccount);
		}break;
		case 2: {
			SearchInTest(con);
		}break;
		case 3: {
			cout << "������Ҫɾ�����˺���" << endl;
			cin >> strDelAccount;
			DeleteByAccount(con, strDelAccount);
		}break;
		case 4: {
			cout << "������Ҫ�޸ĵ��˺���" << endl;
			cin >> strAccount;
			cout << "�������޸ĺ���˺���" << endl;
			cin >> strNewAccount;
			UpdateByAccount(con, strNewAccount, strAccount);
		}break; 
		case 5: {
			cout << "������Ҫ���ҵ��˺���" << endl;
			cin >> strAccount;
			if (!SearchByColumnData(con, "account", strAccount)) {
				cout << "���޴���" << endl;
			}
		}break;
		default: {
			cout << "����ѡ��ʧ�ܣ�������ѡ��" << endl;
		}break;
		}

		system("pause");
	}
	return 0;
}

/*
mysqlpp::SetCharsetNameOption opt = new mysqlpp::SetCharsetNameOption("utf8");
on.set_option(opt);
//����SetCharsetNameOption�Ѷ���con�����Զ��ͷ�opt��������delete opt;
*/
/*
mysqlpp::Connection::Connection(const char* db, const char* server = 0, const char* user = 0, const char* password = 0; unsigned in port = 0)
���������ݿ����ơ����ݿ�����������ַ���û��������롢
*/

/*Query Connection::query(const string & qstr);*/
//Query query = con.query("select * from d_test;");
//StoreQueryResult  res = query.store(); //query.store()����ִ�в�ѯ�����ҽ���ѯ������浽res����
//if (!res){
//	cout << "���޼�¼�����������query����ǲ���д���ˣ�" << endl;
//	return -1;
//}
//cout << "һ������" << res.num_rows() << "������" << endl;//���ز�ѯ�����¼����
/*

Mysql++�ǹٷ������ġ�һ��ΪMySQL��Ƶ�C++���Ե�API��Mysql++ΪMysql��C-Api���ٴη�װ��
����STL(Standard Template Language)��������д����ΪC++�������ṩ�����STL����һ������Ĳ������ݿ��һ�׻��ơ�
��ٷ�API���ܣ�MySQL++ Reference Manual��JDBCһ�����Ƚ�������Connection������Query��ִ�в�����ý����
SimpleResult Query::store()���и��¡�ɾ���������Ȳ�����SimpleResult����ִ��״̬����ѯ�Ƿ�ɹ���Ӱ���˶����С�
StoreQueryResult Query::store():��á�StoreQueryResult�̳�vector<:row>��Row������vector����ʾһ���и��е����ݡ�ʹ�ÿ���result[1][4]��result[2]["price"]��
UseQueryResult Query::use()��������ѯ��UserQueryResult��iterator��һ��ֻ�ܻ��һ���н������ͣ��nextֱ������Ϊֹ��

MySql++֧�����ֲ�ѯ�� Query::execute(), Query::store(), Query::use()

1��execute( )�ӿ�
���ڲ��������ݵĲ�ѯ���ú�������һ��SimpleResult����

2��exec( )�ӿ�
������һ��boolֵ����ʾִ�гɹ�������ֻҪ�ɹ����ı�ʶ������ʹ�øýӿڡ�

3��store() �ӿ�
�����÷�������ȡ���ݣ��ú�������һ��StoreQueryResult���󡣶��������������ѯ�����ʹ��stl::map��ʽ������ȡ���ݼ��ɡ�

4��use()�ӿ�
ͬ�����ڴӷ�������ȡ���ݣ������ú�������UseQueryResult�������store()���Ը���ʡ�ڴ棬�ö�������StoreQueryResult,���ǲ��ṩ������ʵ����ԡ�use��ѯ���÷�����һ�η��ؽ������һ�С�
Query�����errnum()�����ϴ�ִ�ж�Ӧ�Ĵ�����룬error()���ش�����Ϣ��affected_rows()������Ӱ���������

*/