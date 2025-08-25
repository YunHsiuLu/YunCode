try:
    while True:
        s = input()
        count = 0
        if (s[0] == " ") : s = "*" + s[1:]
        for i in range(1, len(s)):
            if (s[i] == " ") : count += 1
            else:
                if (count >= 2) : s = s[0:i-count] + "*"*(count-1) + s[i-1:]
                count = 0
        if (count > 0) : s = s[0:len(s)-count] + "*"*count
        print(s)
except EOFError:
    pass
