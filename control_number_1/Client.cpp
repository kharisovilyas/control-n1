#include "Client.h"
#include <iostream>
using namespace std;

//getter возвращают значение поля
string Client::getTelephone() {
	return telephone;
}

int Client::getCardNumber() {
	return cardNumber;
}

int Client::getBankNumber() {
	return bankNumber;
}

string Client::getFIO() {
	return name + " " + surname + " " + middlename;
}

string Client::getName(){
	return name;
}

string Client::getSurname()
{
	return surname;
}

string Client::getMiddleName()
{
	return middlename;
}


string Client::getAddress()
{
	return address;
}


void Client::setName(string newName) {
	name = newName;
}
void Client::setSurname(string newSurname) {
	surname = newSurname;
}
void Client::setMiddleName(string newMiddleName) {
	middlename = newMiddleName;
}
void Client::setAddress(string newAddress) {
	address = newAddress;
}
void Client::setTelephone(string newTelephone) {
	telephone = newTelephone;
}
void Client::setCardNumber(int newCardNum) {
	cardNumber = newCardNum;
}
void Client::setBankNumber(int newBankNum) {
	bankNumber = newBankNum;
}