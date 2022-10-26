# Praktikum Komputasi Numerik

Anggota Kelompok :

1. Hanafi Satriyo Utomo Setiawan (5025211195)
2. Sandyatama Fransisna Nugraha (5025211196)
3. Robby Ulung Pambudi (5025211042)

## Praktikum 1

### Soal

Anda sudah mengerti algoritma pemrosesan metode Bolzano, dan anda sudah memahami cara kerjanya. Sekarang anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode Bolzano (yang dapat menampilkan proses iteratif numerik, lengkap dengan grafik fungsinya).

### Masukan

Masukan pertama kali adalah fungsi yang berformat sebagai berikut :
`(x**2) + (3*x)` => `x^2 + 3x`

Inputan yang kedua adalah Batas Bawah dan Batas atas dari sebuah fungsi

### Keluaran

| Iterasi | x1    | x2    | x3      | f(x1)    | f(x2)   | f(x3)     |
| ------- | ----- | ----- | ------- | -------- | ------- | --------- |
| 1       | 5     | -1    | 2       | 40       | -2      | 10        |
| 2       | 2     | -1    | 0.5     | 10       | -2      | 1.75      |
| 3       | 0.5   | -1    | -0.25   | 1.75     | -2      | -0.6875   |
| 4       | 0.5   | -0.25 | 0.125   | 1.75     | -0.6875 | 0.390625  |
| 5       | 0.125 | -0.25 | -0.0625 | 0.390625 | -0.6875 | -0.183594 |

Batas Bawah 0.125 dan Batas Atas -0.0625
Hasil root setelah iterasi ke-5 adalah 0.03125

### Code

```
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
```
