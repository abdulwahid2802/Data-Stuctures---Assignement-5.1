#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

template<class T>
class Stack
{
	typedef struct Node
	{
		T data;
		Node *next;
	}*Nptr;

	Nptr head;

	void _makeNode(T);
	void _push(Nptr &, Nptr);
	T _top();
	void _display()const;
	T _pop();


public:
	Stack() : head(NULL){}
	Stack(Stack<T> &src);
	void push(T);
	T pop();
	T top();
	void printAll()const;
	bool isEmpty()const;
};

template<class T>
Stack<T>::Stack(Stack<T> &src)
{
	Stack<T> temp;

	while (!src.isEmpty())
	{
		temp.push(src.pop());
	}

	while (!temp.isEmpty())
	{
		src.push(temp.top());
		push(temp.pop());
	}

}

template<class T>
bool Stack<T>::isEmpty()const
{
	return head == NULL;
}

template<class T>
void Stack<T>::push(T data)
{
	_makeNode(data);
}

template<class T>
void Stack<T>::_makeNode(T data)
{
	Nptr n = new Node();
	n->next = NULL;
	n->data = data;

	_push(head, n);
}

template<class T>
void Stack<T>::_push(Nptr &Ptr, Nptr n)
{
	if (isEmpty() || head == NULL)
	{
		head = n;
	}
	else
	{
		n->next = head;
		head = n;
	}
}

template<class T>
T Stack<T>::top()
{
	return _top();
}

template<class T>
T Stack<T>::_top()
{
	if(!isEmpty())
		return head->data;
}

template<class T>
void Stack<T>::printAll()const
{
	_display();
	cout << endl;
}

template<class T>
void Stack<T>::_display()const
{
	if (!isEmpty())
	{
		Nptr curr = head;
		while (curr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
}

template<class T>
T Stack<T>::pop()
{
	if(!isEmpty())
		return _pop();
}

template<class T>
T Stack<T>::_pop()
{
	if (!isEmpty())
	{

		Nptr temp = head;
		T data = temp->data;

		head = head->next;
		delete temp;

		return data;
	}
}

template<class T>
void transToQueue(Stack<T> *s1, Stack<T> &s2)
{
	while(!s2.isEmpty())
		s2.pop();

	while (!s1->isEmpty())
	{
		s2.push(s1->pop());
	}
}

template<class T>
void printAll(Stack<T> &target)
{
  	while (!target.isEmpty())
	{
		cout << target.pop() << " ";
	}
	cout << endl;
}


int main()
{
	Stack<int> stack;
	Stack<int> target;

	srand(time(0));
	while (1)
	{
		char c;
		cin >> c;

		switch (c)
		{
			case 'i':
				int n;
				cin >> n;
				stack.push(n);
				break;
			case 't':
			{
				Stack<int> *temp = new Stack<int>(stack);
				transToQueue(temp, target);
				break;
			}
			case 'p':
				printAll(target);
				break;
			case 'e':
				exit(1);
			default:
				break;
		}
	}

	cin.get();
	return 0;
}