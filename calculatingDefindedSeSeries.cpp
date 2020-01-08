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
	//this struct is not completed
} series;

int main(){//main function in c++
	
	while (1){
		int userChoice, x;

		

		cout << "\a\n\n1. e^x = 1 + x + (x^2)/2! + ..." << endl;
		cout << "2. 1 + x + x^2 + x^3 + ..." << endl;
		cout << "3. arctan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + ..." << endl;
		cout << "\nPlease choose one of these to calculate it, " << endl;
		cout << "or you can type -1 to exit the program:" << endl;

		cin >> userChoice;
		
		if (userChoice == -1)
			break;

		cout << "\nthen you should enter the x: " << endl;

		cin >> x;

		switch (userChoice) {
			
		case 1:
		  cout << exp(x);
		  break;

		case 2:
		  cout << sigmaPowX(x);
		  break;

		case 3:
		  cout << arcTan(x);
		  break;

		default:
		  cout << "Invalid input!\nGive me a valid choice.";

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

	for (int i = 0;i < 20; i++){
		result += power(x,i) / factorial(i);
	}
	
	return result;
}//end of exp function

double sigmaPowX(double x)
{//calculates sum of power x
	double result = 0;
	
	for (int i = 0; i < 20; i++){
		result += power(x,i);
	}
	
	return result;
}//end of sigmaPowX

double arcTan(double x)
//this function has some problems
{//this function is used for calculating arctan(x)
    double result = 0;

    for (int i = 3, j = 1; i < 42 ; i+=2, j++){
        result += ((power(x,i) / i)*(power(-1,j)));
        cout << result << endl;
    }

    return result;
}//end of arctan function
