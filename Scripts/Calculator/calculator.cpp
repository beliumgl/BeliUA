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
#include "../../Libraries/exprtk.hpp"                       // For parsing expressions
#include <vector>

int clearScreen();
int writeMenu();

void Calc() {
    typedef exprtk::expression<double> expression_t; 
    typedef exprtk::parser<double> parser_t;
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    string expr_str{};                                      // User's expression
    double result{};                                        // Expression result
    expression_t expression{};                              // Parsed (compiled) expr_str
    parser_t parser{};          
    string input{};                                         // For repeating the script if user wants it
    

    clearScreen();


    cout << "\x1b[0mEnter your expression: \x1b[33m";
    std::cin >> expr_str;

    parser.compile(expr_str, expression);                   // Parse the expression
    result = expression.value();
    cout << "\x1b[0mResult: \x1b[33m" << result << '\n';

    // Repeat the script if user wants it
    cout << "\x1b[0mContinue again? (y/n): \x1b[33m";
    std::cin >> input;

    clearScreen();

    if (input == "y") {
        Calc();
    }
    else {
        writeMenu();
    }
}