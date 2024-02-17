#include <iostream>
#include <vector>


using namespace std;


int PrintMenu()
{
	cout
		<< "\t1 - Вывод массива\n"
		<< "\t2 - Добавить элемент\n"
		<< "\t3 - Удалить элемент\n"
		<< "\t4 - Сформировать новый массив\n"
		<< "\t5 - Удалить мин. число нового массива\n"
		<< "\t6 - Определить, у скольких чисел исх. массива цифры образуют возр. п-сть\n"
		<< "\t0 - Выход\n";

	return 0;
}

int PrintArray( vector<int> array )
{
	cout << "Массив: ";

	for ( int elem : array )
		cout << elem << ' ';
	cout << endl;


	return 0;
}

int AddToArray( vector<int>& array, int newNumber )
{
	array.push_back( newNumber );

	return 0;
}

int RemoveFromArray( vector<int>& array, int position )
{
	if ( position >= array.size() )
		return -1;

	array.erase( array.begin() + position );

	return 0;
}

int SumOfDigits( int number )
{
	int result = 0;
	number = abs( number );

	while ( number > 0 )
	{
		result += number % 10;
		number /= 10;
	}

	return result;
}

int CreateNewArray( vector<int> arrayA, vector<int>& arrayB )
{
	for ( int i = 0; i < arrayA.size(); i++ )
	{
		if ( SumOfDigits( arrayA[i] ) % 7 == 0 )
		{
			if ( arrayB.size() > 0 )
			{
				auto position = arrayB.begin() + 1;

				while ( position != arrayB.end() and *position > arrayA[i] )
					position++;

				arrayB.insert( position, arrayA[i] );
			}
			else
				arrayB.push_back( arrayA[i] );
		}
	}

	return 0;
}

int FindMinElement( vector<int> array )
{
	int value = INT_MAX, index = -1;

	for ( int i = 0; i < array.size(); i++ )
	{
		if ( array[i] < value )
		{
			value = array[i];
			index = i;
		}
	}

	return index;
}

bool IsAscendingSequence( int number )
{
	number = abs( number );

	int currentDigit = number % 10;
	number /= 10;

	while ( number > 0 )
	{
		int nextDigit = number % 10;

		if ( nextDigit >= currentDigit )
			return false;

		currentDigit = nextDigit;
		number /= 10;
	}

	return true;
}

int CountAscendingSequences( vector<int> array )
{
	int result = 0;

	for ( int elem : array )
		if ( IsAscendingSequence( elem ) )
			result++;

	return result;
}

int main()
{
	vector<int> array, newArray;
	int tempNumber;
	char menu, subMenu;

	setlocale( LC_ALL, "Russian" );
	PrintMenu();

	while ( true )
	{
		cout << "\nВыберите действи1е: ";
		cin >> menu;

		switch ( menu )
		{

			case '1':
			{
				cout << "\nВыберите массив (1 или 2): ";
				cin >> subMenu;

				switch ( subMenu )
				{
					case '1':
					{
						PrintArray( array );
						break;
					}
					case '2':
					{
						PrintArray( newArray );
						break;
					}
					default:
					{
						cout << "Указан номер несуществующего массива\n";
						break;
					}
				}

				break;
			}

			case '2':
			{
				cout << "Введите число: ";
				cin >> tempNumber;

				AddToArray( array, tempNumber );
				cout << "Элемент добавлен\n";

				break;
			}

			case '3':
			{
				cout << "Введите позицию: ";
				cin >> tempNumber;

				RemoveFromArray( array, tempNumber ) == 0 ? cout << "Элемент успешно удален\n" : cout << "Такого элемента нет\n";


				break;
			}

			case '4':
			{
				CreateNewArray( array, newArray );
				cout << "Новый массив успешно сформирован\n";


				break;
			}

			case '5':
			{
				RemoveFromArray( newArray, FindMinElement( newArray ) ) == 0
					? cout << "Элемент успешно удален\n"
					: cout << "Массив пуст\n";

				break;
			}

			case '6':
			{
				cout << "Кол-во чисел исх. массива, цифры которого образуют возр. посл-сть: " << CountAscendingSequences( array ) << endl;

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

}
