#include <iostream>

using namespace std;
const unsigned int MIN_DAN = 2;
const unsigned int MAX_DAN = 9;
const unsigned int MIN_GOP = 1;
const unsigned int MAX_GOP = 9;

int main() 
{
    unsigned int input_dan;
    cout << "출력할 구구단 단수를 입력하세요 (" << MIN_DAN << "-" << MAX_DAN << " 단): ";
    if (!(cin >> input_dan)) 
    {
        cerr << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
        return 1;
    }
    if (input_dan < MIN_DAN || input_dan > MAX_DAN) {
        cerr << "입력된 단수 (" << input_dan << ")는 유효하지 않습니다. 2-9 범위 내에서 입력해주세요." << endl;
        return 1;
    }
    cout << "\n=== " << input_dan << " 단 출력 ===" << endl;
    for (unsigned int gop = MIN_GOP; gop <= MAX_GOP; gop++)
    {
        cout << input_dan << " * " << gop << " = " << input_dan * gop << endl;
    }
    return 0;
}