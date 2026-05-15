#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;

        for (const string& op : operations) {
            if (op == "D") {
                // Double the last score and add it to record
                stk.push(stk.top() * 2);
            } 
            else if (op == "C") {
                // Invalidate the last score
                stk.pop();
            } 
            else if (op == "+") {
                // Sum of the last two scores
                int topVal = stk.top();
                stk.pop();
                int nextTopVal = stk.top();
                
                // Put them back and add the new sum
                stk.push(topVal); 
                stk.push(topVal + nextTopVal);
            } 
            else {
                // It's an integer score
                stk.push(stoi(op));
            }
        }

        int totalSum = 0;
        while (!stk.empty()) {
            totalSum += stk.top();
            stk.pop();
        }
        return totalSum;
    }
};