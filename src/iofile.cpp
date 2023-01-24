#include "header.hpp"

vector<string> inputCardFromUser() {
    vector<string> inputs;
    string buffer;
    int currentSize = 0;

    cout << "Insert card numbers: " << endl;
    getline(cin, buffer);
    if (buffer == "") {
        getline(cin, buffer);
    }

    string currentWord = "";
    for (int i=0; i <= buffer.length(); i++) {
        if (buffer[i] == ' ' || !buffer[i]) {
            if (currentWord != "") {
                inputs.push_back(currentWord);
                currentSize++;
                currentWord = "";

                if (currentSize == 5) break;
                // Kalau size nya udah 5 langsung break aja karena udah pasti ga valid
            }
        }
        else {
            currentWord += buffer[i];
        }
    }
    return inputs;
}

vector<int> generateRandomCard() {
    const vector<string> cardOptions = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    vector<int> randomCard(TOTALNUMS);
    int random;

    srand((unsigned) time(NULL));
    cout << "Your cards: " << endl;
    for (int i=0; i < TOTALNUMS; i++) {
        random = rand() % 13;
        cout << cardOptions[random] << " ";
        randomCard[i] = convertToInt(cardOptions[random]);
    }
    cout << endl << endl;
    return randomCard;
}

vector<int> getNumsVec() {
    vector<string> temp;
    vector<int> numsVec(TOTALNUMS);

    temp = inputCardFromUser();
    while (!isInputValid(temp)) {
        cout << "Invalid input!" << endl;
        temp = inputCardFromUser();
    } 
    cout << endl;
    
    for (int i=0; i < TOTALNUMS; i++) {
        numsVec[i] = convertToInt(temp[i]);
    }
    
    return numsVec;
}

bool isInputValid(vector<string> inputs) {
    if (inputs.size() != TOTALNUMS) {
        return false;
    }
    for (int i=0; i < TOTALNUMS; i++) {
        if (!isInputElmtValid(inputs[i])) {
            return false;
        }
    }
    return true;
}

bool isInputElmtValid(string input) {
    if (input.length() == 2) {
        return (input == "10");
    }
    if (input.length() == 1) {
        return ((input[0] - '0' > 1 && input[0] - '0' < 10) ||
                (input[0] == 'A') ||
                (input[0] == 'J') ||
                (input[0] == 'Q') ||
                (input[0] == 'K'));
    }
    else {
        return false;
    }
}

int convertToInt(string input) {
    if (input == "10") {return 10;}
    else if (input[0] - '0' > 1 && input[0] - '0' < 10) {return input[0] - '0';}
    else if (input[0] == 'A') {return 1;}
    else if (input[0] == 'J') {return 11;}
    else if (input[0] == 'Q') {return 12;}
    else /* (input[0] == 'K') */ {return 13;}
}

void printResults() {
    for (int i=0; i < savedResults.size(); i++) {
        cout << savedResults[i] << endl;
    }
    cout << endl;
}

void saveResultsToFile(int solutions) {
    string fileName;
    ofstream fout;

    cout << "Insert file name: ";
    cin >> fileName;
    fout.open("test/" + fileName);

    if (!solutions) {
        fout << "No solutions found" << endl;
    }
    else {
        fout << solutions << " solutions found" << endl;
        for (int i=0; i < savedResults.size(); i++) {
            fout << savedResults[i] << endl;
        }
    }
}