#include"mbwc.h"

#include<string.h>
#include<mutex>
#include<vector>
#include<unordered_map>


static std::unordered_map<UINT, const std::basic_string<PATH_CHAR_T>>Nls_CodePage = {
    //计算机\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage
    { 37 , PATH_TEXT("C_037.NLS") }, { 10000 , PATH_TEXT("C_10000.NLS") }, { 10001 , PATH_TEXT("C_10001.NLS") }, { 10002 , PATH_TEXT("C_10002.NLS") }, { 10003 , PATH_TEXT("C_10003.NLS") }, { 10004 , PATH_TEXT("C_10004.NLS") }, { 10005 , PATH_TEXT("C_10005.NLS") }, { 10006 , PATH_TEXT("C_10006.NLS") }, { 10007 , PATH_TEXT("C_10007.NLS") }, { 10008 , PATH_TEXT("C_10008.NLS") }, { 10010 , PATH_TEXT("C_10010.NLS") }, { 10017 , PATH_TEXT("C_10017.NLS") }, { 10021 , PATH_TEXT("C_10021.NLS") }, { 10029 , PATH_TEXT("C_10029.NLS") }, { 10079 , PATH_TEXT("C_10079.NLS") }, { 10081 , PATH_TEXT("C_10081.NLS") }, { 10082 , PATH_TEXT("C_10082.NLS") }, { 1026 , PATH_TEXT("C_1026.NLS") }, { 1047 , PATH_TEXT("C_1047.NLS") }, { 1140 , PATH_TEXT("C_1140.NLS") }, { 1141 , PATH_TEXT("C_1141.NLS") }, { 1142 , PATH_TEXT("C_1142.NLS") }, { 1143 , PATH_TEXT("C_1143.NLS") }, { 1144 , PATH_TEXT("C_1144.NLS") }, { 1145 , PATH_TEXT("C_1145.NLS") }, { 1146 , PATH_TEXT("C_1146.NLS") }, { 1147 , PATH_TEXT("C_1147.NLS") }, { 1148 , PATH_TEXT("C_1148.NLS") }, { 1149 , PATH_TEXT("C_1149.NLS") }, { 1250 , PATH_TEXT("C_1250.NLS") }, { 1251 , PATH_TEXT("C_1251.NLS") }, { 1252 , PATH_TEXT("C_1252.NLS") }, { 1253 , PATH_TEXT("C_1253.NLS") }, { 1254 , PATH_TEXT("C_1254.NLS") }, { 1255 , PATH_TEXT("C_1255.NLS") }, { 1256 , PATH_TEXT("C_1256.NLS") }, { 1257 , PATH_TEXT("C_1257.NLS") }, { 1258 , PATH_TEXT("C_1258.NLS") }, { 1361 , PATH_TEXT("C_1361.NLS") }, { 20000 , PATH_TEXT("C_20000.NLS") }, { 20001 , PATH_TEXT("C_20001.NLS") }, { 20002 , PATH_TEXT("C_20002.NLS") }, { 20003 , PATH_TEXT("C_20003.NLS") }, { 20004 , PATH_TEXT("C_20004.NLS") }, { 20005 , PATH_TEXT("C_20005.NLS") }, { 20105 , PATH_TEXT("C_20105.NLS") }, { 20106 , PATH_TEXT("C_20106.NLS") }, { 20107 , PATH_TEXT("C_20107.NLS") }, { 20108 , PATH_TEXT("C_20108.NLS") }, { 20127 , PATH_TEXT("C_20127.NLS") }, { 20261 , PATH_TEXT("C_20261.NLS") }, { 20269 , PATH_TEXT("C_20269.NLS") }, { 20273 , PATH_TEXT("C_20273.NLS") }, { 20277 , PATH_TEXT("C_20277.NLS") }, { 20278 , PATH_TEXT("C_20278.NLS") }, { 20280 , PATH_TEXT("C_20280.NLS") }, { 20284 , PATH_TEXT("C_20284.NLS") }, { 20285 , PATH_TEXT("C_20285.NLS") }, { 20290 , PATH_TEXT("C_20290.NLS") }, { 20297 , PATH_TEXT("C_20297.NLS") }, { 20420 , PATH_TEXT("C_20420.NLS") }, { 20423 , PATH_TEXT("C_20423.NLS") }, { 20424 , PATH_TEXT("C_20424.NLS") }, { 20833 , PATH_TEXT("C_20833.NLS") }, { 20838 , PATH_TEXT("C_20838.NLS") }, { 20866 , PATH_TEXT("C_20866.NLS") }, { 20871 , PATH_TEXT("C_20871.NLS") }, { 20880 , PATH_TEXT("C_20880.NLS") }, { 20905 , PATH_TEXT("C_20905.NLS") }, { 20924 , PATH_TEXT("C_20924.NLS") }, { 20932 , PATH_TEXT("C_20932.NLS") }, { 20936 , PATH_TEXT("C_20936.NLS") }, { 20949 , PATH_TEXT("C_20949.NLS") }, { 21025 , PATH_TEXT("C_21025.NLS") }, { 21027 , PATH_TEXT("C_21027.NLS") }, { 21866 , PATH_TEXT("C_21866.NLS") }, { 28591 , PATH_TEXT("C_28591.NLS") }, { 28592 , PATH_TEXT("C_28592.NLS") }, { 28593 , PATH_TEXT("C_28593.NLS") }, { 28594 , PATH_TEXT("C_28594.NLS") }, { 28595 , PATH_TEXT("C_28595.NLS") }, { 28596 , PATH_TEXT("C_28596.NLS") }, { 28597 , PATH_TEXT("C_28597.NLS") }, { 28598 , PATH_TEXT("C_28598.NLS") }, { 28599 , PATH_TEXT("C_28599.NLS") }, { 28603 , PATH_TEXT("c_28603.nls") }, { 28605 , PATH_TEXT("C_28605.NLS") }, { 437 , PATH_TEXT("C_437.NLS") }, { 500 , PATH_TEXT("C_500.NLS") }, { 708 , PATH_TEXT("C_708.NLS") }, { 720 , PATH_TEXT("C_720.NLS") }, { 737 , PATH_TEXT("C_737.NLS") }, { 775 , PATH_TEXT("C_775.NLS") }, { 850 , PATH_TEXT("C_850.NLS") }, { 852 , PATH_TEXT("C_852.NLS") }, { 855 , PATH_TEXT("C_855.NLS") }, { 857 , PATH_TEXT("C_857.NLS") }, { 858 , PATH_TEXT("C_858.NLS") }, { 860 , PATH_TEXT("C_860.NLS") }, { 861 , PATH_TEXT("C_861.NLS") }, { 862 , PATH_TEXT("C_862.NLS") }, { 863 , PATH_TEXT("C_863.NLS") }, { 864 , PATH_TEXT("C_864.NLS") }, { 865 , PATH_TEXT("C_865.NLS") }, { 866 , PATH_TEXT("C_866.NLS") }, { 869 , PATH_TEXT("C_869.NLS") }, { 870 , PATH_TEXT("C_870.NLS") }, { 874 , PATH_TEXT("C_874.NLS") }, { 875 , PATH_TEXT("C_875.NLS") }, { 932 , PATH_TEXT("C_932.NLS") }, { 936 , PATH_TEXT("C_936.NLS") }, { 949 , PATH_TEXT("C_949.NLS") }, { 950 , PATH_TEXT("C_950.NLS") }
};


