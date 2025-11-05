#include <iostream>
using namespace std;
int main() 
{
    for (int d = 2; d <= 4; d++) 
    {
        cout << d << "´Ü" << endl;
        for (int n = 1; n <= 9; n++) 
        {
            cout << d << " * " << n << " = " << d * n << endl;
        }
    }

    return 0;
}