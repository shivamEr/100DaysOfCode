
// Problem Link : https://leetcode.com/problems/design-circular-deque/description/

class MyCircularDeque {
public:
    int size = 0;
    int currSize = 0;
    deque<int>dq;
    MyCircularDeque(int k) {
        this->size = k;
    }
    
    bool insertFront(int value) {
        if(currSize == size) return false;

        dq.push_front(value);
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(currSize == size) return false;

        dq.push_back(value);
        currSize++;
        return true;
        
    }
    
    bool deleteFront() {
        if(currSize == 0) return false;
        dq.pop_front();
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(currSize == 0) return false;
        dq.pop_back();
        currSize--;
        return true;
        
    }
    
    int getFront() {
        if(currSize == 0) return -1;
        return dq.front();
    }
    
    int getRear() {
        if(currSize == 0) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */