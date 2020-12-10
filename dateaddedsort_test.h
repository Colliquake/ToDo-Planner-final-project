//
// Created by alexr on 12/10/2020.
//

#ifndef __DATE_ADDED_SORT_TEST_H__
#define __DATE_ADDED_SORT_TEST_H__

#include "gtest/gtest.h"
#include "TodoList.h"
#include "Project.cpp"
#include "Task.cpp"
#include "DueDateDecorator.hpp"
#include "ImportanceDecorator.hpp"
#include "DueDateSort.hpp"
#include "ImportanceSort.hpp"
#include "DateAddedSort.hpp"

TEST(DASTest, a){
    Project* mainP = new Project("Project");
    TodoList* p= new Project("Test");

    Task* t= new Task("task1");
    Task* tt= new Task("task2");
    Task* ttt= new Task("task3");

    TodoList* t1= new DueDateDecorator(t, 1, 1, 2030);
    TodoList* t2= new DueDateDecorator(tt, 1, 1, 2030);
    TodoList* t3= new DueDateDecorator(ttt, 1, 1, 2030);

    p->add(t1); p->add(t2); p->add(t3);

    SortingStrategy* das= new DateAddedSort();
    das->sort(mainP);

    EXPECT_EQ(mainP->vecAt(0)->getName(), "task1");
}

#endif