//this program helps us to calculate some common serieses
#include <iostream>

using namespace std;

// function prototype
int factorial(int);
double power(double, int);
double ePowerx(double);
double sigmaXPowern(double);
double arcTan(double);

int main(){//main function in c++

  int userChoice,x;

  cout << "1. e^x = 1 + x + (x^2)/2! + ..." << endl;
  cout << "2. 1 + x + x^2 + x^3 + ..." << endl;
  cout << "3. arctan(x) = x - (x^3)/3 + (x^5)/5 - (x^7)/7 + ..." << endl;
  cout << "\nPlease choose one of these to let me calculate it: " << endl;

  cin >> userChoice;

  cout << "\nthen you should enter the x: " << endl;

  cin >> x;

  switch (userChoice) {
    case 1:

      cout << ePowerx(x);
      break;

    case 2:
      cout << sigmaXPowern(x);
      break;

    case 3:
      cout << arcTan(x);
      break;

    default:
      cout << "Invalid input!";
  }

  return 0;
}//end of main function

// function definition
int factorial(int x)
{//this function calculate the factorial of x
  int result = 1;

  for (int i = 2; i <= x; i++){
    result *= i;
  }

  return result;
}//end of factorial function

double power(double x, int tavan)
{//this function calculate the power n of x
  double result = x;

  for (int i = 1; i < tavan; i++){
    result *= x;
  }

  return result;
}//end of power function

double arcTan(double x)
{//this function is used for calculating arctan(x)
    double result = 0;

    for (int i = 1, j = 2; i < 1200 ; i+=2, j++)
    {
        result += ((power(x,i) / i)*(power(-1,j)));
    }

    return result;
}//end of arctan function
