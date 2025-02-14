#include<iostream>
#include<string>
using namespace std;
int main(){
	int num = 0;
	while (cin >> num) {
		if (num == 0) {
			break;
		}
		string color;
		string ball[1005];
		int ballnum[1005] = { 0 };
		for (int i = 0; i < num; i++) {
			cin >> color;
			int flag = 0;
			for (int j = 0; j < num; j++) {
				if (ball[j] == color) {
					ballnum[j]++;
					flag = 1;
					break;
				}
			}
			if (flag != 1) {
				ball[i] = color;
				ballnum[i]++;
			}
		}
		int max = 0;
		int n = 0;
		for (int i = 0; i < num; i++) {
			if (max < ballnum[i]) {
				max = ballnum[i];
				n = i;
			}
		}
		cout << ball[n] << endl;
	}
	return 0;
}