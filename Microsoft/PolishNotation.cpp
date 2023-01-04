//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.

class Solution {

    long resolves(int a, int b, char Op){
        if(Op == '+') return a + b;
        else if(Op == '-') return a - b;
        else if(Op == '*') return (long)a*b;
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> S;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            // check if element is an op
            if(tokens[i].size() == 1 and tokens[i][0] < 48){
                long n2 = S.top();
                S.pop();
                long n1 = S.top();
                S.pop();
                
                string Op = tokens[i];
                long val = resolves(n1, n2 , Op[0]);
                S.push(val);
            }else 
                S.push(stol(tokens[i]));
        }
        return S.top();
    }
};