import helpers

operators = {
    "plus": (lambda x,y: x+y),
    "minus": (lambda x,y: x-y),
    "times": (lambda x,y: x*y),
    "divided by": (lambda x,y: x/y),
    "to the power": (lambda x,y: x**y),
    "mod": (lambda x,y: x % y)
}

var1 = helpers.getInt("Input an integer: ")
var2 = helpers.getInt("Input another integer: ")
for operator in operators:
    print(f"{var1} {operator} {var2} is {operators[operator](var1, var2)}.")