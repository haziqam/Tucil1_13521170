#include "header.hpp"

int main() {
    vector<int> test;
    int solutions;
    string option;
    

    while (true) {
        cout << "Do you want to insert cards (0) or generate random cards (1)?: ";
        cin >> option;
        if (option == "0") {
            test = getNumsVec();
            break;
        }
        if (option == "1") {
            test = generateRandomCard();
            break;
        }
        cout << "Invalid input!" << endl;
    }
    
    using namespace std::chrono;

    high_resolution_clock::time_point start = high_resolution_clock::now();
    findNumberPermutation(test, 0, TOTALNUMS-1);
    findOpsPermutation();
    solutions = getPossibleResults();
    high_resolution_clock::time_point end = high_resolution_clock::now();
    duration<double> executionTime = duration_cast<duration<double>>(end - start);

    if (!solutions) {
        cout << "No solutions found" << endl;
    }
    else {
        cout << solutions << " solutions found" << endl;
        printResults();
    }

    cout << "execution time: " << executionTime.count() * 1000 << " ms" << endl << endl;

    while (true) {
        cout << "Do you want to save the result? (Y/N): ";
        cin >> option;
        if (option == "Y") {
            saveResultsToFile(solutions);
            break;
        }
        if (option  == "N") {
            break;
        }
        cout << "Invalid input" << endl;
    }
    
    return 0;
}