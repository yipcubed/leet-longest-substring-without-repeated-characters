#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>


using namespace std;

// makes code faster but larger
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

/**
 * Git instructions for copy-paste
 * F1 to Open Shell

git init; git add main.cpp; git add README.md; git config user.name "Yip Cubed"; git config user.email "yipcubed@gmail.com"; git config credential.helper 'cache --timeout 7200'; git commit -m "starting"; git remote add origin https://yipcubed@github.com/yipcubed/


git push -u origin master

git add main.cpp; git commit -m "Made changes"
git push -u origin master

 *
**/

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

class Solution {
public:
    // uses vector
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int longest = 1;
        vector<int> seen(128, -1);
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
          char c = s[i];
          if (seen[c] >= start) {
            // new start location
            longest = (i - start) > longest ? (i - start) : longest;
            start = seen[c] + 1;
          }
          seen[c] = i;
        }
        longest = (s.length() - start) > longest ? (s.length() - start) : longest;
        return longest;
    }

    // uses map
    int lengthOfLongestSubstring2(string s) {
        if (s.empty()) return 0;
        int longest = 1;
        map<char, int> seen;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
          char c = s[i];
          if (seen.count(c) > 0 && seen[c] >= start) {
            // new start location
            longest = (i - start) > longest ? (i - start) : longest;
            start = seen[c] + 1;
          }
          seen[c] = i;
        }
        longest = (s.length() - start) > longest ? (s.length() - start) : longest;
        return longest;
    }
};

void test1() {
  Solution S;
  string s = "abcabcbb";
  cout << "3? " << S.lengthOfLongestSubstring(s) << endl;
}

void test2() {
  Solution S;

  string s = "bbbbb";
  cout << "1? " << S.lengthOfLongestSubstring(s) << endl;
}

void test3() {
  Solution S;

  string s = "pwwkew";
  cout << "3? " << S.lengthOfLongestSubstring(s) << endl;

}

void test4() {
  Solution S;
  string s;

  s = " ";
  cout << "1? " << S.lengthOfLongestSubstring(s) << endl;

  s = "";
  cout << "0? " << S.lengthOfLongestSubstring(s) << endl;

  s = "au";
  cout << "2? " << S.lengthOfLongestSubstring(s) << endl;

}

int main() {
  test1();
  test2();
  test3();
  test4();
  cout << "Done!" << endl;
  
  return 0;
}
