#include<iostream>
#include<string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
	double have = 0;
	int n = 0;
	struct info {
		double provide;
		double need;
		double rate;
	};
	while (cin >> have >> n && have != 0 && n != 0) {
		double obtain = 0;
		vector<info> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].provide >> a[i].need;
			a[i].rate = a[i].provide / a[i].need;//rate越高越划算
		}

		 std::sort(a.begin(), a.end(), [](const info& a, const info& b) {
		     return a.rate > b.rate;
		 });
		 

		for (int i = 0; i < n; i++) {
			
			if (have > a[i].need) {
				have-= a[i].need;
				obtain += a[i].provide;
			}
			else {
				obtain += have * a[i].rate;
				have = 0;
				break;
			}
			
		}
		cout <<fixed<< setprecision(3)<< obtain << endl;
	}


	return 0;
}