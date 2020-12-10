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
	virtual string getName();
	virtual int getTimeAdded();
	virtual int getDueDate();
	virtual int getVecSize();
	virtual TodoList* vecAt(int);
	virtual void vecSwap(int a, int b);
private:
	TodoList* todoList;
	int importance;
};
#endif
