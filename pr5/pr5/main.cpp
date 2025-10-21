#include <iostream>
#include <iomanip>

const float piValue = 3.14f;

int main()
{
    
    std::cout << "직접 입력된 PI (3.14): " << std::fixed << std::setprecision(2) << 3.14 << "\n";

    std::cout << "const 로 정의된 piValue: " << piValue << "\n";

    return 0;
}