#ifdef  _WINDOWS_SOURCE
#ifdef  __TRACommandAddin
#define ExportedByTRACommandAddin     __declspec(dllexport)
#else
#define ExportedByTRACommandAddin     __declspec(dllimport)
#endif
#else
#define ExportedByTRACommandAddin
#endif
