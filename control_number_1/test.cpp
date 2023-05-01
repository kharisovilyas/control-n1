#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include "test.h"
#include "ui.h"
#include "sortSelection.h"
#include "sortSelection.h"
#include "Client.h"

using namespace std;
using namespace ui;
using namespace sortselect;

enum {
	numberOfTest = 5, sizeOfTestFile = 3
};


template<typename T, typename U>
void printInvalid(T received, U expected, string message) {
	cout << message << endl;
	cout << "Ожидалось: " << expected << endl << "Было получено: " << received << endl;
}

void fillingDataForTest(Client** clients) {
	string surname[numberOfTest] = {
		"Kharisov",
		"Ik",
		"Kjoi",
		"Uifa",
		"Yhio"
	};
	string name[numberOfTest] = {
		"Ilyasik",
		"Ily",
		"I3",
		"IYiiiYI",
		"Poopt"
	};
	string middlename[numberOfTest] = {
		"Renativich",
		"Uyyy",
		"Kjjj",
		"Piii",
		"Oiii"
	};
	string address[numberOfTest] = {
		"ylitsa 12",
		"ylitsa 14",
		"ylitsa 16",
		"ylitsa 18",
		"ylitsa 20"
	};
	string telephone[numberOfTest] = {
		"Renativich",
		"Uyyy",
		"Kjjj",
		"Piii",
		"Oiii"
	};
	int cardNum[numberOfTest] = {
		1299,
		879,
		765,
		1233,
		8766
	};
	int bankNum[numberOfTest] = {
		1299,
		879,
		765,
		1233,
		8766
	};

	for (int i = 0; i < numberOfTest; i++) {
		(*clients)[i].setName(name[i]);
		(*clients)[i].setSurname(surname[i]);
		(*clients)[i].setMiddleName(middlename[i]);
		(*clients)[i].setAddress(address[i]);
		(*clients)[i].setTelephone(telephone[i]);
		(*clients)[i].setCardNumber(cardNum[i]);
		(*clients)[i].setBankNumber(bankNum[i]);
	}

}

void creatingFileForTest() {
	ofstream out("test1.txt");
	out << "Ilyas/Lyu/Renatovi/Z14/89963782628/55361937/1009823" << endl;
	out << "a/b/c/d/e/812/1/1" << endl;
	out.close();

	ofstream out2("test2.txt");
	out2 << "" << endl;
	out2 << "" << endl;
	out2.close();

	ofstream out3("test3.txt");
	out3 << "abc/cde/efg/yhh14/7678123/87123/12512/Extra" << endl;
	out3.close();
}

void deleteData(Client** clients) {
	delete[](*clients);
	*clients = nullptr;
}

bool testReadFile() {
	freader fr{};
	string message{};
	string output{};
	string extraErorr = "Слишком много данных в одной строке! Данные будут проигнорированы\n";
	bool correct = true;
	Client* clients = new Client[numberOfTest];
	creatingFileForTest();
	int size = 0;
	stringstream buffer{};
	streambuf* old_cout_buf = cout.rdbuf(buffer.rdbuf());
	fr.implFile(&clients, &size, "test1.txt");
	cout.rdbuf(old_cout_buf);
	message = "Были не пройдены тесты на коректные данные";
	if (size != 2) {
		printInvalid(size, 2, message);
		correct = false;
	}

	delete[]clients;
	clients = nullptr;
	size = 0;
	buffer = {};
	old_cout_buf = cout.rdbuf(buffer.rdbuf());
	message = "Были не пройдены тесты на пустые строчки";
	fr.implFile(&clients, &size, "test2.txt");
	cout.rdbuf(old_cout_buf);
	if (size != 0) {
		printInvalid(size, 0, message);
		correct = false;
	}

	delete[]clients;
	clients = nullptr;
	size = 0;
	message = "Были не пройдены тесты на лишние данные";
	buffer = {};
	old_cout_buf = cout.rdbuf(buffer.rdbuf());
	fr.implFile(&clients, &size, "test3.txt");    
	cout.rdbuf(old_cout_buf);
	output = buffer.str();
	if (extraErorr != output) {
		printInvalid(extraErorr, output, message);
		correct = false;
	}
	if (size != 1) {
		printInvalid(size, 1, message);
		correct = false;
	}
	deleteData(&clients);
	return correct;
}
bool testFillingField() {
	bool correct = true;
	Client* clients = new Client[numberOfTest];
	fillingDataForTest(&clients);
	if (clients[3].getAddress() != "ylitsa 18") {
		printInvalid("ylitsa 18", clients[3].getAddress(), {});
		correct = false;
	}
	if (clients[2].getSurname() != "Kjoi") {
		printInvalid("Kjoi", clients[2].getSurname(), {});
		correct = false;
	}
	if (clients[4].getMiddleName() != "Oiii") {
		printInvalid("Oiii", clients[4].getMiddleName(), {});
		correct = false;
	}
	if (clients[1].getCardNumber() != 879) {
		printInvalid(879, clients[1].getCardNumber(), {});
		correct = false;
	}
	deleteData(&clients);
	return correct;
}

