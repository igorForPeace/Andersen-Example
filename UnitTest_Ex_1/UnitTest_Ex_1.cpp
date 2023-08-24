#include "pch.h"
#include "CppUnitTest.h"
#include "../Andersen Stack Example/MyStack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestEx1
{
	TEST_CLASS(UnitTestEx1)
	{
	public:
		
		TEST_METHOD(Default_ctor_size_0_test)
		{
			MyStack st;

			int defaultSize = 0;
			
			Assert::IsTrue(st.size() == defaultSize);
		}

		TEST_METHOD(Param_ctor_size_0_test)
		{
			int capacity = 10;
			int defaultSize = 0;

			MyStack st{ capacity };

			Assert::IsTrue(st.size() == defaultSize);
		}

		TEST_METHOD(Is_full_method_test)
		{
			int capacity = 5;

			MyStack st{ capacity };
			for (int i = 0; i < capacity; i++)
			{
				st.Push(i + 1);
			}

			Assert::IsTrue(st.IsFull());
		}

		TEST_METHOD(Is_empty_method_test1)
		{
			MyStack st;

			Assert::IsTrue(st.IsEmpty());
		}

		TEST_METHOD(Is_empty_method_test2)
		{
			MyStack st;

			st.Push(10);
			st.Pop();

			Assert::IsTrue(st.IsEmpty());
		}

		TEST_METHOD(Push_method_test)
		{
			MyStack st;
			int finalSize = 1;

			st.Push(10);

			Assert::IsTrue(st.size() == finalSize);
		}

		TEST_METHOD(Top_method_test)
		{
			MyStack st;
			st.Push(10);

			int temp = 10;

			Assert::IsTrue(st.Top() == temp);
		}

		TEST_METHOD(Pop_method_test)
		{
			MyStack st;

			st.Push(10);
			st.Pop();
			int size = 0;

			Assert::IsTrue(st.size() == size);
		}

	};
}
