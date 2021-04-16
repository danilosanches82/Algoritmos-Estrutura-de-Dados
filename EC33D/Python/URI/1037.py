x = float(input())
#[0,25], (25,50], (50,75], (75,100]

if x >=0 and  x <= 25:
    print("Intervalo %s" % "[0,25]")
elif x>25 and x<=50:
    print("Intervalo %s" % "(25,50]")
elif x > 50 and x <= 75:
    print("Intervalo %s" % "(50,75]")
elif x > 75 and x <= 100:
    print("Intervalo %s" % "(75,100]") 
else:
    print("Fora de intervalo")    

     
