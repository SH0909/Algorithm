#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int t, n;
int result;
int arr[100001][2];
int include[100001] = { 0, };
int find();

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d %d", &arr[j][0], &arr[j][1]);
		}
		int profit = 0;
		int result=find();
		printf("%d\n", result);
	}
	return 0;
}

int find()
{
	int i, j,profit=0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[j][0] < arr[i][0]) {
				if (arr[j][1] < arr[i][1])
					break;
			}
			else {
				if (include[j]==1&&arr[j][1] > arr[i][1]) {
					include[j] = 0;
					profit--;
				}
			}
		}
		if (i == j) {
			profit++;
			include[i] = 1;
		}
	}
	return profit;
}
