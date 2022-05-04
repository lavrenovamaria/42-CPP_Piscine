#include <iostream>
using namespace std;//просто чтобы не писать "std::"" каждый раз

class Animal {
	public:
	void eat() {
		cout << "Я как и любое другое животное могу кушоц!" << endl;
	}

	void sleep() {
		cout << "Как и любое другое животное могу спац!" << endl;
	}
};

class Dog : public Animal {

	public:
	void bark() {
		cout << "Я собакен и я делаю гав-гав!" << endl;
	}
};

// int main() {
// 	Dog dog;

// 	dog.eat();
// 	dog.sleep();
// 	dog.bark();
// 	return 0;
// }

//---------------------пример из видео-------------------------//
class Gun{
	public:
		virtual void Shoot()//virtual мы пишем чтобы была возможность переопределить метод в наследнике(в Uzi)
		{
			cout << "Bang!" << endl;
		}
};

class Uzi: public Gun{
	public:
		void Shoot() //override пишется здесь по-хорошему после скобочек, но это для С++11 стандарта
		{
			cout << "Bang! Bang! Bang!" << endl;
		}
};

class Player{
	public:
	void Shoot(Gun *gun)
	{
		gun->Shoot();
	}
};

int main() {
	Gun gun;//создали объект класса Gun
	Uzi uzi;//объект класса Uzi, который наследник класса Gun

	Gun *weapon = &uzi; //1-создали указатель на Gun, который ссылается на uzi
	//Gun *weapon = &gun; //2-создали указатель на Gun, который ссылается на gun

	//такой указатель может ссылаться на свой собственный тип
	//на объект такого же класса
	//либо ссылаться на любой другой класс, который унаследован от него

	weapon->Shoot();
	//если расскоментить 1, то будет Bang! Bang! Bang!
	//если расскоментить 2, то будет Bang!
	Player player;
	player.Shoot(&gun);//передаем ссылку, потому что там принимает указатель
	//либо можем вместо &gun передать &uzi
	return 0;
}
