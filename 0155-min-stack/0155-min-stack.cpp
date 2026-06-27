#include <stack>
#include <vector>
#include <climits>
using namespace std;

class MinStack {
public:
    int i = 0;
    vector<int> min;       
    stack<int> s1;

    MinStack() {
       
    }

    void push(int val) {
        s1.push(val);
        if (i == 0) {
            min.push_back(val);
        } else {
            if (val > min[i - 1]) {
                min.push_back(min[i - 1]);
            } else {
                min.push_back(val);
            }
        }
        i++;
    }

    void pop() {
        if (!s1.empty()) {
            s1.pop();
            min.pop_back(); 
            i--;
        }
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return min[i - 1];
    }
};