#include <iostream>
#include <cstring>

using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

int fibonacci(int n)
{
    int prev1 = 0, prev2 = 1;
    if (n <= 1)
        return prev1;
    if (n == 2)
        return prev2;
    for (int i = 3; i <= n; ++i)
    {
        int newNum = prev1 + prev2;
        prev1 = prev2;
        prev2 = newNum;
    }
    return prev2;
}

bool isPrime(int num)
{
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int charToInt(char c)
{
    return c - '0';
}

int toInt(char str[])
{
    int length = strlen(str);
    int num = 0;
    for (int i = 0; i < length; ++i)
    {
        int digit = charToInt(str[i]);
        num = num * 10 + digit;
    }
    return num;
}

void swapValues(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getMaxElemOf(int arr[], int n)
{
    int maxElem = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > maxElem)
        {
            swapValues(arr[i], maxElem);
        }
    }
    return maxElem;
}

void strcat(char str1[], char str2[])
{
    int lengthOfStr1 = strlen(str1);
    int lengthOfStr2 = strlen(str2);
    // Notice i <= lengthOfStr2 ... the = is so that we append the '\0' symbol at the end
    for (int i = 0; i <= lengthOfStr2; ++i)
    {
        str1[lengthOfStr1 + i] = str2[i];
    }
}

void printIsPrime(int x)
{
    if (isPrime(x))
    {
        cout << x << " is prime! ";
    }
    else
        cout << x << " is not prime! ";
}

int main()
{
    cout << "factorial tests: " << factorial(3) << " " << factorial(5) << endl;
    cout << "fibonacci tests: " << fibonacci(1) << " " << fibonacci(2) << " " << fibonacci(10) << endl;
    cout << "isPrime tests: ";
    printIsPrime(2);
    printIsPrime(7);
    printIsPrime(4);
    cout << endl;

    char num1[5] = "123";
    char num2[5] = "45";
    cout << "toInt tests: " << toInt(num1) << " " << toInt(num2) << " sum: " << toInt(num1) + toInt(num2) << endl;

    int arr[5] = {1, 102, 42, 2, -1};

    cout << "getMaxElemOf test: " << getMaxElemOf(arr, 5) << endl;

    char str1[100] = "Hello, ";
    char str2[10] = "world!";

    cout << "strcat test" << endl;
    cout << "str1 BEFORE strcat: " << str1 << endl;
    strcat(str1, str2);
    cout << "str1 AFTER strcat: " << str1 << endl;
}