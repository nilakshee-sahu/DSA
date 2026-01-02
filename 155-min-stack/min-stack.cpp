#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> s;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int data) {
        long long val = data;
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                long long encoded = 2 * val - mini;
                s.push(encoded);
                mini = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        long long curr = s.top();
        s.pop();

        if (curr < mini) {
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if (s.empty()) return -1;

        long long curr = s.top();
        if (curr < mini) {
            return (int)mini;
        } else {
            return (int)curr;
        }
    }

    int getMin() {
        if (s.empty()) return -1;
        return (int)mini;
    }
};