/* ��� � �������������� ����������� ����������� ���������� ��������.
 - �������� �� ����������� ������ const std::string&. 
  - multimap < string, string >::iterator ������� �� auto
  - unordered_map < string, string >::iterator ������� �� auto
  -  �������-������� ������ ���� ������������ ������� ������, �. �. ������ ���� ��������� � �������� ������ cons
  

*/

#include "menu.h"

int main() {
	Menu menu;

	while (menu.main_menu()) {													// ���� ���������� ����

		while (menu.getChatRun() && menu.chat()) {								// ���� �������� ���� � ����� ���� ���
		}
	}
	return 0;
}