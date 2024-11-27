import sys

ans = 0

input_str = input()
n = int(input_str.split()[0])
k = int(input_str.split()[1])

sys.set_int_max_str_digits(50000)

curr = 0
prev = 0
for i in range(1, n+1):
    l = len(str(i))
    curr = ((10 ** l) % k) * (prev) + (i % k)
    curr = curr % k
    if (curr == 0):
        ans += 1
    prev = curr

print(ans)
