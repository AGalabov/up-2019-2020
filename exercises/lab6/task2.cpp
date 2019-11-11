#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[1001];
    cin.getline(str, 1001);

    int wordsCount = 0;
    bool wasWordBefore = false;
    for (int i = 0; i < strlen(str); i++)
    {
        if (('0' <= str[i] && str[i] <= '9') || ('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
        {
            wasWordBefore = true;
        }
        else
        {
            if (wasWordBefore)
                wordsCount++;
            wasWordBefore = false;
        }
    }
    if (wasWordBefore)
        wordsCount++; // Counts the last word if it ended on one(no whitespace after it)

    cout << "Words are:" << wordsCount << endl;
    return 0;
}