#include "Task.h"

string getString(string &value)
    {
//        string a = "";
//        getline(cin,a); // прочитал
//        cin.clear(); // почистил
//        value = a;
//        return value;

        string a = "";
        getline(cin,a); // прочитал
        cin.ignore();


//        cin.ignore();
//        cin.clear(); // почистил
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // проигнорировал
        value = a;
        return value;
    }


Date::Date()
    {

    }

Date::Date(int year_, int month_, int day_)
    {
    year = year_;
    month = month_;
    day = day_;
    }

Date::~Date()
    {

    }

void Date::setDate(int year_, int month_, int day_)
    {
        year = year_;
        month = month_;
        day = day_;
    }

Date Date::getDate()
    {
        return *this;
    }

void Date::showDate()
    {
    cout << "Day : "<< day << "Month : " << month << "Year : " << year << endl;
    }

int Date::getYear()
    {
        return year;
    }

int Date::getMonth()
    {
        return month;
    }

int Date::getDay()
    {
        return day;
    }

Task::Task()
    {

    }

Task::Task(Date date_, char *name_, string descr_, Priority priority_, char *tag_)
    {
    eventDeadline = date_;
    eventName = name_;
    eventDescription = descr_;
    eventPriority = priority_;
    eventTag = tag_;
    }

Task::~Task()
    {

    }

string Task::getEventName()
    {
        return eventName;
    }

string Task::getEventDescription()
    {
        return eventDescription;
    }

Priority Task::getEventPriority()
    {
        return eventPriority;
    }

string Task::getEventTag()
    {
        return eventTag;
    }

Date Task::getDate()
    {
        return eventDeadline;
    }

void Task::setDate(int year_, int month_ ,int day_ )
    {
    eventDeadline.setDate(year_,month_,day_);
    }

void Task::setEventName(string name_)
    {
    eventName = name_;
    }

void Task::setEventDescription(string name_)
    {
    eventDescription = name_;
    }

void Task::setEventPriority(Priority priority_)
    {
    eventPriority = priority_;
    }

void Task::setEventTag(string tag_)
    {
    eventTag = tag_;
    }

void Task::showDate()
    {
        Date thisDate = getDate();
        cout << "Day: "<< thisDate.getDay() << " Month: " << thisDate.getMonth() << " Year: " << thisDate.getYear() << endl;
    }

void Task::showEventPriority()
    {
    Priority thisEventPriority = this->getEventPriority();
    if (thisEventPriority == HIGH)
        {
            cout << "High" << endl;
        }
        else if (thisEventPriority == MEDIUM)
        {
            cout << "Medium" << endl;
        }
    else if (thisEventPriority == LOW)
        {
            cout << "Low" << endl;
        }
    else if (thisEventPriority == URGENT)
        {
            cout << "URGENT" << endl;
        }
    }

void Task::makeEventDate()
    {
        int newDay, newMonth, newYear;
        cout << "Please insert Event Date Day!" << endl;
        cin >> newDay;
        cout << "Please insert Event Date Month! " << endl;
        cin >> newMonth;
        cout << "Please insert Event Date Year! " << endl;
        cin >> newYear;
        eventDeadline.setDate(newYear,newMonth,newDay);
        cin.ignore();
    }

string Task::makeEventName()
    {
        string newEventName;
        cout << "Please Insert Event Name" << endl;
        return getString(newEventName);
    }

string Task::makeEventDescrption()
    {
        string newEventDescrption;
        cout << "Please Insert Event Description" << endl;
        getString(newEventDescrption);
        return newEventDescrption;
    }

Priority Task::makeEventPriority()
    {
        Priority newEventPriority;
        cout << "Please Select Event Priority" << endl;
        cout << "1. Low  2. Medium  3. High  4. Urgent" << endl;
        bool success = false;
        while (!success)
            {
                int prioritySelector = 0;
                cin >> prioritySelector;

                switch (prioritySelector)
                    {
                        case 1:
                            newEventPriority = LOW;
                            success = true;
                            break;
                        case 2:
                            newEventPriority = MEDIUM;
                            success = true;
                            break;
                        case 3:
                            newEventPriority = HIGH;
                            success = true;
                            break;
                        case 4:
                            newEventPriority = URGENT;
                            success = true;
                            break;
                    }
            }
        return newEventPriority;
    }

string Task::makeEventTag()
    {
       string newEventTag;
       cout << "Insert The Event Tag" << endl;
       getString(newEventTag);
       return  newEventTag;
    }

void Task::makeEvent()
    {
        Task *newEvent = new Task;

        newEvent->setEventName(makeEventName());
        newEvent->setEventPriority(makeEventPriority());
        newEvent->makeEventDate();
        newEvent->setEventDescription(makeEventDescrption());
        newEvent->setEventTag(makeEventTag());
        setTask(*newEvent);
    }

Task Task::getTask()
    {
        return *this;
    }

void Task::setTask(Task Task_)
    {
    *this = Task_;
    }

void Task::showEventName()
    {
    cout << getEventName() << endl;
    }

void Task::showEventDescription()
    {
    cout << getEventDescription() << endl;
    }

void Task::showEvent()
    {
    cout << "Event Name: " << getEventName() << endl;
    cout << "Event Date: ";
    showDate();
    cout << "Event Priority: ";
    showEventPriority();
    cout << "Event Description: " << getEventDescription() << endl;
    cout << "Event Tag: " << getEventTag() << endl;
    cout << endl;
    }


TaskList::TaskList()
    {

    }

TaskList::~TaskList()
    {
    delete this;
    }

void TaskList::searchEvent()
    {

    }

void TaskList::changeEvent(int pos )
    {
    events[pos]->makeEvent();
    }

void TaskList::deleteEvent(int pos)
    {
    events.erase(pos,pos);
    }

void TaskList::pushNotification()
    {

    }

vector<Task*> TaskList::getEvents()
    {
        return events;
    }

void TaskList::setEvents(vector<Task *> events_)
    {
        events = events_;
    }

void TaskList::saveEvents(string path)
    {
    ofstream outputStream;
    outputStream.open(path);
    if (!outputStream.is_open())
        {
            cerr << "Can't Open The File" << endl;
        }
    else if (outputStream.is_open())
        {


//            for (int i = 0 ; i < getEvents().size(); i++)
//                {
//                    getEvents().begin() + i
//
            cout << events[0]->getEventName();
            int i= 0;
            for (auto Task : getEvents())
                {
                    outputStream << events[i]->getEventName();
                }

//            vector <Task*> temp = getEvents();
//
//            for (int i = 0; i < temp.size(); i++)
//                {
//                   outputStream << temp[i]->getEventName();
//
//
//                }
        }
    outputStream.close();
    }



void TaskList::readEvents(string path)
    {
    ifstream ifs;
    ifs.open(path);

    if(!ifs.is_open())
        {
            cerr << "Can't Open The File" << endl;
        }

    else if (ifs.is_open())
        {
            int currentEventsSize = events.size();

            for (int i = 0; i < currentEventsSize; i++)
                {
                    char ch;
                    while(ifs.get(ch))
                        {
                            cout << ch;
                        }
                }
        }

    ifs.close();
    }

//void TaskList::makeNewEvent()
//    {
//        TaskList * newTaskList = new TaskList;
//
//    Task* newTask = new Task;
//        newTask->setEventName(makeEventName());
//        newTask->setEventPriority(makeEventPriority());
//        newTask->makeEventDate();
//        newTask->setEventDescription(makeEventDescrption());
//        newTask->setEventTag(makeEventTag());
//    getEvents().push_back(newTask);
//    }

