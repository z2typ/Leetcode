class MinStack {
public:
    stack<int> mainSt;
    stack<int> minSt;
    MinStack() {
        mainSt = stack<int>();
        minSt = stack<int>():
    }
    
    void push(int val) {
        mainSt.push(val);
        if(minSt.empty() || val<minSt.top()){
            minSt.push(val);
        }else{
            minSt.push(minSt.top());
    }
    }
    
    void pop() {
        if(!mainSt.empty()){
            mainSt.pop();
            minSt.pop();
        }
    }
    
    int top() {
       if(mainSt.empty()) return -1;
        return mainSt.top();
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
