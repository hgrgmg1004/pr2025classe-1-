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
    std::cout << "��� �� ���� (V, m/s)�� �Է��Ͻÿ�: ";
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
        flow_state = "���� (Laminar)";
    }
    else if (reynolds_number <= RE_TURBULENT_MIN) 
    {
        flow_state = "õ�� (Transitional)";
    }
    else 
    {
        flow_state = "���� (Turbulent)";
    }
    double dynamic_pressure_q = 0.5 * DENSITY_RHO * std::pow(velocity_V, 2);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n[��� ���]" << std::endl;
    std::cout << "���̳��� �� (Re): " << reynolds_number << std::endl;
    std::cout << "������ ����: **" << flow_state << "**" << std::endl;
    std::cout << "��� �� ��ü�� ���� (q): **" << dynamic_pressure_q << " Pa**" << std::endl;
    return 0;
}