#include<iostream>
#include<Windows.h>
using namespace std;

struct Price {
    char tov[20];
    char shop[20];
    int stoim;
};


void vvod(Price* spisok, int& s);

void vyvod(Price* spisok, int& s);

void poisk(Price* spisok, int& s);

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    Price* spisok = new Price[100];

    int a, s = 0;
    do
    {
        system("cls");
        cout << "Ввод данных (1)\nВывод данных (2)\nПоиск товара (3)\nВыход (0)" << endl;
        cout << "Ваш выбор > "; cin >> a;
        switch (a)
        {
        case 1: {
            vvod(spisok, s);
            break;
        }
        case 2: {
            vyvod(spisok, s);
            break;
        }
        case 3: {
            poisk(spisok, s);
            break;
        }
        default:
            break;
        }
    } while (a != 0);

    delete[]spisok;
    return 0;
}

void vvod(Price* spisok, int& s) {
    int a, l;
    l = s;
    do
    {
        system("cls");
        cin.ignore();
        cout << "Введите название товара > "; cin.getline(spisok[l].tov, 20);
        cout << "Введите название магазина > "; cin.getline(spisok[l].shop, 20);
        cout << "Введите стоимость товара > "; cin >> spisok[l].stoim;
        cout << "Добавить еще (1)" << endl;
        cout << "Выход (0)";
        cout << "Ваш выбор > "; cin >> a;
        l++;
    } while (a != 0);
    s = l;

    //Начинается сортировка
    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            if (strcmp(spisok[i].tov, spisok[j].tov) > 0) {
                string q = spisok[i].tov;
                strcpy_s(spisok[i].tov, spisok[j].tov);
                strcpy_s(spisok[j].tov, q.c_str());
                int q1 = spisok[i].stoim;
                spisok[i].stoim = spisok[j].stoim;
                spisok[j].stoim = q1;
                string q2 = spisok[i].shop;
                strcpy_s(spisok[i].shop, spisok[j].shop);
                strcpy_s(spisok[j].shop, q2.c_str());
            }
        }
    }
    //Конец сортировки

    system("cls");
}

void vyvod(Price* spisok, int& s) {
    system("cls");
    cout << "Название товара\t\tНазвание магазина\t\tСтоимость товара\n";
    for (int i = 0; i < s; i++) {
        cout << spisok[i].tov << "\t\t\t" << spisok[i].shop << "\t\t\t\t" << spisok[i].stoim << endl;
    }
    system("pause");
    system("cls");
}

void poisk(Price* spisok, int& s) {
    char arr[30];
    int a = 0;
    system("cls");
    cin.ignore();
    cout << "Введите название товара > "; cin.getline(arr, 30);
    for (int i = 0; i < s; i++) {
        if (strcmp(spisok[i].tov, arr) == 0) {
            cout << "Название товара: " << spisok[i].tov << endl;
            cout << "Название магазина: " << spisok[i].shop << endl;
            cout << "Стоимость товара: " << spisok[i].stoim << endl;
        }
else{
            a++;
        }
    }
    if (a == s) {
         cout << "Нет таких значений! " << endl;
        a = 0;
    }
    system("pause");
    system("cls");
}
