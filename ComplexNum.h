#pragma once
#include "String.h"
#include <iostream>

class ComplexNum :public String {
private:
	double x, y;
public:
	ComplexNum();//����������� �� ���������
	~ComplexNum()override;//����������
	ComplexNum(const char* s); //�����������, ����������� � �������� ��������� �� - ������
	ComplexNum(char c);//�����������, ����������� � �������� ��������� ������(char)
	ComplexNum(const ComplexNum& s);//����������� �����������
	ComplexNum& operator= (const ComplexNum& s);//���������� �������� ������������ � = �
	friend const ComplexNum operator !(const ComplexNum& s);//���������� �������� ��������� ������������ ������������ ����� � ! �
	friend const ComplexNum operator/(const ComplexNum& s1, const ComplexNum& s2);//���������� �������� ������� � / �
	void check();//�������� ������
};