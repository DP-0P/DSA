def reverse(s):
    rev=""
    for i in range(len(s)-1,-1,-1):
        rev+=s[i]
    print(rev)

reverse("wassup")