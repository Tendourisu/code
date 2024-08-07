def eight(x):
    if x==0:return 0
    else:
        ex,last=x//10,x%10
        if last==8:
            return 1+eight(ex)
        else: 
            return eight(ex)
