#ifdef  _WINDOWS_SOURCE
#ifdef  __TRADlgStCmdMod
#define ExportedByTRADlgStCmdMod     __declspec(dllexport)
#else
#define ExportedByTRADlgStCmdMod     __declspec(dllimport)
#endif
#else
#define ExportedByTRADlgStCmdMod
#endif
