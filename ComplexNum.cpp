#include <iostream>
#include "ComplexNum.h"

#define Test

ComplexNum::ComplexNum() : String() {
#ifdef Test
	std::cout << "Конструктор по умолчанию для Комплексного числа сработал." << std::endl;
#endif
	this->id = 3;
	this->x = 0;
	this->y = 0;
	this->len = 4;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "Ошибка при выделении памяти.";
	else {
		this->str[0] = '0';
		this->str[1] = 'i';
		this->str[2] = '0';
		this->str[3] = '\0';
	}
}

ComplexNum::~ComplexNum() {
#ifdef Test
	std::cout << "Деструктор для Комплексного числа сработал." << std::endl;
#endif
}

ComplexNum::ComplexNum(const char* s) :String(s) {
#ifdef Test
	std::cout << "Конструктор, принимабщий СИ-строку, для Комплексного числа сработал." << std::endl;
#endif
	this->id = 3;
	this->check();
}

ComplexNum::ComplexNum(char c) :String(c) {
#ifdef Test
	std::cout << "Конструктор, принимабщий символ, для Комплексного числа сработал." << std::endl;
#endif
	this->id = 3;
	this->check();
}

ComplexNum::ComplexNum(const ComplexNum& s) :String(s) {
#ifdef Test
	std::cout << "Конструктор копирования для Комплексного числа сработал." << std::endl;
#endif
	this->x = s.x;
	this->y = s.y;
	this->id = 3;
	this->check();
}

ComplexNum& ComplexNum::operator=(const ComplexNum& s) {
	this->x = s.x;
	this->y = s.y;
	this->len = s.len;
	if (this->str != nullptr)
		delete[] this->str;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "Ошибка при выделении памяти." << std::endl;
	else {
		for (int i = 0; i < this->len - 1; i++)
			this->str[i] = s.str[i];
		this->str[this->len - 1] = '\0';
	}
	return *this;
}

const ComplexNum operator !(const ComplexNum& s) {
	ComplexNum s1;
	s1.x = s.x;
	s1.y = -s.y;
	if (s1.str != nullptr)
		delete[] s1.str;
	int x1 = (int)s1.x, y1 = (int)s1.y, kl = 2;
	x1 = x1 / 10;
	while (x1) {
		x1 = x1 / 10;
		kl += 1;
	}
	y1 = y1 / 10;
	while (y1) {
		y1 = y1 / 10;
		kl += 1;
	}
	s1.len = kl + 8;
	if (s1.x < 0)
		s1.len += 1;
	if (s1.y < 0)
		s1.len += 1;
	s1.str = new char[s1.len];
	if (s1.str == nullptr)
		std::cout << "Ошибка при выделении памяти." << std::endl;
	else
		sprintf_s(s1.str, s1.len, "%.2lfi%.2lf", s1.x, s1.y);
	return s1;
}

const ComplexNum operator/(const ComplexNum& s1, const ComplexNum& s2) {
	ComplexNum s;
	s.x = (s1.x * s2.x + s1.y * s2.y) / (s2.x * s2.x + s2.y * s2.y);
	s.y = (s2.x * s1.y - s1.x * s2.y) / (s2.x * s2.x + s2.y * s2.y);
	if (s.str != nullptr)
		delete[] s.str;
	int x1 = (int)s.x, y1 = (int)s.y, kl = 2;
	x1 = x1 / 10;
	while (x1) {
		x1 = x1 / 10;
		kl += 1;
	}
	y1 = y1 / 10;
	while (y1) {
		y1 = y1 / 10;
		kl += 1;
	}
	s.len = kl + 8;
	if (s.x < 0)
		s.len += 1;
	if (s.y < 0)
		s.len += 1;
	s.str = new char[s.len];
	if (s.str == nullptr)
		std::cout << "Ошибка при выделении памяти." << std::endl;
	else
		sprintf_s(s.str, s.len, "%.2lfi%.2lf", s.x, s.y);
	return s;
}

void ComplexNum::check() {
#ifdef Test
	std::cout << "Метод проверки Комплексного числа сработал." << std::endl;
#endif
	bool fl = false;
	int kl = 0;
	for (int i = 0; i < this->len - 1; i++)
		if (this->str[i] == 'i')
			kl += 1;
	if (kl == 1)
		fl = true;
	for (int i = 0; fl && i < this->len - 1; i++)
		if (!((this->str[i] >= '0' && this->str[i] <= '9') || this->str[i] == 'i' || this->str[i] == '+' || this->str[i] == '-' || this->str[i] == '.' || this->str[i] == ','))
			fl = false;
	if (!fl) {
		this->len = 4;
		if (this->str != nullptr)
			delete[] this->str;
		this->str = new char[this->len];
		if (this->str == nullptr)
			std::cout << "Ошибка при выделении памяти." << std::endl;
		else {
			this->str[0] = '0';
			this->str[1] = 'i';
			this->str[2] = '0';
			this->str[3] = '\0';
		}
	}
	else
	{
		if (sscanf_s(this->str, "%lfi%lf", &this->x, &this->y) != 2)
		{
			this->y = 0;
			this->x = 0;
			this->len = 4;
			if (this->str != nullptr)
				delete[] this->str;
			this->str = new char[this->len];
			if (this->str == nullptr)
				std::cout << "Ошибка при выделении памяти.";
			else {
				this->str[0] = '0';
				this->str[1] = 'i';
				this->str[2] = '0';
				this->str[3] = '\0';
			}
		}
	}
}