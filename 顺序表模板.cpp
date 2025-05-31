#include <iostream>
using namespace std;

typedef int ElemType;
#define NUM 5

class SeqList
{
	friend ostream& operator<<(ostream& os, const SeqList& l);
	friend void MergeList(SeqList& lc, const SeqList& la, const SeqList& lb);
		
public:
	SeqList() : size(0), capacity(NUM)
	{
		elem = new ElemType[NUM];
	}
	~SeqList()
	{
		delete[] elem;
		elem = nullptr;
	}
	void ClearList()
	{
		size = 0;
	}
	bool ListEmpty() const
	{
		return size == 0;
	}
	int ListLength() const
	{
		return size;
	}
	ElemType& GetElem(int index) const
	{
		return elem[index - 1];
	}
	int LocateElem(ElemType e)
	{
		for (int i = 0; i < size; ++i)
		{
			if (elem[i] == e)
				return i + 1;
		}
		return 0;
	}
	bool ListInsert(int index, ElemType e)
	{
		if (index < 1 || index > size + 1)
			return false;
		if (size >= capacity)
		{
			ElemType* newelem = new ElemType[2 * capacity];
			for (int i = 0; i < size; ++i)
				newelem[i] = elem[i];
			delete[] elem;
			elem = newelem;
			capacity *= 2;
		}
		for (int i = size - 1; i >= index - 1; --i)
			elem[i + 1] = elem[i];
		elem[index - 1] = e;
		++size;
		return true;
	}
	bool ListDelete(int index)
	{
		if (index < 1 || index > size)
			return false;
		for (int i = index; i <= size-1; ++i)
			elem[i - 1] = elem[i];
		--size;
		return true;
	}

private:
	ElemType* elem;
	int size;
	int capacity;
};

ostream& operator<<(ostream& os, const SeqList& l)
{
	if (l.size == 0)
		os << "顺序表为空" << endl;
	for (int i = 0; i < l.size; ++i)
	{
		if (i)
			cout << " ";
		cout << l.elem[i];
	}
	cout << endl;
	return os;
}

void test1()
{
	SeqList la;
	cout << la.ListEmpty() << endl;
	cout << la << endl;
	for (int i = 1; i <= 10; ++i)
		la.ListInsert(i, i * 10);
	cout << la << endl;
	la.ListDelete(1);
	cout << la << endl;
}

void unionList(SeqList& la, const SeqList& lb)
{
	int len_a = la.ListLength();
	int len_b = lb.ListLength();
	for (int i = 0; i < len_b; ++i)
	{
		if (!(la.LocateElem(lb.GetElem(i + 1))))
			la.ListInsert(++len_a, lb.GetElem(i + 1));
	}
}

void MergeList(SeqList& lc, const SeqList& la, const SeqList& lb)
{
	int len_a = la.ListLength();
	int len_b = lb.ListLength();
	lc.size = len_a + len_b;
	lc.elem = new ElemType[len_a + len_b];
	int i = 0, j = 0, k = 0;
	while (i < len_a && j < len_b)
	{
		if (la.elem[i] <= lb.elem[j])
			lc.elem[k++] = la.elem[i++];
		else
			lc.elem[k++] = lb.elem[j++];
	}
	while (i < len_a)
		lc.elem[k++] = la.elem[i++];
	while (j < len_b)
		lc.elem[k++] = lb.elem[j++];
}

void test2()
{
	SeqList la;
	la.ListInsert(1, 3);
	la.ListInsert(2, 5);
	la.ListInsert(3, 8);
	la.ListInsert(4, 11);

	SeqList lb;
	lb.ListInsert(1, 2);
	lb.ListInsert(2, 6);
	lb.ListInsert(3, 8);
	lb.ListInsert(4, 9);
	lb.ListInsert(5, 11);
	lb.ListInsert(6, 15);
	lb.ListInsert(7, 20);
	unionList(la, lb);
	cout << la << endl;
}

void test3()
{
	SeqList la;
	la.ListInsert(1, 3);
	la.ListInsert(2, 5);
	la.ListInsert(3, 8);
	la.ListInsert(4, 11);

	SeqList lb;
	lb.ListInsert(1, 2);
	lb.ListInsert(2, 6);
	lb.ListInsert(3, 8);
	lb.ListInsert(4, 9);
	lb.ListInsert(5, 11);
	lb.ListInsert(6, 15);
	lb.ListInsert(7, 20);
	SeqList lc;
	MergeList(lc, la, lb);
	cout << lc << endl;
}


int main()
{
	test3();
	return 0;
}
