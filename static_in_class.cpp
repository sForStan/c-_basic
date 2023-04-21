#include<iostream>
using namespace std;
class Point {
private:
	int x, y;
	 static int count;//用来记录点的个数
public:
	Point(int x = 0, int y = 0) :x(x), y(y) { count++; }
	Point(Point& p) {//复制构造函数
		x = p.x;
		y = p.y;
		count++;//每次调用时系统生成一个临时对象，所以count++，调用结束后count--
	//因为要count--，所以要有++
	}
	~Point() { count--; }
	int getX() { return x; }
	int getY() { return y; }
	void showCount() { cout << "object count = " << count << endl; }
	static void showCountB() { cout << "object count = " << count << endl; }
};
int Point::count = 0;
int main()
{
	Point a(4, 5);
	cout << "Point A:" << a.getX() << "," << a.getY();
	a.showCount();
	Point::showCountB();
	Point b;
	cout << "Point B: " << b.getX() << "," << b.getY();
	b.showCount();
	Point::showCountB();
	return 0;
}