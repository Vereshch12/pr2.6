#pragma once
class String {
protected:
    char* str;
    int len;
    char id;
    static int count;
public:
    String();//����������� �� ���������
    virtual~String();//����������
    String(const char* str);//�����������, ����������� � �������� ��������� �� - ������
    String(char ch);//�����������, ����������� � �������� ��������� ������(char)
    String(const String& s);//����������� �����������
    String operator =(const String& s2);//���������� �������� ������������ � = �
    char* GetStr();//��������� ����������� ������
    char GetId();//��������� id
    int GetLen();//��������� ����� ������
    int GetCount();//��������� ���������� ������� ������������ �����������
};