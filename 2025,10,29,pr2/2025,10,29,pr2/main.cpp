#include <iostream>
#include <string>
#include <cstdlib> 
const double TEMP_LOWER_NORMAL = 2.0;   
const double TEMP_UPPER_NORMAL = 8.0;  
const int TIME_WARNING_LIMIT = 30;       
const int TIME_CRITICAL_OPEN = 60;      
int main() 
{
    std::cout << "\n--- 2. ��ų���� �µ����� �����ġ ---" << std::endl;
    double temperature;
    std::string door_status_input;
    int time_elapsed;
    std::string status = "Unknown"; 
    std::cout << "���� �µ� (��C)�� �Է��Ͻÿ�: ";
    if (!(std::cin >> temperature)) 
    {
        std::cerr << "invalid input: �µ� �Է��� �ùٸ��� �ʽ��ϴ�." << std::endl; std::exit(1); 
    }
       std::cout << "�� ���� (closed/open)�� �Է��Ͻÿ�: ";
    if (!(std::cin >> door_status_input)) 
    { 
       std::cerr << "invalid input: �� ���� �Է��� �ùٸ��� �ʽ��ϴ�." << std::endl; std::exit(1); 
    }
        std::cout << "�� ����/���� �ʰ� ���� �ð� (��)�� �Է��Ͻÿ�: ";
    if (!(std::cin >> time_elapsed)) 
    { 
        std::cerr << "invalid input: �ð� �Է��� �ùٸ��� �ʽ��ϴ�." << std::endl; std::exit(1); 
    }
    if (door_status_input != "closed" && door_status_input != "open" || time_elapsed < 0.0) 
    {
        std::cerr << "invalid input: �Է°��� �ùٸ��� �ʽ��ϴ�." << std::endl;
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
            status = "Normal (�ӽ�)"; 
        }
    }
    std::cout << "\n[IF �� ���] ����� ����: " << status << std::endl;
    std::string status_cond;
    status_cond = (door_status_input == "closed" && temperature >= TEMP_LOWER_NORMAL && temperature <= TEMP_UPPER_NORMAL) ? "Normal" :
        (door_status_input == "closed" && time_elapsed <= TIME_WARNING_LIMIT) ? "Warning" :
        (door_status_input == "closed" && time_elapsed > TIME_WARNING_LIMIT) ? "Critical" :
        (door_status_input == "open" && time_elapsed >= TIME_CRITICAL_OPEN && (temperature < TEMP_LOWER_NORMAL || temperature > TEMP_UPPER_NORMAL)) ? "Critical" :
        "Normal (�ӽ�-���ǿ�����)";
    std::cout << "[���� ������ ���] ����� ����: " << status_cond << std::endl;
    return 0;
}