#define min(a,b) (((a) < (b)) ? (a) : (b))
#define FORCEINLINE




#define DPRINT
static DWORD lastdwErrCode;
VOID
SetLastError(DWORD dwErrCode)
{
    dwErrCode = dwErrCode;
}

DWORD
GetLastError(VOID)
{
    /* Return the current value */
    return lastdwErrCode;
}

/* Sequence length based on the first character. */
static const char UTF8Length[128] =
{
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0x80 - 0x8F */
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0x90 - 0x9F */
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0xA0 - 0xAF */
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0xB0 - 0xBF */
   0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /* 0xC0 - 0xCF */
   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /* 0xD0 - 0xDF */
   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, /* 0xE0 - 0xEF */
   3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0  /* 0xF0 - 0xFF */
};

/* First byte mask depending on UTF-8 sequence length. */
static const unsigned char UTF8Mask[6] = { 0x7f, 0x1f, 0x0f, 0x07, 0x03, 0x01 };

/* UTF-8 length to lower bound */
static const unsigned long UTF8LBound[] =
{ 0, 0x80, 0x800, 0x10000, 0x200000, 0x2000000, 0xFFFFFFFF };



static
INT
IntMultiByteToWideCharUTF8(DWORD Flags,
    LPCSTR MultiByteString,
    INT MultiByteCount,
    LPWSTR WideCharString,
    INT WideCharCount)
{
    LPCSTR MbsEnd, MbsPtrSave;
    UCHAR Char, TrailLength;
    WCHAR WideChar;
    LONG Count;
    BOOL CharIsValid, StringIsValid = TRUE;
    const WCHAR InvalidChar = 0xFFFD;

    if (Flags != 0 && Flags != MB_ERR_INVALID_CHARS)
    {
        SetLastError(ERROR_INVALID_FLAGS);
        return 0;
    }

    /* Does caller query for output buffer size? */
    if (WideCharCount == 0)
    {
        /* validate and count the wide characters */
        MbsEnd = MultiByteString + MultiByteCount;
        for (; MultiByteString < MbsEnd; WideCharCount++)
        {
            Char = *MultiByteString++;
            if (Char < 0x80)
            {
                TrailLength = 0;
                continue;
            }
            if ((Char & 0xC0) == 0x80)
            {
                TrailLength = 0;
                StringIsValid = FALSE;
                continue;
            }

            TrailLength = UTF8Length[Char - 0x80];
            if (TrailLength == 0)
            {
                StringIsValid = FALSE;
                continue;
            }

            CharIsValid = TRUE;
            MbsPtrSave = MultiByteString;
            WideChar = Char & UTF8Mask[TrailLength];

            while (TrailLength && MultiByteString < MbsEnd)
            {
                if ((*MultiByteString & 0xC0) != 0x80)
                {
                    CharIsValid = StringIsValid = FALSE;
                    break;
                }

                WideChar = (WideChar << 6) | (*MultiByteString++ & 0x7f);
                TrailLength--;
            }

            if (!CharIsValid || WideChar < UTF8LBound[UTF8Length[Char - 0x80]])
            {
                MultiByteString = MbsPtrSave;
            }
        }

        if (TrailLength)
        {
            WideCharCount++;
            StringIsValid = FALSE;
        }

        if (Flags == MB_ERR_INVALID_CHARS && !StringIsValid)
        {
            SetLastError(ERROR_NO_UNICODE_TRANSLATION);
            return 0;
        }

        return WideCharCount;
    }

    /* convert */
    MbsEnd = MultiByteString + MultiByteCount;
    for (Count = 0; Count < WideCharCount && MultiByteString < MbsEnd; Count++)
    {
        Char = *MultiByteString++;
        if (Char < 0x80)
        {
            *WideCharString++ = Char;
            TrailLength = 0;
            continue;
        }
        if ((Char & 0xC0) == 0x80)
        {
            *WideCharString++ = InvalidChar;
            TrailLength = 0;
            StringIsValid = FALSE;
            continue;
        }

        TrailLength = UTF8Length[Char - 0x80];
        if (TrailLength == 0)
        {
            *WideCharString++ = InvalidChar;
            StringIsValid = FALSE;
            continue;
        }

        CharIsValid = TRUE;
        MbsPtrSave = MultiByteString;
        WideChar = Char & UTF8Mask[TrailLength];

        while (TrailLength && MultiByteString < MbsEnd)
        {
            if ((*MultiByteString & 0xC0) != 0x80)
            {
                CharIsValid = StringIsValid = FALSE;
                break;
            }

            WideChar = (WideChar << 6) | (*MultiByteString++ & 0x7f);
            TrailLength--;
        }

        if (CharIsValid && UTF8LBound[UTF8Length[Char - 0x80]] <= WideChar)
        {
            *WideCharString++ = WideChar;
        }
        else
        {
            *WideCharString++ = InvalidChar;
            MultiByteString = MbsPtrSave;
            StringIsValid = FALSE;
        }
    }

    if (TrailLength && Count < WideCharCount && MultiByteString < MbsEnd)
    {
        *WideCharString = InvalidChar;
        WideCharCount++;
    }

    if (MultiByteString < MbsEnd)
    {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        return 0;
    }

    if (Flags == MB_ERR_INVALID_CHARS && (!StringIsValid || TrailLength))
    {
        SetLastError(ERROR_NO_UNICODE_TRANSLATION);
        return 0;
    }

    return Count;
}

