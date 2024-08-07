def area(r,constant):
    assert r>0,'a length must be positive'
    return r*r*constant
print(3)

def identity(k):
    return k

def cube(k):
    return pow(k,3)

def summation(n,term):
    total=0;k=1
    while k<=n:
        total,k=total+term(k),k+1
    return total
lambda n:(lambda f: f(n,f))(lambda n,fact:1 if n==1 else n*fact(n-1,fact))

def f(x, y=[]):
    y.append(x)
    return sum(y)
