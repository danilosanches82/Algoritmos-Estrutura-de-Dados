# solução
custo_gr_A = 8.39 / 400
custo_gr_B = 20.30 / 1000
if abs(custo_gr_A - custo_gr_B) <= 0.0001:
    print("As duas marcas tem preços iguais!")
elif custo_gr_A < custo_gr_B:
    print("A marca A tem melhor preço")
else:
    print("A marca B tem melhor preço.")