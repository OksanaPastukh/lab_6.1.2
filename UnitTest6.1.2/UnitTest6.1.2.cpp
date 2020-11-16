#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.1.2/project6.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest612
{
	TEST_CLASS(UnitTest612)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int n = 25;
			int i=0;
			int p[25] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,26 };
			c = Count(p, n, i);
			Assert::AreEqual(c,24);
		}
	};
}
