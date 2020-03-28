word = input()

longest_palindrome = 0

for i in range(len(word)):
  for j in range(len(word)+1):

    substring = word[i:j]
    reversed_substring = list(substring)
    reversed_substring.reverse()
    reversed_substring = "".join(reversed_substring)

    if substring == reversed_substring and len(substring) > longest_palindrome:
      longest_palindrome = len(substring)

print(longest_palindrome)
