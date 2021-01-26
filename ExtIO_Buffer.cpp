#include "pch.h"
#include "LC_ExtIO_Types.h"
#include "ExtIO_Buffer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <stdint.h>

// [Start of generated code block]
// Pointer function variables
// PFN: BEGIN
pfnInitHW x_InitHW;
pfnOpenHW x_OpenHW;
pfnCloseHW x_CloseHW;
pfnStartHW x_StartHW;
pfnStopHW x_StopHW;
pfnSetCallback x_SetCallback;
pfnSetHWLO x_SetHWLO;
pfnGetStatus x_GetStatus;
pfnGetHWLO x_GetHWLO;
pfnGetHWSR x_GetHWSR;
pfnShowGUI x_ShowGUI;
pfnHideGUI x_HideGUI;
pfnSwitchGUI x_SwitchGUI;
pfnTuneChanged x_TuneChanged;
pfnGetTune x_GetTune;
pfnModeChanged x_ModeChanged;
pfnStartHW64 x_StartHW64;
pfnSetHWLO64 x_SetHWLO64;
pfnGetHWLO64 x_GetHWLO64;
pfnTuneChanged64 x_TuneChanged64;
pfnGetTune64 x_GetTune64;
pfnVersionInfo x_VersionInfo;
pfnExtIoGetSrates x_ExtIoGetSrates;
pfnExtIoGetActualSrateIdx x_ExtIoGetActualSrateIdx;
pfnExtIoSetSrate x_ExtIoSetSrate;
pfnExtIoGetBandwidth x_ExtIoGetBandwidth;
pfnExtIoGetSetting x_ExtIoGetSetting;
pfnExtIoSetSetting x_ExtIoSetSetting;
// PFN: END
// [End of generated code block]

pfnExtIOCallback appCallback;

HINSTANCE extIO;
int bufferMultiplier = 1;
int xIqPairsPerCall = 0;
int bufferIqPairsPerCall = 0;
int hwTypeReported = 0;
void* buffer;
unsigned int bufferIndex = 0;
size_t bufferSize;
BOOL buffering = FALSE;
int bytesPerCallback = 0;

BOOL debug = TRUE;
int appHits = 0;

BOOL dllInit() {
    BOOL retVal = FALSE;
    std::wstring cfgBufferMultiplier;

    if (debug) std::cout << "[ExtIO_Buffer] dllInit" << std::endl;

    std::wifstream cfgFile(L"ExtIO_Buffer.cfg");

    if (cfgFile.is_open()) {
        if (!getline(cfgFile, cfgBufferMultiplier)) {
            std::cerr << "[ExtIO_Buffer] Buffer multiplier not found in ExtIO_Buffer.cfg" << std::endl;
            cfgFile.close();
            return FALSE;
        }
        try {
            bufferMultiplier = std::stoi(cfgBufferMultiplier);
        }
        catch (const std::invalid_argument& ia) {
            (void)ia;
            std::cerr << "[ExtIO_Buffer] Buffer multiplier not valid" << std::endl;
            cfgFile.close();
            return FALSE;
        }
        cfgFile.close();
    }
    else {
        std::cerr << "[ExtIO_Buffer] Could not open ExtIO_Buffer.cfg" << std::endl;
        return FALSE;
    }
    
    // [Start of generated code block]
    // Pointer function variables
    // DLLINIT: BEGIN
	LPCWSTR dllName = L"ExtIO_ICR8600.dll";
	extIO = LoadLibrary(L"ExtIO_ICR8600.dll");

	if (extIO) {
		x_InitHW = (pfnInitHW)GetProcAddress(extIO, "InitHW");
		x_OpenHW = (pfnOpenHW)GetProcAddress(extIO, "OpenHW");
		x_CloseHW = (pfnCloseHW)GetProcAddress(extIO, "CloseHW");
		x_StartHW = (pfnStartHW)GetProcAddress(extIO, "StartHW");
		x_StopHW = (pfnStopHW)GetProcAddress(extIO, "StopHW");
		x_SetCallback = (pfnSetCallback)GetProcAddress(extIO, "SetCallback");
		x_SetHWLO = (pfnSetHWLO)GetProcAddress(extIO, "SetHWLO");
		x_GetStatus = (pfnGetStatus)GetProcAddress(extIO, "GetStatus");
		x_GetHWLO = (pfnGetHWLO)GetProcAddress(extIO, "GetHWLO");
		x_GetHWSR = (pfnGetHWSR)GetProcAddress(extIO, "GetHWSR");
		x_ShowGUI = (pfnShowGUI)GetProcAddress(extIO, "ShowGUI");
		x_HideGUI = (pfnHideGUI)GetProcAddress(extIO, "HideGUI");
		x_SwitchGUI = (pfnSwitchGUI)GetProcAddress(extIO, "SwitchGUI");
		x_TuneChanged = (pfnTuneChanged)GetProcAddress(extIO, "TuneChanged");
		x_GetTune = (pfnGetTune)GetProcAddress(extIO, "GetTune");
		x_ModeChanged = (pfnModeChanged)GetProcAddress(extIO, "ModeChanged");
		x_StartHW64 = (pfnStartHW64)GetProcAddress(extIO, "StartHW64");
		x_SetHWLO64 = (pfnSetHWLO64)GetProcAddress(extIO, "SetHWLO64");
		x_GetHWLO64 = (pfnGetHWLO64)GetProcAddress(extIO, "GetHWLO64");
		x_TuneChanged64 = (pfnTuneChanged64)GetProcAddress(extIO, "TuneChanged64");
		x_GetTune64 = (pfnGetTune64)GetProcAddress(extIO, "GetTune64");
		x_VersionInfo = (pfnVersionInfo)GetProcAddress(extIO, "VersionInfo");
		x_ExtIoGetSrates = (pfnExtIoGetSrates)GetProcAddress(extIO, "ExtIoGetSrates");
		x_ExtIoGetActualSrateIdx = (pfnExtIoGetActualSrateIdx)GetProcAddress(extIO, "ExtIoGetActualSrateIdx");
		x_ExtIoSetSrate = (pfnExtIoSetSrate)GetProcAddress(extIO, "ExtIoSetSrate");
		x_ExtIoGetBandwidth = (pfnExtIoGetBandwidth)GetProcAddress(extIO, "ExtIoGetBandwidth");
		x_ExtIoGetSetting = (pfnExtIoGetSetting)GetProcAddress(extIO, "ExtIoGetSetting");
		x_ExtIoSetSetting = (pfnExtIoSetSetting)GetProcAddress(extIO, "ExtIoSetSetting");
        // DLLINIT: END
        // [End of generated code block]

        if (debug) std::wcout << "[ExtIO_Buffer] Initialized DLL " << dllName << std::endl;


        retVal = TRUE;
    }
    else {
        std::wcerr << "[ExtIO_Buffer] Error loading DLL " << dllName << std::endl;
        retVal = FALSE;
    }
    return retVal;
}

