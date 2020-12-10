//
// Created by alexr on 11/20/2020.
//
#ifndef __TODOLIST__
#define __TODOLIST__

#include <string>
#include <vector>

class TodoList{
public:
    virtual void display()= 0;
    virtual bool status()= 0;
    virtual std::string getName()= 0;
    virtual void setStatus(bool inp)= 0;
    virtual void add(TodoList* inp)= 0;
    virtual int getTimeAdded() = 0;
    virtual int getImportance() = 0;
    virtual int getDueDate() = 0;
    virtual int getVecSize() = 0;
    virtual TodoList* vecAt(int) = 0;
    virtual void vecSwap(int a, int b) = 0;
};

#endif