static inline BOOL utf7_write_w(WCHAR* dst, int dstlen, int* index, WCHAR character)
{
    if (dstlen > 0)
    {
        if (*index >= dstlen)
            return FALSE;

        dst[*index] = character;
    }

    (*index)++;

    return TRUE;
}
static INT Utf7ToWideChar(const char* src, int srclen, WCHAR* dst, int dstlen)
{
    static const signed char base64_decoding_table[] =
    {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x00-0x0F */
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /* 0x10-0x1F */
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, /* 0x20-0x2F */
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1, /* 0x30-0x3F */
        -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, /* 0x40-0x4F */
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, /* 0x50-0x5F */
        -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, /* 0x60-0x6F */
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1  /* 0x70-0x7F */
    };

    const char* source_end = src + srclen;
    int dest_index = 0;

    DWORD byte_pair = 0;
    short offset = 0;

    while (src < source_end)
    {
        if (*src == '+')
        {
            src++;
            if (src >= source_end)
                break;

            if (*src == '-')
            {
                /* just a plus sign escaped as +- */
                if (!utf7_write_w(dst, dstlen, &dest_index, '+'))
                {
                    SetLastError(ERROR_INSUFFICIENT_BUFFER);
                    return 0;
                }
                src++;
                continue;
            }

            do
            {
                signed char sextet = *src;
                if (sextet == '-')
                {
                    /* skip over the dash and end base64 decoding
                     * the current, unfinished byte pair is discarded */
                    src++;
                    offset = 0;
                    break;
                }
                if (sextet < 0)
                {
                    /* the next character of src is < 0 and therefore not part of a base64 sequence
                     * the current, unfinished byte pair is NOT discarded in this case
                     * this is probably a bug in Windows */
                    break;
                }

                sextet = base64_decoding_table[sextet];
                if (sextet == -1)
                {
                    /* -1 means that the next character of src is not part of a base64 sequence
                     * in other words, all sextets in this base64 sequence have been processed
                     * the current, unfinished byte pair is discarded */
                    offset = 0;
                    break;
                }

                byte_pair = (byte_pair << 6) | sextet;
                offset += 6;

                if (offset >= 16)
                {
                    /* this byte pair is done */
                    if (!utf7_write_w(dst, dstlen, &dest_index, (byte_pair >> (offset - 16)) & 0xFFFF))
                    {
                        SetLastError(ERROR_INSUFFICIENT_BUFFER);
                        return 0;
                    }
                    offset -= 16;
                }

                src++;
            } while (src < source_end);
        }
        else
        {
            /* we have to convert to unsigned char in case *src < 0 */
            if (!utf7_write_w(dst, dstlen, &dest_index, (unsigned char)*src))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            src++;
        }
    }

    return dest_index;
}

static
INT
IntMultiByteToWideCharSYMBOL(DWORD Flags,
    LPCSTR MultiByteString,
    INT MultiByteCount,
    LPWSTR WideCharString,
    INT WideCharCount)
{
    LONG Count;
    UCHAR Char;
    INT WideCharMaxLen;


    if (Flags != 0)
    {
        SetLastError(ERROR_INVALID_FLAGS);
        return 0;
    }

    if (WideCharCount == 0)
    {
        return MultiByteCount;
    }

    WideCharMaxLen = WideCharCount > MultiByteCount ? MultiByteCount : WideCharCount;

    for (Count = 0; Count < WideCharMaxLen; Count++)
    {
        Char = MultiByteString[Count];
        if (Char < 0x20)
        {
            WideCharString[Count] = Char;
        }
        else
        {
            WideCharString[Count] = Char + 0xf000;
        }
    }
    if (MultiByteCount > WideCharMaxLen)
    {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        return 0;
    }

    return WideCharMaxLen;
}
typedef struct _LIST_ENTRY
{
    struct _LIST_ENTRY* Flink;
    struct _LIST_ENTRY* Blink;
} LIST_ENTRY, * PLIST_ENTRY;
#define MAXIMUM_LEADBYTES 12
typedef struct _CPTABLEINFO {
    USHORT CodePage;
    USHORT MaximumCharacterSize;       /* 1 = SBCS, 2 = DBCS */
    USHORT DefaultChar;                /* Default MultiByte Character for the CP->Unicode conversion */
    USHORT UniDefaultChar;             /* Default Unicode Character for the CP->Unicode conversion */
    USHORT TransDefaultChar;           /* Default MultiByte Character for the Unicode->CP conversion */
    USHORT TransUniDefaultChar;        /* Default Unicode Character for the Unicode->CP conversion */
    USHORT DBCSCodePage;
    UCHAR LeadByte[MAXIMUM_LEADBYTES];
    PUSHORT MultiByteTable;             /* Table for CP->Unicode conversion */
    PVOID WideCharTable;                /* Table for Unicode->CP conversion */
    PUSHORT DBCSRanges;
    PUSHORT DBCSOffsets;
} CPTABLEINFO, * PCPTABLEINFO;
typedef struct _CODEPAGE_ENTRY
{
    LIST_ENTRY Entry;
    UINT CodePage;
    HANDLE SectionHandle;
    PBYTE SectionMapping;
    CPTABLEINFO CodePageTable;
} CODEPAGE_ENTRY, * PCODEPAGE_ENTRY;
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
static LIST_ENTRY CodePageListHead;
std::mutex CodePageListLock;
#define CONTAINING_RECORD(address, type, field) ((type *)( \
                                                  (PCHAR)(address) - \
                                                  (ULONG_PTR)(&((type *)0)->field)))
PCODEPAGE_ENTRY
IntGetLoadedCodePageEntry(UINT CodePage)
{
    LIST_ENTRY* CurrentEntry;
    PCODEPAGE_ENTRY Current;
    std::lock_guard<std::mutex> _(CodePageListLock);
    for (CurrentEntry = CodePageListHead.Flink;
        CurrentEntry != &CodePageListHead;
        CurrentEntry = CurrentEntry->Flink)
    {
        Current = CONTAINING_RECORD(CurrentEntry, CODEPAGE_ENTRY, Entry);
        if (Current->CodePage == CodePage)
        {
            return Current;
        }
    }
    return NULL;
}


std::basic_string<PATH_CHAR_T>NlsFileStoragePath;

VOID SetNlsFileStoragePath(const PATH_CHAR_T* Path) {
    NlsFileStoragePath = Path;
}

