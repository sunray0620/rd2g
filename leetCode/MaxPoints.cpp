#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int pointSize = points.size();
		if (pointSize <= 2) return pointSize;

		int globalMaxCount = 2;
		for (int i=0; i<pointSize-1; ++i) {
			map<string, int> lineCount;
			int localMaxCount = 2;
			int localBonus = 0;
			for (int j=i+1; j<pointSize; ++j) {
				string lineKey = generateKey(&points[i], &points[j]);
				if (lineKey.size() == 0) {
					++localBonus;
					continue;
				}
				int newCount = 2;
				if(lineCount.find(lineKey) != lineCount.end()) {
					newCount = lineCount[lineKey] + 1;
				}
				lineCount[lineKey] = newCount;
				localMaxCount = max(newCount, localMaxCount);
			}
			globalMaxCount = max(localMaxCount + localBonus, globalMaxCount);
			/*
			for (map<string, int>::iterator itr = lineCount.begin(); itr != lineCount.end(); ++itr) {
				cout << itr->first << " : " << itr->second << endl;
			}*/
		}
		return min(pointSize, globalMaxCount);
    }

private:
	string generateKey(Point *pa, Point *pb) {
		char buffer[30];
		if (pa->x == pb->x && pa->y == pb->y) {
			return string("");
		} else if (pa->x == pb->x) {
			sprintf(buffer, "v-%d", pa->x);
			return string(buffer);
		} else if (pa->y == pb->y) {
			sprintf(buffer, "h-%d", pa->y);
			return string(buffer);
		} else {
			double k = 1.0 * (pa->y - pb->y) / (pa->x - pb->x);
			double b = pa->y - k * pa->x;
			sprintf(buffer, "%.4f-%.4f", k, b);
			return string(buffer);
		}
	}

	int max(int a, int b) {
	    return (a >= b)? a : b;
	}
	
	int min(int a, int b) {
	    return (a <= b)? a : b;
	}
};

