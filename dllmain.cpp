// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <stdio.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

INT changeBuffer(CHAR Buffer[], DWORD* nIn, INT numFromCMD) {
	INT countNum = 0, numOfReplace = 0, i = 0;

	while (i < (*nIn)) { //Количество цифр во всем буффере
		if (Buffer[i] >= '0' && Buffer[i] <= '9')	countNum++;
		i++;
	}

	if (countNum == 0 || numFromCMD <= 0) { //Проверка количества введенных цифр
		printf("Ошибка ввода.\n");
		return -1;
	}

	if (countNum >= numFromCMD) {
		printf("Будет заменено %d цифр(ы).\n", numFromCMD);
	}
	else {
		printf("Слишком большое значение, будут заменены все числа.\n");
		numFromCMD = countNum;
	}

	i = 0;
	while (i < (*nIn)) {
		if (Buffer[i] >= '0' && Buffer[i] <= '9') {
			Buffer[i] = ' ';
			numOfReplace++;

			if (numOfReplace == numFromCMD) i = (*nIn) - 1;
		}
		i++;
	}

	return numOfReplace;
}