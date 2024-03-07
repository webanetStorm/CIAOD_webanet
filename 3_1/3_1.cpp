#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;


const int MAX_TEXT_LENGTH = 1000;


int PrintMenu()
{
	cout << "\t1 - Ввести текст\n\t2 - Получить самое длинное слов из уникальных букв\n\t0 - Выход\n";

	return 0;
}

int main()
{
	char menu, text[MAX_TEXT_LENGTH];

	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	PrintMenu();


	while ( true )
	{
		cout << "\nВыберите действие: ";
		cin >> menu;
		cin.ignore();

		switch ( menu )
		{

			case '1':
			{
				cout << "Введите текст: ";
				cin.getline( text, MAX_TEXT_LENGTH );
				cout << "Текст успешно записан\n";

				break;
			}

			case '2':
			{
				cout << text;

				break;
			}

			case '0':
			{
				return 0;
			}

			default:
			{
				cout << "Некорректный ввод\n";
				PrintMenu();

				break;
			}

		}
	}


	return 0;
}
