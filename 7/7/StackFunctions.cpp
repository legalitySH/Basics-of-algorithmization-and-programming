#include<iostream>

using namespace std;


class List
{
public:
	List() { begin = end = NULL; }	
	void insert();
	void print();
	void del();
	void add(int);

private:
	struct node {
		int el;
		node* next; 
	};
	node* begin, * end;
	int element;
};

int main() {
	List a;

	a.insert();
	a.print();
	a.del();
	cout << endl << endl;
	a.print();
	cout << endl << endl;
	a.add(5);
	a.print();
	cout << endl << endl;
}

void List::insert() {
	node* q;
	int elem;

	cout << "¬ведите число\n";
	cin >> elem;
	if (elem != 0) {
		q = new node;
		(*q).el = elem;
		(*q).next = NULL;
		begin = end = q;
		cin >> elem;
		while (elem != 0)
		{
			q = new node;
			(*q).el = elem;
			(*q).next = NULL;
			(*end).next = q;
			end = q;
			cin >> elem;
		}

	}
	else {
		q = NULL;
		begin = end = q;
	}
}

void List::print() {
	node* q;
	q = begin;
	while (q!= NULL)
	{
		cout << (*q).el << endl;
		q = (*q).next;
	}
}

void List::del() {
	node* q = begin;
	begin = begin->next;
	delete q;
}

void List::add(int element)
{
	node* q = new node;
	q->el = element;
	q->next = NULL;
	end->next = q;
	end = q;

}

