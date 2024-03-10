#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const string MENU = "\t1 - Ввести текст\n\t2 - Получить самое длинное слов из уникальных букв\n\t0 - Выход\n";


vector<string> CreateArrayOfWords( string subject )
{
	vector<string> result;
	string word;

	for ( char symbol : subject )
	{
		if ( symbol == ' ' )
		{
			if ( !word.empty() )
			{
				result.push_back( word );
				word = "";
			}

			continue;
		}

		word += symbol;
	}

	if ( !word.empty() )
		result.push_back( word );


	return result;
}

bool AreAllCharsUnique( string subject )
{
    for ( size_t i = 0; i < subject.length(); i++ )
        if ( subject.find( subject[i], i + 1 ) != string::npos )
            return false;

    return true;
}

string FindLongestWord( vector<string> words )
{
	string result = "";

	for ( string word : words )
		if ( AreAllCharsUnique( word ) and word.length() > result.length() )
			result = word;

	return result;
}

int main()
{
	vector<string> words;
	string text, longest;
	char menu;

	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	cout << MENU;


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
				getline( cin, text );
				cout << "Текст успешно записан\n";

				break;
			}

			case '2':
			{
				longest = FindLongestWord( CreateArrayOfWords( text ) );
				longest.empty()
					? cout << "Самое длинное уникальное слово не введено" << endl
					: cout << "Самое длинное уникальное слово: " << longest << endl;

				break;
			}

			case '0':
			{
				return 0;
			}

			default:
			{
				cout << "Некорректный ввод\n";
				cout << MENU;

				break;
			}

		}
	}


    return 0;
}
