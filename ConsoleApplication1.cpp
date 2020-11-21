#include <iostream>
#include <fstream>
using namespace std;


// read in the file and make sure we check that file is the right size
int readFile(char *text)
{

    //char fileName[256];
    //cout << "Please enter the filename of the MadLib: ";
    //cin >> fileName;
    //cin.ignore();

    //Declare a stream variable. Since this is an input stream us 'ifstream'.
    ifstream fin("madlib.txt");
    //if (fin.fail())                //Check for errors
    //{
    //    cout << "Error reading file " << fileName << endl; //Error message
    //    return -1;
    //}

    //Loop through the file char by char, evaluating for limits
    int charTotal = 0;
    int totalLines = 0;
    int lineLength = 0;
    int totalWords = 0;
    int wordLength = 0;

    while (!fin.eof()) {

        char c;

        //get a single character from the file
        fin.get(c);

        //store a single char
        text[charTotal] = c;

        charTotal++;
        lineLength++;
        wordLength++;

        if (c == '\n') {
            totalLines++;
            lineLength = 0;
        }
        else if (c == ' ') {
            totalWords++;
            wordLength = 0;
        }

        //check to see if anything went out of bounds.    
        if (charTotal > 1024 || totalLines > 32 ||
            lineLength > 80 || totalWords > 256 ||
            wordLength > 32)
            return -1;

    }

    return charTotal;

}


void askQuestions(int charTotal, char *text) {
            
    char story[1024] = { 0 };
    char answers[50][50] = { 0 };
    int numAnswers = 0;

    // we're only concerned with getting answers for this loop
    for (int i=0; i < charTotal; i++)
    {
        char c = text[i];

        // start capturing the token
        if (c == ':') {
            
            //advance cursor to get next character
            i++;
            c = text[i];
            
            char question[50] = { 0 };
            int qIndex = 0;

            // knowing that our special token chars are < 65 we can take advantage to know when to end our question
            
            while (c >= 65) {

                //replace _ with space
                if (c == '_')
                    c = ' ';

                question[qIndex] = c;
                qIndex++;
                i++;
                c = text[i];
            }

            // did we capture a question to ask?
            if (question[0] != 0) {
                //capitalize first char
                question[0] = toupper(question[0]);

                cout << "\t" << question << ": ";
                char answer[100];
                cin >> answer;
                numAnswers++;

                //insert back into story
                strncat(story, answer, strlen(answer));
            }
            else {
                //translate special character and insert into story
                char special = c;
                if (special == '!')
                    story[i - 2] = '\n';
                else if (special == '<')
                    story[i - 1] = '"';
                else if(special == '>')
                    story[i - 1] = '"';
                else if (special == '.')
                    story[i - 1] = '.';
                else if (special == ',')
                    story[i - 1] = ',';
                    
            }
        }
        else {
            //normal character
            story[i] = c;
        }

    }
}

/*********************************************************
*MAIN is calling several functions
**********************************************************/
int main()
{
    char originalText[1024];

    //check if file failed, wrong size, etc
    int charTotal = readFile(originalText);
    if (charTotal >= 0) {
        askQuestions(charTotal, originalText);

        //display story
    }
    else {
        cout << "Failed to read file." << endl;
    }

    return 0;

}




