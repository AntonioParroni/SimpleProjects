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
#include  <cstdlib>


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

// страутура даты
// ограничение на ввод даты




float getFloat(float &value);
std::string getSingleString(std::string &value);
std::string getString(string &value);

unsigned int binarySwitchOperation ();
void moneyDebit (Reader *& arr, unsigned int pos);
void changeBook (Book *&arr, unsigned int currentPos);
void changeReader (Reader *&arr, unsigned int currentPos);

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
    }


unsigned int showSimpleAvailableBooks (Book *&arr, unsigned int size);
unsigned int showSimpleNotAvailableBooks (Book *&arr, unsigned int size);

template <typename T, typename K, K T::*member>
void forceChange(T *&data, int pos) ;
template < typename T >
unsigned int incDarr(T *&arr, unsigned int &size);
//template < typename T >
//unsigned int decrDarr( T *&arr, unsigned int &size, unsigned int pos)
//    {
//        T * new_arr = new T [size - 1];
//        for (int i = 0; i < size ; i++)
//            {
//                if (pos == i)
//                    {
//                        i++;
//                    }
//                new_arr[i] = arr[i];
//            }
//        delete [] arr;
//        arr = new_arr;
//        return size--;
//    }
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
    }
void showObject (Reader arr[], unsigned int pos);
void showObject (Book arr[], unsigned int pos);
void fillBook (Book *&arr, unsigned int &currentPos, unsigned int &booksID);
void fillReader (Reader *&arr, unsigned int &currentPos, unsigned int &readersID);
void changeData (Book *&arr, int pos);
void changeData (Reader *&arr, int pos);
template <typename T, typename K, K T::*member>
void search(T *&arr, K searchParameter, unsigned int size);

template <typename T,typename T::member>
void selectionSortAndShow(T data[], unsigned int size, T member);


template <typename T,typename T::member> void sort (T arr[], unsigned int size);

void searchSort (Reader *&arr, unsigned int size);
void searchSort (Book *&arr, unsigned int size);
void select (Book *& arr, unsigned int size);
void select (Reader *& arr, unsigned int size);
void showSimpleNotAvailableBooksNoNum (Book *&arr, unsigned int size);

template <typename T, typename M>
void find (T arr[], unsigned int size, M T::* m, M parameter);

//template <typename T>
//void sort (T arr[], unsigned int size);
//
//int comp1 (const void * a, const void * b);
//
////функция для сортировки строк по убыванию
//int comp2 (const void * a, const void * b);

#endif //UNTITLED_HEADER_H
