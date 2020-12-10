#include"ImportanceDecorator.hpp"

ImportanceDecorator::ImportanceDecorator() {
	todoList = nullptr;
	importance = 0;
}

ImportanceDecorator::ImportanceDecorator(TodoList* t) {
	todoList = t;
	importance = 1;
}

ImportanceDecorator::ImportanceDecorator(TodoList* t, int i) {
	todoList = t;
	if (i < 1) {
		importance = 1;
	}
	else if (i > 10){
		importance = 10;
	}
	else {
		importance = i;
	}
}

void ImportanceDecorator::setImportance(int i) {
	importance = i;
}

int ImportanceDecorator::getImportance() {
	return importance;
}

void ImportanceDecorator::setStatus(bool inp) {
	todoList->setStatus(inp);
}

void ImportanceDecorator::add(TodoList* inp) {
	todoList->add(inp);
}

void ImportanceDecorator::display() {
	todoList->display();
	cout << "Importance: " << importance << endl;
}

bool ImportanceDecorator::status() {
	return todoList->status();
}

string ImportanceDecorator::getName() {
	return todoList->getName();
}
