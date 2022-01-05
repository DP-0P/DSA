#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> ans;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void solvePartitions(string &input, vector<string> &output, int current)
{
    if (current == input.length())
    {
        int len = 0;
        for (auto str : output)
            len += str.length();
        if (len == input.length())
            ans.push_back(output);
        return;
    }
    for (int i = current; i < input.length(); i++)
    {
        string curr = input.substr(current, i - current + 1);
        if (isPalindrome(curr))
        {
            output.push_back(curr);
            solvePartitions(input, output, i + 1);
            output.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    string input = s;
    vector<string> output;
    solvePartitions(input, output, 0);
    return ans;
}

int main()
{
    string s = "aab";
    partition(s);
    for(int i=0;i<ans.size();i++)
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
}