#include "ReverseList.h"

int main(void)
{
	List list;
	list.Print();
	for (int i = 0; i < 10; i++)
	{
		int z;
		cout << ">> ";
		cin >> z;
		list.AddNode(z);
	}
	cout << "List: " << endl;
	list.Print();
	cout << "Last elem: " << list.GetData(list.GetLastNode()) << endl;
	cout << endl;
	Node* head = list.GetFirstNode();
	list.ReverseList();
	cout << "Reversed list: " << endl;
	list.Print();
	Node* p = list.GetFirstNode();
	do {
		if (list.GetData(p) == 0)
			p = list.DelNode(p);
		else
			p = list.NextNode(p);
	} while (p != NULL);
	cout << "List without zero: " << endl;
	list.Print();
	cout << "There are " << list.GetCount() << " elements in the list(the first and last are swapped):" << endl;
	list.Swap(list.GetFirstNode(), list.GetLastNode());
	list.Print();
	list.DelList();
	list.Print();
	cout << endl;
	cout << "There are " << list.GetCount() << " elements in the list" << endl;
	return 0;
}