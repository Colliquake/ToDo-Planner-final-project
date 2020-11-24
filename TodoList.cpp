//
// Created by alexr on 11/20/2020.
//
#ifndef __TODOLIST__
#define __TODOLIST__

class TodoList{
public:
    virtual void display()= 0;
    virtual bool status()= 0;
};

#endif