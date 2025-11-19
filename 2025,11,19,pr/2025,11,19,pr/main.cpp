#include <iostream>
#include <iomanip>
using namespace std;
void calc(double (*p1)[2], double (*p2)[2], double* m, double* b) 
{
    double x1 = (*p1)[0];
    double y1 = (*p1)[1];
    double x2 = (*p2)[0];
    double y2 = (*p2)[1];
    if (x2 != x1) 
    {
        *m = (y2 - y1) / (x2 - x1);
        *b = y1 - (*m) * x1;
    }
    else 
    {
        *m = 0.0;
        *b = 0.0;
    }
}
int main() 
{
    double data[2][2];
    data[0][0] = 5.7;
    data[0][1] = 10.5;
    data[1][0] = -2.7;
    data[1][1] = 6.5;
    double slope;
    double bias;
    calc(&data[0], &data[1], &slope, &bias);
    cout << "Input 1st point information:" << endl;
    cout << fixed << setprecision(1) << data[0][0] << " " << data[0][1] << endl;
    cout << "Input 2nd point information:" << endl;
    cout << fixed << setprecision(1) << data[1][0] << " " << data[1][1] << endl;
    cout << "Calculated Output, line equation:" << endl;
    cout << "slope: " << fixed << setprecision(4) << slope << endl;
    cout << "bias: " << fixed << setprecision(4) << bias << endl;
    return 0;
}