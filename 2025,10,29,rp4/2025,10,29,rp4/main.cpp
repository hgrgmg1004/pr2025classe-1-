#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
const double PIPE_DIAMETER_D = 0.05;
const double DENSITY_RHO = 998.2;
const double VISCOSITY_MU = 0.001002;
const double RE_LAMINAR_MAX = 2000.0;
const double RE_TURBULENT_MIN = 4000.0;
int main() 
{
    double velocity_V;
    std::cout << "배관 내 유속 (V, m/s)을 입력하시오: ";
    if (!(std::cin >> velocity_V)) 
    {
        std::cerr << "invalid input" << std::endl;
        std::exit(1);
    }
    if (velocity_V < 0.0) 
    {
        std::cerr << "invalid input" << std::endl;
        std::exit(1);
    }
    double reynolds_number = (DENSITY_RHO * velocity_V * PIPE_DIAMETER_D) / VISCOSITY_MU;
    std::string flow_state;
    if (reynolds_number < RE_LAMINAR_MAX) 
    {
        flow_state = "층류 (Laminar)";
    }
    else if (reynolds_number <= RE_TURBULENT_MIN) 
    {
        flow_state = "천이 (Transitional)";
    }
    else 
    {
        flow_state = "난류 (Turbulent)";
    }
    double dynamic_pressure_q = 0.5 * DENSITY_RHO * std::pow(velocity_V, 2);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n[계산 결과]" << std::endl;
    std::cout << "레이놀즈 수 (Re): " << reynolds_number << std::endl;
    std::cout << "유동의 상태: **" << flow_state << "**" << std::endl;
    std::cout << "배관 내 유체의 동압 (q): **" << dynamic_pressure_q << " Pa**" << std::endl;
    return 0;
}