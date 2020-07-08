#include<iostream>
#include<stdio.h>
#include <iomanip>
using namespace std;

void calc() {
	cout << "Choose operation  : " << endl << "1 - Addition\t\t2 - Subtraction " << endl <<
		"3 - Division\t\t4 - Multiplication" << endl << "5 - Squaring\t\t6 - Square root calc" << endl <<
		"7 - Quadratic equation"<< endl<<"(0 - for Exit) ->:";
}
float firstNumber = 0;
float secondNumber = 0;
float thirdNumber = 0;
float disc = 0;//discriminant (for quadratic equation)

float x1 = 0;
float x2 = 0;
float calc_result = 0;
int choise = 0;
int yes_no = 1;

void calc_nice() {
	char arr[3][16] = {
		{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
		{'#','#','#','C','A','L','C','U','L','A','T','O','R','#','#','#'},
		{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (arr[i][j] == '#') {
				cout << char(219);
			}
			else cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	calc();
	cin >> choise;
	if (choise > 7 || choise < 1) {
		cout << "Chose operation: (1-7) or 0 for Exit" << endl;
		cin >> choise;
		calc();
	}
}

float add(float a, float b) { //addition
	return a + b;
}

float sub(float a, float b) { //subtraction
	return a - b;
}

float div(float a, float b) { //division
	return a / b;
}

float mul(float a, float b) { //multiplication
	return a * b;
}

float square(float a) { //squaring
	return a * a;
}

float square_root(float a) { //square root
	float root_add = 0.00001;
	float sqrt = 0;
	while (sqrt * sqrt < a) {
		sqrt += root_add;
	};
	return sqrt;
}

float discriminant(float a,float b, float c) { //discriminant
	return (b * b) - 4 * a * c;
}

int main() {
	do {
		system("cls");
		calc_nice();

		if (choise == 0) {
			yes_no = 0;
			break;
		};
		cout << "Enter number:   -->  ";
		cin >> firstNumber;
		if (choise < 5) {
			cout << "Enter second number:   -->  ";
			cin >> secondNumber;
			if (choise == 3 && secondNumber == 0) {
				cout << "You cannot divide by ZERO!";
				system("pause");
				continue;
			}
		}
		if (choise == 7) {
			cout << "Enter second number:   -->  ";
			cin >> secondNumber;
			cout << "Enter third number: --> ";
			cin >> thirdNumber;
		}

		switch (choise)
		{
		case 1: {//addition
			calc_result = add(firstNumber, secondNumber);
			cout << firstNumber << " + " << secondNumber << " = " << calc_result << endl;
		}break;

		case 2: {//subtraction
			calc_result = sub(firstNumber, secondNumber);
			cout << firstNumber << " - " << secondNumber << " = " << calc_result << endl;
		}break;

		case 3: {//division
			calc_result = div(firstNumber, secondNumber);
			cout << firstNumber << " / " << secondNumber << " = " << calc_result << endl;
		}break;

		case 4: {//multiplication
			calc_result = mul(firstNumber, secondNumber);
			cout << firstNumber << " * " << secondNumber << " = " << calc_result << endl;
		}break;

		case 5: {//squaring
			calc_result = square(firstNumber);
			cout << firstNumber << " ^2 = " << calc_result << endl;
		}break;
		case 6: {//square root
			calc_result = square_root(firstNumber);
			cout << "Square root of " << firstNumber << " = " << setprecision(5)<< calc_result << endl;
		}break;
		case 7: {//quadratic equation
			calc_result = discriminant(firstNumber, secondNumber, thirdNumber);
			if (calc_result == 0) {
				x1 = ((-1) * (secondNumber)) / 2 * firstNumber;
				cout << "Quadratic equation: " << firstNumber << "*X^2 + (" << secondNumber << ")*x + " << thirdNumber << " = 0" << endl;
				cout << "Solution is: " << endl << "x1 = x2 = " << x1 << endl;
			}
			else if (calc_result > 0) {
				x1 = ((-1) * (secondNumber)+square_root(calc_result)) / (2 * firstNumber);
				x2 = ((-1) * (secondNumber)-square_root(calc_result)) / (2 * firstNumber);
				cout << "Quadratic equation: " << firstNumber << "*X^2 + (" << secondNumber << ")*x + " << thirdNumber << " = 0" << endl;
				cout << "Solution is: " << endl << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
			}
			else {
				cout << "Quadratic equation: " << firstNumber << "*X^2 + (" << secondNumber << ")*x + " << thirdNumber << " = 0" << endl;
				cout << "Have no solution! " << endl << "discriminant is : "<< discriminant<<"- lower than zero! " << endl;
			}
		}break;

		case 0: {//quit from calc
			yes_no = 0;
		}break;
			break;
		}
		system("pause");
	} while (yes_no == 1);
	return 0;
}
