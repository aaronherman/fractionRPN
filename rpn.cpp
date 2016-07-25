#include <sstream>
#include <iostream>
#include "stack.h"
#include "fraction.h"
#include <cmath>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Enter an expression: ";
	string str;
	getline(cin, str);


  Fraction x,y,t,value;
  string l;
  //int k;
  double s, real;


  int num, den;
  char delim;

  Stack<Fraction>* stackptr = new Stack<Fraction>();
  unordered_map<string, Fraction> memory;

	while (str!="") {
		istringstream sin(str +" ");
    int denominator = 0;
		//read one character of input
		char token;
		sin >> token;

    try {
  		while (!sin.eof()) {

  			//process the character
  			switch (token) {
               case '+':
                  x = stackptr->pop();
                  y = stackptr->pop();
                  x = x+y;
                  stackptr->push(x);
               break;

               case '-':
                  x = stackptr->pop();
                  y = stackptr->pop();
                  x = x-y;
                  stackptr->push(x);
               break;

               case '*':
                  x = stackptr->pop();
                  y = stackptr->pop();
                  x = x * y;
                  stackptr->push(x);
               break;

               case '/':
                  x = stackptr->pop();
                  y = stackptr->pop();
                  if (x.numerator() == 0)
                    throw new DivideByZero("Can't divide by zero");
                  x = y / x;
                  stackptr->push(x);
               break;

               case 'S':
                sin >> l; //key
                value = stackptr->pop();
                stackptr->push(value);
                memory[l] = value;
                //cout << memory[l];
               break;

               case 'R':
                 sin >> l;
                 value = memory[l];
                 stackptr->push(value);
               break;

               case '(':
                  sin >> num;
                  sin >> delim;
                  sin >> den;
                  if (den == 0)
                    throw new DivideByZero("You can't have zero as a denominator");
                  sin >> delim;
                  stackptr->push(Fraction(num,den));
               break;

               default:
                 sin.putback(token);
                 sin >> real;

                 if (sin.fail()) {
                    cout << "Not a Number" << endl;
                    throw "Malformed Number";
                 }

                 denominator = 1;
                 while (abs((int)real - real) > 0.000000000000001) {     //if the number is 6.95, it will push 695/100 so it's a fraction
                    real = real * 10;
                    denominator = denominator * 10;
                 }
                 //stackptr->push(real);
                 stackptr->push(Fraction((int) real, denominator));
               break;
             }
             //read the next c
             sin >> token;
  		}
      t = stackptr->pop();

      if (!stackptr->isEmpty()) {
        cout << "RPN Expression is invalid." << endl;
        while (!stackptr->isEmpty()) {
          stackptr->pop();
        }
      } else {
        memory["it"] = t;
        if (denominator == 0)
          cout << "it is: " << t << endl;
        else {
          cout << "it is: " << t.asDouble() << endl;
        }
      }

    } catch (DivideByZero* ex) {
      cerr << ex->getMessage() << endl;
      delete stackptr;
      stackptr = new Stack<Fraction>();
    } catch (...) {
      cerr << "This doesn't work" << endl;
      delete stackptr;
      stackptr = new Stack<Fraction>();
    }
    cout << "Enter an expression: ";
		getline(cin, str);
	}
}