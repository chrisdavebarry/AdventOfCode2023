
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// no chat gpt used, only cplusplus.com for reference,,, so much bruteforce...... but it works!!!
int main()
{
    vector<string> inputList;
    string filename = "input.txt";

    ifstream inputFile(filename);

    string input;

    while (getline(inputFile, input)) // read in all the lines to a vector
        inputList.push_back(input);

    int answer = 0;
    for (int i = 0; i < inputList.size(); i++) // loop thru inputList
    {
        // initializations in below 3 lines
        bool foundFirst = false, foundSecond = false;
        string first, second;
        int secondIntIndex = -1;
        for (int j = 0; j < inputList[i].size(); j++) // loop thru current string
        {
            if (isdigit((inputList[i])[j]) && (foundFirst == false)) // found first int in current string
            {
                foundFirst = true;
                first = (inputList[i])[j];
                if ((j == inputList[i].size() - 1) && (foundSecond == false)) // if we reach the end of the current line
                    second = first;
                continue; // next part of inner for loop
            }
            else if (isdigit((inputList[i])[j]) && (foundFirst == true)) // found first and found second int
            {
                if (foundSecond == false)
                {
                    if ((j == inputList[i].size() - 1))
                    {
                        second = first;
                    }
                    foundSecond = true;
                    secondIntIndex = j;
                    second = (inputList[i])[j];
                }
                else                        // we have already found a second int
                    if (j > secondIntIndex) // if index of the int we just found is > than prev
                    {
                        secondIntIndex = j; // this is our new 'latest' int
                        second = (inputList[i])[j];
                    }
            }
            else if ((j == inputList[i].size() - 1) && (foundSecond == false))
                second = first;
        }
        answer += stoi(first) + stoi(second);
    }
    cout << "Final answer is " << answer << endl;

    // Close the file
    inputFile.close();

    return 0;
}