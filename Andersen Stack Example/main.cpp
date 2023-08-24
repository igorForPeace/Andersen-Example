#include <iostream>
#include "MyStack.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <condition_variable>

std::condition_variable isStackFull;
std::condition_variable isStackEmpty;
std::mutex pushStack;
//std::mutex popStack;

using Ms = std::chrono::milliseconds;

void FillStack(MyStack& s)
{
	std::srand(std::time(0));
	
	std::unique_lock<std::mutex> fill_lk(pushStack);
	isStackEmpty.wait(fill_lk, [&s]() {return s.IsEmpty(); });
	
	std::cout<<"Thread id: " << std::this_thread::get_id() << " do FillStack(): ";
	while (!s.IsFull())
	{
		std::this_thread::sleep_for(Ms(200));
		int temp = rand() % 50 + 1;
		std::cout << "Push(" << temp << "), ";
		s.Push(temp);
	}
	std::cout << std::endl;
	isStackFull.notify_one();
}

void PopStack(MyStack& s)
{
	std::unique_lock<std::mutex> pop_lk(pushStack);
	isStackFull.wait(pop_lk, [&s]() {return s.IsFull(); });
	
	std::cout << "Thread id: " << std::this_thread::get_id() << " do PopStack(): ";
	while (!s.IsEmpty())
	{
		std::this_thread::sleep_for(Ms(200));
		std::cout << "Pop(" << s.Top() << "), ";
		s.Pop();
	}
	std::cout << std::endl;
	isStackEmpty.notify_one();
}

int main()
{
	std::cout << "Main start\n";

	MyStack s(5);

	std::thread t1;
	std::thread t2;
	
	while (true)
	{
		t2 = std::thread(PopStack, std::ref(s));
		t1 = std::thread(FillStack, std::ref(s));
		
		t1.join();
		t2.join();
	}
	
	std::cout << "\nMain end()\n";
	return 0;
}