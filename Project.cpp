//
// Created by alexr on 11/21/2020.
//
#include <vector>
#include <iostream>
#include "TodoList.h"

class Project: public TodoList{
public:
    Project(std::string inp){
        name= inp;
        isDone= 0;
        vecSize= 0;

        cnuDone();
    }
    virtual bool status(){
        cnuDone();
        return isDone;
    }
    virtual void setStatus(bool inp){       //should almost never manually change status
        isDone= inp;                        //(cnuDone automatically does that!)
    }
    virtual void add(TodoList* inp){
        vecs.push_back(inp);
        vecSize++;
        cnuDone();
    }
    virtual void display(){
        std::cout<< "For tasks under "<< name<< ":"<< std::endl;
        for(int i= 0; i< vecs.size(); i++){
            vecs.at(i)->display();
        }
    }
    std::string getName(){
        return name;
    }
    int getVecSize(){
        return vecSize;
    }
    auto vecAt(int x){
        return vecs.at(x);
    }
    void vecSwap(int a, int b){         //TODO: what do if nonexistent element?
        auto s1= vecs.at(a);
        auto s2= vecs.at(b);
        std::swap(s1, s2);
    }
private:
    std::string name;
    bool isDone;
    int vecSize;
    std::vector<TodoList*> vecs;

    void cnuDone(){       //Check 'N Update isDone (status)
        bool temp= 1;       //if at least one subtask is not done, this object's status is set to 0
        for(int i= 0; i< vecs.size(); i++){
            if(!vecs.at(i)->status()) temp= 0;
        }
        isDone= temp;
    }
};