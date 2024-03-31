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

void setKeybinds();
int clearScreen();
int autoclicker();

void settings() {
	std::string input;
	clearScreen();
	std::cout << "\t\x1b[0mAutoClicker Settings (type !back to go back):" << '\n';
	std::cout << "\x1b[0m1. Key binds" << '\n';
	std::cout << "\x1b[0mOption: ";
	std::cin >> input;
	if (input == "1") {
		setKeybinds();
		autoclicker();
	}
	else if (input == "!back") {
		autoclicker();
	}
	else {
		settings();
	}
}