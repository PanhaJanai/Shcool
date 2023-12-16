import random

hiragana = ['あ', 'い', 'う', 'え', 'お', 'か', 'き', 'く', 'け', 'こ', 'さ', 'し', 'す', 'せ', 'そ', 'た', 'ち', 'つ', 'て', 'と', 'な', 'に', 'ぬ', 'ね', 'の', 'は', 'ひ', 'ふ', 'へ', 'ほ', 'ま', 'み', 'む', 'め', 'も', 'や', 'ゆ', 'よ', 'ら', 'り', 'る', 'れ', 'ろ', 'わ', 'を', 'ん']
romaji = ['a', 'i', 'u', 'e', 'o', 'ka', 'ki', 'ku', 'ke', 'ko', 'sa', 'shi', 'su', 'se', 'so', 'ta', 'chi', 'tsu', 'te', 'to', 'na', 'ni', 'nu', 'ne', 'no', 'ha', 'hi', 'fu', 'he', 'ho', 'ma', 'mi', 'mu', 'me', 'mo', 'ya', 'yu', 'yo', 'ra', 'ri', 'ru', 're', 'ro', 'wa', 'wo', 'n']
rom = list(romaji)

hiragana_romaji_dict = dict(zip(hiragana, romaji))
print(hiragana_romaji_dict)

hira = None
user = 0
ran_romaji = 1

while user != ran_romaji:

    try:
        user = hiragana_romaji_dict[hira]
    except KeyError:
        pass
    ran_romaji = random.choice(rom)

    print(ran_romaji)
    hira = input()

    if hira not in hiragana:
        hira += '\n'
        hira = hira[:-1]

    if hira == 'q':
        break

else:
    rom = list(romaji)