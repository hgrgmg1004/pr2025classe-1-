#include <iostream>
#include <iomanip> 
const double CM_PER_METER = 100.0;
double centi_to_meter(int cm); 
int main()
{
    double res;
    res = centi_to_meter(187);
    std::cout << std::fixed << std::setprecision(2) << res << "m" << std::endl;
    return 0;
}
double centi_to_meter(int cm)
{
    double converted_m = (double)cm / CM_PER_METER;
    return converted_m;
}