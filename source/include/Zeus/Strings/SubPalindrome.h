#ifndef __SUBPALINDROME__
#define __SUBPALINDROME__

#include <string>
#include <vector>
#include <algorithm>

namespace Zeus
{
    namespace Strings
    {
        class SubPalindrome
        {
            std::vector<int> d1, d2;
        public:
            SubPalindrome(const std::string & s) : d1(s.length()), d2(s.length()) { calculate(s); }
            ~SubPalindrome() {}
            const std::vector<int> & getD1() const { return d1; }
            const std::vector<int> & getD2() const { return d2; }
        private:
            void calculate(const std::string & s)
            {
                const int n=s.length();
                for (int i=0, l=0, r=-1; i<n; ++i) 
                {
                    int k = (i>r ? 0 : std::min(d1[l+r-i], r-i)) + 1;
                    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) ++k;
                    d1[i] = k--;
                    if (i+k > r)
                    {
                        l = i-k;
                        r = i+k;
                    }
                }

                for (int i=0, l=0, r=-1; i<n; ++i) 
                {
                    int k = (i>r ? 0 : std::min (d2[l+r-i+1], r-i+1)) + 1;
                    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k]) ++k;
                    d2[i] = --k;
                    if (i+k-1 > r)
                    {
                        l = i-k;
                        r = i+k-1;
                    }
                }
            }
        };
    }
}


#endif // __SUBPALINDROME__