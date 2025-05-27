#include "pch.h"
#include "CppUnitTest.h"
#include "../FinalExam.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FinalExamUnitTest {
	TEST_CLASS(FinalExamUnitTest) {
		public:
			TEST_METHOD(CountValueUnitTest) {
				// Arrange
				const double matrix[3][5] = {
					{-1.5, 0.5, 0.0, -1.5, -0.5},
					{-1.2, 0.2, 0.5, -0.5, 0.0},
					{0.0, -1.5, -1.5, 0.5, -0.5}
				};
				int output = 0;

				// Act
				for (int i = 0; i < 3; i++) {
					output += CountValue(matrix[i], 5, 1.5);
				}

				// Assert
				Assert::AreEqual(0, output, L"CountValue should return 0 for no occurrences of 1.5");
			}
	};
}
