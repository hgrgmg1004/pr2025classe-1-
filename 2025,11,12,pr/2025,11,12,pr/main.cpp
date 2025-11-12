#include <iostream> 
#include <cmath>    
#include <iomanip>  
using namespace std;
const int N = 10;
int main()
{
    double d[N];
    int r[N];
    double sum = 0.0;
    double avg;
    double var_sum = 0.0;
    double var;
    double stddev;
    cout << "실수 데이터 " << N << "개를 입력하세요:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << i + 1 << "번째 데이터: ";
        if (!(cin >> d[i]))
        {
            cerr << "입력 오류 발생." << endl;
            return 1;
        }
        sum += d[i];
    }
    avg = sum / N;
    for (int i = 0; i < N; ++i)
    {
        var_sum += pow(d[i] - avg, 2);
    }
    var = var_sum / N;
    stddev = sqrt(var);
    for (int i = 0; i < N; ++i)
    {
        int rank = 1;
        for (int j = 0; j < N; ++j)
        {
            if (d[j] > d[i])
            {
                rank++;
            }
        }
        r[i] = rank;
    }
    cout << fixed << setprecision(3);
    cout << " 순번|  입력값   | 순위" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << " " << setw(3) << i + 1 << " | "
            << setw(9) << d[i] << " | "
            << setw(4) << r[i] << endl;
    }
    cout << "\n### 전체 데이터 통계 결과" << endl;
    cout << "전체 데이터 평균:   " << avg << endl;
    cout << "전체 데이터 분산:   " << var << endl;
    cout << "전체 데이터 표준편차: " << stddev << endl;

    return 0;
}