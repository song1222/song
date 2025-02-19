//#include <iostream>
//#include <cmath>
//#include <iomanip>
//#include <algorithm>
//using namespace std;
//
//double distance(double a1, double b1, double a2, double b2) {
//    double a = abs(a2 - a1);
//    double b = abs(b2 - b1);
//    return sqrt(a * a + b * b);
//}
//
//typedef struct {
//    int index;
//    double x;
//    double y;   /*用于记录坐标点*/
//} coord;
//
//coord num[100010];
//
//int main() {
//    int n;
//    while (cin >> n) {
//        if (n == 0) {
//            break;
//        }
//
//         输入点的坐标
//        for (int i = 0; i < n; i++) {
//            cin >> num[i].x >> num[i].y;
//        }
//
//         检查是否有重复点
//        bool hasDuplicate = false;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (num[i].x == num[j].x && num[i].y == num[j].y) {
//                    hasDuplicate = true;
//                    break;
//                }
//            }
//            if (hasDuplicate) break;
//        }
//
//         如果有重复点，直接输出 0.00
//        if (hasDuplicate) {
//            cout << fixed << setprecision(2) << 0.00 << endl;
//            continue;
//        }
//
//         计算所有点对之间的距离
//        double minDist = 1e18;  // 初始化为一个很大的值
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                double dist = distance(num[i].x, num[i].y, num[j].x, num[j].y);
//                minDist = min(minDist, dist);
//            }
//        }
//
//         输出最小距离的一半
//        cout << fixed << setprecision(2) << minDist / 2 << endl;
//    }
//    return 0;
//}


#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

struct point {
    double x, y;
};

bool cmpx(const point& a, const point& b) {
    return a.x < b.x;
}

bool cmpy(const point& a, const point& b) {
    return a.y < b.y;
}

double min(double a, double b) {
    return a < b ? a : b;
}

double dist(const point& a, const point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closeset(vector<point>& p, int low, int high) {
    if (high - low <= 3) {  // 小规模问题直接暴力解决
        double minDist = numeric_limits<double>::max();
        for (int i = low; i <= high; ++i) {
            for (int j = i + 1; j <= high; ++j) {
                minDist = min(minDist, dist(p[i], p[j]));
            }
        }
        return minDist;
    }

    int mid = (low + high) / 2;
    double midX = p[mid].x;

    // 分治递归
    double leftMin = closeset(p, low, mid);
    double rightMin = closeset(p, mid + 1, high);
    double d = min(leftMin, rightMin);

    // 构建 strip
    vector<point> strip;
    for (int i = low; i <= high; ++i) {
        if (abs(p[i].x - midX) < d) {
            strip.push_back(p[i]);
        }
    }

    // 检查 strip 中的点对
    sort(strip.begin(), strip.end(), cmpy);
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<point> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        sort(p.begin(), p.end(), cmpx);  // 按 x 坐标排序
        double dmin = closeset(p, 0, n - 1);

        // 输出最小距离的一半
        cout << fixed << setprecision(2) << dmin / 2 << endl;
    }
    return 0;
}
