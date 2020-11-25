#include "ImportanceSort.hpp"

void ImportanceSort::SortingStrategy(TodoList* todolist) {
    int i, j, min_index;
    int numlength = todolist->size();
    for(i = 0; i < numlength - 1; i++) {
        min_index = i;
        for(j = i + 1; j < numlength; j++) {
            if(todolist->at(j)->getImportance() < todolist->at(min_index)->getImportance()) {
                min_index = j;
            }
            todolist->vecSwap(min_index, i);
        }
    }
}

                
