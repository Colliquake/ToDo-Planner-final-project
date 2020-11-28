#include "DateAddedSort.hpp"

void DateAddedSort::SortingStrategy(TodoList* todolist) {
    int i, j, min_index;
    int numlength = todolist->size();
    for(i = 0; i < numlength - 1; i++) {
        min_index = i;
        for(j = i + 1; j < numlength; j++) {
            if(todolist->at(j)->getTimeAdded() < todolist->at(min_index)->getTimeAdded()) {
                min_index = j;
            }
            todolist->vecSwap(min_index, i);
        }
    }
}


