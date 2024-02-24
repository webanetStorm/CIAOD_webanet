﻿#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


int PrintMenu()
{
    cout
        << "\t1 - Распечатать матрицу\n"
        << "\t2 - Заполнить матрицу\n"
        << "\t3 - Проверить соблюдение условия задания\n"
        << "\t0 - Выход\n";

    return 0;
}

int PrintMatrix( int** matrix, int matrixOrder )
{
    cout << "Матрица:\n";

    for ( int i = 0; i < matrixOrder; i++ )
    {
        for ( int j = 0; j < matrixOrder; j++ )
            cout << setw( 5 ) << matrix[i][j];
        cout << endl;
    }

    return 0;
}

int InitMatrix( int**& matrix, int matrixOrder )
{
    matrix = new int* [matrixOrder];

    for ( int i = 0; i < matrixOrder; i++ )
        matrix[i] = new int[matrixOrder];

    return 0;
}

int FillMatrixManually( int**& matrix, int matrixOrder )
{
    for ( int i = 0; i < matrixOrder; i++ )
    {
        for ( int j = 0; j < matrixOrder; j++ )
        {
            cout << "Введите элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    return 0;
}

int FillMatrixAutomatically( int**& matrix, int matrixOrder )
{
    srand( static_cast<unsigned int>( time( 0 ) ) );

    for ( int i = 0; i < matrixOrder; i++ )
        for ( int j = 0; j < matrixOrder; j++ )
            matrix[i][j] = rand() % 199 - 99;

    return 0;
}

bool CheckProductOfElements( int** matrix, int matrixOrder )
{
    int productMain = 1, productSecondary = 1;

    for ( int i = 0; i < matrixOrder - 1; i++ )
        productMain *= matrix[i][i + 1];

    for ( int i = 0; i < matrixOrder - 1; i++ )
        productSecondary *= matrix[matrixOrder - 2 - i][i];


    return productMain == productSecondary;
}

int main()
{
    int** matrix = nullptr;
    char menu, subMenu;
    int matrixOrder = 0;

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
                PrintMatrix( matrix, matrixOrder );
                break;
            }

            case '2':
            {
                cout << "Введите порядок матрицы (макс. 10): ";

                if ( !( cin >> matrixOrder ) or matrixOrder > 10 or matrixOrder <= 2 )
                {
                    cout << "Некорректный ввод\n";
                    break;
                }


                InitMatrix( matrix, matrixOrder );


                cout << "\nВыберите способ заполнения матрицы (1 - ручное построчное, 2 - автоматическое): ";
                cin >> subMenu;

                switch ( subMenu )
                {
                    case '1':
                    {
                        FillMatrixManually( matrix, matrixOrder );
                        break;
                    }
                    case '2':
                    {
                        FillMatrixAutomatically( matrix, matrixOrder );
                        break;
                    }
                    default:
                    {
                        cout << "Некорректный ввод\n";
                        break;
                    }
                }

                break;
            }

            case '3':
            {
                CheckProductOfElements( matrix, matrixOrder )
                    ? cout << "(+) Произведение элементов, стоящих над побочной диагональю, РАВНО произведению элементов, стоящих над главной диагональю\n"
                    : cout << "(-) Произведение элементов, стоящих над побочной диагональю, НЕ РАВНО произведению элементов, стоящих над главной диагональю\n";

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


    delete[] matrix;


    return 0;
}