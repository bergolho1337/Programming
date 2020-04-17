def f (Ci,Ce,P):
  return (P * ( Ci - Ce )) if Ci > Ce else 0

a = f(1,2,1)
b = f(2,1,1)

print(a)
print(b)
