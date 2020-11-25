//
// Created by alexr on 11/20/2020.
//
#include <ctime>
#include <iostream>
#include <string>
#include "TodoList.cpp"

class Task: public TodoList{
public:
    Task(std::string str, int due){      //TODO: DO SOMETHING WITH THE DUE DATE
        name= str;
        dueDate= due;
        isDone= 0;
        timeAdded= timeRN();
    }
    virtual void display(){
        std::cout<< "ToDo: "<< name<< "\n"
                << "Time Added: "<< formatTime()<< "\n"
                << "Is Done?: "<< boolText()<< "\n"
                << "Due Date:"<< "WORK ON FORMATTING DUE DATE!!!"<< "\n";
    }
    virtual bool status(){
        return isDone;
    }
    virtual void setStatus(bool inp){
        isDone= inp;
    }
    virtual std::string getName(){
        return name;
    }
    int getTimeAdded(){
        return timeAdded;
    }
private:
    std::string name;
    bool isDone;    //0 means not done, 1 means done
    int dueDate;
    int timeAdded;
    std::time_t curTime;

    int timeRN(){           //returns an int in the form (without parentheses): (year)(month)(day)(hour)(min)(sec)
        int ret, year, month, day, hour, min, sec;
        std::time_t t= std::time(0);    //gets current time
        curTime= t;
        std::tm* now= std::localtime(&t);
        year= (now->tm_year+ 1900)* 10000000000;
        month= (now->tm_mon+ 1)* 100000000;
        day= (now->tm_mday)* 1000000;
        hour= (now->tm_hour)* 10000;
        min= (now->tm_min)* 100;
        sec= (now->tm_sec)* 1;
        ret= year+ month+ day+ hour+ min+ sec;
        return ret;
    }
    std::string formatTime(){
        std::string ret, month, day, year, hour, min, sec;
        std::tm* now= std::localtime(&curTime);
        month= std::to_string(now->tm_mon+ 1);
        day= std::to_string(now->tm_mday);
        int hold= now->tm_year+ 1900;
        year= std::to_string(hold);

        if(now->tm_hour< 10){
            hour= "0"+ std::to_string(now->tm_hour);
        }
        else{
            hour= std::to_string(now->tm_hour);
        }

        if(now->tm_min< 10){
            min= "0"+ std::to_string(now->tm_min);
        }
        else{
            min= std::to_string(now->tm_min);
        }

        if(now->tm_sec< 10){
            sec= "0"+ std::to_string(now->tm_sec);
        }
        else{
            sec= std::to_string(now->tm_sec);
        }

        ret= month+ "/"+ day+ "/"+ year+ " "+ hour+ ":"+ min+ ":"+ sec;
        return ret;
    }

    std::string boolText(){
        if(isDone) return "Yes";
        return "No";
    }
};