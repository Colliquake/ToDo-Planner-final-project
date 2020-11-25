#ifndef __IMPORTANCE_DECORATOR__
#define __IMPORTANCE_DECORATOR__
#include"Decorator.hpp"
using namespace std;
class ImportanceDecorator : public Decorator {
public:
	ImportanceDecorator();
	ImportanceDecorator(TodoList*);
	ImportanceDecorator(TodoList*, int);
	void setImportance(int);
	int getImportance();

	virtual void setStatus(bool inp);
	virtual void add(TodoList* inp);
	virtual void display();
	virtual bool status();
private:
	TodoList* todoList;
	int importance;
};
#endif
