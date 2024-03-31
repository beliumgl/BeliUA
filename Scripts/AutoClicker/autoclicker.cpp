/*
 *	           _____                    _____                    _____            _____                    _____                    _____
 *            /\    \                  /\    \                  /\    \          /\    \                  /\    \                  /\    \
 *           /::\    \                /::\    \                /::\____\        /::\    \                /::\____\                /::\____\
 *          /::::\    \              /::::\    \              /:::/    /        \:::\    \              /:::/    /               /::::|   |
 *         /::::::\    \            /::::::\    \            /:::/    /          \:::\    \            /:::/    /               /:::::|   |
 *        /:::/\:::\    \          /:::/\:::\    \          /:::/    /            \:::\    \          /:::/    /               /::::::|   |
 *       /:::/__\:::\    \        /:::/__\:::\    \        /:::/    /              \:::\    \        /:::/    /               /:::/|::|   |
 *      /::::\   \:::\    \      /::::\   \:::\    \      /:::/    /               /::::\    \      /:::/    /               /:::/ |::|   |
 *     /::::::\   \:::\    \    /::::::\   \:::\    \    /:::/    /       ____    /::::::\    \    /:::/    /      _____    /:::/  |::|___|______
 *    /:::/\:::\   \:::\ ___\  /:::/\:::\   \:::\    \  /:::/    /       /\   \  /:::/\:::\    \  /:::/____/      /\    \  /:::/   |::::::::\    \
 *   /:::/__\:::\   \:::|    |/:::/__\:::\   \:::\____\/:::/____/       /::\   \/:::/  \:::\____\|:::|    /      /::\____\/:::/    |:::::::::\____\
 *   \:::\   \:::\  /:::|____|\:::\   \:::\   \::/    /\:::\    \       \:::\  /:::/    \::/    /|:::|____\     /:::/    /\::/    / ~~~~~/:::/    /
 *    \:::\   \:::\/:::/    /  \:::\   \:::\   \/____/  \:::\    \       \:::\/:::/    / \/____/  \:::\    \   /:::/    /  \/____/      /:::/    /
 *     \:::\   \::::::/    /    \:::\   \:::\    \       \:::\    \       \::::::/    /            \:::\    \ /:::/    /               /:::/    /
 *      \:::\   \::::/    /      \:::\   \:::\____\       \:::\    \       \::::/____/              \:::\    /:::/    /               /:::/    /
 *       \:::\  /:::/    /        \:::\   \::/    /        \:::\    \       \:::\    \               \:::\__/:::/    /               /:::/    /
 *        \:::\/:::/    /          \:::\   \/____/          \:::\    \       \:::\    \               \::::::::/    /               /:::/    /
 *         \::::::/    /            \:::\    \               \:::\    \       \:::\    \               \::::::/    /               /:::/    /
 *          \::::/    /              \:::\____\               \:::\____\       \:::\____\               \::::/    /               /:::/    /
 *           \::/____/                \::/    /                \::/    /        \::/    /                \::/____/                \::/    /
 *            ~~                       \/____/                  \/____/          \/____/                  ~~                       \/____/
 *	Hi everyone who reads this code!
 *	This code is made by @belgiumgl
 *	Yeah, you can contact him in discord!!!
 *	I'm very friendly
 */

#include <iostream>
#include <sstream>						// Converts std::string to double
#include <conio.h>						// For getch() which is getting your keybinds
#include <cctype>
#include <Windows.h>					// for GetAsyncKeyState() and mouse_event()s

int clearScreen();
void menu();
int writeMenu();
void settings();
void setKeybinds();

char start{ 'X' };
char stop{ 'C' };
char reset{ 'Z' };
bool isSet{ false };
bool click = false;

std::string delayInMilliseconds{};		// It can contain commands to leave from script or to go to settings so it's std::string
double delayInMillisecondsDOUBLE{};		// This contains delay in double format
bool isCleared{ false };				// For better experience in settings
																				
int autoclicker() {

	clearScreen();

	menu();
	bool click = false;
	while (true)
	{
		if (click == true) 
		{
			std::istringstream(delayInMilliseconds) >> delayInMillisecondsDOUBLE;
			if (isCleared == false) {
				clearScreen();
				std::cout << "\x1b[0mAutoclicking..." << '\n';
				std::cout << "\x1b[0mPress " << reset << " to Reset AutoClicker, press " << stop << " to Stop AutoClicker" << '\n';
				isCleared = true;
			}
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // Clicks Left mouse button
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   // Releases Left mouse button
			Sleep(delayInMillisecondsDOUBLE); 		
		}

		if (GetAsyncKeyState(start)) {
			click = true;
		}
		else if (GetAsyncKeyState(reset))
		{
			clearScreen();
			menu();
			click = false;
		}
		else if (GetAsyncKeyState(stop))
		{
			isCleared = false;
			clearScreen();
			click = false;
			std::cout << "\x1b[0mAutoclicking Stopped!" << '\n';
			std::cout << "\x1b[0mPress " << start << " to Resume AutoClicker, press " << reset << " to Reset AutoClicker" << '\n';
		}
	}
	return 0;
}

void menu() {
	std::cout << "\x1b[0mType " << "!exit" << " to quit to menu, type !settings to enter the settings" << '\n';
	std::cout << "\x1b[0mEnter delay in milliseconds: \x1b[33m";
	std::cin >> delayInMilliseconds;
	if (delayInMilliseconds == "!exit") {
		clearScreen();
		writeMenu();
	}
	else if (delayInMilliseconds == "!settings") {
		clearScreen();
		settings();
	}
	clearScreen();
	std::cout << "\x1b[0mPress " << start << " to Start AutoClicker, press " << stop << " to stop AutoClicker, press " << reset << " to reset AutoClicker" << '\n';
}

void setKeybinds() {
	clearScreen();
	std::cout << "\x1b[0m1. Start keybind (Default: X): ";
	while (!isSet) {								//	For better experience in settings													
		if (_kbhit()) {
			start = toupper(_getch());
			isSet = true;
		}
	}
	isSet = false;
	std::cout << "\x1b[0m\n2. Stop keybind (Default: C): ";
	while (!isSet) {								//	For better experience in settings
		if (_kbhit()) {
			stop = toupper(_getch());
			isSet = true;
		}
	}
	isSet = false;
	std::cout << "\x1b[0m\n3. Reset keybind (Default: Z): ";
	while (!isSet) {								//	For better experience in settings
		if (_kbhit()) {
			reset = toupper(_getch());
			isSet = true;
		}
	}
	isSet = false;
}

