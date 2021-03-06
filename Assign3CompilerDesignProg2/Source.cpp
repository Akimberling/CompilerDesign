#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool cont() {
	string clear;
	bool loop = true,
		again;
	char input;
	while (loop) {
		cout << "\t\tCONTINUE (y/n)? ";
		cin >> input;
		input = toupper(input);
		switch (input) {
		case 'Y':
			again = true;
			loop = false;
			break;
		case 'N':
			again = false;
			loop = false;
			break;
		default:
			loop = true;
		}
	}
	getline(cin, clear, '\n');
	return again;
}

int main() {
	bool again = true;
	string test;
	int i = 0,
		states[4][3] = {
		0, 1, 3,
		3, 1, 2,
		1, 2, 3,
		0, 2, 2,
	},
	state = 0;

	while (again)
	{
		cout << "Enter a string to test if accepted the grammar (EX: abbbcaa): ";
		getline(cin, test, '\n');
		while (i <= test.length())
		{
			if (i == test.length())
			{
				cout << '\t' << test;

				if (state == 0 || state == 2)
				{
					cout << " is not accepted" << endl;
				}
				else
				{
					cout << " is accepted" << endl;
				}
			}
			else
			{

				switch (test[i])
				{
				case 'a':
					state = states[state][0];
					break;
				case 'b':
					state = states[state][1];
					break;
				case 'c':
					state = states[state][2];
					break;
				}
			}
			i++;
		}

		again = cont();
		state = 0;
		i = 0;

	}

	system("PAUSE");
	return 0;
}


