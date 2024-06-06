class Solution {
public:
  int getSum(int a, int b) {
    int total = a, carry = b;
    while (carry) {
      int new_total = total ^ carry;
      int new_carry = total & carry;
      total = new_total;
      carry = new_carry << 1;
    }
    return total;
  }
};
