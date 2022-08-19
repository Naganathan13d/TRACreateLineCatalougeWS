#ifdef  _WINDOWS_SOURCE
#ifdef  __TRAUtilitesMod
#define ExportedByTRAUtilitesMod     __declspec(dllexport)
#else
#define ExportedByTRAUtilitesMod     __declspec(dllimport)
#endif
#else
#define ExportedByTRAUtilitesMod
#endif
