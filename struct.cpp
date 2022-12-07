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
        cout << "���� ������ (1)\n����� ������ (2)\n����� ������ (3)\n����� (0)" << endl;
        cout << "��� ����� > "; cin >> a;
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
        cout << "������� �������� ������ > "; cin.getline(spisok[l].tov, 20);
        cout << "������� �������� �������� > "; cin.getline(spisok[l].shop, 20);
        cout << "������� ��������� ������ > "; cin >> spisok[l].stoim;
        cout << "�������� ��� (1)" << endl;
        cout << "����� (0)";
        cout << "��� ����� > "; cin >> a;
        l++;
    } while (a != 0);
    s = l;

    //���������� ����������
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
    //����� ����������

    system("cls");
}

void vyvod(Price* spisok, int& s) {
    system("cls");
    cout << "�������� ������\t\t�������� ��������\t\t��������� ������\n";
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
    cout << "������� �������� ������ > "; cin.getline(arr, 30);
    for (int i = 0; i < s; i++) {
        if (strcmp(spisok[i].tov, arr) == 0) {
            cout << "�������� ������: " << spisok[i].tov << endl;
            cout << "�������� ��������: " << spisok[i].shop << endl;
            cout << "��������� ������: " << spisok[i].stoim << endl;
        }
        else {
            a++;
        }
    }
    if (a == s) {
        cout << "��� ����� ��������! " << endl;
        a = 0;
    }
    system("pause");
    system("cls");
}
