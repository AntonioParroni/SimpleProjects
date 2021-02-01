
#ifndef TASKMANAGER_TASK_H
#define TASKMANAGER_TASK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

string getString(string &value);




enum Priority
    {
        LOW,
        MEDIUM,
        HIGH,
        URGENT,
    };

class Date
    {
        int year;
        int month;
        int day;
    public:
        Date();
        Date(int year_,int month_, int day_);
        ~Date();
        void setDate (int year_,int month_, int day_);
        Date getDate ();

        int getYear();
        int getMonth();
        int getDay();

        void showDate();
    };


class Task
    {
        Date eventDeadline;
        string eventName;
        string eventDescription;
        Priority eventPriority;
        string eventTag;

    public:
        Task ();
        Task(Date date_, char* name_, string descr_, Priority priority_, char* tag_);
        ~Task();

        string getEventName();
        string getEventDescription();
        Priority getEventPriority();
        string getEventTag();
        Date getDate();

        Task getTask ();

        void showEventName();
        void showEventDescription();
        void showDate ();
        void showEventPriority ();


        void showEvent ();

        void setDate(int year_, int month_ ,int day_ );
        void setEventName (string name_);
        void setEventDescription (string name_);
        void setEventPriority (Priority priority_);
        void setEventTag (string tag_);

        void setTask (Task Task_);

        void makeEventDate();
        string makeEventName();
        string makeEventDescrption();
        Priority makeEventPriority();
        string makeEventTag();

        void makeEvent ();

    };

class TaskList : public Task
    {
        vector<Task*> events;

    public:

        TaskList();
        ~TaskList();

        vector<Task*> getEvents ();
        void setEvents(vector<Task*> events_);

        void saveEvents(string path);
        void readEvents(string path);

//        void makeNewEvent ();

        void searchEvent ();
        void changeEvent(int pos);
        void deleteEvent(int pos);

        void pushNotification ();
    };


#endif
