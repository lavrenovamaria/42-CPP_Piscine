#include "phonebook.hpp"

Contact::Contact(std::string name,//описание реализации класса
				std::string l_name,
				std::string nick,
				std::string phone,
				std::string secret):
				_first_name(name),
				_last_name(l_name),
				_nickname(nick),
				_phone_number(phone),
				_darkest_secret(secret)
				{}
Contact::Contact(){}
std::string Contact::getFname() const{
	return _first_name;}
std::string Contact::getLname() const{
	return _last_name;}
std::string Contact::getNick() const{
	return _nickname;}
std::string Contact::getPhone() const{
	return _nickname;}
std::string Contact::getSecret() const{
	return _darkest_secret;}
