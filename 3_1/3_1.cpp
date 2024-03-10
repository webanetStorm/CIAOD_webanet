#include <windows.h>
#include <iostream>

using namespace std;


const int MAX_TEXT_LENGTH = 1024;
const int MAX_NUM_WORDS = 64;


int CreateArrayOfWords( char* text, char** words )
{
	int result = 0;
	char* word = strtok( text, " " );

	while ( word != NULL )
	{
		words[result] = new char[strlen( word ) + 1];
		strcpy( words[result++], word );
		word = strtok( NULL, " " );
	}

	return result;
}

bool AreAllCharsUnique( char* word )
{
	for ( int i = 0; i < strlen( word ) - 1; i++ )
		for ( int j = i + 1; j < strlen( word ); j++ )
			if ( word[i] == word[j] )
				return false;

	return true;
}

char* FindLongestWord( char** words, int wordCount )
{
	char* result = NULL;
	int maxLength = 0;

	for ( int i = 0; i < wordCount; i++ )
	{
		if ( AreAllCharsUnique( words[i] ) and strlen( words[i] ) > maxLength )
		{
			maxLength = strlen( words[i] );
			result = words[i];
		}
	}

	return result;
}

int main()
{
	char menu, text[MAX_TEXT_LENGTH], *words[MAX_NUM_WORDS];
	int wordCount = 0;

	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );

	cout << "\t1 - Ввести текст\n\t2 - Получить самое длинное слов из уникальных букв\n\t0 - Выход\n";


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
				cin.getline( text, sizeof( text ) );
				cout << "Текст успешно записан\n";
				
				break;
			}

			case '2':
			{
				char* longest = FindLongestWord( words, CreateArrayOfWords( text, words ) );

				longest == NULL
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
				cout << "Некорректный ввод\n\t1 - Ввести текст\n\t2 - Получить самое длинное слов из уникальных букв\n\t0 - Выход\n";

				break;
			}

		}
	}


	return 0;
}
