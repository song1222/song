#include<iostream>
#include <string>
using namespace std;
int main()
{   
	////暴力求解，时间Time Limit Exceeded
	//int num = 0;
	//int a[100010] = { 0 };
	//int b = 0, f = 0;
	//cin >> num;
	//int max = -1001;
	//for (int i = 1; i <= num; i++) {
	//	int n = 0;
	//	cin >> n;
	//	for (int j = 0; j < n; j++) {
	//		cin >> a[j];
	//	}
	//	int max = -1001;
	//	int sum = 0;
	//	for (int j = 0; j < n; j++) {
	//		sum = 0;
	//		for (int k = j; k < n; k++) {
	//			sum = sum + a[k];
	//			if (sum > max) {
	//				b = j;
	//				f = k;
	//				max = sum;
	//			}
	//		}
	//	}
	//	if (i != num) {
	//		cout << "Case " << i << ":" << endl;
	//		cout << max << " " << b + 1 << " " << f + 1 << endl;
	//		cout << endl;
	//	}
	//	else {
	//		cout << "Case " << i << ":" << endl;
	//		cout << max<<" " << b + 1<<" " << f + 1 << endl;
	//	}
	//}

	//动态规划
	int num = 0;
	int a[100010] = { 0 };
	int b = 0, f = 0;
	cin >> num;
	int max = -1001;
	for (int i = 1; i <= num; i++) {
		int n = 0;
		cin >> n;
		int dp[100010] = { -10001 };
		int maxb = 0;
		for (int j = 0; j < n; j++){
			cin >> a[j];
		}
		max = a[0];
		b = 0;
		f = 0;
		dp[0] = a[0];
		if (n == 1) {
			f = 0;
			maxb = 0;
			max = a[0];
		}
		for (int j = 1; j < n; j++) {
			if (dp[j - 1] < 0) {
				dp[j] = a[j];
				b = j;
			}
			else {
				dp[j] = dp[j - 1] + a[j];

			}
			if (max < dp[j]) {
				max = dp[j];
				f = j;
				maxb = b;
			}
		}

		if (i != num) {
			cout << "Case " << i << ":" << endl;
			cout << max << " " << maxb + 1 << " " << f + 1 << endl;
			cout << endl;
		}
		else {
			cout << "Case " << i << ":" << endl;
			cout << max<<" " << maxb + 1<<" " << f + 1 << endl;
		}
	}
	return 0;
}