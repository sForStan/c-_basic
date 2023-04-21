#include<iostream>
using namespace std;
class Rectangle {
private:
	float width;
	float height;
	static int count;
public:
	Rectangle();
	Rectangle( const Rectangle& p)
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
	void move(float widtH, float heighT)
	{
		width = widtH;
		height = heighT;
	}
};
int Rectangle::count = 0;
Rectangle::Rectangle() :width(1), height(1) { count++; }
Rectangle::Rectangle(float newW, float newH) : width(newW), height(newH) { count++; }
float Rectangle::getArea(float width, float height)
{
	return width * height;
}
float Rectangle::getPerimeter(float width, float height)
{
	return 2 * (width + height);
}
int main()
{
	/*Rectangle myRectangle;
	myRectangle.display();
	Rectangle::showCount();

	Rectangle myRectangle2(2, 4);
	myRectangle2.display();
	Rectangle::showCount();
	*/
	//Rectangle *rect = new Rectangle[3];
	/*rect[0].move(3, 4);
	rect[1].move(7, 6);
	rect[2].move(5 ,6);*/

	Rectangle rect[3] = {Rectangle(3,4),Rectangle(7,6),Rectangle(5,6)};
	for (int i = 0; i < 3; i++)
	{
		float answer = rect[i].getArea(rect[i].getWidth(),rect[i].getHeight());
		cout <<"area("<<i<<")	is :	"<< answer << endl;
		answer = rect[i].getPerimeter(rect[i].getWidth(), rect[i].getHeight());
		cout << "perimeter(" << i << ")	is :	" << answer << endl;
	}
	return 0;

	
}
