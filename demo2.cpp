#include<iostream>
using namespace std;
class Rectangle {
private:
	float width;
	float height;
public:
	Rectangle();
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
		cout << width << "\t" << height << endl;
	}
};
Rectangle::Rectangle() :width(1), height(1) {}
Rectangle::Rectangle(float newW, float newH) : width(newW), height(newH) {}
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

	Rectangle myRectangle2(2, 4);
	myRectangle2.display();
	return 0;

	
}
