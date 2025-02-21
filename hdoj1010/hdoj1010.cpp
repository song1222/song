#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int map[8][8] = { 0 };//1��ʾ����ͨ����0��ʾ����ͨ��
int visit[8][8] = { 1 };//1��ʾδ���ʣ�0��ʾ�ѷ���
int step = 0;


bool dfs(int dogx, int dogy,int finx,int finy, int StepNum,int m,int n) {
	if (dogx == finx && dogy == finy) {
		if (step == StepNum) {
			return true ;
		}
		return false;
	}
	//˳ʱ����̽
	//�ҡ�
	if (dogy + 1 < n &&map[dogx][dogy + 1] == 1 && visit[dogx][dogy+1] == 1) {
		visit[dogx][dogy + 1] = 0;//�ѷ���
		step++;
		if (dfs(dogx, dogy+1, finx, finy, StepNum,m,n))return true;
		step--;
		visit[dogx][dogy + 1] = 1;//���ݣ�δ����
	}
	//�¡�
	if (dogx + 1 < m &&map[dogx + 1][dogy] == 1 && visit[dogx + 1][dogy] == 1) {
		visit[dogx + 1][dogy] = 0;
		step++;
		if (dfs(dogx + 1, dogy, finx, finy, StepNum,m,n))return true;
		step--;
		visit[dogx + 1][dogy] = 1;
	}
	//���
	if (dogy-1>=0&&map[dogx][dogy - 1] == 1 && visit[dogx][dogy - 1] == 1) {
		visit[dogx][dogy - 1] = 0;
		step++;
		if (dfs(dogx, dogy-1, finx, finy, StepNum,m,n))return true;
		step--;
		visit[dogx][dogy - 1] = 1;
	}
	//�ϡ�
	if (dogx-1>=0&&map[dogx - 1][dogy] == 1 && visit[dogx - 1][dogy] == 1) {
		visit[dogx - 1][dogy] = 0;
		step++;
		if (dfs(dogx - 1, dogy, finx, finy, StepNum,m,n))return true;
		step--;
		visit[dogx - 1][dogy] = 1;
	}
	return false;
}


int main() {
	int m, n, t;
	char a[8][8];
	
	while (cin >> m >> n >> t && m != 0 && n != 0 && t != 0) {
		step = 0;
		int dogx, dogy,finx,finy;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				map[i][j] = 0;
				visit[i][j] = 1;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					dogx = i;
					dogy = j;
					map[i][j] = 1;
					visit[i][j] = 0;
				}
				if (a[i][j] == 'D') {
					finx = i;
					finy = j;
					map[i][j] = 1;
					visit[i][j] = 1;
				}
				if (a[i][j] == 'X') {
					map[i][j] = 0;
					visit[i][j] = 0;
				}
				if (a[i][j] == '.') {
					map[i][j] = 1;
					visit[i][j] = 1;
				}
			}
		}
		
		if (dfs(dogx, dogy, finx, finy, t, m, n)) {
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}