BOOL
GetCPFileNameFromRegistry(UINT CodePage, PATH_CHAR_T* FileName, ULONG FileNameSize)
{
    BOOL bRetValue;
    bRetValue = FALSE;
     
    if (Nls_CodePage.find(CodePage)!= Nls_CodePage.end())
    {
        auto NlsFileName = Nls_CodePage.at(CodePage);
        
        PATH_CHAR_T _FileName[MAX_PATH];
        #ifdef _WIN32
        wcscpy(_FileName, NlsFileStoragePath.c_str());
        wcscat(_FileName, L"\\");
        wcscat(_FileName, NlsFileName.c_str());
        FILE *f=_wfopen(_FileName,L"r");
        if (f) {
            bRetValue= TRUE;
            fclose(f);
        }
        if (FileName) {
            wcscpy(FileName, _FileName);
        }
        #else
        strcpy(_FileName, NlsFileStoragePath.c_str());
        strcat(_FileName, "/");
        strcat(_FileName, NlsFileName.c_str());
        FILE *f=fopen(_FileName,"r");
        if (f) {
            bRetValue= TRUE;
            fclose(f);
        }
        if (FileName) {
            strcpy(FileName, _FileName);
        }
        #endif
    }
    return bRetValue;
}
BOOL
IsValidCodePage(UINT CodePage)
{
    if (CodePage == 0) return FALSE;
    if (CodePage == CP_UTF8 || CodePage == CP_UTF7)
        return TRUE;
    if (IntGetLoadedCodePageEntry(CodePage))
        return TRUE;
    return GetCPFileNameFromRegistry(CodePage, NULL, 0);
}
typedef struct _NLS_FILE_HEADER
{
    USHORT HeaderSize;
    USHORT CodePage;
    USHORT MaximumCharacterSize;
    USHORT DefaultChar;
    USHORT UniDefaultChar;
    USHORT TransDefaultChar;
    USHORT TransUniDefaultChar;
    UCHAR LeadByte[MAXIMUM_LEADBYTES];
} NLS_FILE_HEADER, * PNLS_FILE_HEADER;

VOID
RtlInitCodePageTable(PUSHORT TableBase,
    PCPTABLEINFO CodePageTable)
{
    PNLS_FILE_HEADER NlsFileHeader;



    NlsFileHeader = (PNLS_FILE_HEADER)TableBase;

    /* Copy header fields first */
    CodePageTable->CodePage = NlsFileHeader->CodePage;
    CodePageTable->MaximumCharacterSize = NlsFileHeader->MaximumCharacterSize;
    CodePageTable->DefaultChar = NlsFileHeader->DefaultChar;
    CodePageTable->UniDefaultChar = NlsFileHeader->UniDefaultChar;
    CodePageTable->TransDefaultChar = NlsFileHeader->TransDefaultChar;
    CodePageTable->TransUniDefaultChar = NlsFileHeader->TransUniDefaultChar;

    memcpy(&CodePageTable->LeadByte,
        &NlsFileHeader->LeadByte,
        MAXIMUM_LEADBYTES);

    /* Offset to wide char table is after the header */
    CodePageTable->WideCharTable =
        TableBase + NlsFileHeader->HeaderSize + 1 + TableBase[NlsFileHeader->HeaderSize];

    /* Then multibyte table (256 wchars) follows */
    CodePageTable->MultiByteTable = TableBase + NlsFileHeader->HeaderSize + 1;

    /* Check the presence of glyph table (256 wchars) */
    if (!CodePageTable->MultiByteTable[256])
        CodePageTable->DBCSRanges = CodePageTable->MultiByteTable + 256 + 1;
    else
        CodePageTable->DBCSRanges = CodePageTable->MultiByteTable + 256 + 1 + 256;

    /* Is this double-byte code page? */
    if (*CodePageTable->DBCSRanges)
    {
        CodePageTable->DBCSCodePage = 1;
        CodePageTable->DBCSOffsets = CodePageTable->DBCSRanges + 1;
    }
    else
    {
        CodePageTable->DBCSCodePage = 0;
        CodePageTable->DBCSOffsets = NULL;
    }
}
VOID
InsertTailList(
    PLIST_ENTRY ListHead,
    PLIST_ENTRY Entry
)
{
    PLIST_ENTRY OldBlink;
    OldBlink = ListHead->Blink;
    Entry->Flink = ListHead;
    Entry->Blink = OldBlink;
    OldBlink->Flink = Entry;
    ListHead->Blink = Entry;
}
char* readfile(const PATH_CHAR_T* fname) 
{
#ifdef _WIN32 
    FILE* f=_wfopen(fname, L"rb"); 
#else
    FILE* f=fopen(fname, "rb"); 
#endif
    if (f == 0)return 0;
    fseek(f, 0, SEEK_END);
    auto len = ftell(f);
    fseek(f, 0, SEEK_SET);
    auto buff = new char[len];
    fread(buff, 1, len, f);
    fclose(f);
    return buff;
}
PCODEPAGE_ENTRY
IntGetCodePageEntry(UINT CodePage)
{
    PATH_CHAR_T FileName[MAX_PATH + 1];
    PCODEPAGE_ENTRY CodePageEntry;
     
    CodePageEntry = IntGetLoadedCodePageEntry(CodePage);
    if (CodePageEntry != NULL)
    {
        return CodePageEntry;
    }
     
    std::lock_guard<std::mutex> _(CodePageListLock);
         
    if (!GetCPFileNameFromRegistry(CodePage,
        FileName,
        MAX_PATH)) 
    {
        return NULL;
    }
    auto SectionMapping = readfile(FileName);
    if (SectionMapping == NULL)
    {   
        return NULL;
    }

    CodePageEntry = (decltype(CodePageEntry))new char[sizeof(CODEPAGE_ENTRY)];
    if (CodePageEntry == NULL)
    {
        return NULL;
    }

    CodePageEntry->CodePage = CodePage;
    CodePageEntry->SectionHandle = (decltype(CodePageEntry->SectionHandle))1;
    CodePageEntry->SectionMapping = (decltype(CodePageEntry->SectionMapping))SectionMapping;

    RtlInitCodePageTable((PUSHORT)SectionMapping, &CodePageEntry->CodePageTable);
    
    /* Insert the new entry to list and unlock. Uff. */
    InsertTailList(&CodePageListHead, &CodePageEntry->Entry);

    return CodePageEntry;
}
#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))


