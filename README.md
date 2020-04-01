# conversion_gbk_utf8
收集C++11 gbk和utf8编码的相互转换


static std::string    ToString(const std::wstring& wstr);

static std::wstring   ToWString(const std::string& str);

static std::string    ToGBK(const std::wstring& wstr);

static std::wstring   FromGBK(const std::string& str);

static std::string    ToUTF8(const std::wstring& wstr);

static std::wstring   FromUTF8(const std::string& str);

static std::string    GBKToUTF8(const std::string& str);

static std::string    UTF8ToGBK(const std::string& str);

static std::u16string UTF8toUTF16(const std::string& str);

static std::u32string UTF8toUTF32(const std::string& str);

static std::string    UTF16toUTF8(const std::u16string& str);

static std::u32string UTF16toUTF32(const std::u16string& str);

static std::string    UTF32toUTF8(const std::u32string& str);

static std::u16string UTF32toUTF16(const std::u32string& str);
