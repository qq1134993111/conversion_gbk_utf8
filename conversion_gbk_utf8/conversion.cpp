
#include "conversion.h"

#include<locale>
#include <codecvt>
#include <string>
using namespace std;

// 包装 wstring/wbuffer_convert 所用的绑定本地环境平面的工具
template<class Facet>
struct deletable_facet : Facet
{
	template<class ...Args>
	deletable_facet(Args&& ...args)
		: Facet(std::forward<Args>(args)...) {}
	~deletable_facet() {}
};

inline wstring gbk_to_utf16(const string &gbk)
{
#ifdef _MSC_VER
	const char* GBK_LOCALE_NAME = ".936";
#else
	const char* GBK_LOCALE_NAME = "zh_CN.GBK";
#endif

	typedef deletable_facet<std::codecvt_byname<wchar_t, char, std::mbstate_t>> gbfacet_t;

	std::wstring_convert<gbfacet_t> conv(new gbfacet_t(GBK_LOCALE_NAME));
	wstring utf16 = conv.from_bytes(gbk);
	return std::move(utf16);
}

inline string utf16_to_gbk(const wstring &utf16)
{
#ifdef _MSC_VER
	const char* GBK_LOCALE_NAME = ".936";
#else
	const char* GBK_LOCALE_NAME = "zh_CN.GBK";
#endif

	typedef deletable_facet<std::codecvt_byname<wchar_t, char, std::mbstate_t>> gbfacet_t;
	std::wstring_convert<gbfacet_t> conv(new gbfacet_t(GBK_LOCALE_NAME));

	string gbk = conv.to_bytes(utf16);
	return std::move(gbk);
}

inline wstring utf8_to_utf16(const string &utf8)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	wstring utf16 = conv.from_bytes(utf8);
	return std::move(utf16);
}

inline string utf16_to_utf8(const wstring &utf16)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	string utf8 = conv.to_bytes(utf16);
	return std::move(utf8);
}


string utf8_to_gbk(const string &utf8)
{
	return utf16_to_gbk(utf8_to_utf16(utf8));
}

string gbk_to_utf8(const string &gbk)
{
	return utf16_to_utf8(gbk_to_utf16(gbk));
}






