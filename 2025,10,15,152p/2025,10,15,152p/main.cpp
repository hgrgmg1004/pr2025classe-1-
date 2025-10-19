#include <iostream>
#include <string>

int main() 
{
    int num1;      
    int num2;     
    char op;      
    int result;   

    std::cout << "사칙연산 입력(정수) : ";
    if (!(std::cin >> num1 >> op >> num2)) 
    {
        std::cerr << "잘못된 입력 형식입니다." << std::endl;
        return 1;
    }

 
    switch (op) 
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        
        if (num2 == 0) 
        {
            std::cerr << "오류: 0으로 나눌 수 없습니다." << std::endl;
            return 1;
        }
        result = num1 / num2; 
        break;
    default:
        std::cerr << "오류: 지원하지 않는 연산자입니다." << std::endl;
        return 1;
    }
    std::cout << num1 << op << num2 << "=" << result << std::endl;

    return 0;
}