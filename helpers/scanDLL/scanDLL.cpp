// scanDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <iostream>
#include "LC_ExtIO_Types.h"

// DO NOT EDIT THIS!!!
// SCRIPT GENERATED CODE!!!
// PFN: BEGIN
pfnInitHW InitHW;
pfnOpenHW OpenHW;
pfnCloseHW CloseHW;
pfnStartHW StartHW;
pfnStopHW StopHW;
pfnSetCallback SetCallback;
pfnSetHWLO SetHWLO;
pfnGetStatus GetStatus;
pfnGetHWLO GetHWLO;
pfnGetHWSR GetHWSR;
pfnRawDataReady RawDataReady;
pfnShowGUI ShowGUI;
pfnHideGUI HideGUI;
pfnSwitchGUI SwitchGUI;
pfnTuneChanged TuneChanged;
pfnGetTune GetTune;
pfnModeChanged ModeChanged;
pfnGetMode GetMode;
pfnIFLimitsChanged IFLimitsChanged;
pfnFiltersChanged FiltersChanged;
pfnMuteChanged MuteChanged;
pfnGetFilters GetFilters;
pfnStartHW64 StartHW64;
pfnSetHWLO64 SetHWLO64;
pfnGetHWLO64 GetHWLO64;
pfnTuneChanged64 TuneChanged64;
pfnGetTune64 GetTune64;
pfnIFLimitsChanged64 IFLimitsChanged64;
pfnStartHW_dbl StartHW_dbl;
pfnSetHWLO_dbl SetHWLO_dbl;
pfnGetHWLO_dbl GetHWLO_dbl;
pfnTuneChanged_dbl TuneChanged_dbl;
pfnGetTune_dbl GetTune_dbl;
pfnIFLimitsChanged_dbl IFLimitsChanged_dbl;
pfnVersionInfo VersionInfo;
pfnGetAttenuators GetAttenuators;
pfnGetActualAttIdx GetActualAttIdx;
pfnSetAttenuator SetAttenuator;
pfnSetModeRxTx SetModeRxTx;
pfnActivateTx ActivateTx;
pfnDeactivateBP DeactivateBP;
pfnExtIoGetSrates ExtIoGetSrates;
pfnExtIoGetActualSrateIdx ExtIoGetActualSrateIdx;
pfnExtIoSetSrate ExtIoSetSrate;
pfnExtIoGetBandwidth ExtIoGetBandwidth;
pfnExtIoGetBwCenter ExtIoGetBwCenter;
pfnExtIoGetAGCs ExtIoGetAGCs;
pfnExtIoGetActualAGCidx ExtIoGetActualAGCidx;
pfnExtIoSetAGC ExtIoSetAGC;
pfnExtIoShowMGC ExtIoShowMGC;
pfnExtIoGetMGCs ExtIoGetMGCs;
pfnExtIoGetActualMgcIdx ExtIoGetActualMgcIdx;
pfnExtIoSetMGC ExtIoSetMGC;
pfnExtIoGetPresels ExtIoGetPresels;
pfnExtIoGetActualPreselIdx ExtIoGetActualPreselIdx;
pfnExtIoSetPresel ExtIoSetPresel;
pfnExtIoGetFreqRanges ExtIoGetFreqRanges;
pfnExtIoGetAdcSrate ExtIoGetAdcSrate;
pfnExtIoGetSetting ExtIoGetSetting;
pfnExtIoSetSetting ExtIoSetSetting;
pfnExtIoVFOchanged ExtIoVFOchanged;
pfnExtIoGetVFOindex ExtIoGetVFOindex;
pfnExtIoSDRInfo ExtIoSDRInfo;
// PFN: END

