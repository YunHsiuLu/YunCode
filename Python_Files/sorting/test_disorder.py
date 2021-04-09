import random
import sys
import time
class Card():
    def __init__(self, suit, number):
        self.suit = suit
        self.number = number

class Deck():
    def __init__(self):
        self.suit = ['Spade', 'Heart', 'Diamond', 'Clud']
        self.number = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
        self.cards = []
        for i in self.suit:
            for j in self.number:
                (self.cards).append(Card(i, j))
    def NormalRiffle(self):
        start = -99
        end = -99
        temp = []
        release = []
        while 1:
            start = random.randint(1, 53)
            count = random.randint(3, 26)
            end = start + count
            if (end<53):
                break
        temp = self.cards[start:end+1]
        release = self.cards[0:start] + self.cards[end+1:]
        self.cards = temp + release
        return 0
    def CutCard(self):
        temp = []
        cut1 = self.cards[0:26]
        cut2 = self.cards[26:52]
        for i in range(len(cut1)):
            temp.append(cut1[i])
            temp.append(cut2[i])
        self.cards = temp
d_normal = Deck()
n = 10
r = 0
for i in range(n):
    sys.stdout.write('\rriffle %d/%d' % (i+1,n))
    sys.stdout.flush()
    d_normal.NormalRiffle()
    if random.random() < 0.3:
        r += 1
        d_normal.CutCard()
    time.sleep(0.1)
for i in range(len(d_normal.cards)):
    print(d_normal.cards[i].suit, d_normal.cards[i].number)
print('cut card: %d times' % (r))
