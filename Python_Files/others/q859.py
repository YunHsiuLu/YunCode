Medalion = [
"Aspect of Combat",
"Ringmaster Scarr",
"Night Rose",
"Aspect of Speed",
"Shrouded Striker",
"Unstoppable",
"Aspect of Siphon",
"Infernal Defenses",
"The Machinist",
"Shogun X",
"Megalo Don",
"Aspect of Agility"
]

try:
    while True:
        n = int(input())
        print(Medalion[n % 12])
except EOFError:
    pass
