#include <iostream>
const int SIZE_S_MAX = 90;
const int SIZE_M_MAX = 100;
 
int main() {
    int chest =105;
    char size;
    if (chest <= SIZE_S_MAX)
    {
        size = 'S';
    }
    else if (chest <= SIZE_M_MAX)
    {
        size = 'M';
    }
    else
    {
        size = 'L';
    }
    std::cout << "�����ѷ�: " << chest << std::endl;
    std::cout << "������ ������: " << size << std::endl;

    return 0;
}