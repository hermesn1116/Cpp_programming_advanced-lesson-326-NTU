#include <iostream>
#include <string>
using namespace std;

class stack;
class queue;
class Node
{
private:
	char data;
	Node *next;

	friend class stack;
	friend class queue;
};

class stack
{
public:
	stack();
	~stack();
	void push(char input);
	void pop();
	void list();

private:
	Node *getNode();

	Node *top;
};

class queue
{
public:
	stack();
	~stack();
	void push(char input);
	void pop();
	void list();

private:
	Node *getNode();

	Node *top;
};

int main(void)
{
	stack s;
	char c;
	string opt;

	while (true)
	{
		cin >> opt;
		if (opt == "push")
		{
			cin >> c;
			s.push(c);
		}
		else if (opt == "pop")
		{
			s.pop();
		}
		else if (opt == "list")
		{
			s.list();
		}
		else
		{
			break;
		}
	}

	return 0;
}

Node *stack::getNode()
{
	Node *new_node;
	new_node = new Node;
	if (new_node == NULL)
	{
		cout << "not enough memory" << endl;
		exit(1);
	}
	new_node->next = NULL;

	return (new_node);
};

stack::stack()
{
	top = NULL;
};

stack::~stack()
{
	Node *cur;

	if (top != NULL)
	{
		while (cur != NULL)
		{
			cur = top->next;
			delete top;
			top = cur;
		}
	}
};

void stack::push(char input_data)
{
	Node *input;
	input = getNode();
	input->data = input_data;

	if (top == NULL)
	{
		top = input;
	}
	else
	{
		input->next = top;
		top = input;
	}
};

void stack::pop()
{
	Node *tmp = top;

	if (top == NULL)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << top->data << endl;
		top = top->next;
		delete tmp;
	}
};

void stack::list()
{
	Node *cur;
	string content;

	if (top != NULL)
	{
		cur = top->next;
		content = top->data;
		while (cur != NULL)
		{
			content = " " + content;
			content = cur->data + content;
			cur = cur->next;
		}
		cout << content;
	}

	cout << endl;
};