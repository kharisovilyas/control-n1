#pragma once
#include <string>

using namespace std;


class Client {
private:
	string name{};
	string surname{};
	string middlename{};
	string address{};
	string telephone{};
	int cardNumber{};
	int bankNumber{};
public:
	string getFIO();
	string getName();
	string getSurname();
	string getMiddleName();
	string getAddress();
	string getTelephone();
	int getCardNumber();
	int getBankNumber();
	void setName(string);
	void setSurname(string);
	void setMiddleName(string);
	void setAddress(string);
	void setTelephone(string);
	void setCardNumber(int);
	void setBankNumber(int);
	bool isNegavive() const {
		return (cardNumber <= 0 || bankNumber <= 0);
	}
	bool operator<(const Client& other) const {
		if (name != other.name) {
			return name < other.name;
		}
		else if (surname != other.surname) {
			return surname < other.surname;
		}
		else {
			return middlename < other.middlename;
		}
	}
};