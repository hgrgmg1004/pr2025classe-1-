#include <iostream>
#include <cmath>

using namespace std;

int calculateGCD_while(int a, int b) 
{
    int num1 = abs(a);
    int num2 = abs(b);

    while (num2 != 0) 
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int calculateLCM(int n1, int n2, int gcd) {
    if (gcd == 0) return 0;
    return (abs(n1) / gcd) * abs(n2);
}
int main()
{
    int numA, numB;
    cout << "�� ���ڸ� �Է��ϼ���: ";
    if (!(cin >> numA >> numB))
    {
        cerr << "�߸��� �Է��Դϴ�." << endl;
        return 1;
    }
    int gcd = calculateGCD_while(numA, numB);
    int lcm = calculateLCM(numA, numB, gcd);
    cout << "\n=== while �� ��� ===" << endl;
    cout << "�Էµ� �� ����: " << numA << ", " << numB << endl;
    cout << "�ִ����� (GCD): " << gcd << endl;
    cout << "�ּҰ���� (LCM): " << lcm << endl;

    return 0;
}