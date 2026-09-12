from helpers import getFloat, getInt

def calcTriArea():
    base = getFloat("Give me the base of your triangle: ")
    height = getFloat("Give me the height of your triangle: ")
    return base * height / 2

def calcRectArea():
    side1 = getFloat("Give me the length of one side: ")
    side2 = getFloat("Give me the length of the other side: ")
    return side1 * side2

def calcSqrArea():
    side = getFloat("Give me your square's side: ")
    return side ** 2

def main():
    areaMenu = {
    1: ("Triangle", calcTriArea),
    2: ("Square", calcSqrArea),
    3: ("Rectangle", calcRectArea),
    0: ("Exit", lambda: None)
}
    while True:
        print("\nOptions:")
        for key, (legend, _) in areaMenu.items():
            print(f"{key}: {legend}")
        userChoice = getInt("\nInput: ")

        if userChoice in areaMenu:
            if userChoice == 0:
                break
            else:
                print("\n", end="")
                _, funct = areaMenu[userChoice]
                area = funct()
                print(f"The area is {area}")
        else:
            print("Not a valid choice.")
    print("Goodbye!")


if __name__ == "__main__":
    main()