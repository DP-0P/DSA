bool areRotations(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    s1 += s1;
    int i = 0, j = s2.size() - 1;
    while (j < s1.size())
    {
        if (s1.substr(i, j - i + 1) == s2)
            return true;
        i++;
        j++;
    }
    return false;
}