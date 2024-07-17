
// Problem Link : https://leetcode.com/problems/min-stack/description/

// Time Complexity : O(1)
// Space Complexity : O(1


#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int>st;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ss.empty()) ss.push(val);
        else if(val<=ss.top()) ss.push(val);
    }
    
    void pop() {
        if(st.top()==ss.top()) ss.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return ss.top();
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

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->getMin()<<endl;
    return 0;
}
