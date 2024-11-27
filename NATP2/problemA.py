n = int(input())

curr = "None"
i = 0
prev = input()
none = True

while (i < n):
    if i < n-1:
        curr = input()
    if (prev != "Present!" and i == n-1) or (curr != "Present!" and prev != "Present!"):
        print(prev)
        none = False
    prev = curr
    i += 1

if (none == True):
    print("No Absences")
