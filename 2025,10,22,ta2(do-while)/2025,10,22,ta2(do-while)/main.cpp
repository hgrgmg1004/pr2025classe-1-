#include <iostream>
#include <cmath> 

using namespace std;

int calculateGCD_do_while(int a, int b) 
{
    int num1 = abs(a);
    int num2 = abs(b);

    if (num2 == 0) 
    {
        return num1;
    }

    do 
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    while (num2 != 0);

    return num1;
}
int calculateLCM(int n1, int n2, int gcd) 
{
    if (gcd == 0) return 0;
    return (abs(n1) / gcd) * abs(n2);
}

int main() 
{
    int numA, numB;
    cout << "두 숫자를 입력하세요: ";
    if (!(cin >> numA >> numB)) 
    {
        cerr << "잘못된 입력입니다." << endl;
        return 1;
    }

    int gcd = calculateGCD_do_while(numA, numB);
    int lcm = calculateLCM(numA, numB, gcd);

    cout << "\n=== do-while 문 결과 ===" << endl;
    cout << "입력된 두 숫자: " << numA << ", " << numB << endl;
    cout << "최대공약수 (GCD): " << gcd << endl;
    cout << "최소공배수 (LCM): " << lcm << endl;

    return 0;
}