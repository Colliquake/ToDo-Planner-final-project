#include "TodoList.h"
#include "Project.cpp"
#include "Task.cpp"
#include "DueDateDecorator.hpp"
#include "ImportanceDecorator.hpp"
#include "DueDateSort.hpp"
#include "ImportanceSort.hpp"
#include "DateAddedSort.hpp"

void displayMenu();
TodoList* addTask();
TodoList* addProject();
void addProjectToProject(TodoList* p, Project* mainP);
void viewPlanner(Project* mainP);
void deleteTaskorProject(Project* mainP);

int main() {
	Project* mainP = new Project("Planner");

	int input = 0;
	while (input != 5) {
		displayMenu();
		cin >> input;
		cin.ignore();

		switch (input) {
		case 1:
		{
			TodoList* t = addTask();
			mainP->add(t);
			break;
		}
		case 2:
		{
			cout << "1. Create new project" << endl;
			cout << "2. Add project to existing project" << endl;
			
			cin >> input;
			cin.ignore();
			
			TodoList* p = addProject();

			switch (input) {
			case 1:
			{
				mainP->add(p);
				break;
			}
			case 2:
			{
				addProjectToProject(p, mainP);
				break;
			}
			}
			break;
		}
		case 3:
		{
			viewPlanner(mainP);
			break;
		}
		case 4:
		{
			deleteTaskorProject(mainP);
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			SortingStrategy* das = new DateAddedSort();
			das->sort(mainP);
			break;
		}
		case 7:
		{
			SortingStrategy* dds = new DueDateSort();
			dds->sort(mainP);
			break;
		}
		case 8:
		{
			SortingStrategy* is = new ImportanceSort();
			is->sort(mainP);
			break;
		}
		default:
		{
			cout << "Please enter a valid option" << endl;
		}
		}
	}

	return 0;
}

void displayMenu() {
	cout << "1. Add a task" << endl;
	cout << "2. Add a project" << endl;
	cout << "3. View Planner" << endl;
	cout << "4. Delete a task/project" << endl;
	cout << "5. Quit" << endl;
	cout << "6. Sort by Date Added" << endl;
	cout << "7. Sort by Due Date" << endl;
	cout << "8. Sort by Importance" << endl;
}

TodoList* addTask() {
	cout << "Name of Task: " << flush;
	string name;
	getline(cin, name);

	Task* t = new Task(name);
	
	cout << "1. This task has a due date." << endl;
	cout << "2. This task has an importance." << endl;
	cout << "3. This task has both." << endl;
	cout << "4. This task has neither." << endl;

	int input;
	cin >> input;
	cin.ignore();

	switch (input) {
	case 1:
	{
		int m, d, y;

		cout << "Due Month (1 - 12): " << flush;
		cin >> m;
		cin.ignore();

		cout << "Due Day (1 - 31): " << flush;
		cin >> d;
		cin.ignore();

		cout << "Due Year: " << flush;
		cin >> y;
		cin.ignore();

		TodoList* ddd = new DueDateDecorator(t, m, d, y);
		return ddd;
	}

	case 2:
	{
		int i;
		cout << "Importance (1 - 10): " << flush;
		cin >> i;
		cin.ignore();

		TodoList* id = new ImportanceDecorator(t, i);
		return id;
	}
	case 3:
	{
		int m2, d2, y2;

		cout << "Due Month (1 - 12): " << flush;
		cin >> m2;
		cin.ignore();

		cout << "Due Day (1 - 31): " << flush;
		cin >> d2;
		cin.ignore();

		cout << "Due Year: " << flush;
		cin >> y2;
		cin.ignore();

		int i2;
		cout << "Importance (1 - 10): " << flush;
		cin >> i2;
		cin.ignore();

		TodoList* ddd2 = new DueDateDecorator(t, m2, d2, y2);
		TodoList* id2 = new ImportanceDecorator(ddd2, i2);
		return id2;
	}
	case 4:
	{
		return t;
	}
	}
}

TodoList* addProject() {
	cout << "Name of Project: " << flush;
	string name;
	getline(cin, name);

	TodoList* p = new Project(name);

	int in = 0;
	do {

		TodoList* t = addTask();
		p->add(t);

		cout << "1. Add another task" << endl;
		cout << "2. Done with project" << endl;
		cin >> in;
		cin.ignore();
	} while (in != 2);

	return p;
}

void addProjectToProject(TodoList* p, Project* mainP) {
	bool matchFound = false;
	while (!matchFound) {
		cout << "Project Name: " << endl;
		string name;
		getline(cin, name);
		for (int i = 0; i < mainP->getVecSize(); i++) {
			if (name.compare(mainP->vecAt(i)->getName()) == 0) {
				mainP->add(p);
				matchFound = true;
				break;
			}
		}
	}
}


void viewPlanner(Project* mainP) {
	cout << endl;
	mainP->display();
	cout << endl;
}

void deleteTaskorProject(Project* mainP) {
	bool matchFound = false;
	while (!matchFound) {
		cout << "Project Name: " << endl;
		string name;
		getline(cin, name);
		for (int i = 0; i < mainP->getVecSize(); i++) {
			if ((name.compare(mainP->vecAt(i)->getName()) == 0)) {
				mainP->erase(i);
				matchFound = true;
				break;
			}
		}
	}
}
