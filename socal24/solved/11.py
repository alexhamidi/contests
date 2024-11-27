n = int(input())

for i in range(n):
    valid = True
    w = input()
    a = input()
    s = {c for c in w}
    for c in a:
        if c not in s:
            print("NO")
            valid = False
            break
    if valid:
        print("YES")
