#include "TodoList.h"
#include "Project.cpp"
#include "Task.cpp"
#include "DueDateDecorator.hpp"
#include "ImportanceDecorator.hpp"

int main() {
	//TodoList* test = new TodoList();
	//test->display();
	//
	//cout << endl;

	//TodoList* testdd = new DueDateDecorator(test);
	//testdd->setIsDone(true);
	//testdd->display();

	//cout << endl;

	//TodoList* test2 = new TodoList();

	//TodoList* testid = new ImportanceDecorator(test2, 3);
	//testid->display();
	//
	//cout << endl;

	//TodoList* testiddd = new ImportanceDecorator(testdd, 0);
	//testiddd->display();

	Task* t = new Task("Take a poop");
	ImportanceDecorator* imp = new ImportanceDecorator(t, 1);
	DueDateDecorator* ddd = new DueDateDecorator(imp);
	ddd->display();

	return 0;
}
