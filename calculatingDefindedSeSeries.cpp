//this program helps us to calculate some common serieses

#include <iostream>

using namespace std;

//function prototype
double factorial(double);
double power(double, double);
double exp(double);
double sigmaPowX(double);
double arcTan(double);

// struct of sersiese
typedef struct 
{
	double exp;
	double sgPowx;
	double iTan;
	
} series;

const double rtd = 180.000 / 3.1415926536;//this constant variable is used to change radiant to degree

int main(){//main function in c++
	
	while (1){

		int userChoice;
		double x, * ptrx = &x;
		series s;
		
		cout << "\n-------------------------------------" << endl;
		cout << "\n1. e^x = 1 + x + (x^2)/2! + ..." << endl;
		cout << "2. 1 + x + x^2 + x^3 + ..." << endl;
		cout << "3. arctan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + ..." << endl;
		cout << "\nPlease choose one of these to calculate it, " << endl;
		cout << "or you can type 0 to exit the program: ";

		cin >> userChoice;
		
		if (userChoice == 0)
			break;
		else if ( userChoice < 1 || userChoice > 3){
			cout << "\ninvalid choice! Try again.";
			continue;
		}

		cout << "\nthen you should enter the x: ";

		cin >> x;
		
		cout << "\nYour answer is : ";
		switch (userChoice) {
			
		case 1:
		  s.exp = exp(*ptrx);
		  cout << s.exp;
		  break;

		case 2:
		  s.sgPowx = sigmaPowX(*ptrx);
		  cout << s.sgPowx;
		  break;

		case 3:
		  if (*ptrx <= 1 && *ptrx >= -1)
			s.iTan = arcTan(*ptrx);
		  else if (*ptrx > 1)
		    s.iTan = 90 - arcTan(1 / *ptrx);
		  else if (*ptrx < -1)
		    s.iTan = -90 - arcTan(1 / *ptrx);
		  cout << s.iTan;
		  break;

		default:
		  cout << "Invalid input!\n Please try again.";

		}
	}

  return 0;
}//end of main function

// function definition
double factorial(double x)
{//this function calculate the factorial of x
  double result = 1;

  for (int i = 2; i <= x; i++){
    result *= i;
  }

  return result;
}//end of factorial function

double power(double x, double tavan)
{//this function calculates the power n of x
  double result = 1;

  for (int i = 0; i < tavan; i++){
    result *= x;
  }

  return result;
}//end of power function

double exp(double x)
{//this function calculates the exponentiation
	double result = 0;

	for (int i = 0;i < 100; i++){
		result += power(x,i) / factorial(i);
	}
	
	return result;
}//end of exp function

double sigmaPowX(double x)
{//calculates sum of power x
	double result = 0;
	
	for (int i = 0; i < 100; i++){
		result += power(x,i);
	}
	
	return result;
}//end of sigmaPowX

double arcTan(double x)
{//this function is used for calculating arctan(x)
	double result = 0;
		
	for (int i = 1, j = 2; i < 600; i+=2 , j++)
		result += ((power(x,i) / i) * (power(-1,j)));
	
	return result * rtd;
}//end of arctan function
