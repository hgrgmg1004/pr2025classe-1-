#include <stdio.h>
void calculate_line(double x1, double y1, double x2, double y2, double* m_out, double* b_out)
{
    double dx = x2 - x1;
    double dy = y2 - y1;5.
    if (dx == 0.0)
    {
        *m_out = 0.0;
        *b_out = x1;
    }
    else
    {
        *m_out = dy / dx;
        *b_out = y1 - (*m_out * x1);
    }
}
int main(void)
{
    double x_a, y_a, x_b, y_b;
    double m, b;
    printf("Input x1 y1 x2 y2:\n");
    scanf_s("%lf %lf %lf %lf", &x_a, &y_a, &x_b, &y_b);
    calculate_line(x_a, y_a, x_b, y_b, &m, &b);
    printf("\nInput 1st point information:\n");
    printf("%.1f %.1f\n", x_a, y_a);
    printf("\nInput 2nd point information:\n");
    printf("%.1f %.1f\n", x_b, y_b);
    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4f\n", m);
    printf("bias: %.4f\n", b);
    return 0;
}
