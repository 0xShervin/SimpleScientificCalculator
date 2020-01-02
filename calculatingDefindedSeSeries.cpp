//this program helps us to calculate some common serieses
#include <iostream>

using namespace std;

// function prototype
int factorial(int);
int power(int, int);
float ePowerx(int);
int sigmaXPowern(int);
float arctanx(int);

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
      cout << arctanx(x);
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

int power(int x, int n)
{//this function calculate the power n of x
  int result = x;

  for (int i = 1; i < n; i++){
    result *= x;
  }

  return result;
}//end of power function
