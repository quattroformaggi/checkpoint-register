#include <iostream>
#include <vector> //push_back() & etc.
#include <iomanip> //setw()
#include <algorithm> //find
#include <string> //getline(cin,string)
#include <fstream> //табличный вывод
#include <windows.h> //SetConsoleCP(1251)
using namespace std;
//090820

////////////////////////////////////////////////////////////////    строки взаимодействия
const string version                = " /// текущая версия v08.2020 (c) quattroformaggi";
const string mainmenu               = "Главное меню:\n";
const string soon                   = "Будет добавлено в следующем обновлении!\n";
const string welcome                = "Добро пожаловать в реестр пропусков КПП №1";
const string bye                    = "Прощайте!";
const string err                    = "Ошибка ввода!";
const string enter                  = "Введите номер функции: ";
const string searchExec             = "Выполняется поиск по всему реестру...\n";
const string phoneElemFound         = "Элемент найден в массиве [Телефонные номера]: ";
const string phoneElemNotFound      = "Элемент не найден в массиве [Телефонные номера]\n";
const string fioElemFound           = "Элемент найден в массиве [ФИО]: ";
const string fioElemNotFound        = "Элемент не найден в массиве [ФИО]\n";
const string commentElemFound       = "Элемент найден в массиве [Комментарий]: ";
const string commentElemNotFound    = "Элемент не найден в массиве [Комментарий]\n";
const string searchWhere            = "Где будем искать?\n[1] По всему реестру\n[2] Телефонные номера\n[3] ФИО\n[4] Комментарии:";
const string searchWhat             = "Что будем искать?:";
const string searchFinishedAll      = "Поиск по всему реестру завершен!\n";
const string searchFinishedPhone    = "Поиск по разделу [Телефонные номера] завершен!\n";
const string searchFinishedFio      = "Поиск по разделу [ФИО] завершен!\n";
const string searchFinishedCom      = "Поиск по разделу [Комментарии] завершен!\n";
const string addPhone               = "Введите полный номер телефона: ";
const string addFio                 = "Введите полное ФИО (пробелы необязательны): ";
const string addCom                 = "Введите комментарий (или оставьте поле пустым): ";
const string addSuccess             = "Строка была успешно добавлена!\n";
const string remSuccess             = "Строка была успешно удалена!\n";
const string regDropSuccess         = "Реестр был успешно выгружен!\n";
const string regReadSuccess         = "Реестр был успешно считан!\n";
const string impossible             = "Удаление невозможно: на данный момент в массиве 0 строк!\n";
const string atmConsistsOf          = "Реестр сейчас состоит из:\n";
const string endofReg               = "[Конец реестра]\n";
////////////////////////////////////////////////////////////////    описание функций программы
const string movedTo    = "Вы переместились в раздел: ";
const string quit       = "[0] Выйти из программы";
const string updateReg  = "[1] Просмотреть реестр";
const string searchReg  = "[2] Найти информацию";
const string addFirst   = "[3] Добавить строку в начало";
const string addLast    = "[4] Добавить строку в конец";
const string remFirst   = "[5] Удалить строку в начале";
const string remLast    = "[6] Удалить строку в конце";
const string dropReg    = "[7] Выгрузить реестр в файл-таблицу";
const string readReg    = "[8] Прочитать реестр из файла-таблицы";
const string showPhoto  = "[КТТС] Вывести фото";
////////////////////////////////////////////////////////////////
const char regfile[11]  = "qf_reg.csv";                    //    имя выходного файла реестра
////////////////////////////////////////////////////////////////    прототипы используемых функций в коде
void fUpdReg    (const vector<string> vec1, const vector<string> vec2, const vector<string> vec3);
void fSearch    (vector<string> vec1, vector<string> vec2, vector<string> vec3);
void fAddfirst   (vector<string>&, vector<string>&, vector<string>&);
void fAddlast   (vector<string>&, vector<string>&, vector<string>&);
void fRemfirst   (vector<string>&, vector<string>&, vector<string>&);
void fRemlast   (vector<string>&, vector<string>&, vector<string>&);
void fShowphoto ();
void fDropreg   (const vector<string> vec1,const vector<string> vec2,const vector<string> vec3);
void fReadreg   ();
////////////////////////////////////////////////////////////////

