#include <iostream>
#include "Client.h"
#include "ui.h"
#include "sortSelection.h"
#include "test.h"

using namespace ui;
using namespace sortselect;

enum { returnp = 0, task1 = 1, task2 = 2};
enum { exitp = 0, rfile = 1, rconsole = 2, unitTest = 3 };
enum { outreturn = 0, fileOutput = 1, coutput = 2};

void selectImplTask(int variant, Client** clients, Client** sortList, int* size, int* sizeSort) {
    sort sorting{};
    select select{};
    switch (variant)
    {
    case task1:
        sorting.sorting(clients, sortList, *size);
        *sizeSort = *size;
        break;
    case task2:
        *sizeSort = select.selectByNum(clients, sortList, *size, {}, 0, false);
        break;
    case returnp:
        cout << "Вы вышли !" << endl;
        break;
    }
}

void selectInput(int variant, Client** clients, int* size) {
    correct correctness{};
    freader freader{};
    creader creader{};
    test mTest;
    switch (variant)
    {
    case exitp:
        cout << "Вы вышли !" << endl;
        break;
    case rfile:
        *size = freader.readFile(clients, {});
        break;
    case rconsole:
        *size = creader.readConsole(clients);
        break;
    case unitTest:
        mTest.startTest();
    }
}

void selectOutput(int variant, Client** sortList, int size) {
    creader creader{};
    freader freader{};
    switch (variant)
    {
    case fileOutput:
        freader.fillFile(sortList, size);
        break;
    case coutput:
        creader.outConsole(sortList, size);
        break;

    case outreturn:
        cout << "Вы вышли !" << endl;
        break;
    }
}

void launchMenu() {
    correct correctness{};
    informing info{};
    int variant = 0;
    int boardMenu = unitTest;
    int sizeSort = 0;
    int size = 0;
    Client* clients = nullptr;
    Client* sortList = nullptr;
    do
    {
        info.printInputWays();
        variant = correctness.getMenuVar(exitp, unitTest);
        try {
            selectInput(variant, &clients, &size);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            continue;
        }
        if (variant == exitp) break;
        if (variant == unitTest) continue;
        do {
            info.printAction();
            boardMenu = task2;
            variant = correctness.getMenuVar(returnp, boardMenu);
            if (variant == returnp) break;
            try {
                selectImplTask(variant, &clients, &sortList, &size, &sizeSort);
            }
            catch (const exception& e) {
                cout << e.what() << endl;
                continue;
            }
            do {
                info.printOutputWays();
                boardMenu = coutput;
                variant = correctness.getMenuVar(outreturn, boardMenu);
                if (variant == outreturn) break;
                try {
                    selectOutput(variant, &sortList, sizeSort);
                }
                catch (const exception& e) {
                    cout << e.what() << endl;
                    continue;
                }
                delete[]sortList;
                sortList = nullptr;
            } while (variant != returnp);
        } while (variant != returnp);
        delete[]clients;
        clients = nullptr;
    } while (variant != exitp);
}


int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Rus");
    informing info{};
    info.outGretting();
    launchMenu();
    system("pause");
}
