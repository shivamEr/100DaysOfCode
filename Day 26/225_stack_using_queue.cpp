
// LINK : https://leetcode.com/problems/implement-stack-using-queues/


#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int d;
        while (!q1.empty())
        {
            d = q1.front();
            q1.pop();
            if (!q1.empty())
                q2.push(d);
        }

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return d;
    }

    int top()
    {
        int d;
        while (!q1.empty())
        {
            d = q1.front();
            q1.pop();
            q2.push(d);
        }

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return d;
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyStack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
    return 0;
}