int main()
{
	LPWSTR* argv;
	int argc;

	argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argv == NULL)
	{
		std::cerr << "Usage: scanDLL.exe <ExtIO DLL File Name>" << std::endl;
		return -1;
	}

    if (argc < 2) {
		std::wcerr << "Usage: " << argv[0] << " <ExtIO DLL File Name>" << std::endl;
		return -1;
	}

    HINSTANCE extIO;

	extIO = LoadLibrary(argv[1]);

	// DO NOT EDIT THIS!!!
	// SCRIPT GENERATED CODE!!!
	// MAIN: BEGIN
	InitHW = (pfnInitHW)GetProcAddress(extIO, "InitHW");
	if (InitHW != NULL) std::cout << "InitHW" << std::endl;

	OpenHW = (pfnOpenHW)GetProcAddress(extIO, "OpenHW");
	if (OpenHW != NULL) std::cout << "OpenHW" << std::endl;

	CloseHW = (pfnCloseHW)GetProcAddress(extIO, "CloseHW");
	if (CloseHW != NULL) std::cout << "CloseHW" << std::endl;

	StartHW = (pfnStartHW)GetProcAddress(extIO, "StartHW");
	if (StartHW != NULL) std::cout << "StartHW" << std::endl;

	StopHW = (pfnStopHW)GetProcAddress(extIO, "StopHW");
	if (StopHW != NULL) std::cout << "StopHW" << std::endl;

	SetCallback = (pfnSetCallback)GetProcAddress(extIO, "SetCallback");
	if (SetCallback != NULL) std::cout << "SetCallback" << std::endl;

	SetHWLO = (pfnSetHWLO)GetProcAddress(extIO, "SetHWLO");
	if (SetHWLO != NULL) std::cout << "SetHWLO" << std::endl;

	GetStatus = (pfnGetStatus)GetProcAddress(extIO, "GetStatus");
	if (GetStatus != NULL) std::cout << "GetStatus" << std::endl;

	GetHWLO = (pfnGetHWLO)GetProcAddress(extIO, "GetHWLO");
	if (GetHWLO != NULL) std::cout << "GetHWLO" << std::endl;

	GetHWSR = (pfnGetHWSR)GetProcAddress(extIO, "GetHWSR");
	if (GetHWSR != NULL) std::cout << "GetHWSR" << std::endl;

	RawDataReady = (pfnRawDataReady)GetProcAddress(extIO, "RawDataReady");
	if (RawDataReady != NULL) std::cout << "RawDataReady" << std::endl;

	ShowGUI = (pfnShowGUI)GetProcAddress(extIO, "ShowGUI");
	if (ShowGUI != NULL) std::cout << "ShowGUI" << std::endl;

	HideGUI = (pfnHideGUI)GetProcAddress(extIO, "HideGUI");
	if (HideGUI != NULL) std::cout << "HideGUI" << std::endl;

	SwitchGUI = (pfnSwitchGUI)GetProcAddress(extIO, "SwitchGUI");
	if (SwitchGUI != NULL) std::cout << "SwitchGUI" << std::endl;

	TuneChanged = (pfnTuneChanged)GetProcAddress(extIO, "TuneChanged");
	if (TuneChanged != NULL) std::cout << "TuneChanged" << std::endl;

	GetTune = (pfnGetTune)GetProcAddress(extIO, "GetTune");
	if (GetTune != NULL) std::cout << "GetTune" << std::endl;

	ModeChanged = (pfnModeChanged)GetProcAddress(extIO, "ModeChanged");
	if (ModeChanged != NULL) std::cout << "ModeChanged" << std::endl;

	GetMode = (pfnGetMode)GetProcAddress(extIO, "GetMode");
	if (GetMode != NULL) std::cout << "GetMode" << std::endl;

	IFLimitsChanged = (pfnIFLimitsChanged)GetProcAddress(extIO, "IFLimitsChanged");
	if (IFLimitsChanged != NULL) std::cout << "IFLimitsChanged" << std::endl;

	FiltersChanged = (pfnFiltersChanged)GetProcAddress(extIO, "FiltersChanged");
	if (FiltersChanged != NULL) std::cout << "FiltersChanged" << std::endl;

	MuteChanged = (pfnMuteChanged)GetProcAddress(extIO, "MuteChanged");
	if (MuteChanged != NULL) std::cout << "MuteChanged" << std::endl;

	GetFilters = (pfnGetFilters)GetProcAddress(extIO, "GetFilters");
	if (GetFilters != NULL) std::cout << "GetFilters" << std::endl;

	StartHW64 = (pfnStartHW64)GetProcAddress(extIO, "StartHW64");
	if (StartHW64 != NULL) std::cout << "StartHW64" << std::endl;

	SetHWLO64 = (pfnSetHWLO64)GetProcAddress(extIO, "SetHWLO64");
	if (SetHWLO64 != NULL) std::cout << "SetHWLO64" << std::endl;

	GetHWLO64 = (pfnGetHWLO64)GetProcAddress(extIO, "GetHWLO64");
	if (GetHWLO64 != NULL) std::cout << "GetHWLO64" << std::endl;

	TuneChanged64 = (pfnTuneChanged64)GetProcAddress(extIO, "TuneChanged64");
	if (TuneChanged64 != NULL) std::cout << "TuneChanged64" << std::endl;

	GetTune64 = (pfnGetTune64)GetProcAddress(extIO, "GetTune64");
	if (GetTune64 != NULL) std::cout << "GetTune64" << std::endl;

	IFLimitsChanged64 = (pfnIFLimitsChanged64)GetProcAddress(extIO, "IFLimitsChanged64");
	if (IFLimitsChanged64 != NULL) std::cout << "IFLimitsChanged64" << std::endl;

	StartHW_dbl = (pfnStartHW_dbl)GetProcAddress(extIO, "StartHW_dbl");
	if (StartHW_dbl != NULL) std::cout << "StartHW_dbl" << std::endl;

	SetHWLO_dbl = (pfnSetHWLO_dbl)GetProcAddress(extIO, "SetHWLO_dbl");
	if (SetHWLO_dbl != NULL) std::cout << "SetHWLO_dbl" << std::endl;

	GetHWLO_dbl = (pfnGetHWLO_dbl)GetProcAddress(extIO, "GetHWLO_dbl");
	if (GetHWLO_dbl != NULL) std::cout << "GetHWLO_dbl" << std::endl;

	TuneChanged_dbl = (pfnTuneChanged_dbl)GetProcAddress(extIO, "TuneChanged_dbl");
	if (TuneChanged_dbl != NULL) std::cout << "TuneChanged_dbl" << std::endl;

	GetTune_dbl = (pfnGetTune_dbl)GetProcAddress(extIO, "GetTune_dbl");
	if (GetTune_dbl != NULL) std::cout << "GetTune_dbl" << std::endl;

	IFLimitsChanged_dbl = (pfnIFLimitsChanged_dbl)GetProcAddress(extIO, "IFLimitsChanged_dbl");
	if (IFLimitsChanged_dbl != NULL) std::cout << "IFLimitsChanged_dbl" << std::endl;

	VersionInfo = (pfnVersionInfo)GetProcAddress(extIO, "VersionInfo");
	if (VersionInfo != NULL) std::cout << "VersionInfo" << std::endl;

	GetAttenuators = (pfnGetAttenuators)GetProcAddress(extIO, "GetAttenuators");
	if (GetAttenuators != NULL) std::cout << "GetAttenuators" << std::endl;

	GetActualAttIdx = (pfnGetActualAttIdx)GetProcAddress(extIO, "GetActualAttIdx");
	if (GetActualAttIdx != NULL) std::cout << "GetActualAttIdx" << std::endl;

	SetAttenuator = (pfnSetAttenuator)GetProcAddress(extIO, "SetAttenuator");
	if (SetAttenuator != NULL) std::cout << "SetAttenuator" << std::endl;

	SetModeRxTx = (pfnSetModeRxTx)GetProcAddress(extIO, "SetModeRxTx");
	if (SetModeRxTx != NULL) std::cout << "SetModeRxTx" << std::endl;

	ActivateTx = (pfnActivateTx)GetProcAddress(extIO, "ActivateTx");
	if (ActivateTx != NULL) std::cout << "ActivateTx" << std::endl;

	DeactivateBP = (pfnDeactivateBP)GetProcAddress(extIO, "DeactivateBP");
	if (DeactivateBP != NULL) std::cout << "DeactivateBP" << std::endl;

	ExtIoGetSrates = (pfnExtIoGetSrates)GetProcAddress(extIO, "ExtIoGetSrates");
	if (ExtIoGetSrates != NULL) std::cout << "ExtIoGetSrates" << std::endl;

	ExtIoGetActualSrateIdx = (pfnExtIoGetActualSrateIdx)GetProcAddress(extIO, "ExtIoGetActualSrateIdx");
	if (ExtIoGetActualSrateIdx != NULL) std::cout << "ExtIoGetActualSrateIdx" << std::endl;

	ExtIoSetSrate = (pfnExtIoSetSrate)GetProcAddress(extIO, "ExtIoSetSrate");
	if (ExtIoSetSrate != NULL) std::cout << "ExtIoSetSrate" << std::endl;

	ExtIoGetBandwidth = (pfnExtIoGetBandwidth)GetProcAddress(extIO, "ExtIoGetBandwidth");
	if (ExtIoGetBandwidth != NULL) std::cout << "ExtIoGetBandwidth" << std::endl;

	ExtIoGetBwCenter = (pfnExtIoGetBwCenter)GetProcAddress(extIO, "ExtIoGetBwCenter");
	if (ExtIoGetBwCenter != NULL) std::cout << "ExtIoGetBwCenter" << std::endl;

	ExtIoGetAGCs = (pfnExtIoGetAGCs)GetProcAddress(extIO, "ExtIoGetAGCs");
	if (ExtIoGetAGCs != NULL) std::cout << "ExtIoGetAGCs" << std::endl;

	ExtIoGetActualAGCidx = (pfnExtIoGetActualAGCidx)GetProcAddress(extIO, "ExtIoGetActualAGCidx");
	if (ExtIoGetActualAGCidx != NULL) std::cout << "ExtIoGetActualAGCidx" << std::endl;

	ExtIoSetAGC = (pfnExtIoSetAGC)GetProcAddress(extIO, "ExtIoSetAGC");
	if (ExtIoSetAGC != NULL) std::cout << "ExtIoSetAGC" << std::endl;

	ExtIoShowMGC = (pfnExtIoShowMGC)GetProcAddress(extIO, "ExtIoShowMGC");
	if (ExtIoShowMGC != NULL) std::cout << "ExtIoShowMGC" << std::endl;

	ExtIoGetMGCs = (pfnExtIoGetMGCs)GetProcAddress(extIO, "ExtIoGetMGCs");
	if (ExtIoGetMGCs != NULL) std::cout << "ExtIoGetMGCs" << std::endl;

	ExtIoGetActualMgcIdx = (pfnExtIoGetActualMgcIdx)GetProcAddress(extIO, "ExtIoGetActualMgcIdx");
	if (ExtIoGetActualMgcIdx != NULL) std::cout << "ExtIoGetActualMgcIdx" << std::endl;

	ExtIoSetMGC = (pfnExtIoSetMGC)GetProcAddress(extIO, "ExtIoSetMGC");
	if (ExtIoSetMGC != NULL) std::cout << "ExtIoSetMGC" << std::endl;

	ExtIoGetPresels = (pfnExtIoGetPresels)GetProcAddress(extIO, "ExtIoGetPresels");
	if (ExtIoGetPresels != NULL) std::cout << "ExtIoGetPresels" << std::endl;

	ExtIoGetActualPreselIdx = (pfnExtIoGetActualPreselIdx)GetProcAddress(extIO, "ExtIoGetActualPreselIdx");
	if (ExtIoGetActualPreselIdx != NULL) std::cout << "ExtIoGetActualPreselIdx" << std::endl;

	ExtIoSetPresel = (pfnExtIoSetPresel)GetProcAddress(extIO, "ExtIoSetPresel");
	if (ExtIoSetPresel != NULL) std::cout << "ExtIoSetPresel" << std::endl;

	ExtIoGetFreqRanges = (pfnExtIoGetFreqRanges)GetProcAddress(extIO, "ExtIoGetFreqRanges");
	if (ExtIoGetFreqRanges != NULL) std::cout << "ExtIoGetFreqRanges" << std::endl;

	ExtIoGetAdcSrate = (pfnExtIoGetAdcSrate)GetProcAddress(extIO, "ExtIoGetAdcSrate");
	if (ExtIoGetAdcSrate != NULL) std::cout << "ExtIoGetAdcSrate" << std::endl;

	ExtIoGetSetting = (pfnExtIoGetSetting)GetProcAddress(extIO, "ExtIoGetSetting");
	if (ExtIoGetSetting != NULL) std::cout << "ExtIoGetSetting" << std::endl;

	ExtIoSetSetting = (pfnExtIoSetSetting)GetProcAddress(extIO, "ExtIoSetSetting");
	if (ExtIoSetSetting != NULL) std::cout << "ExtIoSetSetting" << std::endl;

	ExtIoVFOchanged = (pfnExtIoVFOchanged)GetProcAddress(extIO, "ExtIoVFOchanged");
	if (ExtIoVFOchanged != NULL) std::cout << "ExtIoVFOchanged" << std::endl;

	ExtIoGetVFOindex = (pfnExtIoGetVFOindex)GetProcAddress(extIO, "ExtIoGetVFOindex");
	if (ExtIoGetVFOindex != NULL) std::cout << "ExtIoGetVFOindex" << std::endl;

	ExtIoSDRInfo = (pfnExtIoSDRInfo)GetProcAddress(extIO, "ExtIoSDRInfo");
	if (ExtIoSDRInfo != NULL) std::cout << "ExtIoSDRInfo" << std::endl;

	// MAIN: END

}

