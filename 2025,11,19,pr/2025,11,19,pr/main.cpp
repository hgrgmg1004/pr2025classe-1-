#include <iostream>
#include <iomanip>
using namespace std;
int main() 
{
    double x1 = 5.7;
    double y1 = 10.5;
    double x2 = -2.7;
    double y2 = 6.5;
    double m;
    double b;
    if (x2 != x1) 
    {
        m = (y2 - y1) / (x2 - x1);
        b = y1 - m * x1;
    }
    else 
    {
        m = 0.0;
        b = 0.0;
    }
    cout << "Input 1st point information:" << endl;
    cout << fixed << setprecision(1) << x1 << " " << y1 << endl;
    cout << "Input 2nd point information:" << endl;
    cout << fixed << setprecision(1) << x2 << " " << y2 << endl;
    cout << "Calculated Output, line equation:" << endl;
    cout << "slope: " << fixed << setprecision(4) << m << endl;
    cout << "bias: " << fixed << setprecision(4) << b << endl;
    return 0;
}