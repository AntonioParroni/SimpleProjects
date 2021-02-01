# include "header.h"

using namespace std;


float getFloat(float &value)
{
    cout << "Input float value ";
    float a;
    cin >> a;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Please try again! ";
        cin >> a;
    }
    value = a;
    return value;

//    cout << "Input float value";
//    float a;
//    cin >> a;
//    if (cin.fail())
//   {
//      cin.clear();
//      cin.ignore(32767, '\n');
//       cin >> a;
//   }
//    value = a;
//    return value;
//    while (true)
//    {
//        std::cout << "Enter a float value: ";
//        float a;
//        std::cin >> a;
//
//        if (std::cin.fail())
//        {
//            std::cin.clear();
//            std::cin.ignore(32767,'\n');
//        }
//        else
//            value = a;
//        return value;
//        std::cin.clear();
//        std::cin.ignore();
//    }
}

string getString(string &value)
    {
        string a = "";
        cin.ignore();
        getline(cin,a); // прочитал
        cin.clear(); // почистил
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // проигнорировал
        value = a;
        return value;
    }

unsigned int binarySwitchOperation ()
    {
        unsigned int operation = 3;
        cout << "Please select your operation number!" << endl;
        cin >> operation;
        while (operation < 1 || operation > 2)
            {
                cin.clear();
                cin.ignore(100000, '\n');
                cout << "Please insert the correct operation number! " << endl;
                cin >> operation;
            }
            return operation;
    }

unsigned int showSimpleAvailableBooks (Book *&arr, unsigned int size)
    {
        for (int i = 0; i < size; i++)
            {
                if (arr[i].available)
                cout << "Position:" << i << " " << arr[i].name << "\t" << endl;
            }
        unsigned int desPos;
        cout << "Please insert the desired position "; cin >> desPos;
        return desPos;
    }
unsigned int showSimpleNotAvailableBooks (Book *&arr, unsigned int size)
    {
        for (int i = 0; i < size; i++)
            {
                if (!arr[i].available)
                {
                    cout << "Position: " << i << " " << arr[i].name << "\t" << endl;
                    cout << "Current Reader is: " << arr[i].reader << endl;
                }
            }
        unsigned int desPos;
        cout << "Please insert the desired position "; cin >> desPos;
        return desPos;
    }
void showSimpleNotAvailableBooksNoNum (Book *&arr, unsigned int size)
    {
        bool flag;
        for (int i = 0; i < size; i++)
            {
                if (!arr[i].available)
                    {
                        cout << "Position: " << i << " " << arr[i].name << "\t" << endl;
                        cout << "Current Reader is: " << arr[i].reader << endl;
                        flag = true;
                    }
            }
            if (!flag)
                {
                    cout << "All current books are available!" << endl;
                }
    }

void moneyDebit (Reader *& arr, unsigned int pos)
    {
        int debit = 0;
        cout << "Press 1 if the book return date has expired and it's reader must pay a fee " << endl;
        cout << "Press 2 if the book return date is okay " << endl;
        cin >> debit;
        if (debit == 1)
            {
                cout << "Please insert the fee amount" << endl;
                float trueDebit {};
                cin >> trueDebit;
                arr[pos].personalDebit = trueDebit;
                cout << "Now " << arr[pos].name << " must pay " << arr[pos].personalDebit << "$ of fee!" << endl;
            }
            else if (debit == 2)
            {
                return;
            }
    }

template < typename T >
unsigned int incDarr(T *&arr, unsigned int &size )
{
    T *new_arr = new T [size + 1];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    delete [] arr;
    arr = new_arr;
    return size++;
}

void showObject (Reader arr[], unsigned int pos)
{
    cout << "Reader name is:          \t  " << arr[pos].name << endl;
    cout << "Reader born date is:     \t  " << arr[pos].bornDate << endl;
    cout << "Reader passport ID is:   \t  " << arr[pos].passportID << endl;
    cout << "Reader library ID is:    \t  " << arr[pos].readerID << endl;

    if (arr[pos].readCount > 0)
    {
        cout << "Reader read count is:     \t  " << arr[pos].readCount << endl;
    }
    if (arr[pos].currentBooksCounter != 0)
        {
            cout << "Reader current book/s is/are" << endl;
            for (int i = 0; i < arr[pos].currentBooksCounter; i++)
                {
                    cout << arr[pos].currentBooks[i].name << endl;
                }
        }
        if (arr[pos].personalDebit != 0)
            {
                cout << "Reader Current Debit is: \t" << arr[pos].personalDebit << "$" << endl;
            }
}
void showObject (Book arr[], unsigned int pos)
{
    cout << "Book name is:             \t  " << arr[pos].name << endl;
    cout << "Book author is:           \t  " << arr[pos].author << endl;
    cout << "Book genre is:            \t  " << arr[pos].genre << endl;
    cout << "Book rating is:           \t  " << arr[pos].rating<< endl;
    cout << "Book publish date is:     \t  " << arr[pos].pubDate << endl;
    cout << "Book price is :           \t  " << arr[pos].price << endl;
    cout << "Book ID is:               \t  " << arr[pos].id << endl;

    if (!arr[pos].available)
    {
            cout << "Book current reader is:   \t  " << arr[pos].reader << endl;
    }
    else
    {
        cout << "This book is available for reading!" << endl;
    }
}

