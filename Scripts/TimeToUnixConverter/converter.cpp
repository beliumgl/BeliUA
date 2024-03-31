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
#include <chrono>
#include <ctime>

int clearScreen();
int writeMenu();

std::time_t dateToUnix(int year, int month, int day, int hour, int minute, int second) {
	std::tm timeinfo = { 0 };
	timeinfo.tm_year = year - 1900; 
	timeinfo.tm_mon = month - 1;    
	timeinfo.tm_mday = day;         
	timeinfo.tm_hour = hour;
	timeinfo.tm_min = minute;
	timeinfo.tm_sec = second;

	return std::mktime(&timeinfo); // Final result
}

int convert() {

	clearScreen();

	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	int year{};
	int month{};
	int day{};
	int hour{};
	int minute{};
	int second{};
	string input{};

	cout << "\x1b[0mEnter year: \x1b[33m";
	std::cin >> year;
	cout << "\x1b[0mEnter month: \x1b[33m";
	std::cin >> month;
	cout << "\x1b[0mEnter day: \x1b[33m";
	std::cin >> day;
	cout << "\x1b[0mEnter hour: \x1b[33m";
	std::cin >> hour;
	cout << "\x1b[0mEnter minute: \x1b[33m";
	std::cin >> minute;
	cout << "\x1b[0mEnter second: \x1b[33m";
	std::cin >> second;

	std::time_t unix_time = dateToUnix(year, month, day, hour, minute, second);

	cout << "\x1b[0mResult: \x1b[33m" << unix_time << '\n';

	// Repeat the script if user wants it
	cout << "\x1b[0mContinue again? (y/n): \x1b[33m";
	cin >> input;

	clearScreen();

	if (input == "y") {
		convert();
	}
	else {
		writeMenu();
	}

	
	return 0;
}