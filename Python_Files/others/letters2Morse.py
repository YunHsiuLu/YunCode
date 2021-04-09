MORSE = {"A": ".-","B": "-...","C": "-.-.","D": "-..",
"E": ".","F": "..-.","G": "--.","H": "....",
"I": "..","J": ".---","K": "-.-","L": ".-..",
"M": "--","N": "-.","O": "---","P": ".--.",
"Q": "--.-","R": ".-.","S": "...","T": "-",
"U": "..-","V": "...-","W": ".--","X": "-..-",
"Y": "-.--","Z": "--.."}

words = ['gig', 'zib', 'kpe', 'mip']
s = []
for i in range(len(words)):
    temp = ''
    for c in words[i]:
        temp += MORSE[c.upper()] + " "
    s.append(temp)
print(s)
l = []
for i in range(len(s)):
    ctext = ""
    detext = ""
    for c in s[i]:
        if c != " ":
            ctext += c
        else:
            detext += list(MORSE.keys())[list(MORSE.values()).index(ctext)]
            ctext = ""
    l.append(detext.lower())
print(l)