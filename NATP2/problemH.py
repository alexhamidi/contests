xString = input()
yString = input()

y_sig = float(yString[1:12]) if yString[0] == '+' else -1*float(yString[1:12])
x_sig = float(xString[1:12]) if xString[0] == '+' else -1*float(xString[1:12])
x_exp = int(xString[14:]) if xString[13] == '+' else -1*int(xString[14:])
y_exp = int(yString[14:]) if yString[13] == '+' else -1*int(yString[14:])

x = x_sig*10**x_exp
y = y_sig*10**y_exp

check = 10**-9

userString = input()
user_exp = int(userString[14:]) if userString[13] == '+' else -1*int(userString[14:])
user_sig = float(userString[1:12]) if userString[0] == '+' else -1*float(userString[1:12])
val = user_sig*10**user_exp

add_exp = 0
add_sig = 0

if (x_exp > y_exp):
    add_exp = x_exp
    add_sig = x_sig + y_exp / (10 ** (x_exp - y_exp))
else:
    add_exp = y_exp
    add_sig = y_sig + x_exp / (10 ** (y_exp - x_exp))


#print(val, x+y)
if (x+y == 0 and val != 0) or (abs(val - (x+y)) >= check or abs((val - (x+y))/abs(x+y)) >= check):
    print("Incorrect")
else:
    print("Correct")

userString = input()
user_exp = int(userString[14:]) if userString[13] == '+' else -1*int(userString[14:])
user_sig = float(userString[1:12]) if userString[0] == '+' else -1*float(userString[1:12])
val = user_sig*10**user_exp
##print(val, x-y)
if (x-y == 0 and val != 0) or (abs(val - (x-y)) >= check or abs((val - (x-y))/abs(x-y)) >= check):
    print("Incorrect")
else:
    print("Correct")

userString = input()
user_exp = int(userString[14:]) if userString[13] == '+' else -1*int(userString[14:])
user_sig = float(userString[1:12]) if userString[0] == '+' else -1*float(userString[1:12])
val = user_sig*10**user_exp
#print(val, x*y)
if (x*y == 0 and val != 0) or (abs(val - (x*y)) >= check or abs((val - (x*y))/abs(x*y)) >= check):
    print("Incorrect")
else:
    print("Correct")

userString = input()
user_exp = int(userString[14:]) if userString[13] == '+' else -1*int(userString[14:])
user_sig = float(userString[1:12]) if userString[0] == '+' else -1*float(userString[1:12])
val = user_sig*10**user_exp
#print(val, x/y)
if (x/y == 0 and val != 0) or (abs(val - (x/y)) >= check or abs((val - (x/y))/abs(x/y)) >= check):
    print("Incorrect")
else:
    print("Correct")




