#ifdef  _WINDOWS_SOURCE
#ifdef  __TRAICreateLineFWItfCPP
#define ExportedByTRAICreateLineFWItfCPP     __declspec(dllexport)
#else
#define ExportedByTRAICreateLineFWItfCPP     __declspec(dllimport)
#endif
#else
#define ExportedByTRAICreateLineFWItfCPP
#endif