void changeBook (Book *&arr, unsigned int currentPos)
    {
        cout << "Current book name is:             \t" << arr[currentPos].name << endl;
        cout << "Insert new book name:"; cout << endl;
        getString(arr[currentPos].name);
        cout << "Current book author is:             \t" << arr[currentPos].author << endl;
        cout << "Insert new book author:"; cout << endl;
        getString(arr[currentPos].author);
        cout << "Current book genre is:             \t" << arr[currentPos].genre << endl;
        cout << "Insert new book genre"; cout << endl;
        getString(arr[currentPos].genre);
        cout << "Current book price is:             \t" << arr[currentPos].price << endl;
        cout << "Insert new book price"; cout << endl;
        getFloat(arr[currentPos].price);
        cout << "Current book publication date is:             \t" << arr[currentPos].pubDate << endl;
        cout << "Insert new book publication date"; cout << endl;
        getString(arr[currentPos].pubDate);
        cout << "Current book rating is:             \t" << arr[currentPos].rating << endl;
        cout << "Insert new book rating"; cout << endl;
        getFloat(arr[currentPos].rating);

        cout << "Current book name is:             \t" << arr[currentPos].name << endl;
        cout << "Current book author is:           \t" << arr[currentPos].author << endl;
        cout << "Current book genre is:            \t" << arr[currentPos].genre << endl;
        cout << "Current book price is:            \t" << arr[currentPos].price <<"$" << endl;
        cout << "Current book publication date is: \t" << arr[currentPos].pubDate << endl;
        cout << "Current book rating is:           \t" << arr[currentPos].rating << endl;
        cout << "Current book ID is:               \t" << arr[currentPos].id << endl;
    }
void changeReader (Reader *&arr, unsigned int currentPos)
{
        cout << "Current reader name is:             \t" << arr[currentPos].name << endl;
        cout << "Insert new reader name"; cout << endl;
        getString(arr[currentPos].name);
        cout << "Current reader born date is:             \t" << arr[currentPos].bornDate << endl;
        cout << "Insert new reader born date"; cout << endl;
        getString(arr[currentPos].bornDate); // здесь теряет одну букву начальную, я не знаю как это сделать, и я потратил не один день на проверу ввода, все безсмысленно
        cout << "Current reader passport ID is:             \t" << arr[currentPos].passportID << endl;
        cout << "Insert new reader passport ID"; cout << endl;
        getString(arr[currentPos].passportID);

        cout << "Current reader ID is:        \t " << arr[currentPos].readerID << endl;
        cout << "Current reader name is:      \t " << arr[currentPos].name << endl;
        cout << "Current reader born date is: \t " << arr[currentPos].bornDate<< endl;
        cout << "Current passport ID is:      \t " << arr[currentPos].passportID<< endl;
}

void fillBook (Book *&arr, unsigned int &currentPos, unsigned int &booksID)
{
    incDarr(arr, currentPos);
    cout << "Insert book name"; cout << endl;
        getString(arr[currentPos - 1].name);
    cout << "Insert author name "; cout << endl;
        getString(arr[currentPos - 1].author);
    cout << "Insert book genre "; cout << endl;
    getString(arr[currentPos - 1].genre);
    cout << "Insert book price"; cout << endl;
    getFloat(arr[currentPos - 1].price);
    cout << "Insert book publication date "; cout << endl;
        getString(arr[currentPos - 1].pubDate);
    cout << "Insert book rating "; cout << endl;
    getFloat(arr[currentPos - 1].rating);
    arr[currentPos - 1].id = ++booksID;
    arr[currentPos - 1].available = true;

    cout << "Current book name is:             \t" << arr[currentPos - 1].name << endl;
    cout << "Current book author is:           \t" << arr[currentPos - 1].author << endl;
    cout << "Current book genre is:            \t" << arr[currentPos - 1].genre << endl;
    cout << "Current book price is:            \t" << arr[currentPos - 1].price <<"$" << endl;
    cout << "Current book publication date is: \t" << arr[currentPos - 1].pubDate << endl;
    cout << "Current book rating is:           \t" << arr[currentPos - 1].rating << endl;
    cout << "Current book ID is:               \t" << arr[currentPos - 1].id << endl;
    cout << "Current book is available!" <<  endl;
}
void fillReader (Reader *&arr, unsigned int &currentPos, unsigned int &readersID)
{
    incDarr(arr,currentPos);
    cout << "Insert reader name ";
    getString(arr[currentPos - 1].name);
    cout << "Insert reader born date ";
    getString(arr[currentPos - 1].bornDate);
    cout << "Insert reader passport ID ";
    getString(arr[currentPos - 1].passportID);
    arr[currentPos -1].readerID = readersID++;
    cout << "Current reader ID is:        \t " << arr[currentPos -1].readerID << endl;
    cout << "Current reader name is:      \t " << arr[currentPos -1].name << endl;
    cout << "Current reader born date is: \t " << arr[currentPos -1].bornDate<< endl;
    cout << "Current passport ID is:      \t " << arr[currentPos -1].passportID<< endl;
}

