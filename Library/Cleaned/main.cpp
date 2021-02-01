/* Не смог реализовать сортировку (запутался с strcmp и qsort которые я хотел поместить в единый шаблон).
 * Даже не пробовал сделать все цветным. Так как я использую Линукс, здесь windows.h попросту не работает.
 * Да, к сожалению использвал стринги вместо массивов чаров. Если бы не это упрощение, я сомневась что вообще смог бы что либо сделать.
 * Соответственно большинство информации у меня хранится в стрингах, имя читателя как одна едина строка, даже дата рождения в стринге.
 * Не осилил энум для такой комплексной программы. Хотя следовало бы.
 * Не совсем понял задание в плане того, как оно должно выводить кроме пени, еще и просроченные дни.
 * Как такая вещь должна была высчитыватся, с какими коеефицентами и на чем основыватся. Реализовал только простую пеню.
 *
 * Вполне возможно что в данной программе присутствует не один баг.
 * Самый ярый баг с которым я столкнулся, была проверка пользовательского ввода. Бился над ней не один день, но так и не осилил.
 * Функция getString сжирает по первому символу (иногда)
 * Есть так же баг с тем, когда я удаляю читателя с книгой, возвращаю ее и потом пытаюсь отобразить все данные, происходит сегфолт.
 *
 * Эта программа олицетворять мой текущий уровень навыков, поэтому я буду солидарен с вашей оценкой и я сам вижу как много у меня есть пробелов.
 * Просто пожалуйста, учтите, что она все же работает (возможно частично) К посторонней помощи не прибегал.
 *
 * P.S. В будущем буду сам продолжить улучшать эту программу. Это было очень полезной практикой.
 * Надеюсь что со знаниями которые я приобрету в будущем, она сможет станет еще лучше.
 */

# include "header.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

using namespace std;



