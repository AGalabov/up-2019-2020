#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool areEqualRec(int *first1, int *last1, int *first2)
{
    if (first1 == last1)
    {
        return true;
    }

    return *first1 == *first2 && areEqualRec(first1 + 1, last1, first2 + 1);
}

int *minElementInRec(int *first, int *last)
{
    if (last - first < 2)
    {
        return first;
    }

    int *min_rest = minElementInRec(first + 1, last);

    return *first <= *min_rest ? first : min_rest;
}

void sortRec(int *first, int *last)
{
    if (first != last)
    {
        swap(*first, *minElementInRec(first, last));
        sortRec(first + 1, last);
    }
}

bool permutationrec(int *a, int *b, int size)
{
    sortRec(a, a + size);
    sortRec(b, b + size);

    return areEqualRec(a, a + size, b);
}

int main()
{
    int a[] = {1, 1, 2};
    int b[] = {1, 2, 1};
    int c[] = {1, 2, 2};

    cout << permutationrec(a, b, 3) << '\n'  // true (1)
         << permutationrec(a, c, 3) << '\n'; // false (0)

    return 0;
}