void dllExit() {
    if (debug) std::cout << "[ExtIO_Buffer] dllExit" << std::endl;
    if (debug) std::cout << "[ExtIO_Buffer] App Hits = " << appHits << std::endl;

    if (buffer) {
        free(buffer);
    }
}

int createBuffer() {
    if (debug) std::cout << "[ExtIO_Buffer] Original IQ pairs per call = " << xIqPairsPerCall << std::endl;

    bufferIqPairsPerCall = xIqPairsPerCall * bufferMultiplier;
    if (debug) std::cout << "[ExtIO_Buffer] Buffer IQ pairs per call = " << bufferIqPairsPerCall << std::endl;

    // Create the proper buffer size
    int bytesPerPair = 0;
    bufferIndex = 0;

    switch ((extHWtypeT)hwTypeReported) {
    case exthwUSBdataU8:
    case exthwUSBdataS8:
        bytesPerPair = 2;
    case exthwUSBdata16:
        bytesPerPair = 4;
        break;
    case exthwUSBdata24:
        bytesPerPair = 6;
        break;
    case exthwUSBdata32:
    case exthwUSBfloat32:
    case exthwFullPCM32:
        bytesPerPair = 8;
        break;
    default:
        bytesPerPair = 0;
        break;
    }

    if (bytesPerPair != 0) {
        bytesPerCallback = bytesPerPair * xIqPairsPerCall;
        bufferSize = (size_t)(bytesPerPair * bufferIqPairsPerCall);
        buffer = malloc(bufferSize);
        if (!buffer) {
            std::cerr << "[ExtIO_Buffer] Could not allocate buffer" << std::endl;
            buffering = FALSE;
        }
        else {
            buffering = TRUE;
            if (debug) std::cout << "[ExtIO_Buffer] Buffer size (bytes) = " << bufferSize << std::endl;
        }
    }
    else {
        std::cerr << "[ExtIO_Buffer] Unsupported hwtype = " << hwTypeReported << std::endl;
        buffering = FALSE;
    }

    // Return the new iqPairs per call
    if (buffering)
        return bufferIqPairsPerCall;
    else
        return xIqPairsPerCall;
}