static
INT
IntMultiByteToWideCharCP(UINT CodePage,
    DWORD Flags,
    LPCSTR MultiByteString,
    INT MultiByteCount,
    LPWSTR WideCharString,
    INT WideCharCount)
{
    PCODEPAGE_ENTRY CodePageEntry;
    PCPTABLEINFO CodePageTable;
    PUSHORT MultiByteTable;
    LPCSTR TempString;
    INT TempLength;
    USHORT WideChar;
    /* Get code page table. */
    CodePageEntry = IntGetCodePageEntry(CodePage);
    if (CodePageEntry == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    CodePageTable = &CodePageEntry->CodePageTable;

    /* If MB_USEGLYPHCHARS flag present and glyph table present */
    if ((Flags & MB_USEGLYPHCHARS) && CodePageTable->MultiByteTable[256])
    {
        /* Use glyph table */
        MultiByteTable = CodePageTable->MultiByteTable + 256 + 1;
    }
    else
    {
        MultiByteTable = CodePageTable->MultiByteTable;
    }

    /* Different handling for DBCS code pages. */
    if (CodePageTable->DBCSCodePage)
    {
        UCHAR Char;
        USHORT DBCSOffset;
        LPCSTR MbsEnd = MultiByteString + MultiByteCount;
        INT Count;

        if (Flags & MB_ERR_INVALID_CHARS)
        {
            TempString = MultiByteString;

            while (TempString < MbsEnd)
            {
                DBCSOffset = CodePageTable->DBCSOffsets[(UCHAR)*TempString];

                if (DBCSOffset)
                {
                    /* If lead byte is presented, but behind it there is no symbol */
                    if (((TempString + 1) == MbsEnd) || (*(TempString + 1) == 0))
                    {
                        SetLastError(ERROR_NO_UNICODE_TRANSLATION);
                        return 0;
                    }

                    WideChar = CodePageTable->DBCSOffsets[DBCSOffset + *(TempString + 1)];

                    if (WideChar == CodePageTable->UniDefaultChar &&
                        MAKEWORD(*(TempString + 1), *TempString) != CodePageTable->TransUniDefaultChar)
                    {
                        SetLastError(ERROR_NO_UNICODE_TRANSLATION);
                        return 0;
                    }

                    TempString++;
                }
                else
                {
                    WideChar = MultiByteTable[(UCHAR)*TempString];

                    if ((WideChar == CodePageTable->UniDefaultChar &&
                        *TempString != CodePageTable->TransUniDefaultChar) ||
                        /* "Private Use" characters */
                        (WideChar >= 0xE000 && WideChar <= 0xF8FF))
                    {
                        SetLastError(ERROR_NO_UNICODE_TRANSLATION);
                        return 0;
                    }
                }

                TempString++;
            }
        }

        /* Does caller query for output buffer size? */
        if (WideCharCount == 0)
        {
            for (; MultiByteString < MbsEnd; WideCharCount++)
            {
                Char = *MultiByteString++;

                DBCSOffset = CodePageTable->DBCSOffsets[Char];

                if (!DBCSOffset)
                    continue;

                if (MultiByteString < MbsEnd)
                    MultiByteString++;
            }

            return WideCharCount;
        }

        for (Count = 0; Count < WideCharCount && MultiByteString < MbsEnd; Count++)
        {
            Char = *MultiByteString++;

            DBCSOffset = CodePageTable->DBCSOffsets[Char];

            if (!DBCSOffset)
            {
                *WideCharString++ = MultiByteTable[Char];
                continue;
            }

            if (MultiByteString == MbsEnd || *MultiByteString == 0)
            {
                *WideCharString++ = CodePageTable->UniDefaultChar;
            }
            else
            {
                *WideCharString++ = CodePageTable->DBCSOffsets[DBCSOffset + (UCHAR)*MultiByteString++];
            }
        }

        if (MultiByteString < MbsEnd)
        {
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            return 0;
        }

        return Count;
    }
    else /* SBCS code page */
    {
        /* Check for invalid characters. */
        if (Flags & MB_ERR_INVALID_CHARS)
        {
            for (TempString = MultiByteString, TempLength = MultiByteCount;
                TempLength > 0;
                TempString++, TempLength--)
            {
                WideChar = MultiByteTable[(UCHAR)*TempString];

                if ((WideChar == CodePageTable->UniDefaultChar &&
                    *TempString != CodePageTable->TransUniDefaultChar) ||
                    /* "Private Use" characters */
                    (WideChar >= 0xE000 && WideChar <= 0xF8FF))
                {
                    SetLastError(ERROR_NO_UNICODE_TRANSLATION);
                    return 0;
                }
            }
        }

        /* Does caller query for output buffer size? */
        if (WideCharCount == 0)
            return MultiByteCount;

        /* Fill the WideCharString buffer with what will fit: Verified on WinXP */
        for (TempLength = (WideCharCount < MultiByteCount) ? WideCharCount : MultiByteCount;
            TempLength > 0;
            MultiByteString++, TempLength--)
        {
            *WideCharString++ = MultiByteTable[(UCHAR)*MultiByteString];
        }

        /* Adjust buffer size. Wine trick ;-) */
        if (WideCharCount < MultiByteCount)
        {
            MultiByteCount = WideCharCount;
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            return 0;
        }
        return MultiByteCount;
    }
}


INT
MultiByteToWideChar(UINT CodePage,
    DWORD Flags,
    LPCSTR MultiByteString,
    INT MultiByteCount,
    LPWSTR WideCharString,
    INT WideCharCount)
{
    /* Check the parameters. */
    if (MultiByteString == NULL ||
        MultiByteCount == 0 || WideCharCount < 0 ||
        (WideCharCount && (WideCharString == NULL ||
            (PVOID)MultiByteString == (PVOID)WideCharString)))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    /* Determine the input string length. */
    if (MultiByteCount < 0)
    {
        MultiByteCount = strlen(MultiByteString) + 1;
    }

    switch (CodePage)
    {
    case CP_UTF8:
        return IntMultiByteToWideCharUTF8(Flags,
            MultiByteString,
            MultiByteCount,
            WideCharString,
            WideCharCount);

    case CP_UTF7:
        if (Flags)
        {
            SetLastError(ERROR_INVALID_FLAGS);
            return 0;
        }
        return Utf7ToWideChar(MultiByteString, MultiByteCount,
            WideCharString, WideCharCount);

    case CP_SYMBOL:
        return IntMultiByteToWideCharSYMBOL(Flags,
            MultiByteString,
            MultiByteCount,
            WideCharString,
            WideCharCount);
    default:
        return IntMultiByteToWideCharCP(CodePage,
            Flags,
            MultiByteString,
            MultiByteCount,
            WideCharString,
            WideCharCount);
    }
}

static INT
IntWideCharToMultiByteUTF8(UINT CodePage,
    DWORD Flags,
    LPCWSTR WideCharString,
    INT WideCharCount,
    LPSTR MultiByteString,
    INT MultiByteCount,
    LPCSTR DefaultChar,
    LPBOOL UsedDefaultChar)
{
    INT TempLength;
    DWORD Char;

    if (Flags)
    {
        SetLastError(ERROR_INVALID_FLAGS);
        return 0;
    }

    /* Does caller query for output buffer size? */
    if (MultiByteCount == 0)
    {
        for (TempLength = 0; WideCharCount;
            WideCharCount--, WideCharString++)
        {
            TempLength++;
            if (*WideCharString >= 0x80)
            {
                TempLength++;
                if (*WideCharString >= 0x800)
                {
                    TempLength++;
                    if (*WideCharString >= 0xd800 && *WideCharString < 0xdc00 &&
                        WideCharCount >= 1 &&
                        WideCharString[1] >= 0xdc00 && WideCharString[1] <= 0xe000)
                    {
                        WideCharCount--;
                        WideCharString++;
                        TempLength++;
                    }
                }
            }
        }
        return TempLength;
    }

    for (TempLength = MultiByteCount; WideCharCount; WideCharCount--, WideCharString++)
    {
        Char = *WideCharString;
        if (Char < 0x80)
        {
            if (!TempLength)
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                break;
            }
            TempLength--;
            *MultiByteString++ = (CHAR)Char;
            continue;
        }

        if (Char < 0x800)  /* 0x80-0x7ff: 2 bytes */
        {
            if (TempLength < 2)
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                break;
            }
            MultiByteString[1] = 0x80 | (Char & 0x3f); Char >>= 6;
            MultiByteString[0] = 0xc0 | Char;
            MultiByteString += 2;
            TempLength -= 2;
            continue;
        }

        /* surrogate pair 0x10000-0x10ffff: 4 bytes */
        if (Char >= 0xd800 && Char < 0xdc00 &&
            WideCharCount >= 1 &&
            WideCharString[1] >= 0xdc00 && WideCharString[1] < 0xe000)
        {
            WideCharCount--;
            WideCharString++;

            if (TempLength < 4)
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                break;
            }

            Char = (Char - 0xd800) << 10;
            Char |= *WideCharString - 0xdc00; 
            Char += 0x10000;

            MultiByteString[3] = 0x80 | (Char & 0x3f); Char >>= 6;
            MultiByteString[2] = 0x80 | (Char & 0x3f); Char >>= 6;
            MultiByteString[1] = 0x80 | (Char & 0x3f); Char >>= 6;
            MultiByteString[0] = 0xf0 | Char;
            MultiByteString += 4;
            TempLength -= 4;
            continue;
        }

        /* 0x800-0xffff: 3 bytes */
        if (TempLength < 3)
        {
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            break;
        }
        MultiByteString[2] = 0x80 | (Char & 0x3f); Char >>= 6;
        MultiByteString[1] = 0x80 | (Char & 0x3f); Char >>= 6;
        MultiByteString[0] = 0xe0 | Char;
        MultiByteString += 3;
        TempLength -= 3;
    }

    return MultiByteCount - TempLength;
}

