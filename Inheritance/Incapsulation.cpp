#include <iostream>
using namespace std;//просто чтобы не писать "std::"" каждый раз

class Point{
	private:
		int _x;
		int _y;
		int _z;
	public:
		int getX(){
			return _x;
		}
		void setX(int valueX){
			_x = valueX;
		}
	void print()
	{
		cout << "X = " << _x << endl;
		cout << "Y = " << _y << endl;
	}
};

int main()
{
	Point a;
	a.setX(5);
	a.print();

	return 0;
}
