#include <iostream>


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

int PrintArray( int* array, int size )
{
	cout << "Массив: ";

	for ( int i = 0; i < size; i++ )
		cout << array[i] << ' ';
	cout << endl;

	return 0;
}

int AddToArray( int*& array, int& size, int newNumber )
{
	array = (int*)realloc( array, ++size * sizeof( int ) );
	array[size - 1] = newNumber;

	return 0;
}

int RemoveFromArray( int*& array, int& size, int position )
{
	if ( size <= 0 )
		return -1;
	if ( position >= size )
		return -2;

	for ( int i = position; i < size - 1; i++ )
		array[i] = array[i + 1];

	array = (int*)realloc( array, ( --size ) * sizeof( int ) );


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

int CreateNewArray( int* arrayA, int* arrayB, int sizeA, int& sizeB )
{
	sizeB = 0;

	for ( int i = 0; i < sizeA; i++ )
	{
		if ( SumOfDigits( arrayA[i] ) % 7 == 0 )
		{
			int j = sizeB++ - 1;

			while ( j >= 1 and arrayB[j] < arrayA[i] )
				j--;

			for ( int k = sizeB - 1; k > j + 1; k-- )
				arrayB[k] = arrayB[k - 1];

			arrayB[j + 1] = arrayA[i];
		}
	}

	return 0;
}

int FindMinElement( int* array, int size )
{
	int value = INT_MAX, index = -1;

	for ( int i = 0; i < size; i++ )
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

int CountAscendingSequences( int* array, int size )
{
	int result = 0;

	for ( int i = 0; i < size; i++ )
		if ( IsAscendingSequence( array[i] ) )
			result++;

	return result;
}

int main()
{
	int* dynamicArray = new int[0];
	int* newDynamicArray = new int[0];
	int currentArraySize = 0, currentNewArraySize = 0, tempNumber;
	char menu, subMenu;

	setlocale( LC_ALL, "Russian" );
	PrintMenu();

	while ( true )
	{
		cout << "\nВыберите действие: ";
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
						PrintArray( dynamicArray, currentArraySize );
						break;
					}
					case '2':
					{
						PrintArray( newDynamicArray, currentNewArraySize );
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

				AddToArray( dynamicArray, currentArraySize, tempNumber );
				cout << "Элемент успешно добавлен\n";

				break;
			}

			case '3':
			{
				cout << "Введите позицию: ";
				cin >> tempNumber;

				switch ( RemoveFromArray( dynamicArray, currentArraySize, tempNumber ) )
				{
					case 0:
					{
						cout << "Элемент успешно удален\n";
						break;
					}
					case -1:
					{
						cout << "Массив пуст\n";
						break;
					}
					case -2:
					{
						cout << "Такого элемента нет\n";
						break;
					}
				}

				break;
			}

			case '4':
			{
				CreateNewArray( dynamicArray, newDynamicArray, currentArraySize, currentNewArraySize );
				cout << "Новый массив успешно сформирован\n";

				break;
			}

			case '5':
			{
				RemoveFromArray( newDynamicArray, currentNewArraySize, FindMinElement( newDynamicArray, currentNewArraySize ) ) == 0
					? cout << "Элемент успешно удален\n"
					: cout << "Массив пуст\n";

				break;
			}

			case '6':
			{
				cout << "Кол-во чисел исх. массива, цифры которого образуют возр. посл-сть: "
					<< CountAscendingSequences( dynamicArray, currentArraySize ) << endl;

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

	delete[] dynamicArray;
	delete[] newDynamicArray;

}
