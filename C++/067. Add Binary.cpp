class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string sum = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry){
            int num1 = i < 0 ? 0 : a[i] - '0';
            int num2 = j < 0 ? 0 : b[j] - '0';
            int k = num1 + num2 + carry;
            sum.push_back(k % 2 + '0');
            carry = k > 1 ? 1 : 0;
            i--;
            j--;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
