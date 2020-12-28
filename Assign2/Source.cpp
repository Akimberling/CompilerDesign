#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include"STACKPAC.h"
using namespace std;

int main() {

	STACK<int, 8> POST;
	int x, y, r, s, d;
	char cont;

	do {

		POST.clearStack();
		string token;
		cout << "Enter a postfix expression that ends with a $: ";
		getline(cin, token, '$');
		while (token != "$") {
			if (isalpha(token[0]))
			{
				cout << "Enter the value for" << token << ":" ;
				cin >> s;
				POST.pushStack(s);
			}
			else if(isdigit(token[0])){
				d = stoi(token);
				POST.pushStack(d);
			}
			else if(token == "*"){
				x = POST.popStack();
				y = POST.popStack();
				r = x * y;
				POST.pushStack(r);
			}
			else if (token == "/") {
				x = POST.popStack();
				y = POST.popStack();
				r = x / y;
				POST.pushStack(r);
			}
			else if (token == "+") {
				x = POST.popStack();
				y = POST.popStack();
				r = x + y;
				POST.pushStack(r);
			}
			else if (token == "-") {
				x = POST.popStack();
				y = POST.popStack();
				r = x - y;
				POST.pushStack(r);
			}
			cin >> token;
		}
		int result = POST.popStack();
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