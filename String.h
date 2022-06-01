#pragma once
class String {
protected:
    char* str;
    int len;
    char id;
    static int count;
public:
    String();//конструктор по умолчанию
    virtual~String();//деструктор
    String(const char* str);//конструктор, принимающий в качестве параметра Си - строку
    String(char ch);//конструктор, принимающий в качестве параметра символ(char)
    String(const String& s);//конструктор копирования
    String operator =(const String& s2);//перегрузка операции присваивания « = »
    char* GetStr();//Получение содержимого строки
    char GetId();//получение id
    int GetLen();//получение длины строки
    int GetCount();//получение количества вызовов конструктора копирования
};