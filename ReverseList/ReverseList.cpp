#include "ReverseList.h"

Node* List::AddNode(int value, Node* a = nullptr)
{
	Node* elem = new Node();
	elem->_data = value;
	_count++;
	if (a == NULL)
	{
		if (_head == NULL) {
			elem->next = NULL;
			_head = elem;
		}
		else {
			elem->next = _head;
			_head = elem;
		}
		return elem;
	}
	elem->next = a->next;
	a->next = elem;
	return elem;
}

Node* List::AddNode(int value)
{
	Node* a = nullptr;
	Node* elem = new Node();
	elem->_data = value;
	_count++;
	if (a == NULL)
	{
		if (_head == NULL) {
			elem->next = NULL;
			_head = elem;
		}
		else {
			elem->next = _head;
			_head = elem;
		}
		return elem;
	}
	elem->next = a->next;
	a->next = elem;
	return elem;
}

Node* List::DelNode(Node* a)
{
	if (a == NULL) { return NULL; }
	_count--;
	if (a == _head)
	{
		_head = a->next;
		delete a;
		return _head;
	}
	Node* prev = PrevNode(a);
	prev->next = a->next;
	delete a;
	return prev;
}

Node* List::NextNode(Node* a)
{
	if (IsEmpty()) return NULL;
	return a->next;
}

Node* List::PrevNode(Node* a)
{
	if (IsEmpty()) return NULL;
	if (a == _head) return NULL;
	Node* p = _head;
	while (p->next != a)
		p = p->next;
	return p;
}

Node* List::GetLastNode()
{
	Node* p = _head;
	while (NextNode(p) != NULL)
		p = NextNode(p);
	return p;
}

void List::DelList()
{
	class Node* p = _head;
	if (p == NULL) return;
	do {
		Node* d = p;
		p = NextNode(p);
		delete d;
	} while (p != NULL);
	_count = 0;
	_head = NULL;
}

void List::Print()
{
	if (IsEmpty()) { cout << "The list is empty" << endl; return; }
	Node* p = _head;
	do {
		cout << GetData(p) << " ";
		p = NextNode(p);
	} while (p != NULL);
	cout << endl;
	cout << endl;
}

void List::Swap(Node* a, Node* b)
{
	if (a == NULL || b == NULL) return;
	if (a == b) return;
	if (b->next == a)
	{
		Node* p = a;
		a = b;
		b = p;
	}
	Node* prev1 = PrevNode(a);
	Node* prev2 = PrevNode(b);
	Node* next1 = NextNode(a);
	Node* next2 = NextNode(b);
	if (next1 == b)
	{
		if (prev1 != NULL)
			prev1->next = b;
		else
			_head = b;
		b->next = a;
		a->next = next2;
		return;
	}
	if (prev1 != NULL)
		prev1->next = b;
	else
		_head = b;
	if (prev2 != NULL)
		prev2->next = a;
	else
		_head = a;
	b->next = next1;
	a->next = next2;
}

void List::ReverseList()
{
	Node* cur = _head;
	Node* first = GetFirstNode();
	Node* last = GetLastNode();
	Node* a = nullptr;
	Node* b = nullptr;
	Node* tmp;
	int counter = 0.5 * _count;
	while (counter)
	{
		Swap(first, last);
		tmp = first;
		first = NextNode(last);
		last = PrevNode(tmp);
		counter--;
	}
}