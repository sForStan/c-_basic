#include<iostream>
using namespace std;
class Rectangle {
private:
	float width;
	float height;
	static int count;
public:
	Rectangle();
	Rectangle(Rectangle& p)
	{
		width = p.width;
		height = p.height;
		count++;
	}
	Rectangle(float newW, float newH);
	float getArea(float width,float height);
	float getPerimeter(float width, float height);
	float getWidth()
	{
		return width;
	}
	float getHeight()
	{
		return height;
	}
	int getCount()
	{
		return count;
	}
	void setWidth(float width)
	{
		this->width = width;
	}
	void setHeight(float width)
	{
		this->height = height;
	}
	void display()
	{
		cout << width << "\t" << height<<endl;
	}
	static void showCount()
	{
		cout << "now is " << count << endl;
	}
};
int Rectangle::count = 0;
Rectangle::Rectangle() :width(1), height(1) { count++; }
Rectangle::Rectangle(float newW, float newH) : width(newW), height(newH) { count++; }
float getArea(float width, float heigth)
{
	return width * heigth;
}
float getPerimeter(float width, float height)
{
	return 2 * (width + height);
}
int main()
{
	Rectangle myRectangle;
	myRectangle.display();
	Rectangle::showCount();

	Rectangle myRectangle2(2, 4);
	myRectangle2.display();
	Rectangle::showCount();
	return 0;

	
}
