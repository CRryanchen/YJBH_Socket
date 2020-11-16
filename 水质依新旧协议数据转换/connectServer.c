#include<stdio.h>
#include<windows.h>
#include<sql.h>
#include<sqlext.h>
#include<sqltypes.h>
int main()
{
	SQLRETURN ret;
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;
 
	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv);//���뻷�����
	ret=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//�������ݿ����Ӿ��
 
	ret=SQLConnect(hdbc,(SQLCHAR*)"data_test",SQL_NTS,(SQLCHAR*)"sa",SQL_NTS,(SQLCHAR*)"12345678",SQL_NTS);
	/*data_testΪ���õ�ODBC����Դ���ƣ���������Լ������ý����޸�*/
    if(!(ret==SQL_SUCCESS || ret==SQL_SUCCESS_WITH_INFO))
	{
		printf("�������ݿ�ʧ��!\n");
		return -1;
	}
 
	ret=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);
	/*ִ��sql���*/
	SQLCHAR sql1[]="use stu_info";
	SQLCHAR sql2[]="select * from student";
	ret=SQLExecDirect(hstmt,sql1,SQL_NTS);
	ret=SQLExecDirect(hstmt,sql2,SQL_NTS);
	if(ret==SQL_SUCCESS || ret==SQL_SUCCESS_WITH_INFO)
	{
		SQLCHAR str1[50],str2[50],str3[50],str4[50],str5[50],str6[50];
		SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5, len_str6;
		while(SQLFetch(hstmt)!=SQL_NO_DATA)
		{
			SQLGetData(hstmt,1,SQL_C_CHAR,str1,50,&len_str1);   //��ȡ��һ������
			SQLGetData(hstmt,2,SQL_C_CHAR,str2,50,&len_str2); 
			SQLGetData(hstmt,3,SQL_C_CHAR,str3,50,&len_str3); 
			SQLGetData(hstmt,4,SQL_C_CHAR,str4,50,&len_str4); 
			SQLGetData(hstmt,5,SQL_C_CHAR,str5,50,&len_str5); 
			SQLGetData(hstmt,6,SQL_C_CHAR,str6,50,&len_str6); 
			printf("%s\t%s\t%s\t%s\t%s\t%s\n",str1,str2,str3,str4,str5,str6);
		}
	}
 
	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);//�ͷ����Ӿ��
	SQLFreeHandle(SQL_HANDLE_ENV,henv);//�ͷŻ������
	return 0;
