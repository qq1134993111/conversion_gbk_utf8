// Codec.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "EncodingConversion.h"
int main()
{
	std::string str_utf8 = u8"这是utf8字符串";
	std::cout << "utf8:" << str_utf8 << "\n";
	std::wstring wstr1 = EncodingConversion::ToWString(str_utf8);
	std::wcout << "wstring from utf8:" << wstr1 << "\n";
	std::cout << "wstring[utf8] to string:" << EncodingConversion::ToString(wstr1) << "\n";

	std::string str_gbk = EncodingConversion::UTF8ToGBK(str_utf8);
	std::cout << "gbk:" << str_gbk << "\n";
	std::wstring wstr2 = EncodingConversion::ToWString(str_gbk);
	std::wcout << "wstring from gbk:" << wstr2 << "\n";
	std::cout << "wstring[gbk] to string:" << EncodingConversion::ToString(wstr2) << "\n";
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
