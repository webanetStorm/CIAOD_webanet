#include <windows.h>
#include <iostream>
#include "Struct.h"

using namespace std;


const string MENU = "\
    \t1 - Вывести таблицу\
    \n\t2 - Добавить вопрос\
    \n\t3 - Сформировать тест\
    \n\t4 - Удалить тему\
    \n\t5 - Автоматически заполнить таблицу\n\
    \t0 - Выход\n";



int main()
{
    Test quiz;
    char menu;


    SetConsoleCP( 1251 );
    SetConsoleOutputCP( 1251 );
    cout << MENU;


    while ( true )
    {

        cout << "\nВыберите действие: ";
        cin >> menu;

        switch ( menu )
        {

            case '1':
            {
                quiz.Echo( quiz.Questions );

                break;
            }

            case '2':
            {
                Question question;

                question = InputQuestion( question );
                quiz.InsertQuestion( question );


                break;
            }

            case '3':
            {
                vector<Question> test = quiz.GenerateTest();

                cout << "Тест сгенерирован:\n";
                quiz.Echo( quiz.GenerateTest() );


                break;
            }

            case '4':
            {
                int id;

                cout << "Укажите ID темы: ";
                cin >> id;

                quiz.RemoveQuestions( id );

                cout << "Тема удалена\n";


                break;
            }

            case '5':
            {
                quiz.AutoFillTest();
                cout << "Вопросы успешно добавлены\n";

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
