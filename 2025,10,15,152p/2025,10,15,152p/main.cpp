#include <iostream>
#include <string>

int main() 
{
    int num1;      
    int num2;     
    char op;      
    int result;   

    std::cout << "��Ģ���� �Է�(����) : ";
    if (!(std::cin >> num1 >> op >> num2)) 
    {
        std::cerr << "�߸��� �Է� �����Դϴ�." << std::endl;
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
            std::cerr << "����: 0���� ���� �� �����ϴ�." << std::endl;
            return 1;
        }
        result = num1 / num2; 
        break;
    default:
        std::cerr << "����: �������� �ʴ� �������Դϴ�." << std::endl;
        return 1;
    }
    std::cout << num1 << op << num2 << "=" << result << std::endl;

    return 0;
}