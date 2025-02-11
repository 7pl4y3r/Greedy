// Greedy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#include "First.h"
#include "Second.h"
#include "Third.h"

using namespace std;

void menu() {

	cout << "h - help\n";
	cout << "e - exit\n";
	cout << "1 - 1st problem\n";
	cout << "2 - 2nd problem\n";
	cout << "3 - 3rd problem\n";
}

int main()
{
	menu();

	char option;
	First first;
	Second second;
	Third third;
	do {

		cout << "new option...";
		cin >> option;

		switch (option) {

		case 'h': menu(); break;
		case '1' : first.exe(); break;
		case '2' : second.exe(); break;
		case '3' : third.exe(); break;

		}

	} while (option != 'e');
    
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
