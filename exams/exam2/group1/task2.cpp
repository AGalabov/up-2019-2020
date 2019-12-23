#include <cstring>
#include <iostream>

using namespace std;

/*
* This is a globally declared variable
* It can be used in every function in this file
*/
const int sizeOfMatrix = 5;

/*
* Putting const in front makes the value immutable
* Therfore any attempts at changing it will lead to an error
*/
bool containsAtRow(const char A[sizeOfMatrix][sizeOfMatrix], const char *s, int rowIndex)
{
    int indexForS = 0;
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
        if (s[indexForS] == '\0')
        {
            return true;
        }
        if (A[rowIndex][i] == s[indexForS])
        {
            indexForS++;
        }
        else
        {
            indexForS = 0;
        }
    }
    return s[indexForS] == '\0';
}

bool containsAtColumn(const char A[sizeOfMatrix][sizeOfMatrix], const char *s, int columnIndex)
{
    int indexForS = 0;
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
        if (s[indexForS] == '\0')
        {
            return true;
        }
        if (A[i][columnIndex] == s[indexForS])
        {
            indexForS++;
        }
        else
        {
            indexForS = 0;
        }
    }
    return s[indexForS] == '\0';
}

bool contains(const char A[sizeOfMatrix][sizeOfMatrix], const char *s)
{
    for (int i = 0; i < sizeOfMatrix; ++i)
    {
        if (containsAtColumn(A, s, i) || containsAtRow(A, s, i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    const char A[sizeOfMatrix][sizeOfMatrix]{
        {'a', 'b', 'g', 'o', 'd'},
        {'r', 'o', 'c', 'a', 't'},
        {'1', '2', 'a', '4', '5'},
        {'d', 'e', 't', 'd', 'o'},
        {'6', 'd', 'o', '9', 'g'}};

    cout << contains(A, "rocat") << '\n' // true(1)
         << contains(A, "god") << '\n'   // true(1)
         << contains(A, "dog") << '\n'   // false(0)
         << contains(A, "bo2ed") << '\n' // true(1)
         << contains(A, "r1d") << '\n'   // true(1)
         << contains(A, "zzz") << '\n';  // false(0)

    return 0;
}