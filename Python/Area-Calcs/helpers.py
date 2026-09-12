def getInt(queryString):
    while True:
        value = input(queryString)
        try:
            return int(value)
        except:
            print(f"You must input an integer.")

def getFloat(queryString):
    while True:
        value = input(queryString)
        try:
            return float(value)
        except:
            print(f"You must input a number.")

def getIndex(length):
    while length > 0:
        value = getInt("Choose the desired index: ")
        if -length <= value < length:
            return value
        else:
            print("That is not a valid index.")
    else:
        raise ValueError


def printBinary(integer):
    print(f"{integer} is")
    print(f"\t{int(integer)} in base 10")
    print(f"\t{bin(integer)} in binary")
    print(f"\t{hex(integer)} in hex")