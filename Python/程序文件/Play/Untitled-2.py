def find_max_number(m, n, integers):
    # 对整数列表进行排序，自定义排序规则
    sorted_integers = sorted(integers, key=lambda x: x * (m // len(x) + 1), reverse=True)

    # 构建新的整数，保证位数不超过m
    result = ""
    for num in sorted_integers:
        if len(result) + len(num) <= m:
            result += num

    return result

# 读取输入
m = int(input())
n = int(input())
integers = input().split()

# 输出结果
output = find_max_number(m, n, integers)
print(output)