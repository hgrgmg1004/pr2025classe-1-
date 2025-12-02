#include <stdio.h>
#include <math.h>
int main(void)
{
	double x = 0, y = 0;
	double v0 = 15.0;
	double th = 75.0 * 3.14159 / 180.0;
	double vx = v0 * cos(th);
	double vy = v0 * sin(th);
	double g = 9.81;
	double dt = 0.01;
	double t = 0;
	double hmax = 0;
	while (y >= 0) 
	{
		x = x + vx * dt;
		y = y + vy * dt;
		vy = vy - g * dt;
		t = t + dt;
		if (y > hmax) hmax = y;
	}
	printf("체공시간 = %.2f s", t);
	printf("최고높이 = %.2f m", hmax);
	printf("수평 사거리 = %.2f m", x);
	return 0;
}