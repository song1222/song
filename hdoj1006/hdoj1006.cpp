//第一段是我写的，不知道为什么结果不对，我找不到理论出错的地方

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
    double tsm = 360. / 5.9;//秒针相对分针绕360°需要的时间（秒）
    double tmh = 43200. / 11.;//分针相对时针走360°需要的时间（秒）
    double ths = 43200. / 719.;//秒针相对时针走360°需要的时间（秒）
    double result = 0, f1, f2, f3, e1, e2, e3, op, ed;

    // f1:表示秒针和分针形成 D 度的起始时间,e1:表示秒针和分针形成 D 度的结束时间
    for (f1 = D / 5.9, e1 = tsm - D / 5.9; e1 <= 43200; f1 += tsm, e1 += tsm) {
        // f2:表示分针和时针形成 D 度的起始时间,e2:表示分针和时针形成 D 度的结束时间
        for (f2 = D * 120 / 11, e2 = tmh - D * 120 / 11; e2 <= 43200; f2 += tmh, e2 += tmh) {
            if (e1 < f2 || e2 < f1) continue;
            // f3:表示秒针和时针形成 D 度的起始时间,e3:表示秒针和时针形成 D 度的结束时间
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
//        //模拟时钟
//        while (shi < 360)
//        {
//            t += 0.45;//t是计算总时间，以0.45°为单位累加
//            miao = t - (int)t / 360 * 360;//这里因为t为double型，用不了%，所以自己写了一个类似与%的东西。
//            fen = t / 60 - (int)t / 60 / 360 * 360;
//            shi = t / 720;
//            if (abs(miao - fen) >= n && miao - fen + 360 >= n && fen + 360 - miao >= n)//这里的判断略显繁琐，其实可以用define宏来简化代码。
//                if (abs(miao - shi) >= n && miao - shi + 360 >= n && shi + 360 - miao >= n)
//                    if (abs(fen - shi) >= n && fen - shi + 360 >= n && shi + 360 - fen >= n)
//                        a += 0.45;//a用来统计开心时间
//        }
//        printf("%.3lf\n", a / t * 100);//c++的小数点控制不大会用，方便起见用了c的printf函数
//        cin >> n;
//        a = t = shi = 0;//这里需要重置数据
//    }
//    cin.get();
//    cin.get();//这里用两个cin.get();来暂停界面,保留窗口,不影响oj的判断
//}
