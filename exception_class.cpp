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
	Stack();//���캯��
	Stack(int s);//�вι��캯��
	~Stack();//��������
	void push(char ch)//��Ա��������ջ
	{
		if (isFull())
		{
			throw Full();
		}
		else
			data[++top] = ch;
	}
	char pop()//��Ա��������ջ������ջ��Ԫ�� 
	{
		if (isEmpty())
		{
			throw Empty();
		}
		else
			return data[top--];
	}
	char getTop()//��Ա���������ջ��Ԫ�أ�����ջ��
	{

		if (isEmpty())
		{
			throw Empty();
		}
		else
			return data[top];
	}
	bool isEmpty()//��Ա������ջ�Ƿ�Ϊ��
	{
		if (top == -1 && top > -2)
			return true;
		return false;
	}
	bool isFull()//��Ա������ջ�Ƿ���
	{
		if (top == size - 1 && top < MAX_SIZE)
			return true;
		return false;
	}
	void setNull()//����ջΪ��
	{
		top = -1;
	}
	class Full {};
	class Empty {};
};
//���캯��
Stack::Stack() {
	size = MAX_SIZE;
	top = -1;
	data = new char[MAX_SIZE];//ȱʡ���캯�����������ڴ�ռ�
}
Stack::Stack(int s) {
	size = s;
	top = -1;
	data = new char[size];
}
//��������
Stack::~Stack() {
	delete[] data;
}
int main()
{
	Stack s1(2);
	char  ch;
	try {
		s1.push('a');
		s1.push('b');
		s1.push('c');
	}
	catch (Stack::Full) {
		cout << "stack full!" << endl;
	}
	try {
		ch = s1.pop();
		cout << ch << endl;
		ch = s1.pop();
		cout << ch << endl;
		ch = s1.pop();
		cout << ch << endl;
	}
	catch (Stack::Empty) {
		cout << "stack empty";
	}
	/*cout << s1.isFull() << endl;
	cout << s1.getTop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.isEmpty() << endl;*/
	return 0;
}