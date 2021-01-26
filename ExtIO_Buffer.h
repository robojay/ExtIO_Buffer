#pragma once
#include <stdint.h>
#include "LC_ExtIO_Types.h"

// [Start of generated code block]
// Exported ExtIO DLL calls
// Insert into .h file
//extern "C" int __declspec(dllexport) __stdcall ExtIOCallback(int cnt, int status, float IQoffs, void* IQdata);
extern "C" bool __declspec(dllexport) __stdcall InitHW(char* name, char* model, int& hwtype);
extern "C" bool __declspec(dllexport) __stdcall OpenHW(void);
extern "C" void __declspec(dllexport) __stdcall CloseHW(void);
extern "C" int __declspec(dllexport) __stdcall StartHW(long extLOfreq);
extern "C" void __declspec(dllexport) __stdcall StopHW(void);
extern "C" void __declspec(dllexport) __stdcall SetCallback(pfnExtIOCallback funcptr);
extern "C" int __declspec(dllexport) __stdcall SetHWLO(long extLOfreq);
extern "C" int __declspec(dllexport) __stdcall GetStatus(void);
extern "C" long __declspec(dllexport) __stdcall GetHWLO(void);
extern "C" long __declspec(dllexport) __stdcall GetHWSR(void);
extern "C" void __declspec(dllexport) __stdcall RawDataReady(long samprate, void* Ldata, void* Rdata, int numsamples);
extern "C" void __declspec(dllexport) __stdcall ShowGUI(void);
extern "C" void __declspec(dllexport) __stdcall HideGUI(void);
extern "C" void __declspec(dllexport) __stdcall SwitchGUI(void);
extern "C" void __declspec(dllexport) __stdcall TuneChanged(long tunefreq);
extern "C" long __declspec(dllexport) __stdcall GetTune(void);
extern "C" void __declspec(dllexport) __stdcall ModeChanged(char mode);
extern "C" char __declspec(dllexport) __stdcall GetMode(void);
extern "C" void __declspec(dllexport) __stdcall IFLimitsChanged(long lowfreq, long highfreq);
extern "C" void __declspec(dllexport) __stdcall FiltersChanged(int loCut, int hiCut, int pitch);
extern "C" void __declspec(dllexport) __stdcall MuteChanged(bool muted);
extern "C" void __declspec(dllexport) __stdcall GetFilters(int& loCut, int& hiCut, int& pitch);
extern "C" int __declspec(dllexport) __stdcall StartHW64(int64_t extLOfreq);
extern "C" int64_t __declspec(dllexport) __stdcall SetHWLO64(int64_t extLOfreq);
extern "C" int64_t __declspec(dllexport) __stdcall GetHWLO64(void);
extern "C" void __declspec(dllexport) __stdcall TuneChanged64(int64_t tunefreq);
extern "C" int64_t __declspec(dllexport) __stdcall GetTune64(void);
extern "C" void __declspec(dllexport) __stdcall IFLimitsChanged64(int64_t lowfreq, int64_t highfreq);
extern "C" int __declspec(dllexport) __stdcall StartHW_dbl(double extLOfreq);
extern "C" double __declspec(dllexport) __stdcall SetHWLO_dbl(double extLOfreq);
extern "C" double __declspec(dllexport) __stdcall GetHWLO_dbl(void);
extern "C" void __declspec(dllexport) __stdcall TuneChanged_dbl(double tunefreq);
extern "C" double __declspec(dllexport) __stdcall GetTune_dbl(void);
extern "C" void __declspec(dllexport) __stdcall IFLimitsChanged_dbl(double lowfreq, double highfreq);
extern "C" void __declspec(dllexport) __stdcall VersionInfo(const char* progname, int ver_major, int ver_minor);
extern "C" int __declspec(dllexport) __stdcall GetAttenuators(int idx, float* attenuation);
extern "C" int __declspec(dllexport) __stdcall GetActualAttIdx(void);
extern "C" int __declspec(dllexport) __stdcall SetAttenuator(int idx);
extern "C" int __declspec(dllexport) __stdcall SetModeRxTx(int modeRxTx);
extern "C" int __declspec(dllexport) __stdcall ActivateTx(int magicA, int magicB);
extern "C" int __declspec(dllexport) __stdcall DeactivateBP(int deactivate);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetSrates(int idx, double* samplerate);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetActualSrateIdx(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoSetSrate(int idx);
extern "C" long __declspec(dllexport) __stdcall ExtIoGetBandwidth(int srate_idx);
extern "C" long __declspec(dllexport) __stdcall ExtIoGetBwCenter(int srate_idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetAGCs(int agc_idx, char* text);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetActualAGCidx(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoSetAGC(int agc_idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoShowMGC(int agc_idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetMGCs(int mgc_idx, float* gain);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetActualMgcIdx(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoSetMGC(int mgc_idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetPresels(int idx, int64_t * freq_low, int64_t * freq_high);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetActualPreselIdx(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoSetPresel(int idx);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetFreqRanges(int idx, int64_t * freq_low, int64_t * freq_high);
extern "C" double __declspec(dllexport) __stdcall ExtIoGetAdcSrate(void);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetSetting(int idx, char* description, char* value);
extern "C" void __declspec(dllexport) __stdcall ExtIoSetSetting(int idx, const char* value);
extern "C" void __declspec(dllexport) __stdcall ExtIoVFOchanged(int VFOindex, int numVFO, int64_t extLOfreq, int64_t tunefreq, char mode);
extern "C" int __declspec(dllexport) __stdcall ExtIoGetVFOindex(void);
extern "C" void __declspec(dllexport) __stdcall ExtIoSDRInfo(int extSDRInfo, int additionalValue, void* additionalPtr);

// [End of generated code block]


BOOL dllInit();
void dllExit();
