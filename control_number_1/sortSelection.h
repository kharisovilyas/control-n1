#pragma once
#include "Client.h"
namespace sortselect {
	class select {
	public:
		int selectByNum(Client**, Client**, int, int, int, bool);
	};
	class sort {
	public:
		void sorting(Client**, Client**, int);
	};
}
