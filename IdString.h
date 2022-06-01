#pragma once
#include "String.h"

class IdString :public String {
public:
	IdString();//конструктор по умолчанию
	~IdString()override;//деструктор
	IdString(const char* str);//конструктор, принимающий в качестве параметра —и - строку
	IdString(char c);//конструктор, принимающий в качестве параметра символ(char)
	IdString(const IdString& s);//конструктор копировани€
	void check();//проверка строки
	IdString SetUp();//перевод строки в верхний регистр
	IdString& operator= (const IdString& s);//перегрузка операции присваивани€ Ђ = ї
	friend bool operator <(const IdString& s1, const IdString& s2);//перегрузка операции сравнени€ Ђ < ї
};