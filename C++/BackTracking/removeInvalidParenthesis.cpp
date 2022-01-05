#include <iostream>
using namespace std;
#include <vector>

void misCount(string &s, int left, int right)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            left++;

        else if (s[i] == ')')
        {
            if (left == 0)
                right++;
            else
                left--;
        }
    }
}

void bracCHK(string &s, int i, int bracCount, int left, int right, string str, vector<string> &res)
{
    if (i == s.length())
    {
        if (bracCount == 0)
            res.push_back(str);
        return;
    }

    if (s[i] == '(')
    {
        bracCHK(s, i + 1, bracCount + 1, left, right, str + '(', res);
        if (left > 0)
        {
            while (i < s.length() and s[i] == '(' and left > 0)
            {
                i++;
                left--;
            }
            if (s[i] != '(')
                bracCHK(s, i, bracCount, left, right, str, res);
        }
    }

    else if (s[i] == ')')
    {
        if (bracCount - 1 >= 0)
        {
            bracCHK(s, i + 1, bracCount - 1, left, right, str + ')', res);
        }

        if (right > 0)
        {
            while (i < s.length() && s[i] == ')' && right > 0)
            {
                i++;
                right--;
            }

            if (s[i] != ')')
            {
                bracCHK(s, i, bracCount, left, right, str, res);
            }
        }
    }
    else
    {
        bracCHK(s, i + 1, bracCount, left, right, str + s[i], res);
    }
}

void removeInvalidParentheses(string s)
{
    vector<string> res;
    int left, right;
    misCount(s, left, right);

    if (left + right == s.length())
    {
        res.push_back("");
        return;
    }
    bracCHK(s, 0, 0, left, right, "", res);
    
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}

int main()
{
    string s = "()())()";
    removeInvalidParentheses(s);
    // vector<string> res;
}