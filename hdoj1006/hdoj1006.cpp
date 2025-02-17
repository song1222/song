//��һ������д�ģ���֪��Ϊʲô������ԣ����Ҳ������۳���ĵط�

//#include<iostream>
//#include<string>
//#include<iomanip>
//#include <cmath>
//using namespace std;
//int main() {
//	double D = 0;
//	while (cin >> D)
//	{
//		double out = 0;
//		double x = 0;
//		if (D == -1) {
//			break;
//		}
//		double sec = 0., min = 0, hour = 0;
//		for (int i = 1; i < 43200; i++) {
//			sec = (6 * i)%360;
//			min = fmod((0.1 * i),360.) ;
//			hour = (1. / 120. * i);
//			if (abs(sec - min) >= D&&((sec+360.)-min)>=D &&((min+360.)-sec)>=D) {
//				if (abs(sec - hour) >= D && ((sec + 360.) - hour) >= D && ((hour + 360.) - sec) >= D) {
//					if (abs(min - hour) >= D && ((min + 360.) - hour) >= D && ((hour + 360.) - min) >= D) {
//						x++;
//					}
//				}
//			}
//		}
//		cout << x << endl;
//		out = x * 100. / 43200.;
//		cout << fixed << setprecision(3) << out << endl;
//
//
//	}
//	return 0;
//}



#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double calculateHappyTime(double D) {
    double tsm = 360. / 5.9;//������Է�����360����Ҫ��ʱ�䣨�룩
    double tmh = 43200. / 11.;//�������ʱ����360����Ҫ��ʱ�䣨�룩
    double ths = 43200. / 719.;//�������ʱ����360����Ҫ��ʱ�䣨�룩
    double result = 0, f1, f2, f3, e1, e2, e3, op, ed;

    // f1:��ʾ����ͷ����γ� D �ȵ���ʼʱ��,e1:��ʾ����ͷ����γ� D �ȵĽ���ʱ��
    for (f1 = D / 5.9, e1 = tsm - D / 5.9; e1 <= 43200; f1 += tsm, e1 += tsm) {
        // f2:��ʾ�����ʱ���γ� D �ȵ���ʼʱ��,e2:��ʾ�����ʱ���γ� D �ȵĽ���ʱ��
        for (f2 = D * 120 / 11, e2 = tmh - D * 120 / 11; e2 <= 43200; f2 += tmh, e2 += tmh) {
            if (e1 < f2 || e2 < f1) continue;
            // f3:��ʾ�����ʱ���γ� D �ȵ���ʼʱ��,e3:��ʾ�����ʱ���γ� D �ȵĽ���ʱ��
            for (f3 = D * 120 / 719, e3 = ths - D * 120 / 719; e3 <= 43200; f3 += ths, e3 += ths) {
                if (e1 < f3 || e3 < f1) continue;
                if (e2 < f3 || e3 < f2) continue;
                op = max(max(f1, f2), max(f2, f3));
                ed = min(min(e1, e2), min(e2, e3));
                result += (ed - op);
            }
        }
    }
    return result / 432;
}


int main() {
    double D;
    while (cin >> D && D != -1) {
        if (D == 0) {
            cout << "100.000" << endl;
        }
        else if (D == 120) {
            cout << "0.000" << endl;
        }
        else {
            cout << fixed << setprecision(3) << calculateHappyTime(D) << endl;
        }
    }
    return 0;
}



//#include<iostream>
//#include<string>
//#include<iomanip>
//#include <cmath>
//using namespace std;
//int main()
//{
//    int n;
//    double a = 0, t = 0, miao, fen, shi;
//    cin >> n;
//    shi = 0;
//    while (n <= 120 && n >= 0)
//    {
//        //ģ��ʱ��
//        while (shi < 360)
//        {
//            t += 0.45;//t�Ǽ�����ʱ�䣬��0.45��Ϊ��λ�ۼ�
//            miao = t - (int)t / 360 * 360;//������ΪtΪdouble�ͣ��ò���%�������Լ�д��һ��������%�Ķ�����
//            fen = t / 60 - (int)t / 60 / 360 * 360;
//            shi = t / 720;
//            if (abs(miao - fen) >= n && miao - fen + 360 >= n && fen + 360 - miao >= n)//������ж����Է�������ʵ������define�����򻯴��롣
//                if (abs(miao - shi) >= n && miao - shi + 360 >= n && shi + 360 - miao >= n)
//                    if (abs(fen - shi) >= n && fen - shi + 360 >= n && shi + 360 - fen >= n)
//                        a += 0.45;//a����ͳ�ƿ���ʱ��
//        }
//        printf("%.3lf\n", a / t * 100);//c++��С������Ʋ�����ã������������c��printf����
//        cin >> n;
//        a = t = shi = 0;//������Ҫ��������
//    }
//    cin.get();
//    cin.get();//����������cin.get();����ͣ����,��������,��Ӱ��oj���ж�
//}
