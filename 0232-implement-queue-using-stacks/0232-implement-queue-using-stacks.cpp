class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> in;
    stack<int> out;
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(!out.empty()){
            int n=out.top();
            out.pop();
            return n;
        }
        else{
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
            int n=out.top();
            out.pop();
            return n;
        }
    }
    
    int peek() {
        if(!out.empty()){
         return out.top();
        }
        else{
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
            return out.top();
        }
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */