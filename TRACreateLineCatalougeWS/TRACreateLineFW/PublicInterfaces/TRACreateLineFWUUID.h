#ifdef  _WINDOWS_SOURCE
#ifdef  __TRACreateLineFWUUID
#define ExportedByTRACreateLineFWUUID     __declspec(dllexport)
#else
#define ExportedByTRACreateLineFWUUID     __declspec(dllimport)
#endif
#else
#define ExportedByTRACreateLineFWUUID
#endif
