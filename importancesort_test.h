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

    t1->setImportance(2);
    t2->setImportance(5);
    t3->setImportance(1);

    p->add(t1); p->add(t2); p->add(t3);

    SortingStrategy* is= new ImportanceSort();
    is->sort(p);

    EXPECT_EQ(p->vecAt(0)->getName(), "task3");
}

TEST(ISTest, lasttask){
    TodoList* p= new Project("Test");

    TodoList* t1= new Task("task1");
    TodoList* t2= new Task("task2");
    TodoList* t3= new Task("task3");

    t1->setImportance(2);
    t2->setImportance(5);
    t3->setImportance(1);

    p->add(t1); p->add(t2); p->add(t3);

    SortingStrategy* is= new ImportanceSort();
    is->sort(p);

    EXPECT_EQ(p->vecAt(2)->getName(), "task2");
}

TEST(ISTest, notasks){
    TodoList* p= new Project("Test");

    SortingStrategy* is= new ImportanceSort();
    is->sort(p);

    EXPECT_EQ(p->vecAt(0)->getName(), "Test");
}

TEST(ISTest, lotsoftasks){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");
TodoList* t4= new Task("task4");
TodoList* t5= new Task("task5");

t1->setImportance(2);
t2->setImportance(5);
t3->setImportance(1);
t4->setImportance(6);
t5->setImportance(8);

p->add(t1); p->add(t2); p->add(t3); p->add(t4); p->add(t5);

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->vecAt(3)->getName(), "task4");
}

TEST(ISTest, defaultImportance){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");

t1->setImportance(2);
t2->setImportance(5);

p->add(t1); p->add(t2); p->add(t3);

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task3");
}

TEST(ISTest, negativeImportance){
TodoList* p= new Project("Test");

TodoList* t1= new Task("task1");
TodoList* t2= new Task("task2");
TodoList* t3= new Task("task3");
TodoList* t4= new Task("task4");
TodoList* t5= new Task("task5");

t1->setImportance(2);
t2->setImportance(5);
t3->setImportance(1);
t4->setImportance(-6);
t5->setImportance(-10);

p->add(t1); p->add(t2); p->add(t3); p->add(t4); p->add(t5);

SortingStrategy* is= new ImportanceSort();
is->sort(p);

EXPECT_EQ(p->vecAt(0)->getName(), "task5");
EXPECT_EQ(p->vecAt(1)->getName(), "task4");
}

#endif