#include<iostream>
using namespace std;
class DemoClass {
	public:
		DemoClass(int i);
		~DemoClass();
};
DemoClass::DemoClass(int i)//��������ʱִ��
{
	cout << "Initial value is" << i << endl;
}
DemoClass::~DemoClass()
{
	cout << "destructor" << endl;
}
void main()
{
	DemoClass obj(30);//obj���������������ʱ�����������������destructor
	cout << "This is the end main()" << endl;
	return;
}