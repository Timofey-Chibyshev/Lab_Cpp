#pragma 

#include <iostream>
using namespace std;

class Node
{
	int _data;
	class Node* next;
	friend class List;
};

class List
{
	Node* _head;
	int _count = 0;
	Node* PrevNode(Node*);

public:
	List() { _head = nullptr; }
	int GetData(Node* a) { return a->_data; }
	int GetCount() { return _count; }
	void SetData(Node* a, int data) { a->_data = data; }
	bool IsEmpty() { return _head == nullptr; }
	Node* GetFirstNode() { return _head; }
	Node* GetLastNode();
	Node* NextNode(Node*);
	Node* AddNode(int, Node*);
	Node* AddNode(int);
	Node* DelNode(Node*);
	void DelList();
	void ReverseList();
	void Print();
	void Swap(Node*, Node*);
};
