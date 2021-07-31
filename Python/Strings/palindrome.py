def palindrome(s):
    rev = ""
    for i in range(len(s)-1,-1,-1):
        rev+=s[i]
    if rev == s:
        print("Entered string is palindrome")
    else:
        print(("Entered string is not palindrome"))
        
palindrome('madam')