int main ()
{
    // инициализация дефолтных значений
    unsigned int booksID = 20;
    unsigned int readersID = 10;
    unsigned int shelveSize = 20;
    unsigned int personSize = 10;
    Book *books = new Book [shelveSize];
    Reader *people = new Reader [personSize];

    books [0] = {true,"1949","1984", "George Orwell", "Romance", 29.99,3.8,1};
    books [1] = {true,"1993","Forward The Foundation ", "Isaac Asimov", "Fiction", 5.99,4.7,2};
    books [2] = {true,"1954","Lord Of The Rings", "John Tolkien", "Adventure", 7.99,4.7,3};
    books [3] = {true,"Unknown","Odyssey", "Homer", "Drama", 9.99,4.7,4};
    books [4] = {true,"1865","Alice Adventure in Wonderland", "Lewis Carroll", "Adventure", 2.99,6.7,5};
    books [5] = {true,"2011","Sapiens: A Brief History of Humankind", "Yuval Harari", "Historic", 5.99,8.3,6};
    books [6] = {true,"1924","Necronomicon", "Howard Phillips Lovecraft", "Horror", 6.66,6.6,7};
    books [7] = {true,"1320","The Divine Comedy", "Dante Alighieri", "Drama", 3.99,4.2,8};
    books [8] = {true,"1932","Brave New World", "Aldos Huxley", "Fiction", 12.99,5.5,9};
    books [9] = {true,"1953","Fahrenheit 451", "Ray Bradbury", "Drama", 5.99,4.1,10};
    books [10] = {true,"1988","The Alchemist", "Paulo Goelho", "Adventure", 6.99,3.9,11};
    books [11] = {true,"1967","One Hundred Years of Solitude", "Gabriel Garcia Marquez", "Drama", 3.99,5.7,12};
    books [12] = {true,"1957","Atlas Shrugged", "Ayn Rand", "Drama", 2.99,4.1,13};
    books [13] = {true,"Unknown","The Bible", "Unknown", "Other", 0.99,2.3,14};
    books [14] = {true,"1984","Neuromancer", "William Gibson", "Drama", 6.99,6.7,15};
    books [15] = {true,"1928","The Call of Cthulhu", "Howard Phillips Lovecraft", "Horror", 9.99,3.3,16};
    books [16] = {true,"1988","A Brief History of Time", "Stephen Hawking", "Educational", 6.99,7.7,17};
    books [17] = {true,"1875","The Mysterious Island", "Jules Verne", "Novel", 5.99,7.5,18};
    books [18] = {true,"1989","The 7 Habits of Highly Effective People", "Stephen Covey", "Educational", 19.99,9.9,19};
    books [19] = {true,"1940","Group Psychology and the Analysis of the Ego", "Sigmund Freud", "Educational", 8.99,4.3,20};

    people [0] = {"EP43HH76B",1,"Antonio Parroni","1995",0};
    people [1] = {"HGG3234VB",2,"Anna Maslova","1995",0};
    people [2] = {"SDF456BCC",3,"Paolo Parroni","1962",0};
    people [3] = {"NNN353ZXG",4,"Oksana Filimonchuk","1966",0};
    people [4] = {"65BXBW5WV",5,"Ludmila Volik","1941",0};
    people [5] = {"JPPGK323V",6,"Artem Mushtatov","2001",0};
    people [6] = {"EWSXCB43G",7,"Ada Chen","1992",0};
    people [7] = {"AAVEBE6B3",8,"Yuri Kazarov","1990",0};
    people [8] = {"3456YFXDB",9,"Pavel Kazakov","1985",0};
    people [9] = {"2TZZQRHHG",10,"Zhou Chen","1994",0};

    cout << "Welcome to the library!" << endl;

    // меню
    for (;;)
    {
        cout << "Please select your operation!" << endl;
        cout << "1. Add or Remove" << endl;
        cout << "2. Change" << endl;
        cout << "3. Search & Sort" << endl;
        cout << "4. Give or Return a Book "<< endl;
        cout << "5. Show All Data " << endl;
        cout << "6. Show Current Read Books " << endl;
        unsigned int operation{};
        cin >> operation;
        while (operation < 1 || operation > 6)
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Please insert the correct operation number! " << endl;
            cin >> operation;
        }
        switch (operation)
        {
                case 1:
                    {
                        cout << "1. Add " << endl;
                        cout << "2. Remove " << endl;
                        unsigned int addRemove = binarySwitchOperation(); // создал удобную функцию для двоичного ветвления
                        switch (addRemove)
                        {
                            case 1:
                                {
                                    cout << "1. Add a Book " << endl;
                                    cout << "2. Add a Person " << endl;
                                    unsigned int addOp = binarySwitchOperation();
                                    switch (addOp)
                                        {
                                            case 1:
                                                fillBook(books,shelveSize,booksID);
                                                break;
                                            case 2:
                                                fillReader(people, personSize, readersID);
                                            break;
                                        }
                                }
                                break;
                            case 2:
                                {
                                    cout << "1. Remove a Book " << endl;
                                    cout << "2. Remove a Person " << endl;
                                    unsigned int removeOp = binarySwitchOperation();
                                    switch (removeOp)
                                        {
                                            case 1:
                                                {
                                                    unsigned int deleteBookPos = showSimple(books,shelveSize);
                                                    cout << "You will delete this element from the array" << endl;
                                                    cout << books[deleteBookPos].name << endl;
                                                    decrDarr(books,shelveSize,deleteBookPos);
                                                }
                                            break;
                                            case 2:
                                                {
                                                    unsigned int deletePersonPos =showSimple(people,personSize);
                                                    cout << "You will delete this element from the array" << endl;
                                                    cout << people[deletePersonPos].name << endl;
                                                    decrDarr(people,personSize,deletePersonPos);
                                                }
                                            break;
                                        }
                                }
                                break;
                        }
                    }
                break;
            case 2:
            {
                cout << "1. Change a Reader" << endl;
                cout << "2. Change a Book" << endl;
                unsigned int changeOperation = binarySwitchOperation();
                switch (changeOperation)
                {
                    case 1:
                        {
                            unsigned int personChangePos = showSimple(people,personSize);
                            changeReader(people,personChangePos);
                        }
                        break;
                    case 2:
                        {
                            unsigned int bookChangePos = showSimple(books,shelveSize);
                            changeBook(books,bookChangePos);
                        }
                        break;
                }
            }
                break;
            case 3:
            {
                    cout << "1. Search for Books" << endl;
                    cout << "2. Search for Readers" << endl;
                    unsigned int search = binarySwitchOperation();
                    switch (search)
                        {
                            case 1:
                                {
                                   searchSort(books,shelveSize);
                                }
                                break;
                            case 2:
                                {
                                    searchSort(people,personSize);
                                }
                                break;
                        }
            }
                break;
            case 4:
            {
                    cout << "1. Give a Book" << endl;
                    cout << "2. Return a Book" << endl;
                    unsigned int giveReturn = binarySwitchOperation();
                    switch (giveReturn)
                        {
                            case 1:
                                {
                                    unsigned int giveBookPos = showSimpleAvailableBooks(books, shelveSize);
                                    unsigned int giveToPersonPos = showSimple(people, personSize);
                                    if (books[giveBookPos].available) // здесь даже не нужно условие, да
                                        {
                                            people[giveToPersonPos].currentBooks[people[giveToPersonPos].currentBooksCounter++] = books[giveBookPos];
                                            books[giveBookPos].available = false;
                                            books[giveBookPos].reader = people[giveToPersonPos].name;
                                            books[giveBookPos].readerPos = giveToPersonPos;
                                        }
                                    else
                                        {
                                            cout << "We are sorry! This book is unavailable" << endl;
                                        }
                                }
                            break;
                            case 2:
                                {
                                    // проверяем можно ли вообще что-то вернуть
                                    int notAvailabeBooks = 0;
                                    for (int i = 0; i < shelveSize; i++)
                                        {
                                            if (!books[i].available)
                                                {
                                                    notAvailabeBooks++;
                                                }
                                        }
                                        if (notAvailabeBooks > 0)
                                            {
                                                // возвращаем
                                                cout << "There are currently " << notAvailabeBooks << " not available books in the library" << endl;
                                                unsigned int BookReturnIndex = showSimpleNotAvailableBooks(books, shelveSize);
                                                moneyDebit(people, books[BookReturnIndex].readerPos);
                                                books[BookReturnIndex].available = true;
                                                books[BookReturnIndex].reader = "";
                                                // самый смешной участок моего кода
                                                people[books[BookReturnIndex].readerPos].currentBooks[people[books[BookReturnIndex].readerPos].currentBooksCounter--] = {};
                                                people[books[BookReturnIndex].readerPos].readCount++;
                                            }
                                            else if (notAvailabeBooks == 0)
                                            {
                                                cout << "Sorry, currently all books are available and there is nothing to return!" << endl;
                                            }
                                }
                            break;
                        }
            }
                break;
            case 5:
                {
                for (int i = 0; i < shelveSize; i ++)
                 {showObject(books,i);
                    cout << endl;}
                    cout << endl;
                for (int i = 0; i < personSize; i ++)
                    {
                    showObject(people,i);
                    cout << endl;
                    }
                }
                break;
            case 6:
                {
                    showSimpleNotAvailableBooksNoNum(books, shelveSize);
                }
                break;
        }
    }
    delete [] books;
    delete [] people;
    return 1;
}

