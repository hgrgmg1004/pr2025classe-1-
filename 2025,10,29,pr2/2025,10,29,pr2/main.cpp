#include <iostream>
#include <string>
#include <cstdlib> 
const double TEMP_LOWER_NORMAL = 2.0;   
const double TEMP_UPPER_NORMAL = 8.0;  
const int TIME_WARNING_LIMIT = 30;       
const int TIME_CRITICAL_OPEN = 60;      
int main() 
{
    std::cout << "\n--- 2. 백신냉장고 온도상태 경고장치 ---" << std::endl;
    double temperature;
    std::string door_status_input;
    int time_elapsed;
    std::string status = "Unknown"; 
    std::cout << "현재 온도 (°C)를 입력하시오: ";
    if (!(std::cin >> temperature)) 
    {
        std::cerr << "invalid input: 온도 입력이 올바르지 않습니다." << std::endl; std::exit(1); 
    }
       std::cout << "문 상태 (closed/open)를 입력하시오: ";
    if (!(std::cin >> door_status_input)) 
    { 
       std::cerr << "invalid input: 문 상태 입력이 올바르지 않습니다." << std::endl; std::exit(1); 
    }
        std::cout << "문 열림/범위 초과 지속 시간 (초)을 입력하시오: ";
    if (!(std::cin >> time_elapsed)) 
    { 
        std::cerr << "invalid input: 시간 입력이 올바르지 않습니다." << std::endl; std::exit(1); 
    }
    if (door_status_input != "closed" && door_status_input != "open" || time_elapsed < 0.0) 
    {
        std::cerr << "invalid input: 입력값이 올바르지 않습니다." << std::endl;
        std::exit(1);
    }
    if (door_status_input == "closed") 
    {
        if (temperature >= TEMP_LOWER_NORMAL && temperature <= TEMP_UPPER_NORMAL) 
        {
            status = "Normal"; 
        }
        else 
        {
            if (time_elapsed <= TIME_WARNING_LIMIT) 
            {
                status = "Warning"; 
            }
            else 
            {
                status = "Critical"; 
            }
        }
    }
    else
    { 
        bool temp_out_of_range = (temperature < TEMP_LOWER_NORMAL || temperature > TEMP_UPPER_NORMAL);
        if (time_elapsed >= TIME_CRITICAL_OPEN && temp_out_of_range) 
        {
            status = "Critical";
        }
        else 
        {
            status = "Normal (임시)"; 
        }
    }
    std::cout << "\n[IF 문 결과] 냉장고 상태: " << status << std::endl;
    std::string status_cond;
    status_cond = (door_status_input == "closed" && temperature >= TEMP_LOWER_NORMAL && temperature <= TEMP_UPPER_NORMAL) ? "Normal" :
        (door_status_input == "closed" && time_elapsed <= TIME_WARNING_LIMIT) ? "Warning" :
        (door_status_input == "closed" && time_elapsed > TIME_WARNING_LIMIT) ? "Critical" :
        (door_status_input == "open" && time_elapsed >= TIME_CRITICAL_OPEN && (temperature < TEMP_LOWER_NORMAL || temperature > TEMP_UPPER_NORMAL)) ? "Critical" :
        "Normal (임시-조건연산자)";
    std::cout << "[조건 연산자 결과] 냉장고 상태: " << status_cond << std::endl;
    return 0;
}