#include <iostream>
using namespace std;//просто чтобы не писать "std::"" каждый раз

class Point{
	private:
		int _x;
		int _y;
		int _z;
	public:
	Point()
	{
		_x = 0;
		_y = 0;
		cout << this << "constructor" << endl;
	}
	Point(int valueX, int valueY){
		_x = valueX;
		_y = valueY;
		cout << this << "constructor" << endl;
	}
	int getX(){
			return _x;
		}
	void setX(int valueX){
		_x = valueX;
	}
	Point & operator ++(){
		this->_x++;
		this->_y++;

		return *this;
		//ссылку на текущий объект, над которым производили операцию
	}
	Point & operator ++(int){//ничего не передаем, просто чтобы компилятор отличал постфиксную от префиксной
		this->_x;
		this->_y;

		return *this;
		//ссылку на текущий объект, над которым производили операцию
	}
};

int main()
{
	Point a(1, 1);
	++a;
	Point b = a;

	return 0;
}
