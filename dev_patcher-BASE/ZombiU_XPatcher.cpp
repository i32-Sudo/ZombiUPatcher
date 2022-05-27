#include <windows.h>
#include <iostream>
#include <thread>

using namespace std;

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

int main() {
	HideConsole();
	thread x(run_overlay);
	thread y(timer);
	y.join();
	x.join();
}