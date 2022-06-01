#pragma once
#include "String.h"

class IdString :public String {
public:
	IdString();//����������� �� ���������
	~IdString()override;//����������
	IdString(const char* str);//�����������, ����������� � �������� ��������� �� - ������
	IdString(char c);//�����������, ����������� � �������� ��������� ������(char)
	IdString(const IdString& s);//����������� �����������
	void check();//�������� ������
	IdString SetUp();//������� ������ � ������� �������
	IdString& operator= (const IdString& s);//���������� �������� ������������ � = �
	friend bool operator <(const IdString& s1, const IdString& s2);//���������� �������� ��������� � < �
};