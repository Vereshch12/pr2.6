#pragma once
#include "String.h"
#include <iostream>

class ComplexNum :public String {
private:
	double x, y;
public:
	ComplexNum();//конструктор по умолчанию
	~ComplexNum()override;//деструктор
	ComplexNum(const char* s); //конструктор, принимающий в качестве параметра Си - строку
	ComplexNum(char c);//конструктор, принимающий в качестве параметра символ(char)
	ComplexNum(const ComplexNum& s);//конструктор копирования
	ComplexNum& operator= (const ComplexNum& s);//перегрузка операции присваивания « = »
	friend const ComplexNum operator !(const ComplexNum& s);//перегрузка операции получения сопряженного комплексного числа « ! »
	friend const ComplexNum operator/(const ComplexNum& s1, const ComplexNum& s2);//перегрузка операции деления « / »
	void check();//проверка строки
};