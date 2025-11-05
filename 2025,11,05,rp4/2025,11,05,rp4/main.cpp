#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int main() 
{
    const int COUNT = 10;
    const int MIN_VAL = 1;
    const int MAX_VAL = 100;
    const int RANGE = MAX_VAL - MIN_VAL + 1;
    const int DENOMINATOR = COUNT - 1;
    srand(time(0));
    vector<int> numbers;
    long long totalSum = 0;
    cout << "랜덤 숫자 (" << COUNT << "개):\n";
    for (int i = 0; i < COUNT; ++i) 
    {
        int r = (rand() % RANGE) + MIN_VAL;
        numbers.push_back(r);
        totalSum += r;
        cout << r << (i == COUNT - 1 ? "" : ", ");
    }
    cout << "\n------------------------------\n";
    double average = (double)totalSum / COUNT;
    double sumOfSquares = 0.0;
    for (int n : numbers) 
    {
        double diff = n - average;
        sumOfSquares += diff * diff;
    }
    double variance = sumOfSquares / DENOMINATOR;
    double stdDev = sqrt(variance);
    cout << fixed << setprecision(2);
    cout << "합: " << totalSum << endl;
    cout << "평균: " << average << endl;
    cout << "분산: " << variance << endl;
    cout << "표준편차: " << stdDev << endl;
    return 0;
}