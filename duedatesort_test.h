//
// Created by alexr on 12/10/2020.
//

#ifndef __DUE_DATE_SORT_TEST_H__
#define __DUE_DATE_SORT_TEST_H__

#include "gtest/gtest.h"
#include "TodoList.h"

TEST(DDTest, 3tasks){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");

TodoList* dd1= new DueDateDecorator(t1, 2, 16, 2021);
TodoList* dd2= new DueDateDecorator(t2, 5, 15, 2021);
TodoList* dd3= new DueDateDecorator(t3, 8, 21, 2021);

p->add(dd1); p->add(dd2); p->add(dd3);

SortingStrategy* dd= new DueDateSort();
dd->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task1");
}

TEST(DDTest, blankdate){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");
TodoList* t4= new Task("task4");

TodoList* dd1= new DueDateDecorator(t1, 2, 16, 2021);
TodoList* dd2= new DueDateDecorator(t2, 5, 15, 2021);
TodoList* dd3= new DueDateDecorator(t3, 8, 21, 2021);
TodoList* dd4= new DueDateDecorator(t4);

p->add(dd1); p->add(dd2); p->add(dd3); p->add(dd4);

SortingStrategy* dd= new DueDateSort();
dd->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task1");
}

TEST(DDTest, 5tasks){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");
TodoList* t4= new Task("task4");

TodoList* dd1= new DueDateDecorator(t1, 2, 16, 2021);
TodoList* dd2= new DueDateDecorator(t2, 5, 15, 2021);
TodoList* dd3= new DueDateDecorator(t3, 8, 21, 2021);
TodoList* dd4= new DueDateDecorator(t4, 1, 5, 2021);

p->add(dd1); p->add(dd2); p->add(dd3); p->add(dd4);

SortingStrategy* dd= new DueDateSort();
dd->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task4");
}

TEST(DDTest, notasks){
TodoList* p= new Project("Test");

SortingStrategy* dd= new DueDateSort();
dd->sort(p);

EXPECT_EQ(p->getName(), "Test");
}

#endif