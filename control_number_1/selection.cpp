#include <iostream>
#include "ui.h"
#include "Client.h"
#include "sortSelection.h"
#include <string>
#include <cstring>


using namespace std;
using namespace ui;
using namespace sortselect;


int select::selectByNum(Client** clients, Client** sortList, int size, int lower, int upper, bool isTest) {
	correct correctness{};
	informing info{};
	int i = 0;
	int iter = 0;
	*sortList = new Client[size];
	if (!isTest) {
		info.printInfoSelectLow();
		lower = correctness.getIntField();
		info.printInfoSelectUpper();
		upper = correctness.getIntField();
	}
	for (; i < size; i++) {
		int num = (*clients)[i].getCardNumber();
		if (num >= lower && num <= upper) {
			(*sortList)[iter] = (*clients)[i];
			iter++;
		}
	}
	return iter;
}