int main()
{
    //setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> phoneNumbers (0); //массив телефонных номеров
    vector<string> fullName     (0); //массив ФИО
    vector<string> otherInfo    (0); //массив комментариев

    cout << welcome << version << endl;
    short choice;
    do 
    {
       cout << setw(35)  << mainmenu
            << quit      << endl
            << updateReg << setw(38) << searchReg << endl
            << addFirst  << setw(39) << addLast   << endl
            << remFirst  << setw(39) << remLast   << endl
            << dropReg   << setw(42) << readReg   << endl;
            //<< showPhoto << endl;
        cout << enter; cin >> choice;
        switch (choice)
        {
        case 1: fUpdReg(phoneNumbers, fullName, otherInfo); break;
        case 2: fSearch(phoneNumbers, fullName, otherInfo); break;
        case 3: fAddfirst(phoneNumbers, fullName, otherInfo); break;
        case 4: fAddlast(phoneNumbers, fullName, otherInfo); break;
        case 5: fRemfirst(phoneNumbers, fullName, otherInfo); break;
        case 6: fRemlast(phoneNumbers, fullName, otherInfo); break;
        case 7: fDropreg(phoneNumbers, fullName, otherInfo); break;
        case 8: fReadreg(); break;
        //case 9: fShowphoto(); break; //dunno how to do it yet
        case 0: cout << bye << endl; return 0;
        default: cout << err << endl; break;
        }
    } while (choice != '0');
}

