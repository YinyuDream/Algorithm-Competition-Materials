import sys

mp = {
    "iu": "q",
    "ei": "w",
    "uan": "r",
    "ue": "t",
    "un": "y",
    "sh": "u",
    "ch": "i",
    "uo": "o",
    "ie": "p",
    "ong": "s",
    "iong": "s",
    "ai": "d",
    "en": "f",
    "eng": "g",
    "ang": "h",
    "an": "j",
    "uai": "k",
    "ing": "k",
    "iang": "l",
    "uang": "l",
    "ou": "z",
    "ua": "x",
    "ia": "x",
    "ao": "c",
    "zh": "v",
    "ui": "v",
    "in": "b",
    "iao": "n",
    "ian": "m",
}


def translate(s):
    if len(s) == 1:
        print(s * 2, end=" ")
    elif len(s) == 2:
        print(s, end=" ")
    else:
        if s in mp:
            print(s[0] + mp.get(s), end=" ")
        elif s[1:] in mp:
            print(s[0] + mp.get(s[1:]), end=" ")
        elif s[:-1] in mp:
            print(mp.get(s[:-1]) + s[-1], end=" ")
        elif s[:2] in mp and s[2:] in mp:
            print(mp.get(s[:2]) + mp.get(s[2:]), end=" ")


def main():
    while True:
        s = sys.stdin.readline().strip()
        if not s:
            break
        for word in s.split():
            translate(word)
        print()


if __name__ == "__main__":
    main()
