#pragma once
#include <stdint.h>
#include "LC_ExtIO_Types.h"

// [Start of generated code block]
// Exported ExtIO DLL calls
// EXTERN: BEGIN
extern "C" bool __declspec(dllexport) __stdcall InitHW(char *name, char *model, int& hwtype);
extern "C" bool __declspec(dllexport) __stdcall OpenHW(void);
extern "C" void __declspec(dllexport) __stdcall CloseHW(void);
extern "C" int __declspec(dllexport) __stdcall StartHW(long extLOfreq);
extern "C" void __declspec(dllexport) __stdcall StopHW(void);
extern "C" void __declspec(dllexport) __stdcall SetCallback(pfnExtIOCallback funcptr);
extern "C" int __declspec(dllexport) __stdcall SetHWLO(long extLOfreq);
extern "C" int __declspec(dllexport) __stdcall GetStatus(void);
extern "C" long __declspec(dllexport) __stdcall GetHWLO(void);
extern "C" long __declspec(dllexport) __stdcall GetHWSR(void);
extern "C" void __declspec(dllexport) __stdcall ShowGUI(void);
extern "C" void __declspec(dllexport) __stdcall HideGUI(void);
extern "C" void __declspec(dllexport) __stdcall SwitchGUI(void);
extern "C" void __declspec(dllexport) __stdcall TuneChanged(long tunefreq);
extern "C" long __declspec(dllexport) __stdcall GetTune(void);
extern "C" void __declspec(dllexport) __stdcall ModeChanged(char mode);
extern "C" int __declspec(dllexport) __stdcall StartHW64(int64_t extLOfreq);
extern "C" int64_t __declspec(dllexport) __stdcall SetHWLO64(int64_t extLOfreq);
extern "C" int64_t __declspec(dllexport) __stdcall GetHWLO64(void);
extern "C" void __declspec(dllexport) __stdcall TuneChanged64(int64_t tunefreq);
extern "C" int64_t __declspec(dllexport) __stdcall GetTune64(void);
extern "C" void __declspec(dllexport) __stdcall VersionInfo(const char * progname, int ver_major, int ver_minor);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetSrates(int idx, double * samplerate);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetActualSrateIdx(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoSetSrate(int idx);
extern "C" long __declspec(dllexport) __stdcall ExtIoGetBandwidth(int srate_idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetSetting( int idx, char * description, char * value );
extern "C" void __declspec(dllexport) __stdcall ExtIoSetSetting( int idx, const char * value );
// EXTERN: END
// [End of generated code block]

BOOL dllInit();
void dllExit();