void fUpdReg(const vector<string> vec1, const vector<string> vec2, const vector<string> vec3)
{
    system("cls");
    cout << movedTo + updateReg << endl;
    cout << setw(66) << atmConsistsOf;
    for (short i = 0; i < vec1.size(); i++)
    {
        cout << i << " -> " << vec1.at(i) << setw(22) << " || " << setw(22) << vec2.at(i) << setw(22) << " || " << setw(22) << vec3.at(i) << endl;
    }
    cout << setw(60) << endofReg;
}
void fSearch(vector<string> vec1,vector<string> vec2,vector<string> vec3)
{
    /////////////////////////////////////////////
    vector<string>::iterator iter1, iter2, iter3;
    string query;
    short temp;
    /////////////////////////////////////////////
    system("cls");
    cout << movedTo + searchReg << endl;
    cout << searchWhere; cin >> temp;
    cin.ignore(); //убирает смещение каретки
    cout << searchWhat; getline(cin, query);
    switch (temp)
    {
    case 1:
        cout << searchExec;
        iter1 = find(vec1.begin(), vec1.end(), query);
        if (iter1 != vec1.end())
            cout << phoneElemFound << *iter1 << '\n';
        else
            cout << phoneElemNotFound;
        //////////////////////////////////////////////
        iter2 = find(vec2.begin(), vec2.end(), query);
        if (iter2 != vec2.end())
            cout << fioElemFound << *iter2 << '\n';
        else
            cout << fioElemNotFound;
        //////////////////////////////////////////////
        iter3 = find(vec3.begin(), vec3.end(), query);
        if (iter3 != vec3.end())
            cout << commentElemFound << *iter3 << '\n';
        else
            cout << commentElemNotFound;
        cout << searchFinishedAll << endl;
        break;
    case 2:
        iter1 = find(vec1.begin(), vec1.end(), query);
        if (iter1 != vec1.end())
            cout << phoneElemFound << *iter1 << '\n';
        else
            cout << phoneElemNotFound;
        cout << searchFinishedPhone;
        break;
    case 3:
        iter2 = find(vec2.begin(), vec2.end(), query);
        if (iter2 != vec2.end())
            cout << fioElemFound << *iter2 << '\n';
        else
            cout << fioElemNotFound;
        cout << searchFinishedFio;
        break;
    case 4:
        iter3 = find(vec3.begin(), vec3.end(), query);
        if (iter3 != vec3.end())
            cout << commentElemFound << *iter3 << '\n';
        else
            cout << commentElemNotFound;
        cout << searchFinishedCom;
        break;
    default: cout << err << endl; break;
    }
}
    void fAddlast(vector<string>& vec1, vector<string>& vec2, vector<string>& vec3)
    {
        system("cls");
        string phone_t, fio_t, com_t;
        cout << movedTo + addLast << endl;
        cin.ignore(); //не пропускает смещение каретки => не пропускает строку
        cout << addPhone; getline(cin, phone_t);
        cout << addFio; getline(cin, fio_t);
        cout << addCom; getline(cin, com_t);
        ///////////////////////////
        if (phone_t.size() > 0)
            vec1.push_back(phone_t);
        else
            vec1.push_back("-");
        ///////////////////////////
        if (fio_t.size() > 0)
            vec2.push_back(fio_t);
        else
            vec2.push_back("-");
        ///////////////////////////
        if (com_t.size() > 0)
            vec3.push_back(com_t);
        else
            vec3.push_back("-");
        ///////////////////////////
        cout << addSuccess;
    }
    void fRemlast(vector<string>& vec1, vector<string>& vec2, vector<string>& vec3)
    {
        system("cls");
        cout << movedTo + remLast << endl;
        if (vec1.size() > 0)
        {
            vec1.pop_back();
            vec2.pop_back();
            vec3.pop_back();
            cout << remSuccess;
        }
        else
            cout << impossible;
    }
    void fDropreg(const vector<string> vec1,const vector<string> vec2,const vector<string> vec3)
    {
        system("cls");
        cout << movedTo + dropReg << endl;
        ofstream regDropping;
        regDropping.open(regfile, ios::app);
        regDropping << "Телефоны;ФИО;Комментарий" << endl;
        for (unsigned short strs = 0; strs < vec1.size(); strs++)
        {
            regDropping << vec1[strs] << ";" << vec2[strs] << ";" << vec3[strs] << endl;
        }
        cout << regDropSuccess;
        regDropping.close();
    }
    void fReadreg()
    {
        system("cls");
        string fstr;
        cout << movedTo + readReg << endl;
        ifstream regReading(regfile);
        while (getline(regReading,fstr))
        {
            cout << fstr << endl;
        }
        regReading.close();
        cout << regReadSuccess;
    }
    void fAddfirst(vector<string>& vec1, vector<string>& vec2, vector<string>& vec3)
    {
        system("cls");
        string phone_t, fio_t, com_t;
        cout << movedTo + addFirst << endl;
        cin.ignore(); //не пропускает смещение каретки => не пропускает строку
        cout << addPhone; getline(cin, phone_t);
        cout << addFio; getline(cin, fio_t);
        cout << addCom; getline(cin, com_t);
        ///////////////////////////
        if (phone_t.size() > 0)
            vec1.insert(vec1.begin(), phone_t);
        else
            vec1.insert(vec1.begin(), "-");
        ///////////////////////////
        if (fio_t.size() > 0)
            vec2.insert(vec2.begin(), fio_t);
        else
            vec2.insert(vec2.begin(), "-");
        ///////////////////////////
        if (com_t.size() > 0)
            vec3.insert(vec3.begin(), com_t);
        else
            vec3.insert(vec3.begin(), "-");
        ///////////////////////////
        cout << addSuccess;
    }
    void fRemfirst(vector<string>& vec1, vector<string>& vec2, vector<string>& vec3)
    {
        system("cls");
        cout << movedTo + remFirst << endl;
        if (vec1.size() > 0)
        {
            vec1.erase(vec1.begin());
            vec2.erase(vec2.begin());
            vec3.erase(vec3.begin());
            cout << remSuccess;
        }
        else
            cout << impossible;
    }
    void fShowphoto()
    {
        system("cls");
        cout << movedTo + showPhoto << endl;
        cout << soon;
    }

