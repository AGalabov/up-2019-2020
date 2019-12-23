#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool areEqual(const int *arr1, int size, const int *arr2)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int indexOfMinValue = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[indexOfMinValue] > arr[j])
            {
                indexOfMinValue = j;
            }
        }
        if (indexOfMinValue != i)
        {
            swap(arr[i], arr[indexOfMinValue]);
        }
    }
}

bool permutation(int *a, int *b, int size)
{
    sort(a, size);
    sort(b, size);

    return areEqual(a, size, b);
}

int main()
{
    int a[] = {1, 1, 2};
    int b[] = {1, 2, 1};
    int c[] = {1, 2, 2};

    cout << permutation(a, b, 3) << '\n'  // true (1)
         << permutation(a, c, 3) << '\n'; // false (0)

    return 0;
}