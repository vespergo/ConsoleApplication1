//#include <iostream>
//#include <fstream>
//using namespace std;
//
//
////
////void askQuestions(int charTotal, char* text) {
////
////    int storyCounter = 0;
////    bool token = false;
////
////    char question[50];
////    char* answers[50];
////    int numAnswers = 0;
////
////    // we're only concerned with getting answers for this loop
////    for (int i = 0; i < charTotal; i++)
////    {
////        char c = text[i];
////
////        // start capturing the token
////        if (c == ':') {
////            token = true;
////
////            // reset the question
////            question[0] = '\t';
////            question[1] = '\0';
////            continue;
////        }
////
////        // this is a question
////        if (token && c >= 65) {
////            question
////        }
////
////        // check for the end of token
////        if (c == ' ') {
////            token = false;
////
////            // check if we need to write the question and get an answer
////            if (question[1] != '\0') {
////
////                cout << question;
////                cin >> answers[numAnswers];
////                numAnswers++;
////            }
////        }
////
////
////
////    }
////}
//
//// read in the file and make sure we check that file is the right size
//int readFile(char* text)
//{
//
//    char fileName[256];
//    cout << "Please enter the filename of the MadLib: ";
//    cin >> fileName;
//
//    //Declare a stream variable. Since this is an input stream us 'ifstream'.
//    ifstream fin("madlib.txt");
//    if (fin.fail())                //Check for errors
//    {
//        cout << "Error reading file " << fileName << endl; //Error message
//        return -1;
//    }
//
//    //Loop through the file char by char, evaluating for limits
//    int charTotal = 0;
//    int totalLines = 0;
//    int lineLength = 0;
//    int totalWords = 0;
//    int wordLength = 0;
//
//    while (!fin.eof()) {
//
//        char c;
//
//        //get a single character from the file
//        fin.get(c);
//
//        //store a single char
//        text[charTotal] = c;
//
//        charTotal++;
//        lineLength++;
//        wordLength++;
//
//        if (c == '!') {
//            totalLines++;
//            lineLength = 0;
//        }
//        else if (c == ' ') {
//            totalWords++;
//            wordLength = 0;
//        }
//
//        //check to see if anything went out of bounds.    
//        if (charTotal > 1024 || totalLines > 32 ||
//            lineLength > 80 || totalWords > 256 ||
//            wordLength > 32)
//            return -1;
//
//    }
//
//    return charTotal;
//
//}
//
//
//void askQuestions(int charTotal, char* text, char* story) {
//
//    int storyCounter = 0;
//    bool token = false;
//    bool question = false;
//
//    for (int i = 0; i < charTotal; i++)
//    {
//        char c = text[i];
//        if (c == ':') {
//            token = true;
//            continue;
//        }
//        else if (c == ' ') {
//            token = false;
//
//            //this signals the end of our question, so now we get input from user
//            if (question) {
//                cout << ": ";
//
//                char answer[200];
//                cin.getline(answer, 200);
//                cout << answer << endl;
//                question = false;
//            }
//        }
//
//        if (token) {
//            if (c == '!') {
//                c = '\n';
//            }
//            else if (c == '<' || c == '>') {
//                c = '"';
//            }
//            else if (c == '.') {
//
//            }
//            else {
//                question = true;
//
//                // pre-process first letter
//                char previousChar = text[i - 1];
//                if (previousChar == ':') {
//                    cout << "\t";
//                    c = toupper(c);
//                }
//                // pre-process underscore
//                else if (c == '_') {
//                    c = ' ';
//                }
//
//                // print to screen to ask question        
//                cout << c;
//            }
//
//        }
//
//        // store our char to the final story/madlib array
//        if (!question) {
//            story[storyCounter] = c;
//            storyCounter++;
//        }
//
//    }
//}
//
///*********************************************************
//*MAIN is calling several functions
//**********************************************************/
//int bmain()
//{
//    char originalText[1024];
//
//    //check if file failed, wrong size, etc
//    int charTotal = readFile(originalText);
//    if (charTotal >= 0) {
//        char story[1024];
//        askQuestions(charTotal, originalText, story);
//
//        //display story
//    }
//    else {
//        cout << "Failed to read file." << endl;
//    }
//
//    return 0;
//
//}
//
//
//
//
