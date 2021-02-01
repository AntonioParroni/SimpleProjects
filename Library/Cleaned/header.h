//
// Created by ray on 26.05.2020.
//

#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

# include <iostream>
# include <fstream>
# include <cstring>
# include <typeinfo>
# include <limits>
# include <cstdlib>


using namespace std;

struct Book
{
    bool available;
    string pubDate;
    string name;
    string author;
    string genre;
    float price;
    float rating;
    unsigned int id;
    string reader;
    unsigned int readerPos;
};
struct Reader
{
    string passportID;
    unsigned int readerID;
    string name;
    string bornDate;
    unsigned int readCount = 0;
    Book currentBooks[50];
    unsigned int currentBooksCounter = 0;
    float personalDebit = 0;
};


float getFloat(float &value); // получение флоат значений
string getString(string &value); // получение стринг значений

unsigned int binarySwitchOperation (); // функция для удобного двоичного свитча

void moneyDebit (Reader *& arr, unsigned int pos); // функция для начисления пени

void changeBook (Book *&arr, unsigned int currentPos); // функции изменнений
void changeReader (Reader *&arr, unsigned int currentPos); // функции изменнений

template <typename T>
unsigned int showSimple (T *&arr, unsigned int size)
    {
        for (int i = 0; i < size; i++)
            {
                cout << "Position:" << i << " " << arr[i].name << "\t" << endl;
            }
        unsigned int desPos;
        cout << "Please insert the desired position "; cin >> desPos;
        return desPos;
    } // функция для простого отображения
unsigned int showSimpleAvailableBooks (Book *&arr, unsigned int size); // функция для отображения доступных книг
unsigned int showSimpleNotAvailableBooks (Book *&arr, unsigned int size); // функция для отображения не доступных книг
void showSimpleNotAvailableBooksNoNum (Book *&arr, unsigned int size); // функция для отображения не доступных книг без возврата индекса

template < typename T >
unsigned int incDarr(T *&arr, unsigned int &size); // функция для увеличения динамического массива структур
// почему то ругалось на то, что она в func.cpp сказали поместить в хедер и здесь работает
template < typename T >
void decrDarr(T *&arr, unsigned int &size, unsigned int pos)
    {
        if (size <= 0)
            return;
        T *tmp = new T[--size];
        bool deletedFlag = false;
        for (int i = 0, j = 1; i < size; ++i, ++j)
            {
                if (i == pos)
                    {
                        deletedFlag = true;
                    }
                if (!deletedFlag)
                    {
                tmp[i] = arr[i];
                    }
                    else if (deletedFlag)
                    {
                        tmp[i]= arr[j];
                    }
            }
        delete[]arr;
        arr = tmp;
        cout << "Deleted!" << endl;
    } // функция для уменьшения динамического массива структур

void showObject (Reader arr[], unsigned int pos); // функция для детального отображения обьекта
void showObject (Book arr[], unsigned int pos); // функция для детального отображения обьекта

void fillBook (Book *&arr, unsigned int &currentPos, unsigned int &booksID); // функция для заполнения обьекта
void fillReader (Reader *&arr, unsigned int &currentPos, unsigned int &readersID); // функция для заполнения обьекта

void searchSort (Reader *&arr, unsigned int size); // перегруженные функции для сортировки и поиска
void searchSort (Book *&arr, unsigned int size); // перегруженные функции для сортировки и поиска

template <typename T, typename M>
void find (T arr[], unsigned int size, M T::* m, M parameter); // единственная прототипная функция (для поиска) которую мне удалось реализовать


#endif //UNTITLED_HEADER_H
