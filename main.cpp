//
// Created by alexr on 11/24/2020.
//
#include <iostream>
#include "Project.cpp"
#include "Task.cpp"

int main(){
    Task* math1= new Task("Prepare", 14);

    Task* sci1= new Task("Read", 16);
    Task* sci2= new Task("Nap", 17);

    Task* study= new Task("Study", 19);

    Project* math= new Project("math");
    Project* sci= new Project("science");
    math->add(math1);
    sci->add(sci1);
    sci->add(sci2);

    std::cout<< "Testing displays"<< std::endl;
    math->display();
    std::cout<< std::endl;
    sci->display();

    std::cout<< "Testing task added times:"<< std::endl;
    std::cout<< sci1->getTimeAdded()<< std::endl;

    std::cout<< "Testing timeIntoVecs vectors for math1 task:"<< std::endl;
    std::vector<int> testVec= sci1->timeIntoVecs(sci1->getTimeAdded());
    std::cout<< "Month: "<< testVec.at(0)<< std::endl;
    std::cout<< "Day: "<< testVec.at(1)<< std::endl;
    std::cout<< "Year: "<< testVec.at(2)<< std::endl;
    std::cout<< "Hour: "<< testVec.at(3)<< std::endl;
    std::cout<< "Min: "<< testVec.at(4)<< std::endl;
    std::cout<< "Sec: "<< testVec.at(5)<< std::endl;
    return 0;
}