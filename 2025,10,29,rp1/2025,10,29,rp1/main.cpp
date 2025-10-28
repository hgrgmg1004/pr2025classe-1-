#include <iostream>
#include <cstdlib> 
const double RATED_CAPACITY = 600.0; 
int main() 
{
    std::cout << "--- 1. 엘리베이터 과부하 경고장치 ---" << std::endl;
    double total_weight;
    std::cout << "총 중량 (kg)을 입력하시오: ";
    if (!(std::cin >> total_weight)) 
    {
        std::cerr << "invalid input: 숫자가 입력되지 않았습니다." << std::endl;
        std::exit(1);
    }
    if (total_weight < 0.0) 
    {
        std::cerr << "invalid input: 중량은 음수일 수 없습니다." << std::endl;
        std::exit(1); 
    }
    std::cout << "\n[IF 문 결과] ";
    if (total_weight <= RATED_CAPACITY) 
    {
        std::cout << "OK" << std::endl; 
    }
    else 
    {
        std::cout << "Overload" << std::endl; 
    }
    std::cout << "[조건 연산자 결과] ";
    std::cout << (total_weight <= RATED_CAPACITY ? "OK" : "Overload") << std::endl;
    return 0;
}