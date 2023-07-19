#include "MyStack.h"
#include <iostream>

MyStack::MyStack(int size) : top(-1), capacity(size)
{
	this->data = new int[capacity];
}

MyStack::MyStack() : MyStack(10)
{

}

MyStack::~MyStack()
{
	if (data != nullptr)
	{
		delete[] data;
	}
}

bool MyStack::IsFull()
{
	return top == capacity - 1;
}

bool MyStack::IsEmpty()
{
	return top == -1;
}

void MyStack::Push(int x)
{
	if (!IsFull())
	{
		data[++top] = x;
		return;
	}
	std::cout << "Stack is full\n";
}

int MyStack::Top()
{
	if (!this->IsEmpty())
	{
		return data[top];
	}
	std::cout << "stack is empty\n";
}

void MyStack::Pop()
{
	if (IsEmpty())
	{
		std::cout << "The stack is empty\n";
		return;
	}
	top--;
}

int MyStack::size()
{
	return top+1;
}


