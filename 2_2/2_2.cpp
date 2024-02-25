#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


int PrintMenu()
{
    cout
        << "\t1 - Распечатать матрицу точек\n"
        << "\t2 - Задать координаты точек\n"
        << "\t3 - Получить вертикальную медиану множества\n"
        << "\t0 - Выход\n";

    return 0;
}

int PrintMatrix( vector<vector<int>> points )
{
    cout << "Матрица:\n";

    for ( vector<int> row : points )
    {
        for ( int elem : row )
            cout << setw( 5 ) << elem;
        cout << endl;
    }

    return 0;
}

bool IsXUnique( vector<vector<int>> points, int x )
{
    for ( vector<int> row : points )
        if ( x == row[0] )
            return false;

    return true;
}

int FillMatrix( vector<vector<int>>& points, int x, int y )
{
    if ( !IsXUnique( points, x ) )
        return -1;

    points.push_back( { x, y } );

    return 0;
}

int InsertionSortByX( vector<vector<int>>& points )
{
    for ( int i = 1; i < points.size(); i++ ) 
    {
        vector<int> row = points[i];
        int j = i - 1;

        while ( j >= 0 and points[j][0] > row[0] )
        {
            points[j + 1] = points[j];
            j--;
        }

        points[j + 1] = row;
    }

    return 0;
}

vector<int> GetMedian( vector<vector<int>> points )
{
    InsertionSortByX( points );

    return points[points.size() / 2];
}

int main()
{
    vector<vector<int>> points;
    int amountOfPoints;
    char menu;


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
                PrintMatrix( points );

                break;
            }

            case '2':
            {
                cout << "Введите нечетное количество точек: ";

                if ( !( cin >> amountOfPoints ) or amountOfPoints % 2 == 0 )
                {
                    cout << "Необходимо ввести нечетное кол-во точек на плоскости\n";
                    break;
                }


                int x, y;

                for ( int i = 0; i < amountOfPoints; )
                {
                    cout << "Введите координаты точки " << i + 1 << " (X и Y):\n";
                    cin >> x >> y;

                    if ( FillMatrix( points, x, y ) == -1 )
                        cout << "Координаты по оси X должны быть уникальными\n";
                    else
                        i++;
                }


                break;
            }

            case '3':
            {
                vector<int> median = GetMedian( points );
                cout << "Точка медианы: (" << median[0] << ", " << median[1] << ")\n";

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
