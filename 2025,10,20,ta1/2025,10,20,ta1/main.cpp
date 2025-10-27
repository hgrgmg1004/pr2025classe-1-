#include <iostream>

using namespace std;
const unsigned int MIN_DAN = 2;
const unsigned int MAX_DAN = 9;
const unsigned int MIN_GOP = 1;
const unsigned int MAX_GOP = 9;

int main() 
{
    unsigned int input_dan;
    cout << "����� ������ �ܼ��� �Է��ϼ��� (" << MIN_DAN << "-" << MAX_DAN << " ��): ";
    if (!(cin >> input_dan)) 
    {
        cerr << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << endl;
        return 1;
    }
    if (input_dan < MIN_DAN || input_dan > MAX_DAN) {
        cerr << "�Էµ� �ܼ� (" << input_dan << ")�� ��ȿ���� �ʽ��ϴ�. 2-9 ���� ������ �Է����ּ���." << endl;
        return 1;
    }
    cout << "\n=== " << input_dan << " �� ��� ===" << endl;
    for (unsigned int gop = MIN_GOP; gop <= MAX_GOP; gop++)
    {
        cout << input_dan << " * " << gop << " = " << input_dan * gop << endl;
    }
    return 0;
}