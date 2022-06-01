#include <iostream>
#include <Windows.h>
#include "String.h"
#include "IdString.h"
#include "ComplexNum.h"

using namespace std;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char c, str[300], t;
    int kol = 0, menum;
    String** s = nullptr;
    do {
        system("cls");
        cout << "Введите количество элементов: ";
        t = scanf_s("%d", &kol);
        while (cin.get() != '\n');
    } while (t == 0 || kol <= 0);
    s = new String * [kol];
    for (int i = 0; i < kol; i++) {
        int menu, menu2;
        do {
            system("cls");
            cout << "Укажите тип элемента " << i + 1 << " (1-Строка 2-Строка-идентефикатор 3-Комплексное число): ";
            t = scanf_s("%d", &menu);
            while (cin.get() != '\n');
        } while (t == 0 || menu > 3 || menu < 1);
        do {
            system("cls");
            cout << "Укажите значение элемента " << i + 1 << " (1-Строка 2-Символ 3-Пустая строка): ";
            t = scanf_s("%d", &menu2);
            while (cin.get() != '\n');
        } while (t == 0);
        switch (menu) {
        case 1:
            switch (menu2) {
            case 1:
                cout << "Введите строку: ";
                cin >> str;
                s[i] = new String(str);
                break;
            case 2:
                cout << "Введите символ: ";
                cin >> c;
                s[i] = new String(c);
                break;
            case 3:
                s[i] = new String();
                break;
            }
            break;
        case 2:
            switch (menu2) {
            case 1:
                cout << "Введите строку: ";
                cin >> str;
                s[i] = new IdString(str);
                break;
            case 2:
                cout << "Введите символ: ";
                cin >> c;
                s[i] = new IdString(c);
                break;
            case 3:
                s[i] = new IdString();
                break;
            }
            break;
        case 3:
            switch (menu2) {
            case 1:
                cout << "Введите строку: ";
                cin >> str;
                s[i] = new ComplexNum(str);
                break;
            case 2:
                cout << "Введите символ: ";
                cin >> c;
                s[i] = new ComplexNum(c);
                break;
            case 3:
                s[i] = new ComplexNum();
                break;
            }
            break;
        }
    }
    do {
        do {
            system("cls");
            cout << "1.Изменить элемент\n2.Тестирование Строки\n3.Тестирование Строки-идентефикатора\n4.Тестирование Комплексного числа\n5.Выход\n" << endl;
            t = scanf_s("%d", &menum);
            while (cin.get() != '\n');
        } while (t == 0 || menum < 1 || menum > 5);
        switch (menum) {
        case 1: {
            int k;
            do {
                system("cls");
                cout << "Введите индекс элемента: ";
                t = scanf_s("%d", &k);
            } while (t == 0);
            if (k >= kol) {
                cout << "Такого элемента нет!!!" << endl;
                system("pause");
            }
            else {
                int menu, menu2;
                do {
                    system("cls");
                    cout << "Укажите тип элемента " << k + 1 << " (1-Строка 2-Строка-идентефикатор 3-Комплексное число): ";
                    t = scanf_s("%d", &menu);
                    while (cin.get() != '\n');
                } while (t == 0 || menu > 3 || menu < 1);
                do {
                    system("cls");
                    cout << "Укажите значение элемента " << k + 1 << " (1-Строка 2-Символ 3-Пустая строка): ";
                    t = scanf_s("%d", &menu2);
                    while (cin.get() != '\n');
                } while (t == 0);
                switch (menu) {
                case 1:
                    switch (menu2) {
                    case 1:
                        cout << "Введите строку: ";
                        cin >> str;
                        s[k] = new String(str);
                        break;
                    case 2:
                        cout << "Введите символ: ";
                        cin >> c;
                        s[k] = new String(c);
                        break;
                    case 3:
                        s[k] = new String();
                        break;
                    }
                    break;
                case 2:
                    switch (menu2) {
                    case 1:
                        cout << "Введите строку: ";
                        cin >> str;
                        s[k] = new IdString(str);
                        break;
                    case 2:
                        cout << "Введите символ: ";
                        cin >> c;
                        s[k] = new IdString(c);
                        break;
                    case 3:
                        s[k] = new IdString();
                        break;
                    }
                    break;
                case 3:
                    switch (menu2) {
                    case 1:
                        cout << "Введите строку: ";
                        cin >> str;
                        s[k] = new ComplexNum(str);
                        break;
                    case 2:
                        cout << "Введите символ: ";
                        cin >> c;
                        s[k] = new ComplexNum(c);
                        break;
                    case 3:
                        s[k] = new ComplexNum();
                        break;
                    }
                    break;
                }
            }
        }break;
        case 2: {
            system("cls");
            int kol2 = 0;
            std::cout << "В массиве тип 'Строка' имеют элементы со следующими индексами:\t";
            for (int j = 0; j < kol; j++)
                if (s[j]->GetId() == 1) {
                    kol2 += 1;
                    std::cout << j << '\t';
                }
            std::cout << "\nИх общее количество: " << kol2 << '\n';
            int ind;
            do {
                cout << "Введите индекс элемента типа Строка, с которым вы хотите работать: ";
                t = scanf_s("%d", &ind);
                while (cin.get() != '\n');
            } while (t == 0);
            if (ind >= kol || s[ind]->GetId() != 1) {
                cout << "Ошибка при выборе элемента!!!\n";
                system("pause");
            }
            else {
                int menum2;
                do {
                    do {
                        system("cls");
                        cout << "1.Вывести содержимое\n2.=\n3.Длина строки в байтах\n4.Выход\n";
                        t = scanf_s("%d", &menum2);
                        while (cin.get() != '\n');
                    } while (t == 0);
                    system("cls");
                    switch (menum2) {
                    case 1:
                        cout << "Содержимое строки: " << s[ind]->GetStr() << endl;;
                        break;
                    case 2: {
                        cout << "Введите строку: ";
                        cin >> str;
                        *s[ind] = str;
                        cout << endl;
                    }break;
                    case 3:
                        cout << "Длина строки(в байтах): " << s[ind]->GetLen() << endl;;
                        break;
                    }
                    system("pause");
                } while (menum2 != 4);
            }
        }break;
        case 3: {
            system("cls");
            int kol2 = 0;
            std::cout << "В массиве тип 'Строка-идентефикатор' имеют элементы со следующими индексами:\t";
            for (int j = 0; j < kol; j++)
                if (s[j]->GetId() == 2) {
                    kol2 += 1;
                    std::cout << j << '\t';
                }
            std::cout << "\nИх общее количество: " << kol2 << '\n';
            int ind;
            do {
                cout << "Введите индекс элемента типа Строка-идентефикатор, с которым вы хотите работать: ";
                t = scanf_s("%d", &ind);
                while (cin.get() != '\n');
            } while (t == 0);
            if (ind >= kol || s[ind]->GetId() != 2) {
                cout << "Ошибка при выборе элемента!!!\n";
                system("pause");
            }
            else {
                int menum2;
                do {
                    IdString* s1 = dynamic_cast<IdString*>(s[ind]);
                    do {
                        system("cls");
                        cout << "1.Вывести содержимое\n2.=\n3.Длина строки в байтах\n4.Перевод строки в верхний регистр\n5.<\n6.Выход\n";
                        t = scanf_s("%d", &menum2);
                        while (cin.get() != '\n');
                    } while (t == 0);
                    system("cls");
                    switch (menum2) {
                    case 1:
                        cout << "Содержимое строки: " << s1->GetStr() << endl;;
                        break;
                    case 2: {
                        cout << "Введите строку: ";
                        cin >> str;
                        *s1 = str;
                        cout << endl;
                    }break;
                    case 3:
                        cout << "Длина строки(в байтах): " << s1->GetLen() << endl;;
                        break;
                    case 4: {
                        cout << "Строка переведена в верхний регистр." << endl;
                        s1->SetUp();
                    }break;
                    case 5: {
                        IdString s2;
                        cout << "Введите вторую строку: ";
                        cin >> str;
                        s2 = str;
                        system("cls");
                        if(*s1 < s2)
                            cout << s1->GetStr() << " < " << s2.GetStr() << " - true" << endl;
                        else
                            cout << s1->GetStr() << " < " << s2.GetStr() << " - false" << endl;
                    }break;
                    }
                    system("pause");
                } while (menum2 != 6);
            }
        }break;
        case 4: {
            system("cls");
            int kol2 = 0;
            std::cout << "В массиве тип 'Комплексное число' имеют элементы со следующими индексами:\t";
            for (int j = 0; j < kol; j++)
                if (s[j]->GetId() == 3) {
                    kol2 += 1;
                    std::cout << j << '\t';
                }
            std::cout << "\nИх общее количество: " << kol2 << '\n';
            int ind;
            do {
                cout << "Введите индекс элемента типа Комплексное число, с которым вы хотите работать: ";
                t = scanf_s("%d", &ind);
                while (cin.get() != '\n');
            } while (t == 0);
            if (ind >= kol || s[ind]->GetId() != 3) {
                cout << "Ошибка при выборе элемента!!!\n";
                system("pause");
            }
            else {
                int menum2;
                ComplexNum* s1 = dynamic_cast<ComplexNum*>(s[ind]);
                do {
                    do {
                        system("cls");
                        cout << "1.Вывести содержимое\n2.=\n3.Длина строки в байтах\n4.!\n5./\n6.Выход\n";
                        t = scanf_s("%d", &menum2);
                        while (cin.get() != '\n');
                    } while (t == 0);
                    system("cls");
                    switch (menum2) {
                    case 1:
                        cout << "Содержимое строки: " << s1->GetStr() << endl;
                        break;
                    case 2: {
                        cout << "Введите строку: ";
                        cin >> str;
                        *s1 = str;
                        cout << endl;
                    }break;
                    case 3:
                        cout << "Длина строки(в байтах): " << s1->GetLen() << endl;
                        break;
                    case 4: {
                        ComplexNum s2 = !*s1;
                        cout << s1->GetStr() << " - текущее комплексное число\n" << s2.GetStr() << " - сопряжённое комплексное число" << endl;
                    }break;
                    case 5: {
                        ComplexNum s2, s3;
                        cout << "Введите вторую строку: ";
                        cin >> str;
                        s2 = str;
                        system("cls");
                        s3 = *s1 / s2;
                        cout << s1->GetStr() << " / " << s2.GetStr() << " = " << s3.GetStr() << endl;
                    }break;
                    }
                    system("pause");
                } while (menum2 != 6);
            }
        }break;
        }
    } while (menum != 5);
    if (s != nullptr)
        delete[] s;
    return 0;
}