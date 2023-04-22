#include<iostream>
#include<stdbool.h>
using namespace std;

const int MAX_SIZE = 100;
class Stack {
private:
	char* data;
	int size;
	int top;
public:
	Stack();//构造函数
	Stack(int s);//有参构造函数
	~Stack();//析构函数
	void push(char ch)//成员函数：入栈
	{
		if (!isFull())
		{
			data[++top] = ch;
		}
	}
	char pop()//成员函数：出栈并返回栈顶元素 
	{
		if (!isEmpty())
		{
			return data[top--];
		}
	}
	char getTop()//成员函数：获得栈顶元素（不出栈）
	{

		if (!isEmpty())
		{
			return data[top];
		}
	}
	bool isEmpty()//成员函数：栈是否为空
	{
		if (top ==-1 && top >-2)
			return true;
		return false;
	}
	bool isFull()//成员函数：栈是否满
	{
		if (top == size - 1&&top<MAX_SIZE)
			return true;
		return false;
	}
	void setNull()//设置栈为空
	{
		top = -1;
	}
};
//构造函数
Stack::Stack() {
	size = MAX_SIZE;
	top = -1;
	data = new char[MAX_SIZE];//缺省构造函数分配最大的内存空间
}
Stack::Stack(int s) {
	size = s;
	top = -1;
	data = new char[size];
}
//析构函数
Stack::~Stack(){
	delete[] data;
}
int main()
{
	Stack s1(2);
	s1.push('a');
	s1.push('b');
	cout << s1.isFull() << endl;
	cout << s1.getTop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.isEmpty() << endl;
	return 0;
}