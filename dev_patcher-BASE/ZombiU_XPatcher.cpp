// Ignore this, This is developer issued code and has nothing to do with patching the game
// This code is for the older version of the Patcher (v1.3 and below) So ignore this.
//
// We updated it to (v1.4+) and now only has the modded game files and doesn't require any external code
// You can ignore this.

#include <windows.h>
#include <iostream>
#include <thread>

using namespace std;


// DE
DWORD pID;
int hook_delay = 6000;
// EUR
void clear() {
	system("cls");
}


void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

int delay = 6571;

void run_overlay() {
	system("ZombiU_XPatcherGUI.exe");
}

void timer() {
	Sleep(delay); // Wait for (Time In Miliseconds)
	system("taskkill /F /IM ZombiU_XPatcherGUI.exe");
	system("ZOMBI_Game.exe");
}

void hook_to_proc() {
	Sleep(hook_delay);
	HWND hwnd = FindWindowA(0, ("ZOMBI"));
	if (!hwnd) cerr << "CANNOT FIND ZOMBI.EXE" << endl;
	GetWindowThreadProcessId(hwnd, &pID);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (!pHandle) cerr << "ERROR" << endl;
}


int main() {
	SetConsoleTitleA("DEBUG CONSOLE [ZOMBI]");
	// Hide Console
	//HideConsole();
	ShowConsole();
	// Define Threads
	thread x(run_overlay);
	thread y(timer);
	y.join(); // Start Overlay
	x.join(); // Start Overlay Timer
	// Hook To Proc //
	hook_to_proc();
	while (true) {

	}
}
