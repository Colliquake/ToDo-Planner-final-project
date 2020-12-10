#include <iostream>
#include "DueDateDecorator.hpp"
DueDateDecorator::DueDateDecorator() {
	todoList = nullptr;
	dueMonth = 1;
	dueDay = 11;
	dueYear = 2001;
}

DueDateDecorator::DueDateDecorator(TodoList* t) {
	todoList = t;
	dueMonth = 1;
	dueDay = 11;
	dueYear = 2001;
}

DueDateDecorator::DueDateDecorator(TodoList* t, int m, int d, int y) {
	todoList = t;
	dueMonth = m;
	dueDay = d;
	dueYear = y;
}

void DueDateDecorator::setDueMonth(int m) {
	dueMonth = m;
}

void DueDateDecorator::setDueDay(int d) {
	dueDay = d;
}

void DueDateDecorator::setDueYear(int y) {
	dueYear = y;
}

int DueDateDecorator::getDueMonth() {
	return dueMonth;
}

int DueDateDecorator::getDueDay() {
	return dueDay;
}

int DueDateDecorator::getDueYear() {
	return dueYear;
}

void DueDateDecorator::setStatus(bool inp) {
	todoList->setStatus(inp);
}

void DueDateDecorator::add(TodoList* inp) {
	todoList->add(inp);
}

void DueDateDecorator::display() {
	todoList->display();
	cout << "Due Date: " << dueMonth << "/" << dueDay << "/" << dueYear << endl;
}

bool DueDateDecorator::status() {
	return todoList->status();
}

string DueDateDecorator::getName() {
	return todoList->getName();
}
