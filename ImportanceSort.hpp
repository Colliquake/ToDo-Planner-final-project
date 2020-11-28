#ifndef __IMPORTANCE_SORT_HPP__
#define __IMPORTANCE_SORT_HPP__

#include "SortingStrategy.hpp"
#include "TodoList.hpp"

using namespace std;

class ImportanceSort : public SortingStrategy {
    public:
        ImportanceSort() { };
        void sort(TodoList* todolist);
};

#endif //__IMPORTANCE_SORT_HPP__

