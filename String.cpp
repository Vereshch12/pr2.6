#include <iostream>
#include "String.h"

#define Test

String::String() {
#ifdef Test
	std::cout << "����������� �� ��������� ������ ��������." << std::endl;
#endif
	this->len = 1;
	this->id = 1;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "������ ��������� ������." << std::endl;
	else
		this->str[0] = '\0';
}

String::~String() {
#ifdef Test
	std::cout << "���������� ������ ��������" << std::endl;
#endif
	if (this->str != nullptr)
		delete[] this->str;
}

String::String(const char* s) {
#ifdef Test
	std::cout << "�����������, ���������� ��-������, ������ ��������." << std::endl;
#endif
	this->id = 1;
	this->len = strlen(s) + 1;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "������ ��������� ������." << std::endl;
	else {
		for (int i = 0; i < this->len - 1; i++)
			this->str[i] = s[i];
		this->str[this->len - 1] = '\0';
	}
}

String::String(char c) {
#ifdef Test
	std::cout << "�����������, ���������� ������, ������ ��������." << std::endl;
#endif
	this->id = 1;
	this->len = 2;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "������ ��������� ������." << std::endl;
	else {
		this->str[0] = c;
		this->str[1] = '\0';
	}
}

String::String(const String& s) {
#ifdef Test
	std::cout << "����������� ����������� ������ ��������." << std::endl;
#endif
	this->len = s.len;
	this->id = 1;
	this->str = new char[len];
	if (this->str == nullptr)
		std::cout << "������ ��������� ������." << std::endl;
	else {
		for (int i = 0; i < this->len - 1; i++)
			this->str[i] = s.str[i];
		this->str[this->len - 1] = '\0';
	}
	count++;
}

String String::operator=(const String& s2) {
	if (this->str != nullptr)
		delete[] this->str;
	this->len = s2.len;
	this->str = new char[this->len];
	if (this->str == nullptr)
		std::cout << "������ ��������� ������." << std::endl;
	else {
		for (int i = 0; i < this->len - 1; i++)
			this->str[i] = s2.str[i];
		this->str[len - 1] = '\0';
	}
	return *this;
}

char* String::GetStr() {
#ifdef Test
	std::cout << "����� ��������� ����������� ������ ��������." << std::endl;
#endif
	return this->str;
}

char String::GetId() {
#ifdef Test
	std::cout << "����� ��������� id ��������." << std::endl;
#endif
	return this->id;
}

int String::GetLen() {
#ifdef Test
	std::cout << "����� ��������� ����� ������ ��������." << std::endl;
#endif
	return this->len;
}

int String::GetCount() {
#ifdef Test
	std::cout << "����� ��������� ���������� ������� ������������ ����������� ������ ��������." << std::endl;
#endif
	return count;
}

int String::count = 0;