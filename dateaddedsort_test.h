//
// Created by alexr on 12/10/2020.
//

#ifndef __DATE_ADDED_SORT_TEST_H__
#define __DATE_ADDED_SORT_TEST_H__

#include "gtest/gtest.h"
#include "TodoList.h"

TEST(DASTest, 3tasks){
    TodoList* p= new Project("Test");

    TodoList* t1= new Task("task1");
    TodoList* t2= new Task("task2");
    TodoList* t3= new Task("task3");

    p->add(t1); p->add(t2); p->add(t3);

    SortingStrategy* das= new DateAddedSort();
    das->sort(p);

    EXPECT_EQ(p->vecAt(0)->getName(), "task1");
}

TEST(DASTest, multiple){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");

p->add(t1); p->add(t2); p->add(t3);

SortingStrategy* das= new DateAddedSort();
das->sort(p);

EXPECT_EQ(p->vecAt(1)->getName(), "task2");
}

TEST(DASTest, moretasks){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");

p->add(t1); p->add(t2); p->add(t3);

SortingStrategy* das= new DateAddedSort();
das->sort(p);

EXPECT_EQ(p->vecAt(2)->getName(), "task3");
}

TEST(DASTest, notasks){
TodoList* p= new Project("Test");

SortingStrategy* das= new DateAddedSort();
das->sort(p);

EXPECT_EQ(p->getName(), "Test");
}
#endif