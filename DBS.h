#ifndef _DBS_H_
#define _DBS_H_

#pragma once

#include <mysql++.h>
#include <ssqls.h>
#include <null.h>
using namespace std;
void SearchInTest(mysqlpp::Connection& con);/*查询d_test表内的所有信息*/
bool SearchByColumnData(mysqlpp::Connection& con, const string& strColumnName, const string& strAccount);/*根据输入的数据库项和对应的值查询是否存在*/
void InsertAccount(mysqlpp::Connection& con, const string& strAccount);/*插入一条新的值到数据库中，只需要输入账户account的值即可*/
void Update(mysqlpp::Connection& con, const string& strTable, const string& strColumnName, const string& strNewData, const string& strOldData);/*更新数据库中的值，输入数据库项，要修改的旧值与新值*/
void UpdateByAccount(mysqlpp::Connection& con, const string& strNewData, const string& strOldData);/*更改账户名称，输入新账户名与旧账户名*/
void Delete(mysqlpp::Connection& con, const string& strTable, const string& strColumnName, const string& strDelData);/*更具数据库项以及对应的值删除数据库值*/
void DeleteByAccount(mysqlpp::Connection& con, const string& strDelAccount);/*删除账户信息，输入账户名即可*/

#endif