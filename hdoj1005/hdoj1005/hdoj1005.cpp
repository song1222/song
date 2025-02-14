#include<iostream>
#include<string>
using namespace std;
int main() {
	int a1 = 0, b = 0, n = 0;

	while (cin >> a1 >> b >> n) {
		int a[50] = { 0 };
		a[0] = 1;
		a[1] = 1;
		n = n % 49;
		if (a1==0&&b==0&&n==0) {
			break;
		}
		for (int i = 2; i < n; i++) {
			a[i] = (a1 * a[i - 1] + b * a[i - 2]) % 7;
		}
		cout << a[n - 1] << endl;
	}
	return 0;
}