bool testSort() {
	bool correct = true;
	Client* clients = new Client[numberOfTest];
	Client* sortList = nullptr;
	sort sort{};
	string message = "Не был пройден тест на сортировку по алфавиту";
	fillingDataForTest(&clients);
	clients[2].setName("Aaa");
	clients[1].setName("Aad");
	clients[4].setName("Aab");
	clients[0].setName("Car");
	clients[3].setName("Nar");
	sort.sorting(&clients, &sortList, numberOfTest);
	if (sortList[0].getCardNumber() != 765) {
		printInvalid(sortList[0].getCardNumber(), 756, message);
		correct = false;
	}
	if (sortList[1].getCardNumber() != 8766) {
		printInvalid(sortList[0].getCardNumber(), 8766, message);
		correct = false;
	}
	if (sortList[2].getCardNumber() != 879) {
		printInvalid(sortList[0].getCardNumber(), 879, message);
		correct = false;
	}
	if (sortList[3].getCardNumber() != 1299) {
		printInvalid(sortList[0].getCardNumber(), 1299, message);
		correct = false;
	}
	if (sortList[4].getCardNumber() != 1233) {
		printInvalid(sortList[0].getCardNumber(), 1233, message);
		correct = false;
	}
	deleteData(&clients);
	deleteData(&sortList);
	return correct;
}

bool testSelectByCardNum() {
	bool correct = true;
	select select;
	int upper = 0;
	int lower = 0;
	int oldSize = numberOfTest;
	int newSize = 0;
	string message{};
	Client* clients = new Client[numberOfTest];
	Client* list = new Client[numberOfTest];
	fillingDataForTest(&clients);
	lower = 1000;
	upper = 8000;
	newSize = select.selectByNum(&clients, &list, oldSize, lower, upper, true);
	if (newSize != 2) {
		printInvalid(2, newSize, message);
		correct = false;
	}
	deleteData(&clients);
	return correct;
}
bool testRemoveNegative() {
	bool correct = true;
	freader fr{};
	Client* clients = new Client[numberOfTest];

	fillingDataForTest(&clients);
	clients[3].setCardNumber(-1);
	int size = numberOfTest;
	string message = "Были не пройдены тесты на отрицательные значения полей";
	fr.removeNegative(&clients, &size);
	if (size != numberOfTest - 1) {
		printInvalid(numberOfTest - 1, size, message);
		correct = false;
	}
	clients[2].setBankNumber(-100);
	fr.removeNegative(&clients, &size);
	if (size != numberOfTest - 2) {
		printInvalid(numberOfTest - 2, size, message);
		correct = false;
	}
	clients[1].setCardNumber(-10);
	clients[0].setBankNumber(-1000);
	fr.removeNegative(&clients, &size);
	if (size != numberOfTest - 4) {
		printInvalid(numberOfTest - 4, size, message);
		correct = false;
	}
	deleteData(&clients);
	return correct;
}

void test::startTest() {
	if (
		testReadFile() &&
		testRemoveNegative() &&
		testFillingField() &&
		testSort() &&
		testSelectByCardNum()
		) {
		cout << "Все тесты были пройдены! " << endl;
	}
	else {
		
	}
}