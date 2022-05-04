#include <iostream>
#include <string>
using namespace std;//просто чтобы не писать "std::"" каждый раз

//чисто виртуальная функция значит по сути, что она пустая
//в ней не описана реализация
//класс, в котором присутствует чисто виртуальная функция является абстрактным
//экземпляры абстрактного класса компилятор не позволяет создавать(запрещено)
//т.к. при создании компилятор не будет знать что с ним(объектом класса) делать

//абстрактный класс у себя внутри может иметь функции/методы с полной реализацией
//они будут работать в классах наследниках

class Weapon{
	public:
		virtual void Shoot() = 0;// = 0 мы сообщаем, что функция чисто виртуальная
		void isDead()
		{
			cout << "You died!" << endl;
		}
};

class Gun: public Weapon{
	public:
		void Shoot()//virtual мы пишем чтобы была возможность переопределить метод в наследнике(в Uzi)
		{
			cout << "Bang!" << endl;
		}
};

class Uzi: public Weapon{
	public:
		void Shoot() //override пишется здесь по-хорошему после скобочек, но это для С++11 стандарта
		{
			cout << "Bang! Bang! Bang!" << endl;
		}
};

class Bazooka: public Weapon{
	public:
		void Shoot()
		{
			cout << "BADOOM!" << endl;
		}
};

class Knife: public Weapon{
	public:
		void Shoot()
		{
			cout << "Screw you! Cut your throat!" << endl;
		}
};

class Player{
	public:
	void Shoot(Weapon *weapon)
	{
		weapon->Shoot();
	}
};

int main() {
	Gun gun;//создали объект класса Gun
	Uzi uzi;//объект класса Uzi, который наследник класса Gun
	Bazooka bazooka;
	Knife knife;

	//Gun *weapon = &uzi; //1-создали указатель на Gun, который ссылается на uzi
	//Gun *weapon = &gun; //2-создали указатель на Gun, который ссылается на gun

	//такой указатель может ссылаться на свой собственный тип
	//на объект такого же класса
	//либо ссылаться на любой другой класс, который унаследован от него

	//weapon->Shoot();
	//если расскоментить 1, то будет Bang! Bang! Bang!
	//если расскоментить 2, то будет Bang!
	Player player;
	player.Shoot(&uzi);
	uzi.isDead();//передаем ссылку, потому что там принимает указатель
	//либо можем вместо &gun передать &uzi
	return 0;
}
