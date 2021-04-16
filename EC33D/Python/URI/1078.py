x, y = input().split()
x = int(x)
y = int(y)

if x > y:
  if x % y == 0:
      print("Sao Multiplos")
  else:
      print("Nao sao Multiplos")    
else:
  if y % x == 0:
      print("Sao Multiplos")
  else:
      print("Nao sao Multiplos")    