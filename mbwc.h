#include<string.h>
#include<mutex>
#include<vector>

#ifdef _WIN32
#define PATH_CHAR_T wchar_t
#define PATH_TEXT(x) L##x
#else 
#define PATH_CHAR_T char
#define PATH_TEXT(x) x
#endif


#define CONST               const
#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef CHAR* PCHAR, * LPCH, * PCH;
typedef BYTE  BOOLEAN;
typedef CONST CHAR* LPCCH, * PCCH;
typedef CONST CHAR* LPCSTR, * PCSTR; 
typedef wchar_t WCHAR;    // wc,   16-bit UNICODE character
typedef WCHAR* PWCHAR, * LPWCH, * PWCH;
typedef CONST WCHAR* LPCWCH, * PCWCH;
typedef WCHAR* NWPSTR, * LPWSTR, * PWSTR;
typedef void* PVOID;
typedef unsigned long ULONG;
typedef ULONG* PULONG;
typedef unsigned short USHORT;
typedef USHORT* PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR* PUCHAR;
typedef void* HANDLE;
typedef BYTE* PBYTE;
typedef long NTSTATUS, * PNTSTATUS;
typedef size_t LONG_PTR;
typedef size_t ULONG_PTR, * PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, * PDWORD_PTR;
typedef CONST WCHAR* LPCWSTR, * PCWSTR;
typedef CHAR* NPSTR, * LPSTR, * PSTR;
typedef BOOL * LPBOOL;


VOID SetNlsFileStoragePath(const PATH_CHAR_T* Path);

BOOL
NlsInit(VOID);

VOID
NlsUninit(VOID);

BOOL
IsValidCodePage(UINT CodePage);

INT
WideCharToMultiByte(UINT CodePage,
    DWORD Flags,
    LPCWSTR WideCharString,
    INT WideCharCount,
    LPSTR MultiByteString,
    INT MultiByteCount,
    LPCSTR DefaultChar,
    LPBOOL UsedDefaultChar);

INT
MultiByteToWideChar(UINT CodePage,
    DWORD Flags,
    LPCSTR MultiByteString,
    INT MultiByteCount,
    LPWSTR WideCharString,
    INT WideCharCount);

DWORD
GetLastError(VOID);

