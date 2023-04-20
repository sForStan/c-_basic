#include<iostream>
using namespace std;
class Clock {
private:
	int hour, minute, second;
public:
	Clock();//声明无参构造函数
	Clock(int newH, int newM, int newS);//声明构造函数
	//内联函数，设置属性的值
	void setHour(int hour)
	{
		this->hour = hour;//this->hour属性，hour形参
	}
	void setMinute(int minute)
	{
		this->minute = minute;
	}
	void setSecond(int second)
	{
		this->second = second;
	}
	//获取属性的值
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
//定义无参构造函数，赋初值1
Clock::Clock() :hour(1), minute(1), second(1) {}
//定义有参构造函数，传入初值
Clock::Clock(int newH, int newM, int newS) :hour(newH), minute(newM), second(newS) {}
int main()
{
	Clock myClock1;//定义对象，此时会自动调用无参构造函数
	cout << "利用无参构造函数创建的时间对象为：";
	myClock1.display();

	Clock myClock2(8, 3, 30);//此处讲自动调用有参构造函数
	cout << "利用有参构造函数创建的时间对象为：";
	myClock2.display();

	myClock2.setHour(21);
	cout << "修改过的对象的时间为";
	myClock2.display();

	return 0;
}