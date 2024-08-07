# 定义状态转移
transitions = [
    (1, 0, 0, 1),
    (0, 1, 0, 1),
    (0, 0, 1, 1),
    (1, 0, 0, 0),
    (0, 1, 0, 0),
    (0, 0, 1, 0),
    (0, 0, 0, 1),
    (0, 0, 0, 0)]
def is0_1(i):
    if i==0 or i==1:
        return True
    return False

def is_safe(state):
    if (state[0] == state[1] != state[3]) or (state[1] == state[2] != state[3]):
        return False
    if (is0_1(state[0]) and is0_1(state[1]) and is0_1(state[2]) and is0_1(state[3])):
        return True
    return False

def dfs(state, path):
    if state == (0, 0, 0, 0):
        for p in path:
            print(p)
        return True
    for t in transitions:
        if state[3] != t[3]:
            continue
        if state[3]:
            new_state = tuple(s - m   for s, m in zip(state, t))
        else:
            tem = [s + m  for s, m in zip(state, t)]
            tem.pop()
            tem.append(1)
            new_state = tuple(tem)
        if is_safe(new_state) and new_state not in path:
            path.append(new_state)
            if dfs(new_state, path):
                return True
            path.pop()

    return False

initial_state = (1, 1, 1, 1)

dfs(initial_state, [initial_state])
