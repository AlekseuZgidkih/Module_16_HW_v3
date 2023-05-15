/* чат с использованием контейнеров стандартной библиотеки шаблонов.
 - передача по константной ссылке const std::string&. 
  - multimap < string, string >::iterator заменен на auto
  - unordered_map < string, string >::iterator заменен на auto
  -  Функции-геттеры должны быть константными членами класса, т. е. должны быть объявлены с ключевым словом cons
  

*/

#include "menu.h"

int main() {
	Menu menu;

	while (menu.main_menu()) {													// Цикл оснновного меню

		while (menu.getChatRun() && menu.chat()) {								// Если выполнен вход и вызов меню чат
		}
	}
	return 0;
}