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
	cout << "������� ��� �������" << endl;
	cout << "����: ";
	getline(cin, name);
	(*clients)[i].setName(name);

	cout << "������� ������� �������" << endl;
	cout << "����: ";
	getline(cin, surname);
	(*clients)[i].setSurname(surname);

	cout << "������� �������� �������" << endl;
	cout << "����: ";
	getline(cin, middlename);
	(*clients)[i].setMiddleName(middlename);

	cout << "������� ����� �������" << endl;
	cout << "����: ";
	getline(cin, address);
	(*clients)[i].setAddress(address);

	cout << "������� ������� ������� � ������������ �������" << endl;
	cout << "����: ";
	getline(cin, telephone);
	(*clients)[i].setSurname(telephone);

	cout << "������� ����� ����� �������" << endl;
	cardNumber = correctness.getIntField();
	(*clients)[i].setCardNumber(cardNumber);

	cout << "������� ����� ����������� ����� �������" << endl;
	bankNumber = correctness.getIntField();
	(*clients)[i].setCardNumber(cardNumber);
}

int creader::readConsole(Client** clients) {
	correct correctness{};
	freader fout{};
	int size = 0;
	cout << "-----..........-----..........-----..........-----" << endl;
	cout << "������� ����������� ��������" << endl;
	size = correctness.getIntField();
	cout << "-----..........-----..........-----..........-----" << endl;
	*clients = new Client[size];
	for (int i = 0; i < size; i++) {
		cout << "�� ������� ������� �" << i + 1 << endl;
		filling(clients, i);
		cout << "-----..........-----..........-----..........-----" << endl;
	}
	cout << "���� ��� ������� ��������! " << endl;
	fout.outInitialDataInFile(clients, size);
	return size;
}

void printProduct(Client** clients, int i) {
	cout << "-----..........-----..........-----..........-----" << endl;
	cout << "��� �������: " << (*clients)[i].getName() << endl;
	cout << "�������: " << (*clients)[i].getSurname() << endl;
	cout << "��������: " << (*clients)[i].getMiddleName() << endl;
	cout << "�����: " << (*clients)[i].getAddress() << endl;
	cout << "�������: " << (*clients)[i].getTelephone() << endl;
	cout << "����� �����: " << (*clients)[i].getCardNumber() << endl;
	cout << "����� ����� � �����: " << (*clients)[i].getBankNumber() << endl;
}

void creader::outConsole(Client** clients, int size) {
	if (size != 0) {
		cout << "���������� ������:" << endl;
		for (int i = 0; i < size; i++) {
			printProduct(clients, i);
		}
	}
	else {
		cout << "���������� ������ ������ �����" << endl << endl;
		throw runtime_error("error");
	}
}