#include<iostream>
#include<cctype>
#include "STACKPAC.h"
using namespace std;

int main() {

	STACK<int, 8> POST;
	STACK<int, 8> TEMP;
	STACK<int, 8> NUMST;
	int x, y, r;
	char cont;

	do {

		POST.clearStack();
		TEMP.clearStack();
		NUMST.clearStack();
		int num;
		char c;
		char q = '1';
		cout << "Enter a postfix expression that ends with a $: ";
		cin>>c;

		while (c != '$') {
			POST.pushStack(c);
			cin >> c;
		}
		while (!POST.emptyStack()) {
			char t = POST.popStack();
			TEMP.pushStack(t);
		}
		while (!TEMP.emptyStack()) {
			char s = TEMP.popStack();
			if (isalpha(s)) {
				if (s == q)
				{
					NUMST.pushStack(num);
				}
				else{
					cout << "What is the value of " << s << ": ";
					cin >> num;
					NUMST.pushStack(num);
					q = s;
				}
				
			}
			else {
				switch (s) {
				case '*':
					x = NUMST.popStack();
					y = NUMST.popStack();
					r = x * y;
					NUMST.pushStack(r);
					break;
				case'/':
					x = NUMST.popStack();
					y = NUMST.popStack();
					r = x / y;
					NUMST.pushStack(r);
					break;
				case '+':
					x = NUMST.popStack();
					y = NUMST.popStack();
					r = x + y;
					NUMST.pushStack(r);
					break;
				case '-':
					x = NUMST.popStack();
					y = NUMST.popStack();
					r = x - y;
					NUMST.pushStack(r);
					break;
				}
			}
		}
		int result = NUMST.popStack();
		cout << "Final Result: " << result;
		cout << "\nWould you like to continue? Y or N? ";
		cin >> cont;
		cout << endl;

	} while ((cont == 'y') || (cont == 'Y'));
	system("pause");

}
/*

Enter a postfix expression that ends with a $: ab*c+$
What is the value of a: 2
What is the value of b: 3
What is the value of c: 4
Final Result: 10
Would you like to continue? Y or N? Y

Enter a postfix expression that ends with a $: beef*++$
What is the value of b: 2
What is the value of e: 3
What is the value of f: 4
Final Result: 17
Would you like to continue? Y or N? N

Press any key to continue . . .

*/