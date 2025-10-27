#include <iostream>
int rec_func(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + rec_func(n - 1);
}
int main()
{
    const int MAX_NUM = 10;
    int result = rec_func(MAX_NUM);
    std::cout << result << std::endl;
    return 0;
}