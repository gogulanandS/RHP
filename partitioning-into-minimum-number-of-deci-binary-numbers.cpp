class Solution {
public:
    int minPartitions(string n) {
        char c='0';
      for(auto ch:n){
        c=max(ch,c);
      }
    return c-'0';
    }
};