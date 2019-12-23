#include <cstring>
#include <iostream>

using namespace std;

/*
* This is a globally declared variable
* It can be used in every function in this file
*/
const int sizeOfMatrix = 5;

bool isLetter(char x)
{
    return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}

bool areAdjacentLetters(char a, char b)
{
    if (isLetter(a) && isLetter(b))
    {
        return b - a == 1;
    }
    return false;
}

/*
* Putting const in front makes the value immutable
* Therfore any attempts at changing it will lead to an error
*/
void readFrom(const char A[sizeOfMatrix][sizeOfMatrix], int xIndex, int yIndex, char *s)
{
    *s = A[xIndex][yIndex];
    if (areAdjacentLetters(A[xIndex][yIndex], A[xIndex][yIndex + 1]))
    {
        readFrom(A, xIndex, yIndex + 1, s + 1);
    }
    else if (areAdjacentLetters(A[xIndex][yIndex], A[xIndex + 1][yIndex]))
    {
        readFrom(A, xIndex + 1, yIndex, s + 1);
    }
}

void read(const char A[sizeOfMatrix][sizeOfMatrix], char *s)
{
    int startIndexX = 0;
    int startIndexY = 0;

    readFrom(A, startIndexX, startIndexY, s);
}

int main()
{
    const char A[sizeOfMatrix][sizeOfMatrix]{
        {'b', 'c', 'g', 'o', 'd'},
        {'r', 'd', 'e', 'a', 't'},
        {'1', 'd', 'f', 'g', 'h'},
        {'d', 'e', 'f', 'g', 'i'},
        {'6', 'd', 'o', '9', 'i'}};

    char str[11];

    read(A, str);

    cout << str << endl; // bcdefghi

    return 0;
}