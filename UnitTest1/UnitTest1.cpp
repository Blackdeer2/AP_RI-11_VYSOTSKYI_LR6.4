#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.4/PR6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double* arr;
			arr = new double[5];
			arr[0] = 8.9;
			arr[1] = -12.3;
			arr[2] = 78.45;
			arr[3] = -6.7;
			arr[4] = -0.56;
			double t = Suma(arr, 5, 0, 0);
			Assert::AreEqual(t, -19.56);
		}
	};
}
