#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> v(10);
	vector<char> v2;
	char str[] = "<Vector>";

	for(int i = 0; i < 10; i++) v[i] = i + 'a';

	cout << "Исходное содержимое вектора v: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	vector<char>::iterator p = v.begin();
	p +=2;

	v.insert(p, 10, 'X');

	cout << "Размер вектора после вставки символов Х = " << v.size() << endl;
	cout << "Содержимое вектора v после вставки: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	p = v.begin();
	p +=2;
	v.erase(p, p+10);

	cout << "Размер вектора v после удаления = " << v.size() << endl;
	cout << "Содержимое вектора v после удаления: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n\n";

	for(int i = 0; str[i]; i++) v2.push_back(str[i]);
	v.insert(p, v2.begin(), v2.end());
	cout << "Размер вектора v после вставки вектора v2 = ";
	cout << v.size() << endl;
	cout << "Содержимое вектора v после вставки: \n";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
