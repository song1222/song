#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	while (cin >> n && n != 0) {
		int time = 0;
		int cz;//≤Ó÷µ
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				if (a[n] >= a[i]) {
					cz = abs(a[n] - a[i]);
					time += (cz * 6);
				}
				if (a[n] < a[i]) {
					cz = abs(a[n] - a[i]);
					time += (cz * 4);
				}
				break;
			}
			if (a[i+1] >= a[i]) {
				cz = abs(a[i + 1] - a[i]);
				time += (cz * 6);
			}
			if (a[i + 1] < a[i]) {
				cz = abs(a[i + 1] - a[i]);
				time += (cz * 4);
			}

		}
		time += n * 5;
		cout << time << endl;
	}

	return 0;
}