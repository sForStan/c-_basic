#include<iostream>
using namespace std;
class Point {
private:
	int x, y;
public:
	Point() :x(0), y(0) {
		cout << "Default Constructor called" << endl;
	}
	Point(int x, int y) :x(x), y(y) {
		cout << "Construct called" << endl;
	}
	~Point() { cout << "Destructor called" << endl; }
	int getX() { return x; }
	int getY() { return y; }
	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}
};
int main()
{
/*	cout << "step one:" << endl;//调用缺省构造函数
	Point* ptr1 = new Point;//删除对象调用析构函数
	delete ptr1;

	cout << "step two:" << endl;
	ptr1 = new Point(1, 2);
	delete ptr1;
	*/
	Point* ptr = new Point[2];
	ptr[0].move(5, 10);
	ptr[1].move(15, 20);
	cout << "Deleting.." << endl;
	delete[] ptr;
	return 0;
}