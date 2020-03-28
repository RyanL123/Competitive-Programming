# gets k value
k = int(input())

# gets encrypted word
word = input()

# initializes output string as empty
output = ""

# loops through every letter of the word
for i in range(1, len(word)+1):

    # gets the current S
    s = 3*i + k

    # if the character decoded with S is before A, revert back to Z
    if (ord(word[i-1])-s) < 65:

        output += chr(ord(word[i-1])+26-s)

    # else decrypt the current character
    else:
        output += chr(ord(word[i-1])-s)

print(output)

