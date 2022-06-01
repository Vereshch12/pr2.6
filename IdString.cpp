#include <iostream>
#include "IdString.h"

#define Test

IdString::IdString() :String() {
#ifdef Test
	std::cout << "Конструктор по умолчанию для строки-идентефикатора сработал." << std::endl;
#endif
	this->id = 2;
}

IdString::~IdString() {
#ifdef Test
	std::cout << "Деструктор для строки-идентефикатора сработал." << std::endl;
#endif
}

IdString::IdString(const char* str) :String(str) {
#ifdef Test
	std::cout << "Конструктор, принимающий СИ-Строку, для строки-идентефикатора сработал." << std::endl;
#endif
	this->id = 2;
	this->check();
}

IdString::IdString(char c) :String(c) {
#ifdef Test
	std::cout << "Конструктор, принимающий символ, для строки-идентефикатора сработал." << std::endl;
#endif
	this->id = 2;
	this->check();
}

IdString::IdString(const IdString& s) :String(s) {
#ifdef Test
	std::cout << "Конструктор копирования для строки-идентефикатора сработал." << std::endl;
#endif
	this->id = 2;
	this->check();
}
IdString IdString::SetUp() {
#ifdef Test
	std::cout << "Метод перевода строки-идентефикатора в верхний регистр сработал." << std::endl;
#endif
	for (int i = 0; i < this->len - 1; i++)
		if (this->str[i] >= 'a' && this->str[i] <= 'z')
			this->str[i] += 'A' - 'a';
	return *this;
}

IdString& IdString::operator=(const IdString& s) {
	this->len = s.len;
	if (this->str != nullptr)
		delete[] this->str;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "Ошибка выделения памяти." << std::endl;
	else {
		for (int i = 0; i < this->len - 1; i++)
			this->str[i] = s.str[i];
		this->str[this->len - 1] = '\0';
	}
	return *this;
}

bool operator <(const IdString& s1, const IdString& s2) {
	for (int i = 0; i < s1.len - 1; i++)
		if (s1.str[i] > s2.str[i])
			return true;
	if (s1.len > s2.len)
		return true;
	else
		return false;
}

void IdString::check() {
#ifdef Test
	std::cout << "Метод проверки строки-идентефикатора сработал." << std::endl;
#endif
	bool fl = true;
	if (!((this->str[0] >= 'A' && this->str[0] <= 'Z') || (this->str[0] >= 'a' && this->str[0] <= 'z') || this->str[0] == '_'))
		fl = false;
	for (int i = 1; fl && i < this->len - 1; i++)
		if (!((this->str[i] >= 'A' && this->str[i] <= 'Z') || (this->str[i] >= 'a' && this->str[i] <= 'z') || (this->str[i] >= '0' && this->str[i] <= '9') || this->str[i] == '_'))
			fl = false;
	if (!fl) {
		this->len = 1;
		if (this->str != nullptr)
			delete[] this->str;
		this->str = new char[this->len];
		if (this->str == nullptr)
			std::cout << "Ошибка при выделении памяти." << std::endl;
		else
			this->str[0] = '\0';
	}
}