// Lambda
class Solution {
private:
    unordered_map<char, function<int(int,int)>>m {{'+', [](int a, int b){ return a + b ;}},
                                                  {'-', [](int a, int b){ return a - b ;}},
                                                  {'*', [](int a, int b){ return a * b ;}},
                                                  {'/', [](int a, int b){ return a / b ;}}};
public:
    int calculate(string s) {
        stringstream ss("+" + s + "+");
        int sum(0), temp(0), num(0);
        char op;
        while(ss >> op){
            ss >> num;
            if(op == '+' || op == '-'){
                sum += temp;
                temp = m[op](0, num);
            }
            else temp = m[op](temp, num);
        }
        return sum;
    }
};

// Or
class Solution {
public:
    int calculate(string s) {
        stringstream ss('+' + s + '+');
        int temp = 0, num = 0, sum = 0;
        char op = ' ';
        while(ss >> op){
            ss >> num;
            if(op == '+'){
                sum += temp;
                temp = num;
            }
            if(op == '-'){
                sum += temp;
                temp = -num;
            }
            if(op == '*')
                temp *= num;
            if(op == '/')
                temp /= num;
        }
        return sum;
    }
};

// Using stack
class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int>stk;
        int tmp = 0;
        char op = '+';
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == ' ') continue;
            if(isdigit(c)) tmp = tmp*10 + c - '0';
            if(!isdigit(c)){
                if(op == '+')
                    stk.push(tmp);
                else if(op == '-')
                    stk.push(-tmp);
                else if(op == '*'){
                    int n = stk.top();
                    stk.pop();
                    stk.push(n*tmp);
                }
                else if(op == '/'){
                    int n = stk.top();
                    stk.pop();
                    stk.push(n/tmp);
                }
                op = c;
                tmp = 0;
            }
        }
        int res = 0;
        while(!stk.empty()) res += stk.top(), stk.pop();
        return res;
    }
};
