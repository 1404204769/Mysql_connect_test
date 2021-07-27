#include "DBS.h"
using namespace mysqlpp;
sql_create_3(d_test, 1, 3,
	mysqlpp::sql_bigint, id,
	mysqlpp::sql_varchar, account,
	mysqlpp::sql_timestamp, create_time
);
void SearchInTest(Connection& con) {
	string strSQL = "select * from d_test;";
	//cout << "SQL语句为：" << strSQL << endl;
	Query query = con.query(strSQL);
	vector<d_test>vecarr;
	query.storein(vecarr);
	for (auto it : vecarr) {
		//printf("ID:%10s\tAccount:\tCreate_time:\n", it.id, it.account, it.create_time);
		cout<<left << "ID:" << it.id << "\t\tAccount:" << it.account << "\t\t\tCreate_time:" << it.create_time << endl;
	}
	cout << "一共输出" << vecarr.size() << "条数据" << endl;
}
bool SearchByColumnData(Connection& con, const string& strColumnName, const string& strAccount) {
	string strSQL = "select * from d_test where "+strColumnName+"='"+strAccount+"';";
	//cout << "SQL语句为：" << strSQL << endl;
	Query query = con.query(strSQL);
	vector<d_test>vecarr;
	query.storein(vecarr);
	if (vecarr.size() == 0) {
		return false;
	}
	for (auto it : vecarr) {
		cout << "ID:" <<it.id << "\t\tAccount:" << it.account << "\t\t\tCreate_time:" << it.create_time << endl;
	}
	return true;
}
void InsertAccount(Connection& con, const string& strAccount) {
	d_test row(0, strAccount, NOW());
	Query query = con.query();
	query.insert(row);
	bool bRet= query.exec();
	if (!bRet) {
		cout << "插入失败" << endl;
		return;
	}
	cout << "插入成功" << endl;
	return;
}
void Update(Connection& con, const string& strTable, const string& strColumnName, const string& strNewData, const string& strOldData) {
	if (!SearchByColumnData(con, strColumnName,strOldData)) {
		cout << "该数据库中没有此数据" << endl;
		return;
	}
	string  strSQL = "update " + strTable + " set " + strColumnName + "='" + strNewData + "' where " + strColumnName + "='" + strOldData + "';";
	//cout << "SQL语句为：" << strSQL << endl;
	Query query = con.query(strSQL);
	query.exec();
	cout << "更新成功" << endl;
	SearchByColumnData(con, strColumnName, strNewData);
	return;
}
void UpdateByAccount(Connection& con, const string& strNewData, const string& strOldData) {
	Update(con, "d_test", "account", strNewData, strOldData);
	return;
}

//void fnUpdateByAccount2(Connection& con, const string& strNewAccount, const string& strOldAccount) {
//	string strSQL = "select * from d_test where  account= '" + strOldAccount + "';";
//	cout << "SQL语句为：" << strSQL << endl;
//	mysqlpp::Query query = con.query(strSQL);
//	mysqlpp::StoreQueryResult res = query.store();
//	if (!res) {
//		cout << "未找到此账户，更新失败" << endl;
//		return;
//	}
//	d_test row = res[0];
//	d_test orig_row = res[0];
//	row.account = strNewAccount;
//	bool bRet = query.update(orig_row, row).exec();
//	if (!bRet) {
//		cout << "更新失败" << endl;
//		return;
//	}
//	cout << "更新成功" << endl;
//	return;
//}
void Delete(Connection& con, const string& strTable, const string& strColumnName, const string& strDelData) {
	if (!SearchByColumnData(con, strColumnName, strDelData)) {
		cout << "该数据库中没有此数据" << endl;
		return;
	}
	string strSQL = "delete from " + strTable + " where " + strColumnName + "= '" + strDelData + "';";
	//cout << "SQL语句为：" << strSQL << endl;
	Query query = con.query(strSQL);
	bool bRet = query.exec();
	if (!bRet) {
		cout << "删除失败" << endl;
		return;
	}
	cout << "删除成功" << endl;
	return;
}
void DeleteByAccount(Connection& con, const string& strDelAccount) {
	Delete(con, "d_test", "Account", strDelAccount);
	return;
}