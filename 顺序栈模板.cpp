#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	T* data;
	int size;
	int capacity;
	void resize();
public:
	Stack() : size(0), capacity(10)
	{
		data = new T[capacity];
	}
	~Stack()
	{
		delete[] data;
	}
	void push(T val);
	T pop();
	T top() const;
	int GetSize() const;
};

template<typename T>
void Stack<T>::resize()
{
	int newCapacity = 2 * capacity;
	T* newData = new T[newCapacity];
	for (int i = 0; i < size; ++i)
		newData[i] = data[i];
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

template<typename T>
void Stack<T>::push(T val)
{
	if (size == capacity)
		resize();
	data[size++] = val;
}

template<typename T>
T Stack<T>::pop()
{
	if (size == 0)
		throw std::underflow_error("stack is empty");
	return data[--size];
}

template<typename T>
T Stack<T>::top() const
{
	if (size == 0)
		throw std::underflow_error("stack is empty");
	return data[size-1];
}

template<typename T>
int Stack<T>::GetSize() const
{
	return size;
}

int main()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.top() << endl;
	st.pop();
	st.pop();
	cout << st.top() << endl;
	cout << st.GetSize() << endl;
	return 0;
}
