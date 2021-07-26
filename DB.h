#pragma once
#ifndef _DB_H_
#define _DB_H_
#include <mysql++.h>
#include <ssqls.h>
#include <string>
class DB {
	mysqlpp::Connection conn;
	std::string db, user, password, server;
	int port;
public:
	DB( std::string db, std::string user, std::string password);
	bool ConnectDB();
	bool InsertDB(std::string& table, char _account[]);
	bool DeleteDB(std::string& table, char _account[]);
	bool QueryDB(char _query[]);
	bool UpdateDB(char _query[]);
};
DB::DB(std::string _db, std::string _user, std::string _password) {
	server = "localhost";
	port = 3306;
	db = _db;
	user = _user;
	password = _password;
}
bool DB::ConnectDB(){
	conn = mysqlpp::Connection(true);
	conn.set_option(new mysqlpp::SetCharsetNameOption("gbk"));
	bool ret=conn.connect(db.c_str(), server.c_str(),user.c_str(),password.c_str(), port);
	if (!ret) {
		std::cout << "connect DB false" << std::endl;
		return false;
	}
	else {
		std::cout << "connect DB successful" << std::endl;
		return true;
	}
}
bool DB::QueryDB(char _query[]) {
	mysqlpp::Query query = conn.query(_query);
	mysqlpp::StoreQueryResult res = query.store();
	std::cout << res.num_rows() << std::endl;
	for (auto Tem : res) {
		std::cout << "id:" << Tem[0] << std::endl;
		std::cout << "account:" << Tem[1]<<std::endl;
		std::cout << "create_time:" << Tem[2] << std::endl;
	}
	return true;
}
bool DB::InsertDB(std::string& table, char _account[]) {
	std::string _query = "Insert into " + table + "(account) values ('" + _account+"')";
	mysqlpp::Query query=conn.query();
	bool ret=query.exec(_query);
	if (ret) {
		std::cout << "Insert DB successful" << std::endl;
		return true;
	}
	else {
		std::cout << "Insert DB false" << std::endl;
		return false;
	}
}
bool DB::DeleteDB(std::string& table, char _account[]) {
	std::string _query = "Delete from " + table + " where " + _account ;
	mysqlpp::Query query = conn.query();
	bool ret = query.exec(_query);
	if (ret) {
		std::cout << "Delete DB successful" << std::endl;
		return true;
	}
	else {
		std::cout << "Delete DB false" << std::endl;
		return false;
	}
}
bool DB::UpdateDB(char _query[]) {
	mysqlpp::Query query = conn.query();
	bool ret = query.exec(_query);
	if (ret) {
		std::cout << "Update DB successful" << std::endl;
		return true;
	}
	else {
		std::cout << "Update DB false" << std::endl;
		return false;
	}
}
#endif //!_DB_H_