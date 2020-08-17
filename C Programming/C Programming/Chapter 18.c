#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void TwoDArrayAddress()
{
	int arr2d[3][3];
	printf("%d \n", arr2d);
	printf("%d \n", arr2d[0]);
	printf("%d \n\n", &arr2d[0][0]);

	printf("%d \n", arr2d[1]);
	printf("%d \n\n", &arr2d[1][0]);

	printf("%d \n", arr2d[2]);
	printf("%d \n\n", &arr2d[2][0]);

	printf("sizeof(arr2d) : %d \n", sizeof(arr2d));
	printf("sizeof(arr2d[0]) : %d \n", sizeof(arr2d[0]));
	printf("sizeof(arr2d[1]) : %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]) : %d \n", sizeof(arr2d[2]));
}

void TwoDArrPointerOp()
{
	int arr1[3][2];
	int arr2[2][3];

	printf("arr1 : %p \n", arr1);
	printf("arr1+1 : %p \n", arr1 + 1);
	printf("arr1+2 : %p \n\n", arr1 + 2);

	printf("arr2 : %p \n", arr2);
	printf("arr2+1 : %p \n", arr2 + 1);
	return 0;
}

void TwoDArrNameAndArrPtr()
{
	int arr1[2][2] = {
		{1, 2}, {3, 4}
	};

	int arr2[3][2] = {
		{1, 2}, {3, 4}, {5, 6}
	};

	int arr3[4][2] = {
		{1, 2}, {3, 4}, {5, 6}, {7, 8}
	};

	int(*ptr)[2];
	int i;

	ptr = arr1;
	printf("** Show 2,2 arr1 **\n");
	for (i = 0; i < 2; i++)
	{
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr2;
	printf("** Show 3,2 arr2 **\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	ptr = arr3;
	printf("** Show 4,2 arr3 **\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d %d \n", ptr[i][0], ptr[i][1]);
	}

	return 0;
}

void ArrPtrAndPtrArr()
{
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i, j;

	int* whoA[4] = { &num1, &num2, &num3, &num4 };
	int(*whoB)[4] = arr2d;

	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", whoB[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void ShowArr2DStyle(int(*arr)[4], int column)
{
	int i, j;
	for (i = 0; i < column; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Sum2DArr(int arr[][4], int column)
{
	int i, j, sum = 0;
	for (i = 0; i < column; i++)
	{
		for (j = 0; j < 4; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

void TwoDArrParamMain()
{
	int arr1[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[3][4] = { 1, 1, 1, 1, 3, 3, 3, 3, 5, 5, 5, 5 };

	ShowArr2DStyle(arr1, sizeof(arr1) / sizeof(arr1[0]));
	ShowArr2DStyle(arr2, sizeof(arr2) / sizeof(arr2[0]));
	printf("arr1�� �� : %d \n", Sum2DArr(arr1, sizeof(arr1) / sizeof(arr1[0])));
	printf("arr2�� �� : %d \n", Sum2DArr(arr2, sizeof(arr2) / sizeof(arr2[0])));
}

void TwoDArrAccessType()
{
	int a[3][2] = { {1, 2}, {3, 4}, {5, 6} };

	printf("a[0] : %p \n", a[0]);
	printf("*(a+0) : %p \n", *(a + 0));

	printf("a[1] : %p \n", a[1]);
	printf("*(a+1) : %p \n", *(a + 1));

	printf("a[0] : %p \n", a[0]);
	printf("*(a+2) : %p \n", *(a + 2));

	printf("%d, %d \n", a[2][1], (*(a + 2))[1]);
	printf("%d, %d \n", a[2][1], *(a[2] + 1));
	printf("%d, %d \n", a[2][1], *(*(a + 2) + 1));
}

int main(void)
{
	//TwoDArrayAddress();
	//TwoDArrPointerOp();
	//TwoDArrNameAndArrPtr();
	//ArrPtrAndPtrArr();
	//TwoDArrParamMain();
	TwoDArrAccessType();
}