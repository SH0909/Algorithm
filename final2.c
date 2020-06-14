#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int t, n;
int result;
int arr[100001][2];
int include[100001] = { 0, };
int promising(int i);
void find(int profit, int i);

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d %d", &arr[j][0], &arr[j][1]);
		}
		int profit = 0;
		find(profit,0);
		printf("%d\n", result);
		result = 0;
	}
	return 0;
}

void find(int profit,int i)
{
	for (int j = 1; j < i; j++) {
		if (include[i] == 1) {
			if (arr[j][0] < arr[i][0] && arr[j][1] < arr[i][1])
				profit--;
		}
	}
	if (i == n) {
		if (result < profit) { 
			result = profit; 
		}
		return;
	}
	if (promising(i)) {
		include[i + 1] = 1;
		find(profit + 1, i + 1);
		include[i + 1] = 0;
		find(profit, i + 1);
	}
}

int promising(int i)
{
	for (int j = 1; j <= i; j++) {
		if (include[j] == 1) {
			if (arr[j][0] > arr[i+1][0] && arr[j][1] > arr[i+1][1])
				return 0;
		}
	}
	return 1;
}