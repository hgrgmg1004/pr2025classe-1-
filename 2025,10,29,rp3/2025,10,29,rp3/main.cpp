#include <iostream>
#include <cmath> 
#include <iomanip> 
#include <cstdlib> 
#include <string>
const double MASS_M = 100.0;    
const double GRAVITY_G = 9.8;  
const double MU_STATIC = 0.6;   
const double MU_KINETIC = 0.4;  
const double PI = std::acos(-1.0); 
int main() 
{
    std::cout << "\n--- 3. 물류창고 램프 위 파렛트 가속도 (μs=0.6) ---" << std::endl;
    double angle_deg;
    std::cout << "램프의 경사각 (도)을 입력하시오 (0~90): ";
    if (!(std::cin >> angle_deg)) 
    { 
        std::cerr << "invalid input: 숫자가 입력되지 않았습니다." << std::endl; std::exit(1); 
    }
    if (angle_deg < 0.0 || angle_deg > 90.0) 
    {
        std::cerr << "invalid input: 경사각은 0도에서 90도 사이여야 합니다." << std::endl;
        std::exit(1);
    }
    double angle_rad = angle_deg * (PI / 180.0);
    double critical_angle_rad = std::atan(MU_STATIC);
    double critical_angle_deg = critical_angle_rad * (180.0 / PI);
    double acceleration = 0.0;
    std::string status;
    if (angle_rad <= critical_angle_rad) 
    {
        status = "정지 유지"; 
        acceleration = 0.0;
    }
    else 
    {
        status = "미끄러짐 발생";
        acceleration = GRAVITY_G * (std::sin(angle_rad) - MU_KINETIC * std::cos(angle_rad));
    }
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n[입력 및 상수]" << std::endl;
    std::cout << "경사각 (θ): " << angle_deg << "° (임계각: " << critical_angle_deg << "°)" << std::endl;
    std::cout << "정지마찰계수 (μs): " << MU_STATIC << ", 동마찰계수 (μk): " << MU_KINETIC << std::endl;
    std::cout << "[계산 결과]" << std::endl;
    std::cout << "상태: " << status << std::endl;
    std::cout << "가속도 (a): " << acceleration << " m/s² (경사면 아래로)" << std::endl;
    return 0;
}