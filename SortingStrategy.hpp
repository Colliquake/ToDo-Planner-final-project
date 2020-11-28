#ifndef __SORTING_STRATEGY_HPP__
#define __SORTING_STRATEGY_HPP__

#include "TodoList.hpp"

class TodoList;

class SortingStrategy {
    public:
        SortingStrategy() { };
        virtual void sort(TodoList* todolist) = 0;
};

#endif //__SORTING_STRATEGY_HPP__
