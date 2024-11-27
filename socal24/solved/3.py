n, m = map(int, input().split())

d = list(map(int, input().split()))
queries = []
q = {}
last = 0
for _ in range(m):
    c, v = input().split()
    v = int(v)
    queries.append([c, v])
    if c == 'X':
        q[v] = 0
    else:
        last = max(last, v)

curr = {i for i in d if i not in q}
#build initial dp
dp = [float('inf') for i in range(last+1)]
dp[0] = 0
res = []
for i in range(1, last+1):
    for c in curr:
        if i-c >= 0:
            dp[i] = min(1+ dp[i-c], dp[i])

for i in range(len(queries)-1, -1, -1):
    c, v = queries[i]
    if c == 'X':
        #change dp
        for i in range(1, last+1):
            if i-v >= 0:
                dp[i] = min(1+ dp[i-v], dp[i])

    if c == 'Q':
        #query for v
        res.append(dp[v])
for i in range(len(res)-1, -1, -1):
    if res[i] == float('inf'):
        print(-1)
    else:
        print(res[i])
