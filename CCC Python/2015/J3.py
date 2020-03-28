word = input()
vowels = ["a","e","i","o","u"]
difference = 100
closest_index = 0
for i in range (0,len(word)):
    if word[i] not in vowels:
        print(word[i], end="")
        for j in range (0,5):
            if abs(ord(word[i])-ord(vowels[j])) < difference:
                difference = abs(ord(word[i]) - ord(vowels[j]))
                closest_index = j
        difference = 100
        print(vowels[closest_index], end="")

        if chr(ord(word[i])+1) not in vowels:
            if ord(word[i]) != 122:
                print(chr(ord(word[i])+1), end="")
            else:
                print(word[i],end="")
        else:
            print(chr(ord(word[i])+2), end="")
    else:
        print(word[i], end="")