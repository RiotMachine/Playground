def bubbleSort(myArray):
    if len(myArray) > 1:
        isNotSorted = True
        while (isNotSorted):
            isNotSorted = False
            for index in range(0, len(myArray) - 1):
                if myArray[index] > myArray[index + 1]:
                    tempObj = myArray[index]
                    myArray[index] = myArray[index + 1]
                    myArray[index + 1] = tempObj
                    isNotSorted = True
    return myArray


def binarySearch(myArray, targetObject):
    if not myArray:
        return None
    halfArrayLen = int(len(myArray) / 2)
    middleItem = myArray[halfArrayLen]
    if targetObject == middleItem:
        return middleItem
    elif targetObject < middleItem:
        return binarySearch(myArray[0:halfArrayLen], targetObject)
    else:
        return binarySearch(myArray[(halfArrayLen + 1):], targetObject)


def main():
    myArray = bubbleSort(['b', 'a', 'c', 'f', 'e'])
    targetObject = input("Input a string for which to search: ")
    isFound = bool(binarySearch(myArray, targetObject))
    print(f"{targetObject} is in the array: {isFound}")

if __name__ == "__main__":
    main()
