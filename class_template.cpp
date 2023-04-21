#include<iostream>
using namespace std;
template <class Type>
class Compare {
private:
	Type x;
	Type y;
public:
	Compare(Type x, Type y) {
		this->x = x;
		this->y = y;
	}
	Type max() {
		return (x > y) ? x : y;
	}
	Type min() {
		return (x < y) ? x : y;
	}
};
int main() {
	Compare<int>C1(3, 5);
	cout << "���ֵ" << C1.max() << endl;
	cout << "��Сֵ" << C1.min() << endl;

	Compare<double>C2(3.5, 5.6);
	cout << "���ֵ" << C2.max() << endl;
	cout << "��Сֵ" << C2.min() << endl;

	Compare<char>C3('a','b');
	cout << "���ֵ" << C3.max() << endl;
	cout << "��Сֵ" << C3.min() << endl;

	return 0;
}