class MinStack {
public:
    stack<int> st;
    stack<int> minVal;
    MinStack() {
    }
    
    void push(int val) {
        this->st.push(val);
        if(this->minVal.empty() || val<=this->minVal.top()){
            this->minVal.push(val);
        }
    }
    
    void pop() {
        int t = this->st.top();
        st.pop();
        if(t == this->minVal.top()){
            this->minVal.pop();
        }
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->minVal.top();
    }
};
