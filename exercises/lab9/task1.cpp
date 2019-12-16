#include <iostream>
#include <string.h>

using namespace std;

void generateHistrogram(char a[])
{
    int hist[256] = {0};
    for (int i = 0; i < strlen(a); ++i)
    {
        int index = a[i];
        ++hist[index];
    }

    for (int i = 0; i < 256; ++i)
    {
        if (hist[i] != 0)
        {
            cout << (char)i << " - " << hist[i] << endl;
        }
    }
}

int main()
{
    char a[1000];
    cin.getline(a, 1000);

    generateHistrogram(a);

    return 0;
}