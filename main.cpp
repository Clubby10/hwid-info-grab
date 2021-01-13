#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>

using namespace std;

int main()
{
	SetConsoleTitle("HWID INFO GRAB");
	system("color 3");
	cout << "HWID information" << std::endl;
	cout << "By Clubby10 (github.com/clubby10)\n";
	Sleep(1000);

	//HDD informations
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		cout << "\n";
		cout << "Volume Name: " << volumeName << std::endl;
		cout << "HDD Serial: " << serialNumber << std::endl;
		cout << "File System Type: " << fileSystemName << std::endl;
		cout << "Max Component Length: " << maxComponentLen << std::endl;
	}
	//computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	if (GetComputerName(
		computerName,
		&size))
	{
		cout << "\n";
		cout << "Computer Name: " << computerName << std::endl;
	}
	//CPU Hash
	int cpuinfo[4] = { 0, 0, 0, 0 }; 
	__cpuid(cpuinfo, 0);
	char16_t hash = 0;
	char16_t* ptr = (char16_t*)(&cpuinfo[0]);
	for (char32_t i = 0; i < 8; i++)
		hash += ptr[i];
	cout << "\n";
	cout << "CPU Hash: " << hash << std::endl;
	cout << "\n";
	system("pause");
	return(0);
}
