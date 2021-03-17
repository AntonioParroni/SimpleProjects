/*Реализуйте с использованием паттернов проектирования простейшую систему планирования задач. Должна быть возможность создания списка дел, установки приоритетов, установки
дат выполнения, удаление и изменения дел.
Каждому делу можно установить тег. Список дел можно загружать и сохранять в файл. Необходимо реализовать возможность
поиска конкретного дела. Критерии поиска: по датам, по тегам, по
приоритету и так далее. */

#include "Task.h"

int main()
{
//        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
//        time_t tt = std::chrono::system_clock::to_time_t(now);
//        tm local_tm = *localtime(&tt);
//        std::cout << local_tm.tm_year + 1900 << '\n';
//        std::cout << local_tm.tm_mon + 1 << '\n';
//        std::cout << local_tm.tm_mday << '\n';



//        time_t now = time(0);
//        char* currentTime = ctime(&now);
//        cout << "The local date and time is: " << currentTime << endl;



//        Task* newTask = new Task;
//
//        newTask->setDate(2020,9,23);
//        newTask->setEventPriority(URGENT);
//        newTask->showDate();
//        newTask->showEventPriority();

        string path = "test.txt";



        TaskList * newList = new TaskList [2];


        newList[0].makeEvent();

//        newList->makeNewEvent();
        newList[0].showEvent();

//        newList[0].showEventName();
//        newList[0].showEventPriority();
//        newList[0].showDate();
//        newList[0].showEventDescription();
//        cout << newList[0].getEventDescription() << endl;
//        cout << newList[0].getEventTag() << endl;


//        newList[0].showEvent();
//        newList[1].makeEvent();
//        newList[1].showEvent();


//        newList->saveEvents(path);
//        newList->readEvents(path);

    }

