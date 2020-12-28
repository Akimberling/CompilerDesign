#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	fstream indata, outdata;

	indata.open("input.txt", ios::in);
	outdata.open("output.txt", ios::out);

	string input;
	char cc;
	int location, i = 0;
	bool skip = false;

	while (!indata.eof())
	{
		getline(indata, input, '\n');

		if (input.find("//") < input.length())
		{

			input.erase(input.find("//"), input.length() - input.find("//"));

			if (input.length() == 1) { skip = true; } //remove line if its just a newline
		}
		if (input.length() == 0 && input.find("\n") > 0)
		{

			skip = true;
		}
		if (!skip)
		{

			while (i < input.length())
			{

				cc = input[i];

				if (cc == ' ')
				{

					while (input[i + 1] == ' ') { i++; cc = input[i]; }

				}

				if (input[i + 1] == '>' && input[i + 2] == '>' && input.substr(i - 2, i) != "cin" && cc != ' ')
				{

					input.insert(i + 1, " ");
				}
				else if (cc == '>')
				{

					if (input[i + 1] == '>')
					{
			
						input.insert(i + 2, " ");
					}
				}
				else if (cc == '<')
				{

					if (input[i + 1] == '<')
					{

						input.insert(i + 2, " ");
					}
				}

				if ((input[i + 1] == ';' || input[i + 1] == '(') && cc != ' ')
				{

					input.insert(i + 1, " ");
				}

				outdata << input[i];
				i++;
			}

			outdata << endl;
		}

		skip = false;
		i = 0;
	}

	indata.close();
	outdata.close();

	system("pause");
	return 0;
}

