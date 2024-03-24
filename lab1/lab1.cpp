// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*Определитесь с текстовым документом, характеристики которого вы
будете исследовать.Требования такие :
− документ на английском языке;
− размер текстового файла - 20 - 60 Кб;
− документ должен быть осмысленным.
В программной оболочке FreePascal создайте программу со
следующим функционалом :
− на вход программы поступает текстовый файл;
− в результате обработки программа формирует массив из двух
элементов : символ или его ASCII - код и количество появлений данного
символа в тексте;
− производится сортировка массива любым из доступных вам
методов;
− на экран выводится таблица состоящая из следующих столбцов :
код символа, сам символ в кавычках, количество появлений в тексте,
частота нормированная к 1.
В отчет необходимо поместить таблицу с частотой появления
символов в тексте.*/




#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
}

int main()
{
    setlocale(LC_ALL, "ru");
    while (true) {
        string file = "";
        cout << "Введите имя файла: ";
        cin >> file;

        ifstream fin(file);

        if (!fin) {
            cout << "Ошибка открытия файла!" << endl;
            continue;
        }

        string strh;
        string str;

        while (!fin.eof()) {
            getline(fin, strh);
            str += strh;
        }

        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end()); // удаляем пробелы из строки
        transform(str.begin(), str.end(), str.begin(), ::toupper); // преобразуем все символы в верхний регистр

        vector<pair<char, int>> letters;

        for (int i = 0; i < str.length(); i++) { // заполняем массив буквами и считаем их количество
            if (isalpha(str[i])) { // если символ является буквой
                int k = 0;
                for (int j = 0; j < letters.size(); j++) {
                    if (str[i] == letters[j].first) {
                        letters[j].second += 1;
                        k++;
                        break;
                    }
                }
                if (k == 0) {
                    letters.push_back(make_pair(str[i], 1));
                }
            }
        }

        sort(letters.begin(), letters.end(), compare);

        for (int i = 0; i < letters.size(); i++) { // выводим результат
            cout << letters[i].first << "     " << letters[i].second << '\n';
        }

        fin.close();
    }

    return 0;
}


