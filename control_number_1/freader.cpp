#include <iostream>
#include <filesystem>
#include "ui.h"
#include "Client.h"
#include <string>
#include <fstream>
#include <cstring>


using namespace std;
using namespace ui;

enum {
	ch_name = 0,
	ch_surname = 1,
	ch_middlename = 2,
	ch_address = 3,
	ch_telephone = 4,
	ch_cardnum = 5,
	ch_banknum = 6
};


void freader::outInitialDataInFile(Client** clients, int size) const {
	correct correctness{};
	informing info{};
	freader fr{};
	info.printInformFout();
	bool variant = correctness.getBool();
	if (variant == 0) return;
	fr.fillFile(clients, false);
}

// ��������� ������ �� ���������, ��������� ������ ';' � �������� �����������
void freader::filling(Client** clients, const char* str_ptr, int i) {
	int iter = 0;
	char* str_copy = new char[strlen(str_ptr) + 1];
	strcpy_s(str_copy, strlen(str_ptr) + 1, str_ptr);
	char* context = nullptr;
	char* token = strtok_s(str_copy, "/", &context);
	while (token != nullptr) {
		switch (iter) {
		case ch_name:
			(*clients)[i].setName(token);
			break;
		case ch_surname:
			(*clients)[i].setSurname(token);
			break;
		case ch_middlename:
			(*clients)[i].setMiddleName(token);
			break;
		case ch_address:
			(*clients)[i].setAddress(token);
			break;
		case ch_telephone:
			(*clients)[i].setTelephone(token);
			break;
		case ch_cardnum:
			if (strtod(token, nullptr) <= 0) {
				cout << "������������ ����� �����! ��������� ������ � �����! � " << i + 1 << " ������" << endl;
			}
			(*clients)[i].setCardNumber(strtod(token, nullptr));
			break;
		case ch_banknum:
			if (strtod(token, nullptr) <= 0) {
				cout << "������������ ����� ����� � �����! ��������� ������ � �����! � " << i + 1 << " ������" << endl;
			}
			(*clients)[i].setBankNumber(strtod(token, nullptr));
			break;
		default:
			cout << "������� ����� ������ � ����� ������! ������ ����� ���������������" << endl;
		}
		token = strtok_s(nullptr, "/", &context);
		iter++;
	}
	delete[] str_copy;
}


void freader::implFile(Client** clients, int* size, string name) {
	int i = 0;
	string data{};
	ifstream input;
	input.open(name);
	if (input.is_open()) {
		while (getline(input, data)) {
			*size += 1;
		}
		input.close();
	}
	else {
		cout << endl << "����� � ����� ������ �� ����������!" << endl << endl;
		throw runtime_error("error");
	}

	input.open(name);
	if (input.is_open()) {
		*clients = new Client[*size];
		while (getline(input, data)) {
			if (data.empty()) {
				cout << "���� ������� �� " << i + 1 << " ������ �� ��� ����������! ��������� ���� � ������� ������ ������" << endl;
				*size -= 1;
			}
			else {
				filling(clients, data.c_str(), i);
			}
			i++;
		}
		input.close();
	}
	else {
		cout << endl << "������ ������ �����!" << endl << endl;
		throw runtime_error("An error occurred");
	}
}

void freader::removeNegative(Client** clients, int* size) {
	int newSize = 0;
	for (int i = 0; i < *size; i++) {
		if (!(*clients)[i].isNegavive()) {
			(*clients)[newSize++] = (*clients)[i];
		}
	}
	// �������� ������ ��������
	for (int i = newSize; i < *size; i++) {
		(*clients)[i] = Client();
	}
	*size = newSize;

}

int freader::readFile(Client** clients, string name) {
	informing info{};
	int size = 0;
	info.printInformFin();
	cin >> name;
	implFile(clients, &size, name);
	removeNegative(clients, &size);
	info.printCorrect();
	return size;
}


void freader::fillFile(Client** clients, int size) {
	informing info{};
	info.printInformNameOfFile();
	string filePath = "";
	bool isDataSaved = false;
	correct correctness{};
	do {
		cout << "��������� �:";
		getline(cin, filePath);

		if (ifstream(filePath)) {
			cout << "���� ��� ����������." << endl;
			cout << "[0] - ������������ ������������ ����." << endl;
			cout << "[1] - ��������� ����." << endl;
			int tryAnotherFile = correctness.getBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(filePath, ofstream::app);

		error_code ec{};

		if (!myFile) {
			cout << "������ ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filePath, ofstream::trunc);
		for (int i = 0; i < size; i++) {
			myFile << "-----..........-----..........-----..........-----" << endl;
			myFile << "������ �" << i + 1 << endl;
			myFile << "-----..........-----..........-----..........-----" << endl;
			myFile << "���: " << (*clients)[i].getName() << endl;
			myFile << "�������: " << (*clients)[i].getSurname() << endl;
			myFile << "��������: " << (*clients)[i].getMiddleName() << endl;
			myFile << "�����: " << (*clients)[i].getAddress() << endl;
			myFile << "�������: " << (*clients)[i].getTelephone() << endl;
			myFile << "����� �����: " << (*clients)[i].getCardNumber() << endl;
			myFile << "����� ����� � �����: " << (*clients)[i].getBankNumber() << endl;
		}
		myFile.close();
		cout << "������ ���������." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}
