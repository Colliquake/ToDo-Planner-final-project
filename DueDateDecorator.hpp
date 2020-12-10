#ifndef __DUE_DATE_DECORATOR__
#define __DUE_DATE_DECORATOR__
#include"Decorator.hpp"
using namespace std;
class DueDateDecorator : public Decorator {
public:
	DueDateDecorator();
	DueDateDecorator(TodoList*);
	DueDateDecorator(TodoList*, int, int, int);
	void setDueMonth(int);
	void setDueDay(int);
	void setDueYear(int);
	int getDueMonth();
	int getDueDay();
	int getDueYear();

	virtual void setStatus(bool inp);
	virtual void add(TodoList* inp);
	virtual void display();
	virtual bool status();
	virtual string getName();
private:
	TodoList* todoList;
	int dueMonth;
	int dueDay;
	int dueYear;
};

#endif
