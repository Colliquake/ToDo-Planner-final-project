#ifndef __DUE_DATE_SORT_HPP__
#define __DUE_DATE_SORT_HPP__

#include "SortingStrategy.hpp"
#include "TodoList.hpp"

using namespace std;

class DueDateSort : public SortingStrategy {
    public:
        DueDateSort() { };
        void sort(TodoList* todolist);
};

#endif //__DUE_DATE_SORT_HPP__
