#include "ui.h"
#include <iostream>
#include <map>

using namespace ui;
using namespace std;

void filling(Client** clients, int i) {
	correct correctness{};
	string name{};
	string surname{};
	string middlename{};
	string address{};
	string telephone{};
	int cardNumber{};
	int bankNumber{};
	cout << "-----..........-----..........-----..........-----" << endl;
	cout << "Введите имя клиента" << endl;
	cout << "Ввод: ";
	getline(cin, name);
	(*clients)[i].setName(name);

	cout << "Введите фамилию клиента" << endl;
	cout << "Ввод: ";
	getline(cin, surname);
	(*clients)[i].setSurname(surname);

	cout << "Введите отчество клиента" << endl;
	cout << "Ввод: ";
	getline(cin, middlename);
	(*clients)[i].setMiddleName(middlename);

	cout << "Введите адрес клиента" << endl;
	cout << "Ввод: ";
	getline(cin, address);
	(*clients)[i].setAddress(address);

	cout << "Введите телефон клиента в произвольном формате" << endl;
	cout << "Ввод: ";
	getline(cin, telephone);
	(*clients)[i].setSurname(telephone);

	cout << "Введите номер карты клиента" << endl;
	cardNumber = correctness.getIntField();
	(*clients)[i].setCardNumber(cardNumber);

	cout << "Введите номер банковского счета клиента" << endl;
	bankNumber = correctness.getIntField();
	(*clients)[i].setCardNumber(cardNumber);
}

int creader::readConsole(Client** clients) {
	correct correctness{};
	freader fout{};
	int size = 0;
	cout << "-----..........-----..........-----..........-----" << endl;
	cout << "Введите колличество клиентов" << endl;
	size = correctness.getIntField();
	cout << "-----..........-----..........-----..........-----" << endl;
	*clients = new Client[size];
	for (int i = 0; i < size; i++) {
		cout << "Вы вводите клиента №" << i + 1 << endl;
		filling(clients, i);
		cout << "-----..........-----..........-----..........-----" << endl;
	}
	cout << "Ввод был успешно проведен! " << endl;
	fout.outInitialDataInFile(clients, size);
	return size;
}

void printProduct(Client** clients, int i) {
	cout << "-----..........-----..........-----..........-----" << endl;
	cout << "Имя клиента: " << (*clients)[i].getName() << endl;
	cout << "Фамилия: " << (*clients)[i].getSurname() << endl;
	cout << "Отчество: " << (*clients)[i].getMiddleName() << endl;
	cout << "Адрес: " << (*clients)[i].getAddress() << endl;
	cout << "Телефон: " << (*clients)[i].getTelephone() << endl;
	cout << "Номер карты: " << (*clients)[i].getCardNumber() << endl;
	cout << "Номер счета в банке: " << (*clients)[i].getBankNumber() << endl;
}

void creader::outConsole(Client** clients, int size) {
	if (size != 0) {
		cout << "Полученные данные:" << endl;
		for (int i = 0; i < size; i++) {
			printProduct(clients, i);
		}
	}
	else {
		cout << "Попробуйте ввести данные снова" << endl << endl;
		throw runtime_error("error");
	}
}