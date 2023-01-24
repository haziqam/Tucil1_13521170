#include "header.hpp"

const char allOps[TOTALOPS] = {'+', '-', '*', '/'};
vector<vector<int>> numsPermutations;
vector<vector<char>> opsPermutations;
vector<string> savedResults;

float evaluate(float firstNum, float secondNum, char op) {
    if (op == '+') {return firstNum + secondNum;}
    else if (op == '-') {return firstNum - secondNum;}
    else if (op == '*') {return firstNum * secondNum;}
    else /* (op == '/') */ {return firstNum / secondNum;}
}

void swapElmt(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

bool shouldSwap(vector<int>& container, int leftIdx, int currentIdx) {
    for (int i=leftIdx; i < currentIdx; i++) {
        if (container[i] == container[currentIdx]) {
            return false;
        }
    }
    return true;
}

void findNumberPermutation(vector<int>& container, int leftIdx, int rightIdx) {
    if (leftIdx == rightIdx) {
        numsPermutations.push_back(container);
        return;
    }

    for (int i=leftIdx; i <= rightIdx; i++) {
        bool check = shouldSwap(container, leftIdx, i);
        if (check) {
            swapElmt(container[leftIdx], container[i]);
            findNumberPermutation(container, leftIdx + 1, rightIdx);
            swapElmt(container[leftIdx], container[i]);
        }
    }
}

void findOpsPermutation() {
    vector<char> temp(3);
    for (int i=0; i < TOTALOPS; i++) {
        for (int j=0; j < TOTALOPS; j++) {
            for (int k=0; k < TOTALOPS; k++) {
                temp[0] = allOps[i];
                temp[1] = allOps[j];
                temp[2] = allOps[k];
                opsPermutations.push_back(temp);
            }
        }
    }
}

int getPossibleResults() {
    int solutions = 0;
    int a, b, c, d;
    float result;
    char op1, op2, op3;
    string temp;
    for (int i=0; i < opsPermutations.size(); i++) {
        for (int j=0; j < numsPermutations.size(); j++) {
            a = numsPermutations[j][0];
            b = numsPermutations[j][1];
            c = numsPermutations[j][2];
            d = numsPermutations[j][3];
            op1 = opsPermutations[i][0];
            op2 = opsPermutations[i][1];
            op3 = opsPermutations[i][2];

            // (a op1 b) op2 (c op3 d)
            result = evaluate(evaluate(a, b, op1), evaluate(c, d, op3), op2);
            if (result == 24) {
                temp = "(" + to_string(a) + op1 + to_string(b) + ")" + op2 + "(" + to_string(c) + op3 + to_string(d) + ")";
                savedResults.push_back(temp);
                solutions++;
            }

            // a op1 (b op2 (c op3 d))
            result = evaluate(a, evaluate(b, evaluate(c, d, op3), op2), op1);
            if (result == 24) {
                temp = to_string(a) + op1 + "(" + to_string(b) + op2 + "(" + to_string(c) + op3 + to_string(d) + "))";
                savedResults.push_back(temp);
                solutions++;
            }

            // a op1 ((b op2 c) op3 d)
            result = evaluate(a, evaluate(evaluate(b, c, op2), d, op3), op1);
            if (result == 24) {
                temp = to_string(a) + op1 + "((" + to_string(b) + op2 + to_string(c) + ")" + op3 + to_string(d) + ")";
                savedResults.push_back(temp);
                solutions++;
            }

            // ((a op1 b) op2 c) op3 d
            result = evaluate(evaluate(evaluate(a, b, op1), c, op2), d, op3);
            if (result == 24) {
                temp = "((" + to_string(a) + op1 + to_string(b) + ")" + op2 + to_string(c) + ")" + op3 + to_string(d);
                savedResults.push_back(temp);
                solutions++;
            }

            // (a op1 (b op2 c)) op3 d
            result = evaluate(evaluate(a, evaluate(b, c, op2), op1), d, op3);
            if (result == 24) {
                temp = "(" + to_string(a) + op1 + "(" + to_string(b) + op2 + to_string(c) + "))" + op3 + to_string(d);
                savedResults.push_back(temp);
                solutions++;
            }
        }
    }
    return solutions;
}