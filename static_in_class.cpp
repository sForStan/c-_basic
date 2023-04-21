#include<iostream>
using namespace std;
class Point {
private:
	int x, y;
	 static int count;//������¼��ĸ���
public:
	Point(int x = 0, int y = 0) :x(x), y(y) { count++; }
	Point(Point& p) {//���ƹ��캯��
		x = p.x;
		y = p.y;
		count++;//ÿ�ε���ʱϵͳ����һ����ʱ��������count++�����ý�����count--
	//��ΪҪcount--������Ҫ��++
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