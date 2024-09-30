
Problem Link : 

class CustomStack {
public:
    int *arr;
    int mx_size;
    int top = -1;
    CustomStack(int maxSize) {
        this->mx_size = maxSize;
        arr = new int[maxSize];
    }
    
    void push(int x) {
        if(top<mx_size-1){
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if(top == -1) return -1;
        int num = arr[top];
        top--;
        return num;
    }
    
    void increment(int k, int val) {
        int n = top+1 < k? top+1:k;
        for(int i = 0;i<n; i++){
            arr[i] += val;
        } 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */