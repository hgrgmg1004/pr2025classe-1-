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
    std::cout << "가슴둘레: " << chest << std::endl;
    std::cout << "결정된 사이즈: " << size << std::endl;

    return 0;
}