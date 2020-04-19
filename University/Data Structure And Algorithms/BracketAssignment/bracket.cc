/**
* Assignment 2
* Made by Aldrin Azucena
* University Of Lethbridge
* Data Structures and Algorithms - CPSC3620
* SID: 01220471
* Created on February 2nd, 2020
*/
#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include "bracket.h"

bool Bracket::isBalanced(std::string ex) {
    std::stack<char> c;

	// uses the variable from the value for top of the stack
	char s;

    // Searches the characters on the given word
    for (int i = 0; i < ex.length(); i++) {

        //Pushes the Left Brackets to stack if they exist on expression
        if(ex[i] == '(' || ex[i] == '[' || ex[i] == '{') {
            c.push(ex[i]);
            continue;
        }

        //Pops left bracket from stack if right bracket exists in expression
        if (ex[i] == ')') {
            s = c.top();
            c.pop();
            if(s != '(') {
                return false;
            }
        }
        if (ex[i] == ']') {
            s = c.top();
            c.pop();
            if(s != '[') {
                return false;
            }
        }
        if(ex[i] == '}') {
            s = c.top();
            c.pop();
            if(s != '{') {
                return false;
            }
        }
    }
    return (c.empty());
}

bool Bracket::hasBrackets(std::string ex) {
    char bra[]={'(', '{', '[', ')', '}', ']'};
    for (int i = 0; i < ex.length(); i++){
        for (int j = 0; j < 6; j++){
            if(ex[i] == bra[j]){
                return true;
            }
        }
    }
    return false;
}
int main() {
	char input;
    std::cout << "Welcome to the <CHECK your expression if it is balanced> program where you can type up to check!" << std::endl;
	do{
        std::cout << std::endl;
		std::cout << "G - start the program " << std::endl
		<< "Q - Quit the program" << std::endl;
		std::cin >> input;
		if(input == 'G' || input == 'g'){
			std::string expression;
			std::cout << "Type your expression: ";
			std::cin >> expression;
            Bracket b(expression);
			if (!b.hasBrackets(b.getString())){
				std::cout << "Type again all over..." << std::endl;
				break;
			}
			else{
				if(b.isBalanced(b.getString())) {
					std::cout << "Brackets are properly nested for: " << b.getString() << std::endl;
				}
				else {
					std::cout << "Brackets are disorganized for: " << b.getString() << std::endl;
				}
			}
		}
        else if (input == 'q'){
            break;
        }
		else {
            std::cout << "WRONG!! TRY AGAIN..." << std::endl;
        }
	}
	while(input != 'Q');
	std::cout << "Thanks for using the program!! Have a nice day!" << std::endl;
	return 0;
}
