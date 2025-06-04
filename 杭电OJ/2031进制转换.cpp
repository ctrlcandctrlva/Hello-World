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
	int n;
	int r;
	while (cin >> n >> r) {
		Stack<int> st;
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}
		if (n < 0) {
			cout << '-';
			n = -n;
		}
		while (n) {
			st.push(n % r);
			n /= r;
		}
		while (st.getsize()) {
			int x = st.pop();
			if (x >= 10)
				cout << char('A' + x - 10);
			else
				cout << x;
		}
		cout << endl;
	}
	return 0;
}
