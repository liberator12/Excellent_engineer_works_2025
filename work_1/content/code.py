import random

# 生成五个随机数（unsigned int32 范围：0 ~ 2^32 - 1）
random_numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]

# 写入 input.txt 并在终端打印
with open('input.txt', 'w') as f:
    for num in random_numbers:
        f.write(f"{num} ")
        print(num, end=" ")
    print()  # 换行

# 从 input.txt 读取数据并计算均值
with open('input.txt', 'r') as f:
    numbers = list(map(int, f.read().split()))
    mean = sum(numbers) / len(numbers)

# 写入 output.txt 并在终端打印均值
with open('output.txt', 'w') as f:
    f.write(f"{mean:.6f}")  # 保留 6 位小数，可根据需求调整
    print(f"均值为: {mean:.6f}")