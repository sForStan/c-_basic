#include<iostream>
using namespace std;
class DemoClass {
	public:
		DemoClass(int i);
		~DemoClass();
};
DemoClass::DemoClass(int i)//创建对象时执行
{
	cout << "Initial value is" << i << endl;
}
DemoClass::~DemoClass()
{
	cout << "destructor" << endl;
}
void main()
{
	DemoClass obj(30);//obj这个对象生命结束时调用析构函数，输出destructor
	cout << "This is the end main()" << endl;
	return;
}