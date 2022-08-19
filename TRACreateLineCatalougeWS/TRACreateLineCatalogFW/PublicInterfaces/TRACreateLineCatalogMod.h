#ifdef  _WINDOWS_SOURCE
#ifdef  __TRACreateLineCatalogMod
#define ExportedByTRACreateLineCatalogMod     __declspec(dllexport)
#else
#define ExportedByTRACreateLineCatalogMod     __declspec(dllimport)
#endif
#else
#define ExportedByTRACreateLineCatalogMod
#endif
