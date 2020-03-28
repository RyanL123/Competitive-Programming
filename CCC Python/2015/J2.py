line = input()
happy = line.count(":-)")
sad = line.count(":-(")

if happy == sad == 0:
  print("none")
elif happy == sad:
  print("unsure")
elif happy > sad:
  print("happy")
else:
  print("sad")
