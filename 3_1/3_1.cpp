#include <windows.h>
#include <iostream>

using namespace std;


const int MAX_WORD_LENGTH = 100;
const int MAX_WORDS = 100;


char** CreateArrayOfWords( char* subject, int* count )
{
	char** result = (char**)malloc( MAX_WORDS * sizeof( char* ) );
	char* word = strtok( subject, " " );
	*count = 0;

	while ( word != NULL and *count < MAX_WORDS )
	{
		result[*count] = (char*)malloc( ( strlen( word ) + 1 ) * sizeof( char ) );
		strcpy( result[*count], word );
		( *count )++;
		word = strtok( NULL, " " );
	}

	return result;
}

bool AreAllCharsUnique( char* word )
{
	for ( int i = 0; i < strlen( word ) - 1; i++ )
		for ( int j = i + 1; j < strlen( word ); j++ )
			if ( word[i] == word[j] )
				return true;

	return false;
}

char* FindLongestWord( char** words, int count )
{
	char* result = new char;
	int maxLength = 0;

	for ( int i = 0; i < count; i++ )
	{
		if ( AreAllCharsUnique( words[i] ) and strlen( words[i] ) > maxLength )
		{
			result = words[i];
			maxLength = strlen( words[i] );
		}
	}

	return result;
}

int main()
{
	char menu, text[1024] = { 0 }, *longest, **words;
	int wordsCount;

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

				fgets( text, sizeof( text ), stdin );
				text[strcspn( text, "\n" )] = 0;

				cout << "Текст успешно записан\n";


				break;
			}

			case '2':
			{
				words = CreateArrayOfWords( text, &wordsCount );
				longest = FindLongestWord( words, wordsCount );

				strlen( longest ) == 0 
					? cout << "Самое длинное уникальное слово не введено\n"
					: cout << "Самое длинное уникальное слово: " << longest << endl;

				for ( int i = 0; i < wordsCount; i++ ) 
					free( words[i] );
				free( words );


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
