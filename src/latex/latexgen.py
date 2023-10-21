def latex_matrix_2x2(l):
    if (l == [[],[]]): return

    print("$\\begin{pmatrix}")
    print("%.2f & %.2f \\\\" % (l[0][0], l[0][1]))
    print("%.2f & %.2f \\\\" % (l[1][0], l[1][1]))
    print("\\end{pmatrix}$")


def latex_matr_2x2(l):
    if (l == [[],[]]): return

    print("$\\begin{pmatrix}")
    print("%d & %d \\\\" % (l[0][0], l[0][1]))
    print("%d & %d \\\\" % (l[1][0], l[1][1]))
    print("\\end{pmatrix}$")


def latex_vector(v):
    if (v == []): return
    print("$\\begin{pmatrix}", end="")
    print(" %d & %d " % (v[0], v[1]), end="")
    print("\\end{pmatrix}$")


#inputs matrix from file
f = open('Z:\practlinal_lab2\src\latex\data5.txt', 'r')
lines = [line for line in f]
print("Примеры преобразования точек:")
print()
for i in range(len(lines)):
    m = [[float(num) for num in line.split()] for line in lines[2*i:2*i+2:]]
    
    latex_vector(m[0])
    print("$\\rightarrow$")
    latex_vector(m[1])
    


