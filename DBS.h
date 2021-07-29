#ifndef _DBS_H_
#define _DBS_H_

#pragma once

#include <mysql++.h>
#include <ssqls.h>
#include <null.h>
#include <string>
std::string SQL_injection_prevention(const std::string& resource_str);
bool StrReplase(std::string& resource_str, const std::string& str_sub, const std::string& str_new);
bool SearchInTest(mysqlpp::Connection& con);/*��ѯd_test���ڵ�������Ϣ*/
bool SearchByColumnData(mysqlpp::Connection& con, const std::string& strColumnName, const std::string& strAccount);/*������������ݿ���Ͷ�Ӧ��ֵ��ѯ�Ƿ����*/
bool InsertAccount(mysqlpp::Connection& con, const std::string& strAccount);/*����һ���µ�ֵ�����ݿ��У�ֻ��Ҫ�����˻�account��ֵ����*/
bool Update(mysqlpp::Connection& con, const std::string& strTable, const std::string& strColumnName, const std::string& strNewData, const std::string& strOldData);/*�������ݿ��е�ֵ���������ݿ��Ҫ�޸ĵľ�ֵ����ֵ*/
bool UpdateByAccount(mysqlpp::Connection& con, const std::string& strNewData, const std::string& strOldData);/*�����˻����ƣ��������˻�������˻���*/
bool Delete(mysqlpp::Connection& con, const std::string& strTable, const std::string& strColumnName, const std::string& strDelData);/*�������ݿ����Լ���Ӧ��ֵɾ�����ݿ�ֵ*/
bool DeleteByAccount(mysqlpp::Connection& con, const std::string& strDelAccount);/*ɾ���˻���Ϣ�������˻�������*/

#endif