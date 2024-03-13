#include <iostream>
#include <vector>
#include <string>


using namespace std;


struct Question
{

    int themeNumber;

    string questionText;

    int points;

    vector<string> answerOptions;

    int correctAnswerIndex;

};


struct QuestionTable
{

    vector<Question> questions;

};


int main()
{
    return 0;
}
