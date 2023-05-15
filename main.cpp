/*  
 - chat using containers of the standard template library.
 - transmission by constant reference const std::string&. 
 - multimap < string, string>::iterator replaced with auto
 - unordered_map < string, string>::iterator replaced with auto
 - Getter functions must be constant members of the class, i.e. they must be declared with the keyword cons

*/

#include "menu.h"

int main() {
	Menu menu;

	while (menu.main_menu()) {													// Öèêë îñííîâíîãî ìåíþ

		while (menu.getChatRun() && menu.chat()) {								// Åñëè âûïîëíåí âõîä è âûçîâ ìåíþ ÷àò
		}
	}
	return 0;
}
