#ifndef _DBS_H_
#define _DBS_H_

#pragma once

#include <mysql++.h>
#include <ssqls.h>
#include <null.h>
#include <string>
std::string SQL_injection_prevention(const std::string& resource_str);
bool StrReplase(std::string& resource_str, const std::string& str_sub, const std::string& str_new);
bool SearchInTest(mysqlpp::Connection& con);/*查询d_test表内的所有信息*/
bool SearchByColumnData(mysqlpp::Connection& con, const std::string& strColumnName, const std::string& strAccount);/*根据输入的数据库项和对应的值查询是否存在*/
bool InsertAccount(mysqlpp::Connection& con, const std::string& strAccount);/*插入一条新的值到数据库中，只需要输入账户account的值即可*/
bool Update(mysqlpp::Connection& con, const std::string& strTable, const std::string& strColumnName, const std::string& strNewData, const std::string& strOldData);/*更新数据库中的值，输入数据库项，要修改的旧值与新值*/
bool UpdateByAccount(mysqlpp::Connection& con, const std::string& strNewData, const std::string& strOldData);/*更改账户名称，输入新账户名与旧账户名*/
bool Delete(mysqlpp::Connection& con, const std::string& strTable, const std::string& strColumnName, const std::string& strDelData);/*更具数据库项以及对应的值删除数据库值*/
bool DeleteByAccount(mysqlpp::Connection& con, const std::string& strDelAccount);/*删除账户信息，输入账户名即可*/

#endif