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
 
	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv);//申请环境句柄
	ret=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3,SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//申请数据库连接句柄
 
	ret=SQLConnect(hdbc,(SQLCHAR*)"data_test",SQL_NTS,(SQLCHAR*)"sa",SQL_NTS,(SQLCHAR*)"12345678",SQL_NTS);
	/*data_test为配置的ODBC数据源名称，这里根据自己的配置进行修改*/
    if(!(ret==SQL_SUCCESS || ret==SQL_SUCCESS_WITH_INFO))
	{
		printf("连接数据库失败!\n");
		return -1;
	}
 
	ret=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);
	/*执行sql语句*/
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
			SQLGetData(hstmt,1,SQL_C_CHAR,str1,50,&len_str1);   //获取第一列数据
			SQLGetData(hstmt,2,SQL_C_CHAR,str2,50,&len_str2); 
			SQLGetData(hstmt,3,SQL_C_CHAR,str3,50,&len_str3); 
			SQLGetData(hstmt,4,SQL_C_CHAR,str4,50,&len_str4); 
			SQLGetData(hstmt,5,SQL_C_CHAR,str5,50,&len_str5); 
			SQLGetData(hstmt,6,SQL_C_CHAR,str6,50,&len_str6); 
			printf("%s\t%s\t%s\t%s\t%s\t%s\n",str1,str2,str3,str4,str5,str6);
		}
	}
 
	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);//释放连接句柄
	SQLFreeHandle(SQL_HANDLE_ENV,henv);//释放环境句柄
	return 0;
