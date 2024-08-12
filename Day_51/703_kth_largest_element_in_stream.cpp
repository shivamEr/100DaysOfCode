

// Problem Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k; // kth largest element ka location batatega
    vector<int>stream; // stream jo all element ka values store krega
    priority_queue<int,vector<int>,greater<int>>pq; // ye top pe kth element track krega

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        stream = nums;
        // pahle hi current kth element find kar
        for(auto it:stream){
            pq.push(it);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        // val push to stream
        stream.push_back(val);
        // value push to min heap
        pq.push(val);
        // size greater ho kth se pop() kar
        if(pq.size()>k) pq.pop();
        // top pe hamesa kth large element hi hoga
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 int main(){
    KthLargest* obj = new KthLargest(3, {4,5
    ,8,2});
    cout<<obj->add(3)<<endl; // returns 4
    cout<<obj->add(5)<<endl; // returns 5
    cout<<obj->add(10)<<endl; // returns 5
    cout<<obj->add(1)<<endl; // returns 4
    return 0;
 }