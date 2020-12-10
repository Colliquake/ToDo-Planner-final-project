//
// Created by alexr on 11/21/2020.
//
#include <vector>
#include <iostream>
#include <ctime>
#include "TodoList.h"

class Project : public TodoList {
public:
    Project(std::string inp) {
        name = inp;
        isDone = 0;
        vecSize = 0;
        timeAdded = timeRN();
        cnuDone();
    }
    virtual bool status() {
        cnuDone();
        return isDone;
    }
    virtual void setStatus(bool inp) {       //should almost never manually change status
        isDone = inp;                        //(cnuDone automatically does that!)
    }
    virtual void add(TodoList* inp) {
        vecs.push_back(inp);
        vecSize++;
        cnuDone();
    }
    virtual void display() {
        std::cout << "For tasks under " << name << ":" << std::endl;
        for (int i = 0; i < vecs.size(); i++) {
            vecs.at(i)->display();
        }
    }
    std::string getName() {
        return name;
    }
    int getVecSize() {
        return vecSize;
    }
    TodoList* vecAt(int x) {
        return vecs.at(x);
    }
    void vecSwap(int a, int b) {         //TODO: what do if nonexistent element?
        TodoList* temp = vecs.at(a);
        vecs.at(a) = vecs.at(b);
        vecs.at(b) = temp;
    }
    void erase(int i) {
        vecs.erase(vecs.begin() + i);
    }
    int getTimeAdded() {
        return timeAdded;
    }
    int getImportance() {
        return -1;
    }

    int getDueDate() {
        return -1;
    }
private:
    std::string name;
    bool isDone;
    int vecSize;
    std::vector<TodoList*> vecs;
    std::time_t curTime;
    int timeAdded;

    void cnuDone() {       //Check 'N Update isDone (status)
        bool temp = 1;       //if at least one subtask is not done, this object's status is set to 0
        for (int i = 0; i < vecs.size(); i++) {
            if (!vecs.at(i)->status()) temp = 0;
        }
        isDone = temp;
    }

    int timeRN() {           //returns an int in the form (without parentheses): (year)(month)(day)(hour)(min)(sec)
        int ret, year, month, day, hour, min, sec;
        std::time_t t = std::time(0);    //gets current time
        curTime = t;
        std::tm* now = std::localtime(&t);
        year = (now->tm_year + 1900) * 10000000000;
        month = (now->tm_mon + 1) * 100000000;
        day = (now->tm_mday) * 1000000;
        hour = (now->tm_hour) * 10000;
        min = (now->tm_min) * 100;
        sec = (now->tm_sec) * 1;
        ret = year + month + day + hour + min + sec;
        return ret;
    }
};
