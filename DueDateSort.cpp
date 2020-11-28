#include "DueDateSort.hpp"

void DueDateSort::SortingStrategy(TodoList* todolist) {
    int i, j, min_index;
    int numlength = todolist->size();
    for(i = 0; i < numlength - 1; i++) {
        min_index = i;
        for(j = i + 1; j < numlength; j++) {
            if(todolist->at(j)->getDueDate() < todolist->at(min_index)->getDueDate()) {
                min_index = j;
            }
            todolist->vecSwap(min_index, i);
        }
    }
}

