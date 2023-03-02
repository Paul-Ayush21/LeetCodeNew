class MyStack {
public:
    MyStack() {
        
    }
    queue<int> s;
    void push(int x) {
        s.push(x);
        for(int i=0;i<s.size()-1;i++){
            s.push(s.front());
            s.pop();
        }
    }
    
    int pop() {
        int n=s.front();
        s.pop();
        return n;
    }
    
    int top() {
        return s.front();
    }
    
    bool empty() {
        return s.size()==0;
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