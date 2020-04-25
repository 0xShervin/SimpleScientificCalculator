//this program helps us to calculate some common serieses

#include <iostream>
#include <stdio.h>

using namespace std;

//function prototype
double factorial(double);
double power(double, double);
double exp(double);
double sigmaPowX(double);
double arcTan(double);
double calculate_answer(int, double);
void read_file(int &, double &);
void write_file(int , double);

// struct of sersiese
typedef struct 
{//this structure is used to create three data types for serieses
	double exp;
	double sgPowx;
	double iTan;
	
} series;

int main(){//main function in c++
	
	while (1){

		int userChoice;
		double x, *ptrx = &x;
		char fileAvailability;
		
		cout << "\n-------------------------------------" << endl;
		cout << "\n0. (for exiting the program)" << endl;
		cout << "1. e^x" << endl;
		cout << "2. 1 + x + x^2 + x^3 + ..." << endl;
		cout << "3. arctan(x)" << endl;
		cout << "\nIs there any file?(y|n) ";
		cin >> fileAvailability;

		if (fileAvailability == 'y')
			read_file(userChoice, x);

		else{
			cout << "\nThen you should choose one of the above things: ";
			cin >> userChoice;
		}
		
		if (userChoice == 0)
			break;
		
		else if ( userChoice < 1 || userChoice > 3){
			cout << "\ninvalid choice! Try again.";
			continue;
		}
		
		if (fileAvailability == 'n'){
			cout << "\nThen you should enter the x: ";
			cin >> x;
			cout << "\nYour answer is : ";
			cout << calculate_answer(userChoice, *ptrx);
		}

		else {
			write_file(userChoice, *ptrx);
			cout << "Your answer was writen in a file which is named \"output.txt\".";
		}
	}
  return 0;
}

// function definition
double factorial(double x)
{//this function calculate the factorial of x
	double result = 1;

	for (int i = 2; i <= x; i++){
		result *= i;
	}

	return result;
}

double power(double x, double tavan)
{//this function calculates the power n of x
	double result = 1;

	for (int i = 0; i < tavan; i++){
		result *= x;
	}

	return result;
}

double exp(double x)
{//this function calculates the exponentiation
	double result = 0;

	for (int i = 0;i < 100; i++){
		result += power(x,i) / factorial(i);
	}
	
	return result;
}

double sigmaPowX(double x)
{//calculates sum of power x
	double result = 0;
	
	for (int i = 0; i < 100; i++){
		result += power(x,i);
	}
	
	return result;
}

double arcTan(double x)
{//this function is used for calculating arctan(x)
	const double rtd = 180.000 / 3.1415926536;//this constant variable is used to change radiant to degree
	double result = 0;
	
	if (x <= 1 && x >= -1){
	
		for (int i = 1, j = 2; i < 600; i+=2 , j++)
			result += ((power(x,i) / i) * (power(-1,j)));
	
		result *= rtd;
	}
	
	else if (x > 1){
		x = 1 / x;
		
		for (int i = 1, j = 2; i < 600; i+=2 , j++)
			result += ((power(x,i) / i) * (power(-1,j)));

		result = 90 - result * rtd;
	}

	else if (x < -1){
		x = 1 / x;

		for (int i = 1, j = 2; i < 600; i+=2 , j++)
			result += ((power(x,i) / i) * (power(-1,j)));
		
		result = -90 - result * rtd;
	}
	
	return result;

}

double calculate_answer(int userChoice, double x)
{//this function is used to calculate the answer of user's choice
	series s;

	switch (userChoice) {
	case 1:
		s.exp = exp(x);
		return s.exp;
		break;

	case 2:
		s.sgPowx = sigmaPowX(x);
		return s.sgPowx;
		break;

	case 3:
		s.iTan = arcTan(x);
		return s.iTan;
		break;

	}
	return 0;
}

void read_file(int &UC, double &x)
{//this function is used to read a file 
	FILE * fptr;

	fptr = fopen("input.txt", "r");

	fscanf(fptr, "%d %lf", &UC, &x);

	fclose(fptr);
}

void write_file(int UC, double x)
{//this function is used to write the answer into a file
	FILE * fptr;
	double answer = calculate_answer(UC, x);

	fptr = fopen("output.txt", "w");

	fprintf(fptr, "Your answer is : %lf", answer);

	fclose(fptr);

}
