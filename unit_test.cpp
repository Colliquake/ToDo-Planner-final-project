//
// Created by alexr on 12/10/2020.
//

#include "gtest/gtest.h"

#include "TodoList.h"
#include "Project.cpp"
#include "Task.cpp"
#include "DueDateDecorator.hpp"
#include "ImportanceDecorator.hpp"
#include "DueDateSort.hpp"
#include "ImportanceSort.hpp"
#include "DateAddedSort.hpp"


#include "dateaddedsort_test.h"


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}