static inline BOOL utf7_can_directly_encode(WCHAR codepoint)
{
    static const BOOL directly_encodable_table[] =
    {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, /* 0x00 - 0x0F */
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* 0x10 - 0x1F */
        1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, /* 0x20 - 0x2F */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, /* 0x30 - 0x3F */
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /* 0x40 - 0x4F */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, /* 0x50 - 0x5F */
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, /* 0x60 - 0x6F */
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1                 /* 0x70 - 0x7A */
    };

    return codepoint <= 0x7A ? directly_encodable_table[codepoint] : FALSE;
}

static inline BOOL utf7_write_c(char* dst, int dstlen, int* index, char character)
{
    if (dstlen > 0)
    {
        if (*index >= dstlen)
            return FALSE;

        dst[*index] = character;
    }

    (*index)++;

    return TRUE;
}

static INT WideCharToUtf7(const WCHAR* src, int srclen, char* dst, int dstlen)
{
    static const char base64_encoding_table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    const WCHAR* source_end = src + srclen;
    int dest_index = 0;

    while (src < source_end)
    {
        if (*src == '+')
        {
            if (!utf7_write_c(dst, dstlen, &dest_index, '+'))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            if (!utf7_write_c(dst, dstlen, &dest_index, '-'))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            src++;
        }
        else if (utf7_can_directly_encode(*src))
        {
            if (!utf7_write_c(dst, dstlen, &dest_index, *src))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
            src++;
        }
        else
        {
            unsigned int offset = 0;
            DWORD byte_pair = 0;

            if (!utf7_write_c(dst, dstlen, &dest_index, '+'))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }

            while (src < source_end && !utf7_can_directly_encode(*src))
            {
                byte_pair = (byte_pair << 16) | *src;
                offset += 16;
                while (offset >= 6)
                {
                    if (!utf7_write_c(dst, dstlen, &dest_index, base64_encoding_table[(byte_pair >> (offset - 6)) & 0x3F]))
                    {
                        SetLastError(ERROR_INSUFFICIENT_BUFFER);
                        return 0;
                    }
                    offset -= 6;
                }
                src++;
            }

            if (offset)
            {
                /* Windows won't create a padded base64 character if there's no room for the - sign
                 * as well ; this is probably a bug in Windows */
                if (dstlen > 0 && dest_index + 1 >= dstlen)
                {
                    SetLastError(ERROR_INSUFFICIENT_BUFFER);
                    return 0;
                }

                byte_pair <<= (6 - offset);
                if (!utf7_write_c(dst, dstlen, &dest_index, base64_encoding_table[byte_pair & 0x3F]))
                {
                    SetLastError(ERROR_INSUFFICIENT_BUFFER);
                    return 0;
                }
            }

            /* Windows always explicitly terminates the base64 sequence
               even though RFC 2152 (page 3, rule 2) does not require this */
            if (!utf7_write_c(dst, dstlen, &dest_index, '-'))
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }
        }
    }

    return dest_index;
}

