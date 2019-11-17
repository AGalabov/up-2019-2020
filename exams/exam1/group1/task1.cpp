#include <iostream>

using namespace std;

bool pointIsInSquare(double pX, double pY, double sX, double sY, double length)
{
    return pX >= sX && pX <= sX + length && pY >= sX - length && pY <= sY;
}

int main()
{
    int S, P;
    do
    {
        cout << "Enter a natural number S not bigger than 10:" << endl;
        cin >> S;
    } while (S <= 0 || S > 10);

    do
    {
        cout << "Enter a natural number P not bigger than 10:" << endl;
        cin >> P;
    } while (P <= 0 || P > 10);

    double topLeftX[10];
    double topLeftY[10];
    double length[10];

    cout << "Enter " << S << " squares: " << endl;

    for (int i = 0; i < S; ++i)
    {
        cin >> topLeftX[i] >> topLeftY[i] >> length[i];
    }

    double pointX[10];
    double pointY[10];

    cout << "Enter " << P << " points: " << endl;

    for (int i = 0; i < P; ++i)
    {
        cin >> pointX[i] >> pointY[i];
    }

    int pointsInSquare = 0;

    for (int i = 0; i < P; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            if (pointIsInSquare(pointX[i], pointY[i], topLeftX[j], topLeftY[j], length[j]))
            {
                ++pointsInSquare;
                break;
            }
        }
    }

    int squaresWithNoPoints = 0;
    int maxIndex = 0;
    int maxPoints = 0;

    for (int i = 0; i < S; ++i)
    {
        int pointsInSquareCount = 0;
        for (int j = 0; j < P; ++j)
        {
            if (pointIsInSquare(pointX[j], pointY[j], topLeftX[i], topLeftY[i], length[i]))
                ++pointsInSquareCount;
        }
        if (pointsInSquareCount == 0)
            ++squaresWithNoPoints;
        else if (pointsInSquareCount > maxPoints)
        {
            maxPoints = pointsInSquareCount;
            maxIndex = i;
        }
    }
    cout << "Points within atleast 1 square: " << pointsInSquare << endl;
    cout << "Squares with no points in it: " << squaresWithNoPoints << endl;
    cout << "Square with max points in it: " << maxIndex + 1 << endl;
}