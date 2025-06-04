#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	struct ListNode
	{
		T data;
		ListNode* next;
		ListNode(T d) : data(d), next(nullptr) {}
	};
	ListNode* head;
	int size;
public:
	Stack() : head(nullptr), size(0) {};
	~Stack();
	void push(T val);
	T pop();
	T top() const;
	int getsize() const;
};

template<typename T>
Stack<T>::~Stack()
{
	while (head) {
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<typename T>
void Stack<T>::push(T val)
{
	ListNode* p = new ListNode(val);
	p->next = head;
	head = p;
	++size;
}

template<typename T>
T Stack<T>::pop()
{
	if (size == 0)
		throw std::underflow_error("stack is empty");
	ListNode* tmp = head;
	T ret = head->data;
	head = head->next;
	delete tmp;
	--size;
	return ret;
}

template<typename T>
T Stack<T>::top() const
{
	if (size == 0)
		throw std::underflow_error("stack is empty");
	return head->data;
}

template<typename T>
int Stack<T>::getsize() const
{
	return size;
}

int main()
{
	Stack<int> st;
	st.push(4);
	st.push(7);
	st.push(13);
	cout << st.top() << endl;
	st.push(17);
	cout << st.top() << endl;
	st.pop();
	st.pop();
	cout << st.top() << endl;
	cout << st.getsize() << endl;
	return 0;
}
