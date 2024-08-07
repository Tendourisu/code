from collections import deque

# 标识每个状态
class State:
    def __init__(self, farmer, wolf, goat, cabbage):
        self.farmer = farmer
        self.wolf = wolf
        self.goat = goat
        self.cabbage = cabbage

    def is_valid(self):
        if self.goat == self.cabbage and self.farmer != self.goat:
            return False
        if self.wolf == self.goat and self.farmer != self.wolf:
            return False
        return True

    def is_final(self):
        return self.farmer == 0 and self.wolf == 0 and self.goat == 0 and self.cabbage == 0

# 广度优先搜索
def breadth_first_search():
    start_state = State(1, 1, 1, 1)
    queue = deque([([], start_state)])

    while queue:
        path, current_state = queue.popleft()
        if current_state.is_final():
           return path + [current_state]

        for next_state in [
            State(1-current_state.farmer, current_state.wolf, current_state.goat, current_state.cabbage),
            State(1-current_state.farmer, 1-current_state.wolf, current_state.goat, current_state.cabbage),
            State(1-current_state.farmer, current_state.wolf, 1-current_state.goat, current_state.cabbage),
            State(1-current_state.farmer, current_state.wolf, current_state.goat, 1-current_state.cabbage)
        ]:
            if next_state.is_valid():
                queue.append((path + [current_state], next_state))

    return None

# 执行搜索并输出结果
result = breadth_first_search()
if result:
   for state in result:
         print(state.farmer, state.wolf, state.goat, state.cabbage)
else:
    print("No solution found")

