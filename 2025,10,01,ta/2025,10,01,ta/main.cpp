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

	printf("�̸�, �й�, Ű(cm), ������(kg)�� �Է��ϼ��� :\n");

	if (scanf_s("%s %d %f %f", szName, (unsigned int)sizeof(szName), &nStudentID, &fHeight, &fWeight) != 4)
	{ 
		printf("�Է� ������ �߻��߽��ϴ�.\n");
		return 1; 
	} 
	fHeightMeters = fHeight / 100.0f;
	fBMI = fWeight / (fHeightMeters * fHeightMeters);
	printf("\n--- �Է� ���� ---\n");
	printf("�̸�: %s\n", szName);
	printf("�й�: %d\n", nStudentID);
	printf("Ű: %.1f cm\n", fHeight);
	printf("������: %.1f kg\n", fWeight);
	printf("--- BMI ��� ��� ---\n");
	printf("BMI: %.2f\n", fBMI);

	return 0;
}