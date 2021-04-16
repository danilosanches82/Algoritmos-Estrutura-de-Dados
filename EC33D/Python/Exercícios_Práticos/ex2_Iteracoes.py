# solução
n = int(input("Forneça a maior potência: "))
p = 1
for i in range(n + 1):
    print("2^%d é igual a %d" % (i,p))
    p = p * 2