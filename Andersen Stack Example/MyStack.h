#pragma once

class MyStack
{
private:
	int top;
	int capacity;
	int* data;

public:
	MyStack(int size);
	MyStack();
	~MyStack();
	bool IsFull();
	bool IsEmpty();
	void Push(int x);
	int Top();
	void Pop();
	int size();
};

