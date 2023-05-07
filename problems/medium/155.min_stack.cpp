class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s1, s2;
    
    void push(int x) {
        if(s1.empty()){
            s2.push(x);
        }
        else if(x <= s2.top()){
            s2.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        if(s1.empty())return;
        if(s1.top() == s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        if(s1.empty())return -1;
        return s1.top();
    }
    
    int getMin() {
        if(s1.empty())return -1;
        return s2.top();
    }
};