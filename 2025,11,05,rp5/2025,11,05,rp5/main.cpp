#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
using namespace std;
int main() 
{
    const int MIN = 1;
    const int MAX = 100;
    int guess = 0;
    srand(static_cast<unsigned int>(time(0)));
    const int ANSWER = (rand() % (MAX - MIN + 1)) + MIN;
    cout << "업다운 게임\n";
    int tries = 0;
    while (true) 
    {
        cout << "입력: ";
        if (!(cin >> guess)) 
        {
            cout << "❌ 유효하지 않은 입력!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        tries++;
        if (guess > ANSWER) 
        {
            cout << "⬇️ DOWN!\n";
        }
        else if (guess < ANSWER) 
        {
            cout << "⬆️ UP!\n";
        }
        else 
        {
            cout << "🎉 " << tries << "번 만에 정답입니다! (" << ANSWER << ")\n";
            break;
        }
    }
    return 0;
}