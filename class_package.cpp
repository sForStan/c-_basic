#include<iostream>
using namespace std;
class Clock {
private:
	int hour, minute, second;
public:
	Clock();//�����޲ι��캯��
	Clock(int newH, int newM, int newS);//�������캯��
	//�����������������Ե�ֵ
	void setHour(int hour)
	{
		this->hour = hour;//this->hour���ԣ�hour�β�
	}
	void setMinute(int minute)
	{
		this->minute = minute;
	}
	void setSecond(int second)
	{
		this->second = second;
	}
	//��ȡ���Ե�ֵ
	int getHour()
	{
		return hour;
	}
	int getMinute()
	{
		return minute;
	}
	int getSecond()
	{
		return second;
	}
	void display()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
};
//�����޲ι��캯��������ֵ1
Clock::Clock() :hour(1), minute(1), second(1) {}
//�����вι��캯���������ֵ
Clock::Clock(int newH, int newM, int newS) :hour(newH), minute(newM), second(newS) {}
int main()
{
	Clock myClock1;//������󣬴�ʱ���Զ������޲ι��캯��
	cout << "�����޲ι��캯��������ʱ�����Ϊ��";
	myClock1.display();

	Clock myClock2(8, 3, 30);//�˴����Զ������вι��캯��
	cout << "�����вι��캯��������ʱ�����Ϊ��";
	myClock2.display();

	myClock2.setHour(21);
	cout << "�޸Ĺ��Ķ����ʱ��Ϊ";
	myClock2.display();

	return 0;
}