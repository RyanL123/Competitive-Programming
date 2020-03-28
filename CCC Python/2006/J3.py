words = []
counter = 0
while True:
  a = input()
  if a == "halt":
    break
  words.append(a)

letters = [["a","b","c"],["d","e","f"],["g","h","i"],["j","k","l"],["m","n","o"],
["p","q","r","s"],["t","u","v"],["w","x","y","z"]]

for i in range(len(words)):
  for j in range(len(words[i])):
    if words[i][j] in "adgjmptw":
      counter+=1
    elif words[i][j] in "behknqux":
      counter+=2
    elif words[i][j] in "cfilorvy":
      counter+=3
    elif words[i][j] in "sz":
      counter+=4

    if j != len(words[i])-1:
      if words[i][j] == words[i][j+1]:
        counter+=2
      else:
        for k in range(len(letters)):
          if words[i][j] in letters[k] and words[i][j+1] in letters[k]:
            counter+=2
            break
  print(counter)
  counter = 0
