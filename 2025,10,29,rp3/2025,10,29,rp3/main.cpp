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
    std::cout << "\n--- 3. ����â�� ���� �� �ķ�Ʈ ���ӵ� (��s=0.6) ---" << std::endl;
    double angle_deg;
    std::cout << "������ ��簢 (��)�� �Է��Ͻÿ� (0~90): ";
    if (!(std::cin >> angle_deg)) 
    { 
        std::cerr << "invalid input: ���ڰ� �Էµ��� �ʾҽ��ϴ�." << std::endl; std::exit(1); 
    }
    if (angle_deg < 0.0 || angle_deg > 90.0) 
    {
        std::cerr << "invalid input: ��簢�� 0������ 90�� ���̿��� �մϴ�." << std::endl;
        std::exit(1);
    }
    double angle_rad = angle_deg * (PI / 180.0);
    double critical_angle_rad = std::atan(MU_STATIC);
    double critical_angle_deg = critical_angle_rad * (180.0 / PI);
    double acceleration = 0.0;
    std::string status;
    if (angle_rad <= critical_angle_rad) 
    {
        status = "���� ����"; 
        acceleration = 0.0;
    }
    else 
    {
        status = "�̲����� �߻�";
        acceleration = GRAVITY_G * (std::sin(angle_rad) - MU_KINETIC * std::cos(angle_rad));
    }
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n[�Է� �� ���]" << std::endl;
    std::cout << "��簢 (��): " << angle_deg << "�� (�Ӱ谢: " << critical_angle_deg << "��)" << std::endl;
    std::cout << "����������� (��s): " << MU_STATIC << ", ��������� (��k): " << MU_KINETIC << std::endl;
    std::cout << "[��� ���]" << std::endl;
    std::cout << "����: " << status << std::endl;
    std::cout << "���ӵ� (a): " << acceleration << " m/s�� (���� �Ʒ���)" << std::endl;
    return 0;
}