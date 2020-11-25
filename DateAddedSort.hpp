#ifndef __DATE_ADDED_SORT_HPP__
#define __DATE_ADDED_SORT_HPP__

#include "SortingStrategy.hpp"
#include "TodoList.hpp"

using namespace std;

class DateAddedSort : public SortingStrategy {
    public:
        DateAddedSort() { };
        void sort(TodoList* todolist);
};

#endif //__DATE_ADDED_SORT_HPP__
