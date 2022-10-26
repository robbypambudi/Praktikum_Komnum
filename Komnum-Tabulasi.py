import matplotlib.pyplot as plt
import numpy as np
from tabulate import tabulate

def bolzano_method(func, a, b, it):
    i = 1
    ite = int(it)
    def f(x):
        f = eval(func)
        return f
    ListData = [['Iterasi  ', '  x1  ', '  x2  ', '  x3  ', '  f(x1)  ', '  f(x2)  ', '  f(x3)  ']]
    while it > 0:
        c = (b+a)/2
        ListData.append([i,a,b,c,f(a),f(b),f(c)])
        i = i + 1
        if f(a) * f(b) >= 0:
            print("No root or multiple roots present")
            quit()

        elif f(c) * f(a) < 0:
            b = c

        elif f(c) * f(b) < 0:
            a = c
        else:
            print("Error happens")
            quit()
        ans = (b+a)/2
        it -= 1


    print(tabulate(ListData, headers="firstrow", tablefmt="github"))

    print(f"Batas Bawah {a} dan Batas Atas {b}")
    print(f"Hasil root setelah iterasi ke-{ite} adalah {ans}")


def main () :
  function = input("Masukan Fungsi  : ")
  a = input("Batas Bawah: ")
  b = input("Batas Atas : ")
  iteration = input("Jumlah Iterasi: ")

  x = np.linspace(-10,10,num = 1000)
  y = eval(function)
  plt.plot(x, y)
  plt.show()

  bolzano_method(function, float(a), float(b), float(iteration))

if (__name__ == "__main__"):
  main()