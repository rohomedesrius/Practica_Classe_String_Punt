#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Classes_Punt2D_String\point2D.h"
#include "..\Classes_Punt2D_String\point2D.cpp"
#include "..\Classes_Punt2D_String\projString.h"
#include "..\Classes_Punt2D_String\projString.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSetZeroIsZero)
		{
			point2D point;

			point.setZero();

			Assert::IsTrue(point.isZero());
		};

		TEST_METHOD(TestNegateVar)
		{
			point2D point_2;

			point_2.x = 2;
			point_2.y = 3;

			point_2.negateVar();

			Assert::IsTrue(point_2.x == -2 && point_2.y == -3);
		}

		TEST_METHOD(TestDistanceTo)
		{
			point2D point_3;
			point2D point_4;

			point_3.x = 3;
			point_3.y = 5;

			point_4.x = 2;
			point_4.y = -1;

			Assert::AreEqual(point_3.distanceTo(point_4), 6.08276f, 0.0001f);
		}

		TEST_METHOD(TestOperatorPlus)
		{
			point2D point_5;
			point2D point_6;
			point2D point_7;

			point_5.x = 5;
			point_5.y = 4;

			point_6.x = 5;
			point_6.y = 4;

			point_7 = point_5 + point_6;

			Assert::IsTrue(point_7.x == 10 && point_7.y == 8);

		}

		TEST_METHOD(TestOperatorMinus)
		{
			point2D point_8;
			point2D point_9;
			point2D point_10;

			point_8.x = 5;
			point_8.y = 4;

			point_9.x = 5;
			point_9.y = 4;

			point_10 = point_8 - point_9;

			Assert::IsTrue(point_10.x == 0 && point_10.y == 0);

		}

		TEST_METHOD(TestOperatorPlusEqual)
		{
			point2D point_11;
			point2D point_12;
			point2D point_13;

			point_11.x = 5;
			point_11.y = 4;

			point_12.x = 5;
			point_12.y = 4;

			point_13 = point_11 += point_12;

			Assert::IsTrue(point_13.x == 10 && point_13.y == 8);

		}

		TEST_METHOD(TestOperatorMinusEqual)
		{
			point2D point_14;
			point2D point_15;
			point2D point_16;

			point_14.x = 5;
			point_14.y = 4;

			point_15.x = 5;
			point_15.y = 4;

			point_16 = point_14 -= point_15;

			Assert::IsTrue(point_16.x == 0 && point_16.y == 0);

		}

		TEST_METHOD(TestOperatorEqualEqual)
		{
			point2D point_17;
			point2D point_18;

			point_17.x = 5;
			point_17.y = 4;

			point_18.x = 5;
			point_18.y = 4;

			Assert::IsTrue(point_17 == point_18);
		}

		TEST_METHOD(TestOperatorDiference)
		{
			point2D point_19;
			point2D point_20;

			point_19.x = 5;
			point_19.y = 4;

			point_20.x = 9;
			point_20.y = 6;

			Assert::IsTrue(point_19 != point_20);
		}
		
		TEST_METHOD(TestStringConstructor)
		{
			projString str_1;

			Assert::AreEqual(str_1.strLen(), 0);
			Assert::AreEqual(str_1.strGetString(), "\0");

		}
		
		TEST_METHOD(TestStringConstructorFormat)
		{
			projString str_2("%s%s%s", "obj1", "obj2", "obj3");

			Assert::AreEqual(str_2.strLen(), 12);
			Assert::AreEqual(str_2.strGetString(), "obj1obj2obj3");

		}
			
		TEST_METHOD(TestStringConstructorObject)
		{
			projString str_3("obj1");
			projString str_4(str_3);

			Assert::IsTrue(str_3.strLen() == str_4.strLen());
			Assert::AreEqual(str_4.strLen(), 4);
			Assert::AreEqual(str_4.strGetString(), "obj1");

		}
	
		TEST_METHOD(TestStringEqualOperator)
		{
			projString str_5("");
			projString str_6("obj1");

			str_5 = str_6.strGetString();

			Assert::AreEqual(str_5.strLen() , str_6.strLen());
			Assert::AreEqual(str_5.strGetString(), str_6.strGetString());

		}
		
		TEST_METHOD(TestStringEqualOperator2)
		{
			projString str_5("");
			projString str_6("obj1");

			str_5 = str_6;

			Assert::AreEqual(str_5.strLen(), str_6.strLen());
			Assert::AreEqual(str_5.strGetString(), str_6.strGetString());


		}
		
		TEST_METHOD(TestStringOperatorEqualEqual)
		{
			projString str_7;

			Assert::IsTrue(str_7 == "");
		}
		
		TEST_METHOD(TestStringOperatorEqualEqual2)
		{
			projString str_8;
			projString str_9;

			Assert::IsTrue(str_8 == str_9);
		}
		
		TEST_METHOD(TestStringOperatorDiference)
		{
			projString str_10("obj1");

			Assert::IsTrue(str_10 != "obj2");
		}
		
		TEST_METHOD(TestStringOperatorDiference2)
		{
			projString str_11("obj1");
			projString str_12;

			Assert::IsTrue(str_11.operator!= (str_12));
		}
		
		TEST_METHOD(TestStringOperatorPlusEqual)
		{
			projString str_13("obj1");

			str_13 += "obj2";

			Assert::IsTrue(str_13 == "obj1obj2");
		}
		
		TEST_METHOD(TestStringOperatorPlusEqual2)
		{
			projString str_14("obj1");
			projString str_15("obj2");

			str_14 += str_15;

			Assert::IsTrue(str_14 == "obj1obj2");
		}

		TEST_METHOD(TestStringToolStrLen)
		{
			projString str_16("obj1");

			Assert::AreEqual(str_16.strLen(), 4);
		}

		TEST_METHOD(TestStringToolCapacity)
		{
			projString str_17("obj1");

			Assert::AreEqual(str_17.strCapacity(), 5);

		}

		TEST_METHOD(TestStringToolClear)
		{
			projString str_18("obj1");

			str_18.strClear();

			Assert::AreEqual(str_18.strLen(), 0);
			Assert::AreEqual(str_18.strGetString(), "\0");

		}

		TEST_METHOD(TestStringToolGetString)
		{
			projString str_19("obj1");

			Assert::AreEqual(str_19.strGetString(), "obj1");

		}
	};

}