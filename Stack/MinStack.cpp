#include<iostream>
#include<stack>
using namespace std;
class MinStack{
public:
    stack<int> s1, s2;
    MinStack(){
    }
    void push(int val){
        s1.push(val);
        if(s2.empty()){
            s2.push(val);
        }else{
            s2.push(min(val, s2.top()));
        }
    }

    void pop(){
        s1.pop();
        s2.pop();
    }

    int top(){
        return s1.top();
    }

    int getMin(){
        return s2.top();
    }

};
int main(){
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(7);
    cout << "Top: " << obj->top() << endl;        // 7
    cout << "Min: " << obj->getMin() << endl;     // 3
    obj->pop();
    cout << "Top: " << obj->top() << endl;        // 3
    cout << "Min: " << obj->getMin() << endl;     // 3

}