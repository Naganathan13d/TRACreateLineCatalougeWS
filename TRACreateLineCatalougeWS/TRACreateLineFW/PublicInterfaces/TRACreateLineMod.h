#ifdef  _WINDOWS_SOURCE
#ifdef  __TRACreateLineMod
#define ExportedByTRACreateLineMod     __declspec(dllexport)
#else
#define ExportedByTRACreateLineMod     __declspec(dllimport)
#endif
#else
#define ExportedByTRACreateLineMod
#endif
