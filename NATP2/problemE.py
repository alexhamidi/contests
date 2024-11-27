import collections
p, n = map(int, input().split())

events = []


cars = collections.deque()

for _ in range(n):
    t, f, d = input().split()
    t = int(t)
    f = int(f)
    cars.append([t, f, d])
    collections.heapq.heappush(events, t)

left = [collections.deque() for _ in range(n)]
right = [collections.deque() for _ in range(n)]
valid = True

A_valid_left = [-1 for _ in range(n)]
B_valid_left = [-1 for _ in range(n)]
A_valid_right = [-1 for _ in range(n)]
B_valid_right = [-1 for _ in range(n)]


curr = 0
while (events):
    curr = collections.heapq.heappop(events)
    print(curr)
    if len(cars) > 0 and cars[0][0] == curr:
        #process car then pop from cars
        print(car)
        newCar = cars.popleft()
        if newCar[2] == 'R':
            minL = float('inf')
            for q in range(p):
                if len(left[q]) < minL:
                    minL = len(left[q])
                    currMinQ = q

            left[currMinQ].append(newCar)

        else:
            minL = float('inf')
            for q in range(p):
                if len(right[q]) < minL:
                    minL = len(right[q])
                    currMinQ = q
            right[currMinQ].append(newCar)
    #Update state of game
    for i in range(p):
        if curr > A_valid_left and len(left[i]) > 0:
            #left car fills up pump at column i
            car = left.popleft()
            if curr > B_valid_left:
                B_valid_left[i] = curr+car[1]
            else:
                A_valid_left[i] = curr+car[1]
            collections.heapq.heappush(events, car[2])

        if curr > A_valid_right and len(right[i]) > 0:
            #left car fills up pump at column i
            car = right.popleft()
            if curr > B_valid_right:
                B_valid_right[i] = curr+car[1]
            else:
                A_valid_right[i] = curr+car[1]
            collections.heapq.heappush(events, car[2])
print(curr)
