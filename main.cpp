#include "globals.h"
#include "ConsoleColor.h"

#include <iostream>
#include <Psapi.h>
#include <string>
#include <thread>
#include <TlHelp32.h>
#include "Game/Game.h"

bool FreezeSt = false;


std::uint32_t find_process_by_id(const std::string& name)
{
	const auto snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!Process32First(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!Process32Next(snap, &proc_entry));
	}

	CloseHandle(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}


uintptr_t GetProcessBaseAddress(HANDLE Handle)
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;

	if (EnumProcessModules(Handle, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(Handle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				std::string wstrModName = szModName;
				std::string wstrModContain = "RainbowSix.exe";
				if (wstrModName.find(wstrModContain) != std::string::npos)
				{
					base_address = (uintptr_t)hMods[i];
					return base_address;
				}
			}
		}
	}

	return false;
}

int main()
{
	SetConsoleTitle("ProjectX R6");

	{
		pid = find_process_by_id("RainbowSix.exe");
		if (!pid)
		{
			MessageBox(NULL, "Cannot Find RainbowSix.exe", NULL, MB_ICONHAND);
			exit(-1);
		}

		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, pid);
		if (hProcess == INVALID_HANDLE_VALUE || !hProcess)
		{
			MessageBox(NULL, "Driver Not Loaded", NULL, MB_ICONHAND);
			exit(-1);
		}

		base_address = GetProcessBaseAddress(hProcess);
		if (!base_address)
		{
			MessageBox(NULL, "Cannot Get Process Base Address", NULL, MB_ICONHAND);
			exit(-1);
		}
	}

	std::cout << std::endl << red << "ProjectX R6 || Beta" << std::endl;
	std::cout << "F1 -> Freeze Lobby" << std::endl;
	std::cout << "F2 -> Speed" << std::endl;
	std::cout << "F3 -> Spoot" << std::endl;
	std::cout << "F4 -> NoClip" << std::endl;
	std::cout << "F5 -> ThirdPerson" << std::endl;
	std::cout << "F6 -> Drone Jump" << std::endl;
	std::cout << "F7 -> CavEsp" << std::endl;
	std::cout << "END -> Exit" << std::endl;


	int Freeze = 0;
	int NoClip = 0;
	int Speed = 0;
	int Spoot = 0;
	int ThirdPersonView = 0;
	int DroneJump = 0;
	int EspOutline = 0;
	int SilentAim = 0;
	int Padrao = 1;
	uintptr_t baseAddress = base_address;
	while (true)
	{

		if (GetAsyncKeyState(VK_F1))
		{
			if (Freeze == 1)
			{
				Freeze = 0;
				RainbowSix::un_freeze_lobby(baseAddress);
				Beep(1000, 100);
			}
			else
			{
				Freeze = 1;
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F2))
		{
			if (Speed == 1)
			{
				Speed = 0;
				RainbowSix::un_SpeedMax(baseAddress);
				Beep(1000, 100);
			}
			else
			{
				Speed = 1;
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F3))
		{
			if (Spoot == 1)
			{
				Spoot = 0;
				Beep(1000, 100);
			}
			else
			{
				Spoot = 1;
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F4))
		{
			if (NoClip == 1)
			{
				NoClip = 0;
				Beep(1000, 100);
			}
			else
			{
				NoClip = 1;
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F5))
		{
			if (ThirdPersonView == 1)
			{
				ThirdPersonView = 0;
				RainbowSix::unThirdPerson(baseAddress);
				Beep(1000, 100);
			}
			else
			{
				ThirdPersonView = 1;
				RainbowSix::ThirdPerson(baseAddress);
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F6))
		{
			if (DroneJump == 1)
			{
				DroneJump = 0;
				Beep(1000, 100);
			}
			else
			{
				DroneJump = 1;
				Beep(500, 100);
			}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_F7))
		{
			RainbowSix::CavEsp(baseAddress);
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			if (DroneJump == 1)
			{
				int DroneState = RainbowSix::GetDroneState(baseAddress);
				if (DroneState == 2)
				{
					RainbowSix::DroneIncreaseJump(baseAddress);
				}
			}
		}

		if (GetAsyncKeyState(VK_F9))
		{
			float x = RainbowSix::GetEntityPos_X(base_address, 1);
			float y = RainbowSix::GetEntityPos_Y(base_address, 1);
			float z = RainbowSix::GetEntityPos_Z(base_address, 1);
			RainbowSix::TpKnife(base_address, x, y, z);
		}

		if (Freeze == 1)
		{
			RainbowSix::freeze_lobby(baseAddress);
		}
		if (NoClip == 1)
		{
			RainbowSix::NoClipGad(baseAddress);
		}
		if (Speed == 1)
		{
			RainbowSix::SpeedMax(baseAddress);
		}
		if (Spoot == 1)
		{
			RainbowSix::SpottWall(baseAddress);
		}
		if (EspOutline == 1)
		{
			RainbowSix::Ataque(baseAddress);
		}

		if (Padrao == 1)
		{
			RainbowSix::Glow(baseAddress, -3, -2, -1, 0, 0, 0, 0); // glow bom
			RainbowSix::FovGame(baseAddress, 1.9f, 1.9f);
			RainbowSix::NoRecoil(baseAddress);
			RainbowSix::NoSpread(baseAddress);
			RainbowSix::NoFlash(baseAddress);
			RainbowSix::WeaponAuto(baseAddress);
			RainbowSix::NoAnimation(baseAddress);
		}
		//driver->ClearMapperTraces();
		//driver->ClearPidCache();
		Sleep(100);
	}

	return 0;
}