class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value >= mini)
                st.push(value);
            else{
                st.push(2LL*value-mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            long long x = st.top();
            st.pop();
            if(x < mini) mini = 2LL*mini-x;
        }
    }
    
    int top() {
        if(!st.empty()){
            long long x = st.top();
            if(x >= mini) return (int)x;
            else return (int)mini;
        }
        return -1;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */