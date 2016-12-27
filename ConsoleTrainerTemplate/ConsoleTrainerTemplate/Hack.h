#pragma once
#include "Memory.h"

enum HackType
{
	CODEPATCH,
	VALFREEZE,
	VALWRITE,
	HOOK
};



class Hack
{
public: //ctors
	// code patch ctor
	Hack(TCHAR * HackName, Memory & mem, HackType ht, uintptr_t pAddress, UINT szSize);

	// code injection ctor
	Hack(TCHAR * HackName, Memory & mem, HackType ht, uintptr_t pAddress, UINT szSize, byte * pData, UINT iCaveSize);

	// val freeze ctors
	Hack(TCHAR * HackName, Memory & mem,std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pAddress, int value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pBase, UINT * Offsets, UCHAR count, int value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pAddress, int64_t value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pBase, UINT * Offsets, UCHAR count, int64_t value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pAddress, float value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pBase, UINT * Offsets, UCHAR count, float value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pAddress, double value);
	Hack(TCHAR * HackName, Memory & mem, std::vector<std::reference_wrapper<Hack>> & pGVHacks, HackType ht, ValType vt, uintptr_t pBase, UINT * Offsets, UCHAR count, double value);
	~Hack();

public: //Inits
	void InitHackAndAddress(TCHAR * HackName, HackType ht, ValType vt, uintptr_t pAddress);
	void InitHackAndPointer(TCHAR * HackName, HackType ht, ValType vt, uintptr_t pBase, UINT * Offsets, UCHAR count);

public: //Getters
	TCHAR* GetName();
	HackType GetHackType();

public: //Hotkey
	void SetHotkey(int vKey);
	int GetHotkey();

public: //Toggles
	void TogglePatch();
	void WriteValue();
	void ToggleHook();
	void Toggle();

	void AddHackToVec();
	void AddToVec(std::vector<Hack> & hack);

private:
	Memory & mem;
	HackType ht;
	ValType vt;

	TCHAR * HackName;
	bool bEnabled = false;
	int iHotkey = 0;

	//for code patch and maybe hooking hacks
	uintptr_t pAddress = NULL;
	uintptr_t pCaveAddress = NULL;
	UINT szSize = NULL;
	std::vector<byte> vOldBytes;
	std::vector<byte> vCaveData;

	//for pointer based hacks.
	uintptr_t pBase = NULL;
	UCHAR ucOffsetCount = NULL; //amount of offsets
	UINT * pOffsets = nullptr; //ptr -> offsets	

	int iValue = 0;
	int64_t i64Value = 0;
	float fValue = 0;
	double dValue = 0;

	std::vector<std::reference_wrapper<Hack>> & pGVHacks;	
};

