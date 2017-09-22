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
        stringstream ss("+" + s + "+");
        int sum(0), temp(0), num(0);
        char op;
        while(ss >> op){
            ss >> num;
            if(op == '+' || op == '-'){
                sum += temp;
                temp = op == '+' ? num : -num;
            }
            else temp = op == '*' ? temp * num : temp / num;
        }
        return sum;
    }
};
