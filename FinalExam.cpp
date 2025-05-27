/**
 * \file FinalExam.cpp
 * \brief Matrix Manipulation
 * \details This program is designed to prompt a menu to the user in order to manipulate a matrix (given by the user). We prompt a menu in order to select which operation they want to perfom (enter data, sum data, exit program) and then we perfom the operation.
 * \author Marios Kyriacou (U244N0037)
 * \version 0.1
 * \date 2025
 * \copyright GNU Public License
*/

#include <iostream>

using namespace std;

// Function Prototypes
void DisplayMenu();
void GetData(double[], const int, const int);
double SumNegativeData(const double[], const int);

/**
 * Main function: It is the main function in order to prompt the menu to the user and perform the operations selected by the user
 * until they select to exit the program. We prompt the menu, we do the appropriate validation checks and then we perfom the correct operation
 * using a switch statement
 * @return Returns 0 to indicate successful execution
 */
int main() {
	// Variables
	const int ROW = 3, COL = 5;
	int option = 0;
	double matrix[ROW][COL], tempTotal = 0;

	do {
		DisplayMenu();
		cin >> option;

		// Data validation in order to ensure that the user enters a valid option
		while (option < 0 || option > 2) {
			cout << "Incorrect option. Please try again: ";
			cin >> option;
		}

		switch (option) {
			case 1:
				for (int i = 0; i < ROW; i++) {
					GetData(matrix[i], COL, i);
				}

				break;
			case 2:
				tempTotal = 0;

				for (int i = 0; i < ROW; i++) {
					tempTotal += SumNegativeData(matrix[i], COL);
				}

				cout << "The sum of all negative numbers is: " << tempTotal << endl;

				break;
			case 0:
			default:
				break;
		}
	} while (option != 0);

	return 0;
}

/**
 * This function displays the appropriate menu options to the user
*/
void DisplayMenu() {
	cout << endl;

	cout << "1) Enter data in matrix (Range -1.5 to 0.5)" << endl;
	cout << "2) Sum of all negative numbers" << endl;
	cout << "0) Exit" << endl << endl;

	cout << "Please enter choice: ";
}

/**
 * This function gets the data from the user and stores it in the matrix. It prompts the user to enter a number and also gives them for which row and column they are entering the number for.
 * (It gives it with the number starting from 1 in order to ensure that the user doesn't get confused)
 * @param matrix The matrix where the data will be stored
 * @param COLUMNS The number of columns that is in the matrix
 * @param SELECTED_ROW The current row that we are on
*/
void GetData(double matrix[], const int COLUMNS, const int SELECTED_ROW) {
	for (int j = 0; j < COLUMNS; j++) {
		cout << "Enter a number for row " << SELECTED_ROW + 1 << " and column " << j + 1 << ": ";
		cin >> matrix[j];

		while (matrix[j] < -1.5 || matrix[j] > 0.5) {
			cout << "Invalid number. Please provide a number between -1.5 and 0.5: ";
			cin >> matrix[j];
		}

		cout << endl;
	}
}

/**
 * This function gets the matrix from the main function, sums all the negative numbers and returns it so it can be added up
 * @param matrix The matrix with all of the data
 * @param COLUMN The number of columns in the matrix
 * @return Returns 0 if no negative numbers are found and the sum of all negative numbers in the specific row of the matrix if negative number(s) are found
*/
double SumNegativeData(const double matrix[], const int COLUMN) {
	double sum = 0;

	for (int j = 0; j < COLUMN; j++) {
		if (matrix[j] < 0) {
			sum += matrix[j];
		}
	}

	return sum;
}
