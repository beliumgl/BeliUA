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

int clearScreen();
int writeMenu();

int secret() {
	clearScreen();

	std::string input{};
	std::cout << "\x1b[0mIn Development!!!" << '\n';

	// Repeat the script if user wants it
	std::cout << "\x1b[0mContinue again? (y/n): \x1b[33m";
	std::cin >> input;

	clearScreen();

	if (input == "y") {
		secret();
	}
	else {
		writeMenu();
	}
	return 0;
}
