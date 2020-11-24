//
// Created by alexr on 11/21/2020.
//
#include <vector>
#include <iostream>
#include "TodoList.cpp"

class Project: public TodoList{
public:
    Project(std::string inp){
        name= inp;
        isDone= 0;

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
        cnuDone();
    }
    virtual void display(){
        std::cout<< "For tasks under "<< name<< ":"<< std::endl;
        for(int i= 0; i< vecs.size(); i++){
            vecs.at(i)->display();
        }
    }
private:
    std::string name;
    bool isDone;
    std::vector<TodoList*> vecs;

    void cnuDone(){       //Check 'N Update isDone (status)
        bool temp= 1;       //if at least one subtask is not done, this object's status is set to 0
        for(int i= 0; i< vecs.size(); i++){
            if(!vecs.at(i)->status()) temp= 0;
        }
        isDone= temp;
    }
};