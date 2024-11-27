import math
s, e, n = map(int, input().split())
timeList = []
maxVal = float('-inf')
for _ in range(n):
    m, h = map(int, input().split())
    timeList.append([h, m])
    maxVal = max(maxVal, m)
valid = maxVal >= s

timeList.sort()
res = 0
end = e
for i in range(len(timeList)):
    start = timeList[i][1]
    if start >= s:
        start = s
    if start > end:
        time = timeList[i][0]
        res += time*math.log(end/start, 1/2)
        end = start
    if end == s:
        break
res = res if valid else -1
print(res)


