def tree(label, branches=[]):
    for branch in branches:
        assert is_tree(branch)
    return [label] + list(branches)

def label(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) !=list or len(tree)<1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

def fib_tree(n):
    if n<=1:
        return tree(n)
    else:
        left,right=fib_tree(n-2),fib_tree(n-1)
        return tree(label(left)+label(right),[left,right])
    
def count_leaves(tree):
    if is_leaf(tree):
        return 1
    else:
        return sum([count_leaves(t) for t in branches(tree)])
    
def leaves(t):
    if is_leaf(t):
        return [label(t)]
    else:
        return sum([leaves(s) for s in branches(t)],[])

def increment_leaves(t):
    if is_leaf(t):
        return tree(label(t) + 1)
    else:
        bs = [increment_leaves(b) for b in branches(tree)]
        return tree(label(t),bs)

def increment(t):
    return tree(label(t) + 1 , [increment(b) for b in branches(t)])

def print_tree(t, indent=0):
    print(' '*indent + str(label(t)))
    for b in branches(t):
        print_tree(b,indent+1)

def print_sums(t, so_far):
    so_far = so_far + label(t)
    if is_leaf(t):
        print(so_far)
    else:
        for b in branches(t):
            print_sums(b,so_far)

def add_tree(t1, t2):
    result_label = label(t1) + label(t2)
    result_branches = [add_tree(b1,b2) for b1,b2 in zip (branches(t1),branches(t2))]
    i = len(result_branches)
    result_branches = result_branches + branches(t1)[i:]
    result_branches = result_branches + branches(t2)[i:]
    return tree(result_label, result_branches)