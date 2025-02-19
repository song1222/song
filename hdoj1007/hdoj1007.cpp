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
//    double y;   /*���ڼ�¼�����*/
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
//         ����������
//        for (int i = 0; i < n; i++) {
//            cin >> num[i].x >> num[i].y;
//        }
//
//         ����Ƿ����ظ���
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
//         ������ظ��㣬ֱ����� 0.00
//        if (hasDuplicate) {
//            cout << fixed << setprecision(2) << 0.00 << endl;
//            continue;
//        }
//
//         �������е��֮��ľ���
//        double minDist = 1e18;  // ��ʼ��Ϊһ���ܴ��ֵ
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                double dist = distance(num[i].x, num[i].y, num[j].x, num[j].y);
//                minDist = min(minDist, dist);
//            }
//        }
//
//         �����С�����һ��
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
    if (high - low <= 3) {  // С��ģ����ֱ�ӱ������
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

    // ���εݹ�
    double leftMin = closeset(p, low, mid);
    double rightMin = closeset(p, mid + 1, high);
    double d = min(leftMin, rightMin);

    // ���� strip
    vector<point> strip;
    for (int i = low; i <= high; ++i) {
        if (abs(p[i].x - midX) < d) {
            strip.push_back(p[i]);
        }
    }

    // ��� strip �еĵ��
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

        sort(p.begin(), p.end(), cmpx);  // �� x ��������
        double dmin = closeset(p, 0, n - 1);

        // �����С�����һ��
        cout << fixed << setprecision(2) << dmin / 2 << endl;
    }
    return 0;
}
