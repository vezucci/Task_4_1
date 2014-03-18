#include "stack.h"
#include "stdlib.h"
#include "string.h"
#include <string>
#include <iostream>

using namespace std;

void checkBracers(char* str, Stack<char> &st);
void info();


void main()
{
	
	info();
	cout << "Enter a string. Enter 'q' when you want to exit." << endl;
	string s;
	getline(cin, s);
	

	while (s[0] != 'q')
	{
		Stack<char> st;
		char* str = (char*)s.data();
		checkBracers(str, st);

		if (st.isEmpty())
		{
			cout << "GOOD! No bracers conflicts found." << endl;
		}
		else
		{
			cout << "BAD! Bracers conflicts found." << endl;
		}
		getline(cin, s);
	}


	system("pause");
}




void checkBracers(char* str, Stack<char> &st)
{
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
		{
					st.push(str[i]);
					break;
		}
		case '{':
		{
					st.push(str[i]);
					break;
		}
		case '[':
		{
					st.push(str[i]);
					break;
		}
		case ')':
		{
					if (st.peek() == '(')
					{
						st.pop();
					}
					else
					{
						st.push('-');
					}
					break;
		}
		case '}':
		{
					if (st.peek() == '{')
					{
						st.pop();
					}
					else
					{
						st.push('-');
					}
					break;
		}
		case ']':
		{
					if (st.peek() == '[')
					{
						st.pop();
					}
					else
					{
						st.push('-');
					}
					break;
		}

		default:
			break;
		}
	}
}


void info()
{
	unsigned i;
	for (i = 0; i < 10; ++i)
		printf("-");
	puts("\nBracersCheck v1.0");
	puts("\nThis genial program checks if bracers are set correctly in the text you enter.");
	puts("\nTsybran Vitalii 2014 All rigths reserved.");
	for (i = 0; i < 10; ++i)
		printf("-");
	printf("\n");
}