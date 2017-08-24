// Solution 1.
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string res = "";
        for(int i = num2.size() - 1, zero = 0; i >= 0; i--, zero++)
            res=addStr(res, multiStr(num1, num2[i] - '0', zero));
        return res;
    }
    //string * multiple -> string
    string multiStr(string s, int multiple, int zero){
        int carry = 0;
        int n = 0;
        for(int i = s.size()-1; i >= 0; i--){
            n = (s[i]-'0') * multiple + carry;
            s[i] = n%10 + '0';
            carry = n/10;
        }
        if(carry) s = to_string(carry) + s;
        while(zero) s += "0", zero--;
        return s;
    }
    //string + string -> string
    string addStr(string num1, string num2) {
        string s = "";
        int carry = 0;
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >= 0 || carry; i--, j--){
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            s.push_back((x + y + carry) % 10 + '0');
            carry = (x + y + carry) / 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

// Solution 2.
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int>pos(m + n);
   
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); 
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];
                pos[p1] += sum / 10;
                pos[p2] = (sum) % 10;
            }
        }  
    
        string s = "";
        for(int p : pos) if(!(s.length() == 0 && p == 0)) s.push_back(p + '0');
        return s.size() == 0 ? "0" : s;
    }
};