int main() {

	Solution *s = new Solution();

	vector<Point> allPoints;
	allPoints.push_back(Point(1, 1));
	allPoints.push_back(Point(1, 1));
	allPoints.push_back(Point(1, 1));
	/*
	allPoints.push_back(Point(-240,-657));
	allPoints.push_back(Point(-27,-188));
	allPoints.push_back(Point(-616,-247));
	allPoints.push_back(Point(-264,-311));
	allPoints.push_back(Point(-352,-393));
	allPoints.push_back(Point(-270,-748));
	allPoints.push_back(Point(3,4));
	allPoints.push_back(Point(-308,-87));
	allPoints.push_back(Point(150,526));
	allPoints.push_back(Point(0,-13));
	allPoints.push_back(Point(-7,-40));
	allPoints.push_back(Point(-3,-10));
	allPoints.push_back(Point(-531,-892));
	allPoints.push_back(Point(-88,-147));
	allPoints.push_back(Point(4,-3));
	allPoints.push_back(Point(-873,-555));
	allPoints.push_back(Point(-582,-360));
	allPoints.push_back(Point(-539,-207));
	allPoints.push_back(Point(-118,-206));
	allPoints.push_back(Point(970,680));
	allPoints.push_back(Point(-231,-47));
	allPoints.push_back(Point(352,263));
	allPoints.push_back(Point(510,143));
	allPoints.push_back(Point(295,480));
	allPoints.push_back(Point(-590,-990));
	allPoints.push_back(Point(-236,-402));
	allPoints.push_back(Point(308,233));
	allPoints.push_back(Point(-60,-111));
	allPoints.push_back(Point(462,313));
	allPoints.push_back(Point(-270,-748));
	allPoints.push_back(Point(-352,-393));
	allPoints.push_back(Point(-35,-148));
	allPoints.push_back(Point(-7,-40));
	allPoints.push_back(Point(440,345));
	allPoints.push_back(Point(388,290));
	allPoints.push_back(Point(270,890));
	allPoints.push_back(Point(10,-7));
	allPoints.push_back(Point(60,253));
	allPoints.push_back(Point(-531,-892));
	allPoints.push_back(Point(388,290));
	allPoints.push_back(Point(-388,-230));
	allPoints.push_back(Point(340,85));
	allPoints.push_back(Point(0,-13));
	allPoints.push_back(Point(770,473));
	allPoints.push_back(Point(0,73));
	allPoints.push_back(Point(873,615));
	allPoints.push_back(Point(-42,-175));
	allPoints.push_back(Point(-6,-8));
	allPoints.push_back(Point(49,176));
	allPoints.push_back(Point(308,222));
	allPoints.push_back(Point(170,27));
	allPoints.push_back(Point(-485,-295));
	allPoints.push_back(Point(170,27));
	allPoints.push_back(Point(510,143));
	allPoints.push_back(Point(-18,-156));
	allPoints.push_back(Point(-63,-316));
	allPoints.push_back(Point(-28,-121));
	allPoints.push_back(Point(396,304));
	allPoints.push_back(Point(472,774));
	allPoints.push_back(Point(-14,-67));
	allPoints.push_back(Point(-5,7));
	allPoints.push_back(Point(-485,-295));
	allPoints.push_back(Point(118,186));
	allPoints.push_back(Point(-154,-7));
	allPoints.push_back(Point(-7,-40));
	allPoints.push_back(Point(-97,-35));
	allPoints.push_back(Point(4,-9));
	allPoints.push_back(Point(-18,-156));
	allPoints.push_back(Point(0,-31));
	allPoints.push_back(Point(-9,-124));
	allPoints.push_back(Point(-300,-839));
	allPoints.push_back(Point(-308,-352));
	allPoints.push_back(Point(-425,-176));
	allPoints.push_back(Point(-194,-100));
	allPoints.push_back(Point(873,615));
	allPoints.push_back(Point(413,676));
	allPoints.push_back(Point(-90,-202));
	allPoints.push_back(Point(220,140));
	allPoints.push_back(Point(77,113));
	allPoints.push_back(Point(-236,-402));
	allPoints.push_back(Point(-9,-124));
	allPoints.push_back(Point(63,230));
	allPoints.push_back(Point(-255,-118));
	allPoints.push_back(Point(472,774));
	allPoints.push_back(Point(-56,-229));
	allPoints.push_back(Point(90,228));
	allPoints.push_back(Point(3,-8));
	allPoints.push_back(Point(81,196));
	allPoints.push_back(Point(970,680));
	allPoints.push_back(Point(485,355));
	allPoints.push_back(Point(-354,-598));
	allPoints.push_back(Point(-385,-127));
	allPoints.push_back(Point(-2,7));
	allPoints.push_back(Point(531,872));
	allPoints.push_back(Point(-680,-263));
	allPoints.push_back(Point(-21,-94));
	allPoints.push_back(Point(-118,-206));
	allPoints.push_back(Point(616,393));
	allPoints.push_back(Point(291,225));
	allPoints.push_back(Point(-240,-657));
	allPoints.push_back(Point(-5,-4));
	allPoints.push_back(Point(1,-2));
	allPoints.push_back(Point(485,355));
	allPoints.push_back(Point(231,193));
	allPoints.push_back(Point(-88,-147));
	allPoints.push_back(Point(-291,-165));
	allPoints.push_back(Point(-176,-229));
	allPoints.push_back(Point(154,153));
	allPoints.push_back(Point(-970,-620));
	allPoints.push_back(Point(-77,33));
	allPoints.push_back(Point(-60,-111));
	allPoints.push_back(Point(30,162));
	allPoints.push_back(Point(-18,-156));
	allPoints.push_back(Point(425,114));
	allPoints.push_back(Point(-177,-304));
	allPoints.push_back(Point(-21,-94));
	allPoints.push_back(Point(-10,9));
	allPoints.push_back(Point(-352,-393));
	allPoints.push_back(Point(154,153));
	allPoints.push_back(Point(-220,-270));
	allPoints.push_back(Point(44,-24));
	allPoints.push_back(Point(-291,-165));
	allPoints.push_back(Point(0,-31));
	allPoints.push_back(Point(240,799));
	allPoints.push_back(Point(-5,-9));
	allPoints.push_back(Point(-70,-283));
	allPoints.push_back(Point(-176,-229));
	allPoints.push_back(Point(3,8));
	allPoints.push_back(Point(-679,-425));
	allPoints.push_back(Point(-385,-127));
	allPoints.push_back(Point(396,304));
	allPoints.push_back(Point(-308,-352));
	allPoints.push_back(Point(-595,-234));
	allPoints.push_back(Point(42,149));
	allPoints.push_back(Point(-220,-270));
	allPoints.push_back(Point(385,273));
	allPoints.push_back(Point(-308,-87));
	allPoints.push_back(Point(-54,-284));
	allPoints.push_back(Point(680,201));
	allPoints.push_back(Point(-154,-7));
	allPoints.push_back(Point(-440,-475));
	allPoints.push_back(Point(-531,-892));
	allPoints.push_back(Point(-42,-175));
	allPoints.push_back(Point(770,473));
	allPoints.push_back(Point(118,186));
	allPoints.push_back(Point(-385,-127));
	allPoints.push_back(Point(154,153));
	allPoints.push_back(Point(56,203));
	allPoints.push_back(Point(-616,-247));
	*/
	cout << "Result: " << s->maxPoints(allPoints) << endl;

	return 0;
}
