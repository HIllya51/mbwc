从reactos中提取出来的WideCharToMultiByte&MultiByteToWideChar，nls文件来自windows/system32，从而可在Linux上像windows一样处理unicode字符串

首先使用NlsInit初始化，并使用SetNlsFileStoragePath设置nls文件所在路径。最后使用NlsUninit释放资源。

<!-- https://github.com/tongzx/nt5src/blob/master/Source/XPSP1/NT/base/win32/winnls/mbcs.c -->
