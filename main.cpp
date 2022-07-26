#include "Data.h"
#include "Windows.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	Data Picard;
	Picard.inputData();
	char mChoice;
	string initials = "";

	cout << "Welcome to PraxNes" << endl << endl;
	cout << "Enter your Initials: ";
	cin >> initials;
	system("cls");
	do {
		cout << "Chose one of the following\n1.Praxis Cheat Sheet\n2.Article Lookup\n3.Quit" << endl;
		cin >> mChoice;
		switch (mChoice) {
		case '1':
			system("cls");
			Picard.printCheatSheet();
			continue;
		case '2':
			system("cls");
			Picard.praxisArticleCheck(initials);
			continue;
		case '3':
			break;
		default:
			system("cls");
			continue;
		}
		system("cls");
	} while (mChoice != '3');
}