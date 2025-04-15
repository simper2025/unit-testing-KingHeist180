#include "pch.h"
#include "CppUnitTest.h"
#include "../TicTacToe.Logic/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeTest)
	{
	public:

		TEST_METHOD(TestTrue)
		{
			Assert::AreEqual(true, true);
		}

		TEST_METHOD(TestSetSquare)
		{
			//Arrange
			Board b;
			
			//Act
			b.SetSquare(0, 0, 'X');

			//Assert
			Assert::AreEqual('X', b.GetSquare(0,0));
		}

		TEST_METHOD(TestSetSquare_False)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');

			//Assert
			Assert::AreEqual('O', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestSetTwoSquares)
		{
			//Arrange
			Board b;

			//Act
			b.SetSquare(0, 0, 'X');
			b.SetSquare(1, 1, 'O');

			//Assert
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestBoard2Create)
		{
			Board b;
			char setup[3][3] = { {'X',' ','O'}, {'X', 'O', ' '}, {' ', ' ', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestBoard3Create)
		{
			Board b;
			char setup[3][3] = { {'X',' ',' '}, {' ', 'O', ' '}, {' ', ' ', 'X'} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}

		TEST_METHOD(TestBoard4Create)
		{
			Board b;
			char setup[3][3] = { {'X','O',' '}, {' ', 'O', ' '}, {' ', 'O', ' '} };
			b.SetBoard(setup);
			Assert::AreEqual('X', b.GetSquare(0, 0));
		}
	};
}
