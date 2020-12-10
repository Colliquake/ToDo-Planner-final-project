//
// Created by alexr on 12/10/2020.
//

#ifndef __IMPORTANCE_SORT_TEST__
#define __IMPORTANCE_SORT_TEST__

#include "gtest/gtest.h"
#include "TodoList.h"

TEST(ISTest, 3tasks){
    TodoList* p= new Project("Test");

    TodoList* t1= new Task("task1");
    TodoList* t2= new Task("task2");
    TodoList* t3= new Task("task3");

    TodoList* ip1= new ImportanceDecorator(t1, 2);
    TodoList* ip2= new ImportanceDecorator(t2, 5);
    TodoList* ip3= new ImportanceDecorator(t3, 1);
    p->add(ip1); p->add(ip2); p->add(ip3);

    SortingStrategy* is= new ImportanceSort();
    is->sort(p);

    EXPECT_EQ(p->vecAt(0)->getName(), "task3");
}

TEST(ISTest, 5tasks){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");
TodoList* t4= new Task("task4");
TodoList* t5= new Task("task5");

TodoList* ip1= new ImportanceDecorator(t1, 2);
TodoList* ip2= new ImportanceDecorator(t2, 5);
TodoList* ip3= new ImportanceDecorator(t3, 1);
TodoList* ip4= new ImportanceDecorator(t4, 7);
TodoList* ip5= new ImportanceDecorator(t5, 9);
p->add(ip1); p->add(ip2); p->add(ip3); p->add(ip4); p->add(ip5);

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task3");
}

TEST(ISTest, notasks){
TodoList* p= new Project("Test");

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->getName(), "Test");
}

TEST(ISTest, negImportance){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");

TodoList* ip1= new ImportanceDecorator(t1, 2);
TodoList* ip2= new ImportanceDecorator(t2, -10);
TodoList* ip3= new ImportanceDecorator(t3, 1);
p->add(ip1); p->add(ip2); p->add(ip3);

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task2");
}
#endif