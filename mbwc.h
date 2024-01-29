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


#ifndef NULL
#define NULL 0
#endif

#define MAX_PATH                                            260

#define FALSE               0
#define TRUE                1

#define CP_ACP                    0           // default to ANSI code page
#define CP_OEMCP                  1           // default to OEM  code page
#define CP_MACCP                  2           // default to MAC  code page
#define CP_THREAD_ACP             3           // current thread's ANSI code page
#define CP_SYMBOL                 42          // SYMBOL translations
#define CP_UTF7                   65000       // UTF-7 translation
#define CP_UTF8                   65001       // UTF-8 translation

#define MB_PRECOMPOSED            0x00000001  // DEPRECATED: use single precomposed characters when possible.
#define MB_COMPOSITE              0x00000002  // DEPRECATED: use multiple discrete characters when possible.
#define MB_USEGLYPHCHARS          0x00000004  // DEPRECATED: use glyph chars, not ctrl chars
#define MB_ERR_INVALID_CHARS      0x00000008  // error for invalid chars

#define WC_COMPOSITECHECK         0x00000200  // convert composite to precomposed
#define WC_DISCARDNS              0x00000010  // discard non-spacing chars          // Used with WC_COMPOSITECHECK
#define WC_SEPCHARS               0x00000020  // generate separate chars            // Used with WC_COMPOSITECHECK
#define WC_DEFAULTCHAR            0x00000040  // replace w/ default char            // Used with WC_COMPOSITECHECK
#define WC_ERR_INVALID_CHARS      0x00000080  // error for invalid chars
#define WC_NO_BEST_FIT_CHARS      0x00000400  // do not use best fit chars

#define ERROR_INVALID_FLAGS              1004L
#define ERROR_INSUFFICIENT_BUFFER        122L    // dderror
#define ERROR_INVALID_PARAMETER          87L    // dderror
#define ERROR_NO_UNICODE_TRANSLATION     1113L


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

