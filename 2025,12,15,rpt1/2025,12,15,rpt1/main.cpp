#include <stdio.h>
#include <stdlib.h>

// kPa -> Pa 변환 상수 정의 (1 kPa = 1,000 Pa)
#define KPA_TO_PA 1000.0

// 유동일 계산 함수
// dP_Pa: 압력 (Pa 단위), dTemp_C: 온도 (섭씨), dVel_ms: 속도 (m/s), dRho: 밀도 (kg/m^3)
// 주의: 온도와 속도 값은 입력만 받고, 유동일 계산에는 사용하지 않습니다.
double 유동일_계산_함수(double dP_Pa, double dTemp_C, double dVel_ms, double dRho)
{
    double d유동일 = 0.0;

    // 유동일 수식: W_flow = P / rho
    // 오직 압력과 밀도만 사용하여 계산합니다.
    d유동일 = dP_Pa / dRho;

    return d유동일;
}

// 메인 함수
int main(void)
{
    // 변수 초기화
    double d압력_kPa = 0.0;      //  kPa 입력
    double d온도_섭씨 = 0.0;     //  온도 입력 (계산에 미사용)
    double d속도_ms = 0.0;       //  유체 속도 m/s 입력 (계산에 미사용)
    double d밀도 = 0.0;          //  유체 밀도 kg/m^3 입력

    // 계산에 사용될 단위 변환된 변수
    double d압력_Pa = 0.0;
    double d유동일_결과_J = 0.0; // 유동일 결과 (J/kg)
    double d유동일_결과_kJ = 0.0; // 유동일 결과 (kJ/kg)

    printf("==========================================\n");
    printf("      유동일 (Flow Work) 계산기\n");
    printf("    (W_flow = P / rho 만 계산합니다.)\n");
    printf("==========================================\n");

    printf("1. 압력 (P)을 kPa 단위로 입력하세요: ");
    scanf_s("%lf", &d압력_kPa);

    printf("2. 온도 (T)를 섭씨 (C) 단위로 입력하세요: ");
    scanf_s("%lf", &d온도_섭씨);

    printf("3. 유체 속도 (v)를 m/s 단위로 입력하세요: ");
    scanf_s("%lf", &d속도_ms);

    printf("4. 유체 밀도 (rho)를 kg/m^3 단위로 입력하세요: ");
    scanf_s("%lf", &d밀도);

    // 밀도 유효성 검사 (0으로 적는것을 방지하기 위해 제작 하였습니다.)
    if (d밀도 <= 0.0)
    {
        printf("\n[오류] 밀도는 0보다 큰 양수 값이어야 합니다.\n");
        system("pause");
        return 1;
    }

    // kPa -> Pa 단위 변환
    d압력_Pa = d압력_kPa * KPA_TO_PA;

    // 유동일 계산 함수 호출 (온도와 속도 변수는 전달되지만 함수 내에서 사용되지 않습니다.)
    d유동일_결과_J = 유동일_계산_함수(d압력_Pa, d온도_섭씨, d속도_ms, d밀도);

    // J/kg -> kJ/kg 단위 변환
    d유동일_결과_kJ = d유동일_결과_J / 1000.0;

    // 마지막으로 결과를 출력 합니다.
    printf("\n[계산 결과]\n");
    printf("--- 입력 요약 ---\n");
    printf("압력 (P): %.2lf kPa | 밀도 (rho): %.2lf kg/m^3\n",
        d압력_kPa, d밀도);
    printf("------------------------------------------\n");
    printf("유동일 (W_flow) = P / rho\n");
    printf("유동일 (W_flow): %.4lf J/kg\n", d유동일_결과_J);
    printf("유동일 (W_flow): %.4lf kJ/kg\n", d유동일_결과_kJ);

    // 실행 결과 확인 대기
    system("pause");
    return 0;
}