#include "ui.h"
#include <iostream>

using namespace ui;
using namespace std;

template<typename T>
T getInput() {
	T userInput = 0;
	cout << "Ввод: ";
	cin >> userInput;
	if (cin.fail()) {
		cout << "Некоректный ввод. Попробуйте еще раз" << endl;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Ввод: ";
			cin >> userInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}


int correct::getMenuVar(int lower, int upper) {
	bool inputCorrect = false;
	int in = 0;
	while (!inputCorrect) {
		in = getInt();
		if (in >= lower && in <= upper) {
			inputCorrect = true;
		}
		else {
			cout << "Нет такого пункта меню!" << endl;
		}
	}
	return in;
}

int correct::getInt() {
	return getInput<int>();
}

bool correct::getBool() {
	return getInput<bool>();
}

double correct::getDouble() {
	return getInput<double>();
}

int correct::getIntField() {
	correct check;
	bool inputCorrect = false;
	int in = 0;
	while (!inputCorrect) {
		in = check.getInt();
		if (in >= 1) {
			inputCorrect = true;
		}
		else {
			cout << "Введено неположительное число! Попробуйте еще раз" << endl;
		}
	}
	return in;
}

double correct::getDoubleField() {
	correct check;
	bool inputCorrect = false;
	double in = 0;
	while (!inputCorrect) {
		in = check.getDouble();
		if (in >= 1) {
			inputCorrect = true;
		}
		else {
			cout << "Введено неположительное число! Попробуйте еще раз" << endl;
		}
	}
	return in;
}