#include <iostream>
#include "ui.h"
#include "Client.h"
#include "sortSelection.h"
#include <string>
#include <cstring>


using namespace std;
using namespace ui;
using namespace sortselect;


void sort::sorting(Client** clients, Client** sortList, int size) {
    informing info{};
    int i = 0;
    *sortList = new Client[size];
    for (i = 0; i < size; i++) {
        (*sortList)[i] = *(*clients + i);
    }
    // Сортировка вставками
    for (i = 1; i < size; i++) {
        Client tmp = (*sortList)[i];
        int j = i - 1;
        while (j >= 0 && tmp < (*sortList)[j]) {
            (*sortList)[j + 1] = (*sortList)[j];
            j--;
        }
        (*sortList)[j + 1] = tmp;
    }
}