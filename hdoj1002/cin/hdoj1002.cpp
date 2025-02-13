#include<iostream>
#include <string>
using namespace std;


string stringsum(string& a, string& b){
	string big, small;
	if (a.length() > b.length()) {
		big = a;
		small = b;
	}
	else {
		big = b;
		small = a;
	}
	int biglen = big.length();
	int smalllen = small.length();
	int k = biglen;
	for (int j = smalllen-1 ;j >= 0;j--,k--){
		big[k-1] = big[k-1] + small[j]-'0';
	}
	for (int i = biglen - 1; i > 0; i--) {
		if (big[i] > '9') {
			big[i] = big[i] - '9' + '0' - 1;
			big[i - 1]++;
		}
	}
	if (big[0] > '9') {
		big[0] = big[0] - '9' + '0' - 1;
		big = '1' + big;
	}
	

	return big;
}
int main()
{
	int n;
	string a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {

			cin >> a >> b;
			cout << "Case " << i << ":" << endl;
			cout << a << " + " << b << " = " << stringsum(a, b) << endl;
			if (i < n) {
				cout << endl;
			}
	}

	return 0;
}




	
