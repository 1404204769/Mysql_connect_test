#include "DBS.h"
using namespace std;
using namespace mysqlpp;
sql_create_3(d_test, 1, 3,
	mysqlpp::sql_bigint, id,
	mysqlpp::sql_varchar, account,
	mysqlpp::sql_timestamp, create_time
);
bool StrReplase(string& resource_str, const string& str_sub, const string& str_new)
{
	string::size_type pos = 0;
	string::size_type a = str_sub.size();
	string::size_type b = str_new.size();
	while ((pos = resource_str.find(str_sub, pos)) != string::npos)
	{
		resource_str.replace(pos, a, str_new);
		pos += b;
	}
	return true;
}
string SQL_inject(const string& resource_str) {
	//cout << "�滻ǰ" << resource_str << endl;
	string _resource_str(resource_str);
	StrReplase(_resource_str, "'", "\\'");
	StrReplase(_resource_str, "\"", "\\\"");
	//cout << "�滻��" << resource_str << endl;
	return _resource_str;
}
bool SearchInTest(Connection& con) {
	const string strSQL = "select * from d_test;";
	//cout << "SQL���Ϊ��" << strSQL << endl;
	Query query = con.query(strSQL);
	if (!query)return false;
	vector<d_test>vecarr;
	query.storein(vecarr);
	for (auto it : vecarr) {
		//printf("ID:%10s\tAccount:\tCreate_time:\n", it.id, it.account, it.create_time);
		cout << left << "ID:" << it.id << "\t\tAccount:" << it.account << "\t\t\tCreate_time:" << it.create_time << endl;
	}
	cout << "һ�����" << vecarr.size() << "������" << endl;
	return true;
}
bool SearchByColumnData(Connection& con, const string& strColumnName, const string& strAccount) {
	const string strSQL = "select * from d_test where " + SQL_inject(strColumnName) + "='" + SQL_inject(strAccount) + "';";
	cout << "SQL���Ϊ��" << strSQL << endl;
	Query query = con.query(strSQL);
	if (!query)return false;
	vector<d_test>vecarr;
	query.storein(vecarr);
	if (vecarr.size() == 0) return false;
	for (auto it : vecarr) {
		cout << "ID:" << it.id << "\t\tAccount:" << it.account << "\t\t\tCreate_time:" << it.create_time << endl;
	}
	return true;
}
bool InsertAccount(Connection& con, const string& strAccount) {
	d_test row(0, SQL_inject(strAccount), NOW());
	Query query = con.query();
	if (!query)return false;
	query.insert(row);
	if (!query.exec()) {
		cout << "����ʧ��" << endl;
		return false;
	}
	cout << "����ɹ�" << endl;
	return true;
}
bool Update(Connection& con, const string& strTable, const string& strColumnName, const string& strNewData, const string& strOldData) {
	if (!SearchByColumnData(con, strColumnName, strOldData)) {
		cout << "�����ݿ���û�д�����" << endl;
		return false;
	}
	const string  strSQL = "update " + strTable + " set " + strColumnName + "='" + strNewData + "' where " + strColumnName + "='" + strOldData + "';";
	//cout << "SQL���Ϊ��" << strSQL << endl;
	Query query = con.query(strSQL);
	if (!query)return false;
	if (!query.exec()) {
		cout << "����ʧ��" << endl;
		return false;
	}
	cout << "���³ɹ�" << endl;
	if (!SearchByColumnData(con, strColumnName, strNewData)) {
		cout << "�������󣬸����ݿ���û�в鵽���º������" << endl;
		return false;
	}
	return true;
}
bool UpdateByAccount(Connection& con, const string& strNewData, const string& strOldData) {
	return Update(con, "d_test", "account", SQL_inject(strNewData), SQL_inject(strOldData));
}

//void fnUpdateByAccount2(Connection& con, const string& strNewAccount, const string& strOldAccount) {
//	string strSQL = "select * from d_test where  account= '" + strOldAccount + "';";
//	cout << "SQL���Ϊ��" << strSQL << endl;
//	mysqlpp::Query query = con.query(strSQL);
//	mysqlpp::StoreQueryResult res = query.store();
//	if (!res) {
//		cout << "δ�ҵ����˻�������ʧ��" << endl;
//		return;
//	}
//	d_test row = res[0];
//	d_test orig_row = res[0];
//	row.account = strNewAccount;
//	bool bRet = query.update(orig_row, row).exec();
//	if (!bRet) {
//		cout << "����ʧ��" << endl;
//		return;
//	}
//	cout << "���³ɹ�" << endl;
//	return;
//}
bool Delete(Connection& con, const string& strTable, const string& strColumnName, const string& strDelData) {
	if (!SearchByColumnData(con, strColumnName, strDelData)) {
		cout << "�����ݿ���û�д�����" << endl;
		return false;
	}
	const string strSQL = "delete from " + strTable + " where " + strColumnName + "= '" + strDelData + "';";
	cout << "SQL���Ϊ��" << strSQL << endl;
	Query query = con.query(strSQL);
	if (!query)return false;
	if (!query.exec()) {
		cout << "ɾ��ʧ��" << endl;
		return false;
	}
	cout << "ɾ���ɹ�" << endl;
	return true;
}
bool DeleteByAccount(Connection& con, const string& strDelAccount) {
	return Delete(con, "d_test", "Account", SQL_inject(strDelAccount));
}