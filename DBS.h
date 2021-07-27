#ifndef _DBS_H_
#define _DBS_H_

#pragma once

#include <mysql++.h>
#include <ssqls.h>
#include <null.h>
using namespace std;
void SearchInTest(mysqlpp::Connection& con);/*��ѯd_test���ڵ�������Ϣ*/
bool SearchByColumnData(mysqlpp::Connection& con, const string& strColumnName, const string& strAccount);/*������������ݿ���Ͷ�Ӧ��ֵ��ѯ�Ƿ����*/
void InsertAccount(mysqlpp::Connection& con, const string& strAccount);/*����һ���µ�ֵ�����ݿ��У�ֻ��Ҫ�����˻�account��ֵ����*/
void Update(mysqlpp::Connection& con, const string& strTable, const string& strColumnName, const string& strNewData, const string& strOldData);/*�������ݿ��е�ֵ���������ݿ��Ҫ�޸ĵľ�ֵ����ֵ*/
void UpdateByAccount(mysqlpp::Connection& con, const string& strNewData, const string& strOldData);/*�����˻����ƣ��������˻�������˻���*/
void Delete(mysqlpp::Connection& con, const string& strTable, const string& strColumnName, const string& strDelData);/*�������ݿ����Լ���Ӧ��ֵɾ�����ݿ�ֵ*/
void DeleteByAccount(mysqlpp::Connection& con, const string& strDelAccount);/*ɾ���˻���Ϣ�������˻�������*/

#endif