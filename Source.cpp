#include <iostream>
using namespace std;

int countLetters(char text[], char letter)
{
	int sumLetter = 0;
	for (int i = 0; text[i]; i++)
	{
		if (text[i] == letter)
			sumLetter++;
	}
	return sumLetter;
}


/**********************************************************
MAIN prompts the user for a line of input (using getline),
calls countLetters(), and displays the number of letters.
**********************************************************/
int test()
{
	//prompt for a string
	char letter;
	char text[256];
	cout << "Enter a letter: ";
	cin >> letter;
	cout << "Enter text; ";
	cin.ignore();
	cin.getline(text, 256);
	cout << countLetters(text, letter);
	return 0;
}






