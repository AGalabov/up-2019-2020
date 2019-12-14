#include <iostream>
#include <string.h>

using namespace std;

bool visited[10][10] = {0};
int a[10][10];

bool canMove(int n, int i, int j)
{
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= n)
        return false;
    if (visited[i][j])
        return false;
    if (a[i][j] == 1)
        return false;
    return true;
}

bool findPathRec(int n,
                 int currI, int currJ, int endI, int endJ)
{
    if (currI == endI && currJ == endJ)
        return true;
    visited[currI][currJ] = true;
    if (canMove(n, currI - 1, currJ))
        if (findPathRec(n, currI - 1, currJ, endI, endJ))
            return true;
    if (canMove(n, currI, currJ - 1))
        if (findPathRec(n, currI, currJ - 1, endI, endJ))
            return true;
    if (canMove(n, currI, currJ + 1))
        if (findPathRec(n, currI, currJ + 1, endI, endJ))
            return true;
    if (canMove(n, currI + 1, currJ))
        if (findPathRec(n, currI + 1, currJ, endI, endJ))
            return true;
    return false;
}

bool findPath(int n, int endI, int endJ)
{
    return findPathRec(n, 0, 0, endI, endJ);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << findPath(n, n - 1, n - 1);

    return 0;
}