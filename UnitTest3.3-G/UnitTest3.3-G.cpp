#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3-G/Bill.h"
#include "../Lab_3.3-G/Bill.cpp"
#include "../Lab_3.3-G/Time.h"
#include "../Lab_3.3-G/Time.cpp"
#include "../Lab_3.3-G/Object.h"
#include "../Lab_3.3-G/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest33G
{
	TEST_CLASS(UnitTest33G)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bill B1;
			B1.SetSurname("Osadchuk");
			string surname = "Osadchuk";
			Assert::AreEqual(surname, B1.GetSurname());
		}
	};
}
