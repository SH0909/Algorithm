#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(a,b,temp){temp=a;a=b;b=temp;}
int t, n;
int compare(const int(*a)[], const int(*b)[]);
int find(int arr[][2]);

int main()
{
	scanf("%d", &t);
	int arr[100001][2];
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &arr[j][0], &arr[j][1]);
		}
		qsort(arr, n,8,compare);
		int result = find(arr);
		printf("%d\n", result);
	}
	return 0;
}

int find(int arr[][2])
{
	int bound = arr[0][1];
	int result = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i][1] < bound) {
			result++;
			bound = arr[i][1];
		}
	}
	return result;
}

int compare(const int(*a)[], const int(*b)[])
{
	return (*a)[0] > (*b)[0] ? 1 : -1;
}