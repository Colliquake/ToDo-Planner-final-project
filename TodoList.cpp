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
};

#endif