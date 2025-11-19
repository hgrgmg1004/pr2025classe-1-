#include <stdio.h>
void calc_line_params(double p1_x, double p1_y, double p2_x, double p2_y, double* m_out, double* b_out)
{
    double delta_x = p2_x - p1_x;
    double delta_y = p2_y - p1_y;
    if (delta_x != 0.0)
    {
        *m_out = delta_y / delta_x;
        *b_out = p1_y - (*m_out * p1_x);
    }
    else
    {
        *m_out = 0.0; 
        *b_out = 0.0;
    }
}
int main(void)
{
    double x1 = 5.7;
    double y1 = 10.5;
    double x2 = -2.7;
    double y2 = 6.5;
    double slope;
    double bias;
    calc_line_params(x1, y1, x2, y2, &slope, &bias);
    printf("Input 1st point information:\n");
    printf("%.1f %.1f\n", x1, y1);
    printf("Input 2nd point information:\n");
    printf("%.1f %.1f\n", x2, y2);
    printf("Calculated Output, line equation:\n");
    printf("slope: %.4f\n", slope);
    printf("bias: %.4f\n", bias);
    return 0;
}