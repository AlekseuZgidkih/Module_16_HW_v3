#include <iostream>
#include "menu.h"
#include <vector>
#include <memory>
#include <unordered_map> 
#include < map >
#include <string>

using namespace std;

int Menu::findMessage(const string& login) {

	int i = 0;
	for (auto it = messages.begin(); it != messages.end(); ++it)
	{
		if (it->first == _curentName) {
			i++;
			cout << i << endl;
		}
	}
	return i;

}

bool Menu::changeLogin(const string& login) {

	auto itFindLogin = mapUsers.find(login);

	if (itFindLogin != mapUsers.end()) {
		return true;
	}
	return false;
}

void Menu::saveLogPass(string& login, string& password) {														// çàïèñü ëîãèíà
	mapUsers.emplace(login, password);
}

bool Menu::main_menu() {	//char operation	

	char operation;
	cout << " 1 - Enter, 2 - Registration, 0 - Out" << endl;

	cin >> operation;

	switch (operation)
	{
		// enter into profile
	case '1': {																// âõîä â ïðîôèëü

		if (mapUsers.empty()) { cout << "No users" << endl; return true; }	// åñëè áàçà ïóñòàÿ	
		string login, password;

		cout << " Enter login: ";
		cin >> login;

		cout << " Enter password: ";
		cin >> password;

		auto itBegin = mapUsers.find(login);
		if (changeLogin(login) && (itBegin->second == password)) {					// ïðîâåðêà ëîãèíà è ïàðîëÿ ïðîéäåíû

			_curentName = login;							// çàïîìèíàåì òåêóùèé ëîãèí 
			_chatRun = true;
			cout << endl << endl << "\tUser:" << _curentName << " You have: " << findMessage(login) << " messenge(s)." << endl;
		}
		else {
			cout << "Try again" << endl;
		}
		return true;
	}

			// registration
	case '2': {				
		string login, password;

		cout << " Enter login: ";
		cin >> login;

		cout << " Enter password: ";
		cin >> password;

		if (!changeLogin(login)) {
			cout << endl << endl << "\tUser: " << login << ". Registration completed. " << endl;
			saveLogPass(login, password);

			_chatRun = true;
			_curentName = login;
			return true;
		}
		else {
			cout << " Login is busy." << endl;
			return true;
		}
	}

			// Покинуть чат
	case '0': {	
		_chatRun = false;
		_curentName = " ";
		return false;
	}
	default: {
		cout << "wrong command." << endl;
	}
		   return true;
	}
}

bool Menu::chat() {
	char operation;
	cout << "1 - read, 2 - send, 3 - send to all, 4 - delete messages, other - exit" << endl;
	cin >> operation;

	switch (operation)
	{
		// read messages
	case '1': {												
		cout << "read messages" << endl;

		for (auto it = messages.begin(); it != messages.end(); ++it)
		{
			if (it->first == _curentName)
				cout << it->second << endl;
		}
		return true;	
	}

			// send message to ..
	case '2': {	
		cout << " Send to: ";
		string nameTo;
		cin >> nameTo;

		if (!changeLogin(nameTo)) {
			cout << " Recipient not found." << endl;
			break;
		}
		cout << "text: ";// << endl;

		string text;
		cin >> text;

		messages.emplace(nameTo, text);	// add message		

		return true;											
	}

			//send message to all
	case '3': {														
		cout << "text:";
		string text;
		cin >> text;

		for (auto it = mapUsers.begin(); it != mapUsers.end(); ++it) {
			if (it->first == _curentName) continue;
			messages.emplace(it->first, text);
		}
		return true;
	}
		
			// dellete messages
	case '4': {												

		for (auto it = messages.begin(); it != messages.end();) {
			if (it->first == _curentName) {
				it = messages.erase(it);
				continue;
			}
			++it;
		}
		return true;									
	}
	default:
		_chatRun = false;
		return false;								
	}
}
