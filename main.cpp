#include "TodoList.h"
#include "Project.cpp"
#include "Task.cpp"
#include "DueDateDecorator.hpp"
#include "ImportanceDecorator.hpp"

void displayMenu();
TodoList* addTask();
TodoList* addProject();
void addProjectToProject(TodoList* p, vector<TodoList*>& vec);
void viewPlanner(vector<TodoList*>& vec);
void deleteTaskorProject(vector<TodoList*>& vec);

int main() {
	vector<TodoList*> vec;

	int input = 0;
	while (input != 5) {
		displayMenu();
		cin >> input;
		cin.ignore();

		switch (input) {
		case 1:
		{
			TodoList* t = addTask();
			vec.push_back(t);
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
				vec.push_back(p);
				break;
			}
			case 2:
			{
				addProjectToProject(p, vec);
				break;
			}
			}
			break;
		}
		case 3:
		{
			viewPlanner(vec);
			break;
		}
		case 4:
		{
			deleteTaskorProject(vec);
			break;
		}
		case 5:
		{
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

		TodoList* ddd = new DueDateDecorator(t);
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

		TodoList* ddd2 = new DueDateDecorator(t);
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

void addProjectToProject(TodoList* p, vector<TodoList*>& vec) {
	bool matchFound = false;
	while (!matchFound) {
		cout << "Project Name: " << endl;
		string name;
		getline(cin, name);
		for (auto i : vec) {
			if (name.compare(i->getName()) == 0) {
				i->add(p);
				matchFound = true;
				break;
			}
		}
	}
}


void viewPlanner(vector<TodoList*>& vec) {
	cout << endl;
	for (auto i : vec) {
		i->display();
		cout << endl;
	}
	cout << endl;
}

void deleteTaskorProject(vector<TodoList*>& vec) {
	bool matchFound = false;
	while (!matchFound) {
		cout << "Project Name: " << endl;
		string name;
		getline(cin, name);
		int iter = 0;
		for (auto i : vec) {
			if (name.compare(i->getName()) == 0) {
				vec.erase(vec.begin() + iter);
				matchFound = true;
				break;
			}
			iter++;
		}
	}
}
