#include <iostream>
#include <cstring>

using namespace std;

//Assuming this function is called on letters only
int toLetterIndex(char x)
{
    if ('a' <= x && x <= 'z')
    {
        return x - 'a';
    }

    return x - 'A';
}

/*
* Putting const in front makes the value immutable
* Therfore any attempts at changing it will lead to an error
*/
void countLettersRec(const char *first1, const char *first2, int *letterBallance)
{
    if (*first1 == '\0')
    {
        return;
    }
    int str1LetterIndex = toLetterIndex(*first1);
    int str2LetterIndex = toLetterIndex(*first2);

    letterBallance[str1LetterIndex]++;
    letterBallance[str2LetterIndex]--;
    countLettersRec(first1 + 1, first2 + 1, letterBallance);
}

bool isZeroFilledRec(const int *first, const int *last)
{
    if (first == last)
    {
        return *first == 0;
    }
    if (*first != 0)
    {
        return false;
    }
    return isZeroFilledRec(first + 1, last);
}

bool shufflerec(const char *str1, const char *str2)
{
    //The English alphabet has 26 letters
    int letterBallance[26] = {0};

    countLettersRec(str1, str2, letterBallance);

    return isZeroFilledRec(letterBallance, letterBallance + 25);
}

int main()
{
    cout << shufflerec("Exam", "MaXe") << '\n'  // true (1)
         << shufflerec("AsDa", "AsdD") << '\n'; // false (0)

    return 0;
}