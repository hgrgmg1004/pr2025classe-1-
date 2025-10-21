#include <iostream>
#include <ios> 

int main()
{
    int a, b;
    std::cout << "두 개의 정수를 입력하세요: ";

    if (!(std::cin >> a >> b)) 
    {
        std::cerr << "유효하지 않은 입력입니다.\n";
        return 1; 
    }

    std::cout << std::boolalpha;

    std::cout << "a > b 결과: " << (a > b) << "\n";
    std::cout << "a == b 결과: " << (a == b) << "\n";

    if (a > 0 && b > 0)
        std::cout << "두 수 모두 양수입니다.\n";
    else
        std::cout << "한 개 이상은 음수 또는 0입니다.\n";
    a++; 
    b--; 
    std::cout << "증감 후 값: a=" << a << ", b=" << b << "\n";

    return 0;
}