int bufferCallback(int cnt, int status, float IQoffs, void* IQdata) {
    if (buffering) {
        // buffer, then call if full
        if (cnt > 0) {
            // Data
            uint8_t* buf = (uint8_t*)buffer;
            memcpy(&buf[bufferIndex], IQdata, bytesPerCallback);
            bufferIndex += bytesPerCallback;
            if (bufferIndex >= bufferSize) {
                bufferIndex = 0;
                appHits++;
                return appCallback(bufferIqPairsPerCall, status, IQoffs, buffer);
            }
            else {
                return 0;
            }
        }
        else {
            // Info

            // ** it is possible format changes while running ***
            // TODO: handle this...
            // following status codes to change sampleformat at runtime
            //            , extHw_SampleFmt_IQ_UINT8 = 126   // change sample format to unsigned 8 bit INT (Realtek RTL2832U)
            //                , extHw_SampleFmt_IQ_INT16 = 127   //           -"-           signed 16 bit INT
            //                , extHw_SampleFmt_IQ_INT24 = 128   //           -"-           signed 24 bit INT
            //                , extHw_SampleFmt_IQ_INT32 = 129   //           -"-           signed 32 bit INT
            //                , extHw_SampleFmt_IQ_FLT32 = 130   //           -"-           signed 16 bit FLOAT

            return appCallback(cnt, status, IQoffs, IQdata);
        }
    }
    else {
        // just call the app callback as is
        return appCallback(cnt, status, IQoffs, IQdata);
    }
}

// Create cross DLL calls

/*
Tricky bits...

In order to create the proper buffer size, need to obtain the hwtype
when InitHW() is called, and need to obtain the number of IQ pairs
returned for each callback, which is reported when StartHW() is called.

To perform the acutal buffering, also need to intercept the
SetCallback() function to insert our own callback
*/

// [Start of generated code block]
// Pointer function variables
// FNCALLS: BEGIN

bool __stdcall InitHW(char* name, char* model, int& hwtype) {
	bool retVal;

	retVal = x_InitHW(name, model, hwtype);
	hwTypeReported = hwtype;

	if (debug) std::cout << "[ExtIO_Buffer] hwtype = " << hwTypeReported << std::endl;

	return retVal;
}
bool __stdcall OpenHW(void) {
	return x_OpenHW();
}

void __stdcall CloseHW(void) {
	return x_CloseHW();
}


int __stdcall StartHW(long extLOfreq) {

	xIqPairsPerCall = x_StartHW(extLOfreq);
	return(createBuffer());
}
void __stdcall StopHW(void) {
	return x_StopHW();
}


void __stdcall SetCallback(pfnExtIOCallback funcptr) {
	// intercept callback functions with our own
	if (debug) std::cout << "[ExtIO_Buffer] Redirecting callback" << std::endl;
	appCallback = funcptr;
	return x_SetCallback(bufferCallback);
}
int __stdcall SetHWLO(long extLOfreq) {
	return x_SetHWLO(extLOfreq);
}

int __stdcall GetStatus(void) {
	return x_GetStatus();
}

long __stdcall GetHWLO(void) {
	return x_GetHWLO();
}

long __stdcall GetHWSR(void) {
	return x_GetHWSR();
}

void __stdcall ShowGUI(void) {
	return x_ShowGUI();
}

void __stdcall HideGUI(void) {
	return x_HideGUI();
}

void __stdcall SwitchGUI(void) {
	return x_SwitchGUI();
}

void __stdcall TuneChanged(long tunefreq) {
	return x_TuneChanged(tunefreq);
}

long __stdcall GetTune(void) {
	return x_GetTune();
}

void __stdcall ModeChanged(char mode) {
	return x_ModeChanged(mode);
}


int __stdcall StartHW64(int64_t extLOfreq) {
	xIqPairsPerCall = x_StartHW64(extLOfreq);
	return(createBuffer());
}
int64_t __stdcall SetHWLO64(int64_t extLOfreq) {
	return x_SetHWLO64(extLOfreq);
}

int64_t __stdcall GetHWLO64(void) {
	return x_GetHWLO64();
}

void __stdcall TuneChanged64(int64_t tunefreq) {
	return x_TuneChanged64(tunefreq);
}

int64_t __stdcall GetTune64(void) {
	return x_GetTune64();
}

void __stdcall VersionInfo(const char * progname, int ver_major, int ver_minor) {
	return x_VersionInfo(progname,ver_major,ver_minor);
}

int __stdcall ExtIoGetSrates(int idx, double * samplerate) {
	return x_ExtIoGetSrates(idx,samplerate);
}

int __stdcall ExtIoGetActualSrateIdx(void) {
	return x_ExtIoGetActualSrateIdx();
}

int __stdcall ExtIoSetSrate(int idx) {
	return x_ExtIoSetSrate(idx);
}

long __stdcall ExtIoGetBandwidth(int srate_idx) {
	return x_ExtIoGetBandwidth(srate_idx);
}

int __stdcall ExtIoGetSetting( int idx, char * description, char * value ) {
	return x_ExtIoGetSetting(idx,description,value);
}

void __stdcall ExtIoSetSetting( int idx, const char * value ) {
	return x_ExtIoSetSetting(idx,value);
}

// FNCALLS: END
// [End of generated code block]
