#include <bits/stdc++.h>
class BrowserHistory {
public:
    vector<string> history;
    int curr ;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0 ;
    }
    
    void visit(string url) {
        history.resize(curr+1);
        history.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        int back = max(0,curr-steps);
        curr = back;
        return history[curr];
    }
    
    string forward(int steps) {
        int far = min((int)history.size()-1,curr+steps);
        curr = far ;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */