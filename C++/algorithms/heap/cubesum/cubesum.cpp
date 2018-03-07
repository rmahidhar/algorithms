//
// Created by mahidhar.ramesh on 1/1/2018.
//

#include <vector>
#include <functional>
#include <queue>
#include <iostream>

int main(int argc, char *argv[]) {

    struct CubeSum {
        CubeSum() : a(0), b(0), sum(0) {

        }

        CubeSum(int a, int b) : a(a), b(b){
            sum = (a * a * a) + (b * b * b);
        }
        int a;
        int b;
        int sum;

        bool operator () (const CubeSum& lhs, const CubeSum& rhs) {
            return lhs.sum > rhs.sum;
        }
    };

    std::priority_queue<CubeSum, std::vector<CubeSum>, CubeSum> minPq;

    int n = 500;
    for (int i = 1; i < n; i++) {
        minPq.push(CubeSum(i, i));
    }

    CubeSum currSum;
    CubeSum prevSum;
    while (!minPq.empty()) {
        currSum = minPq.top();
        minPq.pop();
        //std::cout << currSum.sum << " ";

        if (currSum.b < n) {
            minPq.push(CubeSum(currSum.a, currSum.b+1));
        }

        if (currSum.sum == prevSum.sum) {
            std::cout << currSum.a << " " << currSum.b << " "
                      << prevSum.a  << " " << prevSum.b << " "
                      << currSum.sum << std::endl;
        }
        prevSum = currSum;
    }
}

