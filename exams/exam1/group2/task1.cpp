#include <iostream>

using namespace std;

bool pointIsInCircle(double pX, double pY, double cX, double cY, double radius)
{
    double distance = (pX - cX) * (pX - cX) + (pY - cY) * (pY - cY);
    return distance <= radius * radius;
}

int main()
{
    int C, P;
    do
    {
        cout << "Enter a natural number C not bigger than 10:" << endl;
        cin >> C;
    } while (C <= 0 || C > 10);

    do
    {
        cout << "Enter a natural number P not bigger than 10:" << endl;
        cin >> P;
    } while (P <= 0 || P > 10);

    double centerX[10];
    double centerY[10];
    double radius[10];

    cout << "Enter " << C << " circles: " << endl;

    for (int i = 0; i < C; ++i)
    {
        cin >> centerX[i] >> centerY[i] >> radius[i];
    }

    double pointX[10];
    double pointY[10];

    cout << "Enter " << P << " points: " << endl;

    for (int i = 0; i < P; ++i)
    {
        cin >> pointX[i] >> pointY[i];
    }

    int pointsInNoCircles = 0;

    for (int i = 0; i < P; ++i)
    {
        bool isInCircle = false;
        for (int j = 0; j < C; ++j)
        {
            if (pointIsInCircle(pointX[i], pointY[i], centerX[j], centerY[j], radius[j]))
            {
                isInCircle = true;
                break;
            }
        }
        if (!isInCircle)
            ++pointsInNoCircles;
    }

    int circlesWithPoints = 0;
    int maxPoints = 0;

    for (int i = 0; i < C; ++i)
    {
        int pointsInCircleCount = 0;
        for (int j = 0; j < P; ++j)
        {
            if (pointIsInCircle(pointX[j], pointY[j], centerX[i], centerY[i], radius[i]))
                ++pointsInCircleCount;
        }
        if (pointsInCircleCount > 0)
            ++circlesWithPoints;
        if (pointsInCircleCount > maxPoints)
        {
            maxPoints = pointsInCircleCount;
        }
    }
    cout << "Points that are  not in any circles: " << pointsInNoCircles << endl;
    cout << "Circles with atleast 1 point in it: " << circlesWithPoints << endl;
    cout << "Max number of points within 1 circle: " << maxPoints << endl;
}