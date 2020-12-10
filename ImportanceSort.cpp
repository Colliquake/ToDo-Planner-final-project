#include "ImportanceSort.hpp"

void ImportanceSort::sort(TodoList* todolist) {
    int i, j, min_index;
    int numlength = todolist->getVecSize();
    for(i = 0; i < numlength - 1; i++) {
        min_index = i;
        for(j = i + 1; j < numlength; j++) {
            if(todolist->vecAt(j)->getImportance() < todolist->vecAt(min_index)->getImportance()) {
                min_index = j;
            }
        }
        todolist->vecSwap(min_index, i);
    }
}