void searchSort (Reader *&arr, unsigned int size)
{
    cout << "Please select your operation!" << endl;
    cout << "1. Search a reader \t"; cout << endl;
    cout << "2. Sort all readers \t";cout << endl;
    unsigned int operation{};
    cin >> operation;
    while (operation < 1 || operation > 2)
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
                    cout << "Please select your operation!" << endl;
                    cout << "1. Search by name \t";
                    cout << endl;
                    cout << "2. Search by born date \t";
                    cout << endl;
                    cout << "3. Search by Reader ID \t";
                    cout << endl;
                    cout << "4. Search by passport \t";
                    cout << endl;
                    int searchby = 0;
                    cin >> searchby;
                    switch (searchby)
                        {
                            case 1:
                                {
                                   string readerSearchingName;
                                    cout << "Please insert the reader name you wish to find" << endl;
                                    getString(readerSearchingName);
                                    find(arr, size, &Reader::name, readerSearchingName);
                                }
                                break;
                            case 2:
                                {
                                    string readerSearchingBornDate;
                                    cout << "Please insert the reader born date you wish to find" << endl;
                                    getString(readerSearchingBornDate);
                                    find(arr, size, &Reader::bornDate, readerSearchingBornDate);
                                }
                                break;
                            case 3:
                                {

                                    unsigned int readerSearchingId;
                                    cout << "Please insert the reader ID you wish to find" << endl;
                                    cin >> readerSearchingId;
                                    find(arr, size, &Reader::readerID, readerSearchingId);
                                }
                                break;
                            case 4:
                                {

                                    string readerSearchingPassport;
                                    cout << "Please insert the reader passport number you wish to find" << endl;
                                    getString(readerSearchingPassport);
                                    find(arr, size, &Reader::passportID, readerSearchingPassport);
                                }
                                break;
                        }
                }
            break;
            case 2:
                {

                }
            break;
        }
}
void searchSort (Book *&arr, unsigned int size)
{
    cout << "Please select your operation!" << endl;
    cout << "1. Search a book \t"; cout << endl;
    cout << "2. Sort all books \t";cout << endl;
    unsigned int operation{};
    cin >> operation;
    while (operation < 1 || operation > 2)
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
                        cout << "Please select your operation!" << endl;
                        cout << "1. Search by name \t";
                        cout << endl;
                        cout << "2. Search by author \t";
                        cout << endl;
                        cout << "3. Search by genre \t";
                        cout << endl;
                        cout << "4. Search by popularity \t";
                        cout << endl;
                        cout << "5. Search by publication date \t";
                        cout << endl;
                        int searchby = 0;
                        cin >> searchby;
                        switch (searchby)
                            {
                                case 1:
                                    {
                                        string bookSearchingName;
                                        cout << "Please insert the book name you wish to find" << endl;
                                        getString(bookSearchingName);
                                        find(arr, size, &Book::name, bookSearchingName);
                                    }
                                break;
                                case 2:
                                    {
                                        string bookSearchAuthor;
                                        cout << "Please insert the book author you wish to find" << endl;
                                        getString(bookSearchAuthor);
                                        find(arr, size, &Book::author, bookSearchAuthor);
                                    }
                                break;
                                case 3:
                                    {

                                        string bookSearchingGenre;
                                        cout << "Please insert the book genre you wish to find" << endl;
                                        getString(bookSearchingGenre);
                                        find(arr, size, &Book::genre, bookSearchingGenre);
                                    }
                                break;
                                case 4:
                                    {
                                        float bookSearchingPopularity;
                                        cout << "Please insert the reader passport number you wish to find" << endl;
                                        cin >> bookSearchingPopularity;
                                        find(arr, size, &Book::rating, bookSearchingPopularity);
                                    }
                                break;
                                case 5:
                                    {
                                        string bookSearchingPubDate;
                                        cout << "Please insert the book publication date you wish to find" << endl;
                                        getString(bookSearchingPubDate);
                                        find(arr, size, &Book::pubDate, bookSearchingPubDate);
                                    }
                                break;
                            }
                    }
                break;
                case 2:
                    {

                    }
                break;
            }
}

template <typename T, typename M>
void find (T arr[], unsigned int size, M T::* m, M parameter)
{
    bool flag = false;
        for (int i = 0; i < size; i++)
        {
                if (arr[i].*m == parameter)
                {
                        cout << "Found a result :"<< arr[i].*m << endl;
                        showObject(arr,i);
                        flag = true;
                }
            }
            if (!flag)
                {
                    cout << "Sorry, no search results "<< endl;
                }
    }

