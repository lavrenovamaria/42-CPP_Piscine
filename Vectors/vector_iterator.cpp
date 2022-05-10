#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
//простейший пример операции над векторами
int main()
{
	vector<char> v(10);//создание вектора на 10 элементов
	cout << "Размер = " << v.size() << endl;
	for(int i = 0; i < 10; i++) v[i] = i + 'a';
	cout << "Текущее содержимое: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	cout << "Расширенный вектор: \n";
	for(int i = 0; i < 10; i++) v.push_back(i + 10 + 'a');
	cout << "Новый размер = : " << v.size() << endl;
	cout << "Текущее содержимое: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	for(int i = 0; i < v.size(); i++) v[i] = toupper(v[i]);
	cout << "Модифицированное содержимое: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

	return 0;
}

