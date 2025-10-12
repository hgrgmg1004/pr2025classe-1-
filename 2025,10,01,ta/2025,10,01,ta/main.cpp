#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	char szName[50];
	int nStudentID;
	float fHeight;
	float fWeight;
	float fBMI;
	float fHeightMeters;

	printf("이름, 학번, 키(cm), 몸무게(kg)를 입력하세요 :\n");

	if (scanf_s("%s %d %f %f", szName, (unsigned int)sizeof(szName), &nStudentID, &fHeight, &fWeight) != 4)
	{ 
		printf("입력 오류가 발생했습니다.\n");
		return 1; 
	} 
	fHeightMeters = fHeight / 100.0f;
	fBMI = fWeight / (fHeightMeters * fHeightMeters);
	printf("\n--- 입력 정보 ---\n");
	printf("이름: %s\n", szName);
	printf("학번: %d\n", nStudentID);
	printf("키: %.1f cm\n", fHeight);
	printf("몸무게: %.1f kg\n", fWeight);
	printf("--- BMI 계산 결과 ---\n");
	printf("BMI: %.2f\n", fBMI);

	return 0;
}