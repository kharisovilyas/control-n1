#pragma once
#include "Client.h"
namespace ui {
	class correct {
	public:
		int getInt();
		int getMenuVar(int, int);
		double getDouble();
		bool getBool();
		int getIntField();
		double getDoubleField();
	};

	class informing {
	public:
		void printInformFout();
		void printInformFin();
		void printInformNameOfFile();
		void printCorrect();
		void printInfoSelectLow();
		void printInfoSelectUpper();
		void outGretting();
		void printInputWays();
		void printAction();
		void printOutputWays();
	};

	class creader {
	public:
		int readConsole(Client**);
		void outConsole(Client**, int);
	};

	class freader {
	public:
		int readFile(Client**, string);
		void fillFile(Client**, int);
		void implFile(Client**, int*, string);
		void filling(Client**, const char*, int);
		void removeNegative(Client**, int*);
		void outInitialDataInFile(Client**, int) const;
	};
}