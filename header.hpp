#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

// CONSTANTS
#define TOTALNUMS 4
#define TOTALOPS 4
extern const char allOps[TOTALNUMS];

// GLOBAL VARIABLES
extern vector<vector<int>> numsPermutations;
extern vector<vector<char>> opsPermutations;
extern vector<string> savedResults;

// IO RELATED FUNCTIONS
vector<string> inputCardFromUser();

vector<int> generateRandomCard();

vector<int> getNumsVec();

bool isInputValid(vector<string> inputs);

bool isInputElmtValid(string input);

int convertToInt(string input);

void printResults();

void saveResultsToFile(int solutions);

// ALGORITHM
float evaluate(float firstNum, float secondNum, char op);

void swapElmt(int& num1, int& num2);

void findNumberPermutation(vector<int>& container, int leftIdx, int rightIdx);

void findOpsPermutation();

int getPossibleResults();

#endif