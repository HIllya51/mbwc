#include"mbwc.h"
#include<string>
#include<iostream>

#if 0
#include<optional>
inline std::optional<std::wstring> StringToWideString(const std::string& text, UINT encoding)
{
    std::vector<wchar_t> buffer(text.size() + 1);
     
    if (int length = MultiByteToWideChar(encoding, 0, text.c_str(), text.size() + 1, buffer.data(), buffer.size()))
        return std::wstring(buffer.data(), length - 1);
    return {};  
}

inline std::optional<std::string> WideStringToString(const std::wstring& text, UINT encoding)
{
    std::vector<char> buffer((text.size() + 1) * 4);
    if(int length=WideCharToMultiByte(encoding, 0, text.c_str(), -1, buffer.data(), buffer.size(), nullptr, nullptr))
        return buffer.data();
    return {};
}
#else
#include<optional>
inline std::wstring StringToWideString(const std::string& text, UINT encoding)
{
    std::vector<wchar_t> buffer(text.size() + 1);
     
    if (int length = MultiByteToWideChar(encoding, 0, text.c_str(), text.size() + 1, buffer.data(), buffer.size()))
        return std::wstring(buffer.data(), length - 1);
    return {};  
}

inline std::string WideStringToString(const std::wstring& text, UINT encoding)
{
    std::vector<char> buffer((text.size() + 1) * 4);
    if(int length=WideCharToMultiByte(encoding, 0, text.c_str(), -1, buffer.data(), buffer.size(), nullptr, nullptr))
        return buffer.data();
    return {};
}
#endif
int main() {
#ifdef _WIN32
    SetNlsFileStoragePath(LR"(.\nls)");
    FILE* f = fopen(R"(.\1.txt)", "wb");
    FILE* fw = fopen(R"(.\2.txt)", "wb");
#else
    SetNlsFileStoragePath("./nls"); 
    FILE* f = fopen("./1.txt", "wb");
    FILE* fw = fopen("./2.txt", "wb");
#endif 
    
    
    NlsInit();
    printf("valid %d\n",IsValidCodePage(936));

    #if 0
    auto ss= StringToWideString(WideStringToString(L"我草泥马", 936).value(), 936).value();
    #else
    auto ss= StringToWideString(WideStringToString(L"ABCD", 936), 936);
    #endif
    
    printf("%d\n",ss.size());
    
    auto x=WideStringToString(L"我草泥马", 936);fwrite(x.c_str(), 1, x.size() , f);
    printf("%d\n",x.size());
    auto y=StringToWideString(x,936);fwrite(y.c_str(), sizeof(wchar_t), y.size() , fw);
    printf("%d\n",y.size());
    auto z=StringToWideString(WideStringToString(L"我草泥马", 936), 936);
    printf("%d\n",z.size());

    fclose(f);
    fclose(fw);
    NlsUninit();
    return 0;
}