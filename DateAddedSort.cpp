#include "DateAddedSort.hpp"

void DateAddedSort::sort(TodoList* todolist) {
    int i, j, min_index;
    int numlength = todolist->getVecSize();
    for(i = 0; i < numlength - 1; i++) {
        min_index = i;
        for(j = i + 1; j < numlength; j++) {
            if(todolist->vecAt(j)->getTimeAdded() < todolist->vecAt(min_index)->getTimeAdded()) {
                min_index = j;
            }
        }
        todolist->vecSwap(min_index, i);
    }
}