static INT
IntWideCharToMultiByteSYMBOL(DWORD Flags,
    LPCWSTR WideCharString,
    INT WideCharCount,
    LPSTR MultiByteString,
    INT MultiByteCount)
{
    LONG Count;
    INT MaxLen;
    WCHAR Char;

    if (Flags != 0)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }


    if (MultiByteCount == 0)
    {
        return WideCharCount;
    }

    MaxLen = MultiByteCount > WideCharCount ? WideCharCount : MultiByteCount;
    for (Count = 0; Count < MaxLen; Count++)
    {
        Char = WideCharString[Count];
        if (Char < 0x20)
        {
            MultiByteString[Count] = (CHAR)Char;
        }
        else
        {
            if ((Char >= 0xf020) && (Char < 0xf100))
            {
                MultiByteString[Count] = Char - 0xf000;
            }
            else
            {
                SetLastError(ERROR_NO_UNICODE_TRANSLATION);
                return 0;
            }
        }
    }

    if (WideCharCount > MaxLen)
    {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        return 0;
    }
    return MaxLen;
}
static inline BOOL
IntIsValidDBCSMapping(PCPTABLEINFO CodePageTable, DWORD Flags, WCHAR wch, USHORT ch)
{
    /* If ch is the default character, but the wch is not, it can't be a valid mapping */
    if (ch == CodePageTable->TransDefaultChar && wch != CodePageTable->TransUniDefaultChar)
        return FALSE;

    /* If the WC_NO_BEST_FIT_CHARS flag has been specified, the characters need to match exactly. */
    if (Flags & WC_NO_BEST_FIT_CHARS)
    {
        if (ch & 0xff00)
        {
            USHORT uOffset = CodePageTable->DBCSOffsets[ch >> 8];
            /* if (!uOffset) return (CodePageTable->MultiByteTable[ch] == wch); */
            return (CodePageTable->DBCSOffsets[uOffset + (ch & 0xff)] == wch);
        }

        return (CodePageTable->MultiByteTable[ch] == wch);
    }

    /* If we're still here, we have a valid mapping */
    return TRUE;
}
static
inline
BOOL
IntIsValidSBCSMapping(PCPTABLEINFO CodePageTable, DWORD Flags, WCHAR wch, UCHAR ch)
{
    /* If the WC_NO_BEST_FIT_CHARS flag has been specified, the characters need to match exactly. */
    if (Flags & WC_NO_BEST_FIT_CHARS)
        return (CodePageTable->MultiByteTable[ch] == wch);

    /* By default, all characters except TransDefaultChar apply as a valid mapping
       for ch (so also "nearest" characters) */
    if (ch != CodePageTable->TransDefaultChar)
        return TRUE;

    /* The only possible left valid mapping is the default character itself */
    return (wch == CodePageTable->TransUniDefaultChar);
}
static
INT
IntWideCharToMultiByteCP(UINT CodePage,
    DWORD Flags,
    LPCWSTR WideCharString,
    INT WideCharCount,
    LPSTR MultiByteString,
    INT MultiByteCount,
    LPCSTR DefaultChar,
    LPBOOL UsedDefaultChar)
{
    PCODEPAGE_ENTRY CodePageEntry;
    PCPTABLEINFO CodePageTable;
    INT TempLength;

    /* Get code page table. */
    CodePageEntry = IntGetCodePageEntry(CodePage);
    if (CodePageEntry == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    CodePageTable = &CodePageEntry->CodePageTable;


    /* Different handling for DBCS code pages. */
    if (CodePageTable->DBCSCodePage)
    {
        /* If Flags, DefaultChar or UsedDefaultChar were given, we have to do some more work */
        if (Flags || DefaultChar || UsedDefaultChar)
        {
            BOOL TempUsedDefaultChar;
            USHORT DefChar;

            /* If UsedDefaultChar is not set, set it to a temporary value, so we don't have
               to check on every character */
            if (!UsedDefaultChar)
                UsedDefaultChar = &TempUsedDefaultChar;

            *UsedDefaultChar = FALSE;

            /* Use the CodePage's TransDefaultChar if none was given. Don't modify the DefaultChar pointer here. */
            if (DefaultChar)
                DefChar = DefaultChar[1] ? ((DefaultChar[0] << 8) | DefaultChar[1]) : DefaultChar[0];
            else
                DefChar = CodePageTable->TransDefaultChar;

            /* Does caller query for output buffer size? */
            if (!MultiByteCount)
            {
                for (TempLength = 0; WideCharCount; WideCharCount--, WideCharString++, TempLength++)
                {
                    USHORT uChar;

                    if ((Flags & WC_COMPOSITECHECK) && WideCharCount > 1)
                    {
                        /* FIXME: Handle WC_COMPOSITECHECK */
                        DPRINT("WC_COMPOSITECHECK flag UNIMPLEMENTED\n");
                    }

                    uChar = ((PUSHORT)CodePageTable->WideCharTable)[*WideCharString];

                    /* Verify if the mapping is valid for handling DefaultChar and UsedDefaultChar */
                    if (!IntIsValidDBCSMapping(CodePageTable, Flags, *WideCharString, uChar))
                    {
                        uChar = DefChar;
                        *UsedDefaultChar = TRUE;
                    }

                    /* Increment TempLength again if this is a double-byte character */
                    if (uChar & 0xff00)
                        TempLength++;
                }

                return TempLength;
            }

            /* Convert the WideCharString to the MultiByteString and verify if the mapping is valid */
            for (TempLength = MultiByteCount;
                WideCharCount && TempLength;
                TempLength--, WideCharString++, WideCharCount--)
            {
                USHORT uChar;

                if ((Flags & WC_COMPOSITECHECK) && WideCharCount > 1)
                {
                    /* FIXME: Handle WC_COMPOSITECHECK */
                    DPRINT("WC_COMPOSITECHECK flag UNIMPLEMENTED\n");
                }

                uChar = ((PUSHORT)CodePageTable->WideCharTable)[*WideCharString];

                /* Verify if the mapping is valid for handling DefaultChar and UsedDefaultChar */
                if (!IntIsValidDBCSMapping(CodePageTable, Flags, *WideCharString, uChar))
                {
                    uChar = DefChar;
                    *UsedDefaultChar = TRUE;
                }

                /* Handle double-byte characters */
                if (uChar & 0xff00)
                {
                    /* Don't output a partial character */
                    if (TempLength == 1)
                        break;

                    TempLength--;
                    *MultiByteString++ = uChar >> 8;
                }

                *MultiByteString++ = (char)uChar;
            }

            /* WideCharCount should be 0 if all characters were converted */
            if (WideCharCount)
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }

            return MultiByteCount - TempLength;
        }

        /* Does caller query for output buffer size? */
        if (!MultiByteCount)
        {
            for (TempLength = 0; WideCharCount; WideCharCount--, WideCharString++, TempLength++)
            {
                /* Increment TempLength again if this is a double-byte character */
                if (((PWCHAR)CodePageTable->WideCharTable)[*WideCharString] & 0xff00)
                    TempLength++;
            }

            return TempLength;
        }

        /* Convert the WideCharString to the MultiByteString */
        for (TempLength = MultiByteCount;
            WideCharCount && TempLength;
            TempLength--, WideCharString++, WideCharCount--)
        {
            USHORT uChar = ((PUSHORT)CodePageTable->WideCharTable)[*WideCharString];

            /* Is this a double-byte character? */
            if (uChar & 0xff00)
            {
                /* Don't output a partial character */
                if (TempLength == 1)
                    break;

                TempLength--;
                *MultiByteString++ = uChar >> 8;
            }

            *MultiByteString++ = (char)uChar;
        }

        /* WideCharCount should be 0 if all characters were converted */
        if (WideCharCount)
        {
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            return 0;
        }

        return MultiByteCount - TempLength;
    }
    else /* SBCS code page */
    {
        INT nReturn;

        /* If Flags, DefaultChar or UsedDefaultChar were given, we have to do some more work */
        if (Flags || DefaultChar || UsedDefaultChar)
        {
            BOOL TempUsedDefaultChar;
            CHAR DefChar;

            /* If UsedDefaultChar is not set, set it to a temporary value, so we don't have
               to check on every character */
            if (!UsedDefaultChar)
                UsedDefaultChar = &TempUsedDefaultChar;

            *UsedDefaultChar = FALSE;

            /* Does caller query for output buffer size? */
            if (!MultiByteCount)
            {
                /* Loop through the whole WideCharString and check if we can get a valid mapping for each character */
                for (TempLength = 0; WideCharCount; TempLength++, WideCharString++, WideCharCount--)
                {
                    if ((Flags & WC_COMPOSITECHECK) && WideCharCount > 1)
                    {
                        /* FIXME: Handle WC_COMPOSITECHECK */
                        DPRINT("WC_COMPOSITECHECK flag UNIMPLEMENTED\n");
                    }

                    if (!*UsedDefaultChar)
                        *UsedDefaultChar = !IntIsValidSBCSMapping(CodePageTable,
                            Flags,
                            *WideCharString,
                            ((PCHAR)CodePageTable->WideCharTable)[*WideCharString]);
                }

                return TempLength;
            }

            /* Use the CodePage's TransDefaultChar if none was given. Don't modify the DefaultChar pointer here. */
            if (DefaultChar)
                DefChar = *DefaultChar;
            else
                DefChar = (CHAR)CodePageTable->TransDefaultChar;

            /* Convert the WideCharString to the MultiByteString and verify if the mapping is valid */
            for (TempLength = MultiByteCount;
                WideCharCount && TempLength;
                MultiByteString++, TempLength--, WideCharString++, WideCharCount--)
            {
                if ((Flags & WC_COMPOSITECHECK) && WideCharCount > 1)
                {
                    /* FIXME: Handle WC_COMPOSITECHECK */
                    DPRINT("WC_COMPOSITECHECK flag UNIMPLEMENTED\n");
                }

                *MultiByteString = ((PCHAR)CodePageTable->WideCharTable)[*WideCharString];

                if (!IntIsValidSBCSMapping(CodePageTable, Flags, *WideCharString, *MultiByteString))
                {
                    *MultiByteString = DefChar;
                    *UsedDefaultChar = TRUE;
                }
            }

            /* WideCharCount should be 0 if all characters were converted */
            if (WideCharCount)
            {
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return 0;
            }

            return MultiByteCount - TempLength;
        }

        /* Does caller query for output buffer size? */
        if (!MultiByteCount)
            return WideCharCount;

        /* Is the buffer large enough? */
        if (MultiByteCount < WideCharCount)
        {
            /* Convert the string up to MultiByteCount and return 0 */
            WideCharCount = MultiByteCount;
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            nReturn = 0;
        }
        else
        {
            /* Otherwise WideCharCount will be the number of converted characters */
            nReturn = WideCharCount;
        }

        /* Convert the WideCharString to the MultiByteString */
        for (TempLength = WideCharCount; --TempLength >= 0; WideCharString++, MultiByteString++)
        {
            *MultiByteString = ((PCHAR)CodePageTable->WideCharTable)[*WideCharString];
        }

        return nReturn;
    }
}
INT
WideCharToMultiByte(UINT CodePage,
    DWORD Flags,
    LPCWSTR WideCharString,
    INT WideCharCount,
    LPSTR MultiByteString,
    INT MultiByteCount,
    LPCSTR DefaultChar,
    LPBOOL UsedDefaultChar)
{
    /* Check the parameters. */
    if (WideCharString == NULL ||
        WideCharCount == 0 ||
        (MultiByteString == NULL && MultiByteCount > 0) ||
        (PVOID)WideCharString == (PVOID)MultiByteString ||
        MultiByteCount < 0)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    /* Determine the input string length. */
    if (WideCharCount < 0)
    {
        WideCharCount = wcslen(WideCharString) + 1;
    }

    switch (CodePage)
    {
    case CP_UTF8:
        if (DefaultChar != NULL || UsedDefaultChar != NULL)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return 0;
        }
        return IntWideCharToMultiByteUTF8(CodePage,
            Flags,
            WideCharString,
            WideCharCount,
            MultiByteString,
            MultiByteCount,
            DefaultChar,
            UsedDefaultChar);

    case CP_UTF7:
        if (DefaultChar != NULL || UsedDefaultChar != NULL)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return 0;
        }
        if (Flags)
        {
            SetLastError(ERROR_INVALID_FLAGS);
            return 0;
        }
        return WideCharToUtf7(WideCharString, WideCharCount,
            MultiByteString, MultiByteCount);

    case CP_SYMBOL:
        if ((DefaultChar != NULL) || (UsedDefaultChar != NULL))
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return 0;
        }
        return IntWideCharToMultiByteSYMBOL(Flags,
            WideCharString,
            WideCharCount,
            MultiByteString,
            MultiByteCount);

    default:
        return IntWideCharToMultiByteCP(CodePage,
            Flags,
            WideCharString,
            WideCharCount,
            MultiByteString,
            MultiByteCount,
            DefaultChar,
            UsedDefaultChar);
    }
}


