// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBox(NULL, L"DLL загружена", L"Антибаг-фича", MB_OK);
		break;
	case DLL_THREAD_ATTACH:
		MessageBox(NULL, L"A thread is created in this process", L"Антибаг-фича", MB_OK);
		break;
	case DLL_THREAD_DETACH:
		MessageBox(NULL, L"A thread is destroyed in this process", L"Антибаг-фича", MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		MessageBox(NULL, L"DLL выгружена", L"Антибаг-фича", MB_OK);
		break;
	}
    return TRUE;
}

INT changeBuffer(CHAR Buffer[], DWORD& nIn, INT numFromCMD) {
	INT numOfNum = 0, index = 0;

	while (index < nIn) { //Количество цифр во всем буффере
		if (Buffer[index] >= '0' && Buffer[index] <= '9') {
			numOfNum++;
		}
		index++;
	}

	if (numOfNum == 0 || numFromCMD <= 0) { //Проверка количества введнных цифр
		printf("Нельзя заменено 0 цифр(ы), либо в документе они отсутствуют.\n");
		return -1;
	}
	if (numOfNum >= numFromCMD) {
		printf("Будет заменено %d цифр(ы).\n", numFromCMD);
	}
	else {
		printf("Во всем документе %d цифр(ы), а не %d, поэтому будут заменены все.\n\n", numOfNum, numFromCMD);
		numFromCMD = numOfNum;
	}

	index = 0;
	INT numOfReplace = 0;
	while (index < nIn) {
		if (Buffer[index] >= '0' && Buffer[index] <= '9') {
			Buffer[index] = ' ';
			numOfReplace++;
			if (numOfReplace == numFromCMD) {
				index = nIn;
			}
		}
		index++;
	}

	return numOfReplace;
}