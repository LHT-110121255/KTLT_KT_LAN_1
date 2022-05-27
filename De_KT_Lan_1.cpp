#include <stdio.h>

void KT_nhiet_do(float c);
void Xuat_tam_giac(int n);
float Cau_3(int n);
float giai_thua(int n);
void NhapMang(float *arr, int n);
void XuatMang(float *arr, int n);
void swap(float &a, float &b); 
void quickSort_T(float *arr, int left, int right);
void Chen_x(float *arr, int n, float x);

int main()
{
	int KT = true;
	while(KT)
	{
		printf("\nchon cau may ? ");
		int lc; scanf("%d", &lc);
		switch(lc)
		{
			case 0:
				KT = false;
				break;
			case 1:
				float c;
				printf("\nnhap nhiet do");
				scanf("%d", &c);
				KT_nhiet_do(c);
				break;
			case 2:
				int n;
				printf("\nNhap n = ");
				scanf("%d", &n);
				Xuat_tam_giac(n);
				break;
			case 3:
				printf("\nNhap n = ");
				scanf("%d", &n);
				printf("\nGia tri bieu thuc S(%d)= %.2f", n, Cau_3(n));
				break;
			case 4:
				printf("\nNhap kich thuoc mang = ");
				scanf("%d", &n);
				float arr[n];
				NhapMang(arr, n);
				XuatMang(arr, n);
				printf("\nMang sau khi sap xep\n");
				quickSort_T(arr, 1, n);
				XuatMang(arr, n);
				float x;
				printf("\nNhap phan tu muon chen = ");
				scanf("%f", &x);
				Chen_x(arr, n, x);
				break;
			deflaut:
				printf("\nkhong co cau do !!!");
				break;
		}
	}
}

void KT_nhiet_do(float c)
{
	(c >= 0.0 && c < 10.0) ? printf("\nVery Cold weather") :
		((c >= 10.0 && c < 20.0) ? printf("\nCold weather") :
			((c >= 20.0 && c < 30.0) ? printf("\nNormal") :
				((c >= 30.0 && c < 40.0) ? printf("\nIt is hot") : 
					printf("\nIt is very hot")))); 
}
void Xuat_tam_giac(int n)
{
	int i, j;
	int arr[n][n];
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
}
float giai_thua(int n)
{
	if(n == 1) return 1;
        return n* giai_thua(n-1);
}
float Cau_3(int n)
{
	float S = 1.0;
	int i;
	for(i = 2; i <= n; i++)
	{
		S += 1.0/giai_thua(i);
	}
	return S;
}
void NhapMang(float *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("\nNhap arr[%d]", i);
		scanf("%f", &arr[i]);
	}
}
void XuatMang(float *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("%.3f\t", arr[i]);
	}
}
void swap(float &a, float &b) 
{
    float t = a;  a = b;   b = t;
}
void quickSort_T(float *arr, int left, int right) {
    int i, j;
    float x;
    if(left >= right) return;
    x = arr[(left+right)/2];
    i = left; j = right;
    while(i <= j) {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i++;    j--;
            }
    }
    quickSort_T(arr, left, j);
    quickSort_T(arr, i, right);
}
void Chen_x(float *arr, int n, float x)
{
	int i, j, t;
	for(i = 1; i <= n; i++)
		if(x < arr[i])
		{
			t = i;
			break; 
		}
	for(i = 1; i < t; i++)
		for(j = 0; j < i; j++)
			arr[j] = arr[i];
	arr[t-1] = x;
	printf("\n", t);
	for(j = 0; j <= n; j++)
		printf("%.3f\t", arr[j]);
}