FORCEINLINE
BOOLEAN
IsListEmpty(
    const LIST_ENTRY* ListHead
)
{
    return (BOOLEAN)(ListHead->Flink == ListHead);
}
FORCEINLINE
PLIST_ENTRY
RemoveHeadList(
    PLIST_ENTRY ListHead)
{
    PLIST_ENTRY Flink;
    PLIST_ENTRY Entry;

    Entry = ListHead->Flink;
    Flink = Entry->Flink;
    ListHead->Flink = Flink;
    Flink->Blink = ListHead;
    return Entry;
}
VOID
NlsUninit(VOID)
{
    PCODEPAGE_ENTRY Current;
    std::lock_guard<std::mutex> _(CodePageListLock);
    /* Delete the code page list. */
    while (!IsListEmpty(&CodePageListHead))
    {
        Current = CONTAINING_RECORD(CodePageListHead.Flink, CODEPAGE_ENTRY, Entry);
        if (Current->SectionHandle != NULL)
        {
            delete (Current->SectionMapping);
        }
        RemoveHeadList(&CodePageListHead);
    }
}
FORCEINLINE
VOID
InitializeListHead(
    PLIST_ENTRY ListHead
)
{
    ListHead->Flink = ListHead->Blink = ListHead;
}
BOOL
NlsInit(VOID)
{
    std::lock_guard<std::mutex> _(CodePageListLock);
    InitializeListHead(&CodePageListHead);
    return TRUE;
}
