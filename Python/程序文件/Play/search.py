def search(f):
    x=0
    while True:
        if f(x):
            return x
        x+=1

square=lambda x:x*x
print(10)
def inverse(f):
    return lambda y:search(lambda x:f(x)==y)

def l():
    search(lambda x:x)
    a=search

import socket 
import sys 