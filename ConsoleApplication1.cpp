#include <iostream>
#include <fstream>
using namespace std;


// read in the file and make sure we check that file is the right size
int readFile(char originalText[][50], char questions[][50])
{

	char fileName[256];
	cout << "Please enter the filename of the Mad Lib: ";
	cin >> fileName;
	cin.ignore();

	//Declare a stream variable. Since this is an input stream us 'ifstream'.
	ifstream fin(fileName);
	if (fin.fail())                //Check for errors
	{
		cout << "Error reading file " << fileName << endl; //Error message
		return -1;
	}

	//Loop through the file char by char, evaluating for limits
	int charTotal = 0;
	int totalLines = 0;
	int lineLength = 0;
	int totalWords = 0;

	int questionCursor = 0;

	while (!fin.eof()) {

		//store each word into an array
		char word[100];
		fin >> word;
		strcpy_s(originalText[totalWords], word);

			

		// store our questions
		if (word[0] == ':' && word[1] >= 65) {		
			//store the question, starting with the first character after the :
			strcpy_s(questions[questionCursor], word+1);
			questionCursor++;
		}

		charTotal += strlen(word);
		totalWords++;

		//check to see if anything went out of bounds.    
		if (charTotal > 1024 || totalLines > 32 ||
			lineLength > 80 || totalWords > 256 ||
			strlen(word) > 32)
			return -1;

	}

	return charTotal;

}

void askQuestions(char questions[][50], char answers[][50]) 
{
	int currentQuestion = 0;
	while (questions[currentQuestion][0]) {
		char* question = questions[currentQuestion];
		question[0] = toupper(questions[currentQuestion][0]);

		//replace _ with space
		for (int i = 0; i < strlen(question); i++) {
			if (question[i] == '_')
				question[i] = ' ';
		}

		cout << "\t" << question << ": ";
		cin >> answers[currentQuestion];

		currentQuestion++;
	}
}


void display(char originalText[][50], char answers[][50]) {
	
	int currentAnswer = 0;
	char previousChar = '\n';

	for (int i = 0; originalText[i][0] != '\0'; i++) {
		
		if (i > 0) {
			//we're only concerned with tokens at the moment so we look at the second char
			char previousChar = originalText[i - 1][1];
			char currentChar = originalText[i][1];
			if (previousChar != '!' && previousChar != '<' &&
				currentChar != '>' && currentChar != '.' && currentChar != ',')
			{
				cout << ' ';
			}
		}
		
		//token
		if (originalText[i][0] == ':') {
			char token = originalText[i][1];

			if (token == '!')
				cout << '\n';
			else if (token == '<')
				cout << '"';
			else if (token == '>')
				cout << '"';
			else if (token == '.')
				cout << '.';
			else if (token == ',')
				cout << ',';
			else
			{
				cout << answers[currentAnswer];
				currentAnswer++;
			}

		}
		else {

			//normal word print
			cout << originalText[i];
		}
	}

}

/*********************************************************
*MAIN is calling several functions
**********************************************************/
int main()
{
	bool playing = true;
	while (playing) {
		char originalText[500][50] = { '\0' };
		char answers[50][50];
		char questions[50][50] = { '\0' };

		//check if file failed, wrong size, etc
		int charTotal = readFile(originalText, questions);
		if (charTotal >= 0) {
			askQuestions(questions, answers);

			// merge and display story
			display(originalText, answers);
		}
		else {
			cout << "Failed to read file." << endl;
		}

		char answer;
		cout << "\nDo you want to play again (y/n)? ";
		cin >> answer;
		if (answer == 'n') {
			playing = false;
			cout << "Thank you for playing.";
		}
	}

	return 0;

}




