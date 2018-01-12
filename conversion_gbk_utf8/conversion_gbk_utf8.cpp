// conversion_gbk_utf8.cpp: 定义控制台应用程序的入口点。
//

#include<string>
using namespace std;


#include"conversion.h"

int main()
{
	string str = "你好,我是utf8编码";
	string str_gbk = utf8_to_gbk(str);
	string str_utf8 = gbk_to_utf8(str_gbk);

	printf("Raw:%s[%d]\ngbk:%s[%d]\nutf8:%s[%d]\n", str.c_str(), str.size(), str_gbk.c_str(), str_gbk.size(), str_utf8.c_str(), str_utf8.size());
	return 0;
}