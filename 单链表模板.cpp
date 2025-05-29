#include <iostream>
#include <stdexcept>
using namespace std;

typedef int ElemType;
struct LinkNode
{
	ElemType data;
	LinkNode* next;

	LinkNode(ElemType x) : data(x), next(nullptr) {}
};

class LinkList
{
public:
	LinkList() : head(nullptr), size(0) {}
	~LinkList();
	void insert(int i, ElemType value);
	void remove(int i);
	LinkNode* find(ElemType value);
	LinkNode* get(int i);
	void update(int i, ElemType value);
	void print();
	ElemType sum();
	void append(ElemType value);
	void ascInsert(ElemType value);
private:
	LinkNode *head;
	int size;
};

LinkList::~LinkList()
{
	LinkNode* curr = head;
	while (curr) {
		LinkNode *tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}

void LinkList::insert(int i, ElemType value)
{
	if (i < 0 || i > size)
		throw std::out_of_range("Invalid position");
	LinkNode* p = new LinkNode(value);
	if (i == 0) {
		p->next = head;
		head = p;
	}
	else {
		LinkNode* curr = head;
		int j = 0;
		while (curr && j < i - 1) {
			curr = curr->next;
			++j;
		}
		p->next = curr->next;
		curr->next = p;
	}
	++size;
}

void LinkList::remove(int i)
{
	if (i < 0 || i > size-1)
		throw std::out_of_range("Invalid position");
	if (i == 0) {
		LinkNode* p = head;
		head = head->next;
		delete p;
	}
	else {
		LinkNode* curr = head;
		int j = 0;
		while (curr->next && j < i - 1) {
			curr = curr->next;
			++j;
		}
		LinkNode* p = curr->next;
		curr->next = curr->next->next;
		delete p;
	}
	--size;
}

LinkNode* LinkList::find(ElemType value)
{
	LinkNode* p = head;
	while (p && p->data != value) {
		p = p->next;
	}
	return p;
}

LinkNode* LinkList::get(int i)
{
	if (i < 0 || i > size - 1)
		throw std::out_of_range("Invalid position");
	LinkNode* p = head;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	return p;
}

void LinkList::update(int i, ElemType value)
{
	get(i)->data = value;
}

void LinkList::print()
{
	LinkNode* p = head;
	while (p) {
		cout << p->data;
		p = p->next;
		if (p)
			cout << " ";
		else
			cout << endl;
	}
}

ElemType LinkList::sum()
{
	ElemType ret = 0;
	LinkNode* p = head;
	while (p) {
		ret += p->data;
		p = p->next;
	}
	return ret;
}

void LinkList::append(ElemType value)
{
	insert(size, value);
}

void LinkList::ascInsert(ElemType value)
{
	if (size == 0) {
		insert(0, value);
		return;
	}
	LinkNode* p = head;
	for (int i = 0; i < size; ++i) {
		if (value <= p->data) {
			insert(i, value);
			return;
		}
		p = p->next;
	}
	insert(size, value);
}

int main()
{
	//斐波那契数列
	LinkList la;
	la.insert(0, 1);
	la.insert(1, 1);
	la.insert(2, 1);
	for (int i = 3; i <= 40; ++i)
		la.insert(i, la.get(i - 1)->data + la.get(i - 2)->data);
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		cout << la.get(m)->data << endl;
	}
	return 0;
}
