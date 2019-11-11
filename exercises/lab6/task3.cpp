#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[1001];
    cin.getline(str, 1001);

    int histogram['z' - 'a' + 1]; // 26 letters
    /*
     'z' and 'a' are constant, there will be no error. So you don't have to remember how many letters there 
     are in the alphabet z = 'a' + 25, so we need 1 more for a!
     */
    for (int i = 0; i <= ('z' - 'a'); i++)
    {
        histogram[i] = 0; // ALWAYS SET THE MEMORY BEFORE USING IT
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            int indexOfLetter = str[i] - 'a'; // This ensures 'a' to be at index 0, b -> 1, ... , z -> 25
            histogram[indexOfLetter]++;       // We add 1 to the index of the letter, thus counting the letter;
        }
    }

    for (int i = 0; i <= ('z' - 'a'); i++)
    {
        if (histogram[i] != 0) // We onlu want to print existing symbols
        {
            cout << char(i + 'a') << ":" << histogram[i] << endl;
            // Prints the i-th symbol after 'a' = corresponding letter
        }
    }

    return 0;
}