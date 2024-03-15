#include <windows.h>
#include <iostream>
#include <format>
#include <random>
#include <ctime>
#include "Struct.h"

using namespace std;



int Question::_nextId = 1;

Question::Question() = default;

Question::Question(
    int themeId,
    string questionText,
    int points,
    vector<string> answerOptions,
    int correctAnswerIndex
) :
    ThemeId( themeId ),
    QuestionText( questionText ),
    Points( points ),
    CorrectAnswerIndex( correctAnswerIndex ),
    AnswerOptions( answerOptions )
{
    Id = _nextId++;
}

string Question::ToFormatString()
{
    string options;

    for ( int i = 0; i < AnswerOptions.size(); i++ )
        options += format( "{}.{} ", (char)( 'а' + i ), AnswerOptions[i] );

    return format( "|{:^4}|{:^4}|{:^52}|{:^52}|\n{:-^117}",
        ThemeId,
        Points,
        QuestionText,
        options,
        ""
    );
}



Test::Test() = default;

void Test::Echo( vector<Question> questions )
{
    cout << format( "|{:^4}|{:^4}|{:^52}|{:^52}|\n{:=^117}\n",
        "Тема",
        "Балл",
        "Вопрос",
        "Варианты ответов",
        ""
    );

    for ( int i = 0; i < questions.size(); i++ )
        cout << questions.at( i ).ToFormatString() << endl;
}

void Test::InsertQuestion( Question question )
{
    Questions.insert( find_if( Questions.begin(), Questions.end(), [question]( Question q )
    {
        return q.ThemeId > question.ThemeId;
    } ), question );
}

void Test::RemoveQuestions( int themeId )
{
    Questions.erase( remove_if( Questions.begin(), Questions.end(), [themeId]( Question& q )
    {
        return q.ThemeId == themeId;
    } ), Questions.end() );
}

vector<Question> Test::GenerateTest()
{
    vector<Question> result;
    int prevTopicNumber = 0;

    srand( time( 0 ) );


    for ( int i = 0; i < Questions.size(); i++ )
    {

        Question currentElem = Questions[i];

        if ( prevTopicNumber == currentElem.ThemeId )
            continue;

        prevTopicNumber = currentElem.ThemeId;



        auto index = find_if( Questions.begin() + i + 1, Questions.end(), [currentElem]( Question q )
        {
            return q.ThemeId != currentElem.ThemeId;
        } );


        int firstRandomIndex = rand() % ( index - Questions.begin() - i ) + i, secondRandomIndex;
        result.push_back( Questions[firstRandomIndex] );

        if ( index - Questions.begin() - i > 1 )
        {
            while ( firstRandomIndex == ( secondRandomIndex = rand() % ( index - Questions.begin() - i ) + i ) )
            {
            };
            result.push_back( Questions[secondRandomIndex] );
        }

    }


    return result;
}

void Test::AutoFillTest()
{
    InsertQuestion( Question( 1, "2 + 2 = ?", 1, { "1", "2", "3", "4" }, 4 ) );
    InsertQuestion( Question( 1, "3 - 4 = ?", 2, { "-1", "1", "-7", "7" }, 1 ) );
    InsertQuestion( Question( 1, "5 * 5 = ?", 2, { "5", "25", "55", "10" }, 2 ) );
    InsertQuestion( Question( 1, "0 / 2 = ?", 2, { "2", "0" }, 2 ) );
    InsertQuestion( Question( 2, "Столица Венгрии?", 5, { "Будапешт", "Берн", "Бухарест", "Брест" }, 1 ) );
    InsertQuestion( Question( 2, "Наибольшая по площади страна?", 5, { "Бельгия", "Германия", "Франция" }, 3 ) );
    InsertQuestion( Question( 2, "Древнейший город?", 10, { "Вологда", "Иркутск", "Владивосток", "Керчь" }, 4 ) );
    InsertQuestion( Question( 3, "Лучший ЯП?", 15, { "Java", "C++", "PHP", "Kotlin", "Lua" }, 3 ) );
    InsertQuestion( Question( 3, "Сколько бит в байте?", 10, { "1000", "1024", "8", "2", "16" }, 3 ) );
    InsertQuestion( Question( 3, "PHP-фреймворк?", 20, { "Yii", "Angular", "Django" }, 1 ) );
    InsertQuestion( Question( 3, "'2' .(+) '2' = ?", 10, { "4", "22", "0" }, 2 ) );
    InsertQuestion( Question( 3, "IPS Invision Community написан на...", 25, { "Python", "Ruby", "PHP", "Perl" }, 3 ) );
    InsertQuestion( Question( 3, "Хостер?", 18, { "IPS", "Beget", "ООО \"Большие надежды\"", "ВНИИА" }, 2 ) );
}



Question InputQuestion( Question& obj )
{
    int optionsCount;
    string option;


    cout << "Введите ID темы: ";
    cin >> obj.ThemeId;

    cout << "Введите текст вопроса: ";
    cin.ignore();
    getline( cin, obj.QuestionText );

    cout << "Введите количество баллов за правильный ответ: ";
    cin >> obj.Points;

    cout << "Введите количество вариантов ответов: ";
    cin >> optionsCount;
    cin.ignore();

    for ( int i = 0; i < optionsCount; i++ )
    {
        cout << "Введите вариант ответа " << i + 1 << ": ";
        getline( cin, option );

        obj.AnswerOptions.push_back( option );
    }

    cout << "Введите номер правильного ответа: ";
    cin >> obj.CorrectAnswerIndex;


    return obj;
}
