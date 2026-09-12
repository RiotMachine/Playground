import helpers
import collections

## Credit to timgeb for his suggestion
## https://stackoverflow.com/questions/36688966/let-a-class-behave-like-its-a-list-in-python
class NameList(collections.UserList):
    @classmethod
    def newList(cls, length):
        newList = []
        for x in range(length):
            name = input(f"Give me name {x+1}: ")
            newList.append(name.upper())
        return cls(newList)

    ## Helpful for understanding this dunder method
    ## https://www.digitalocean.com/community/tutorials/python-str-repr-functions
    def __str__(self):
        string = ""
        ## Cheers to Ferdinand for the idea on skipping the final iteration
        ## https://stackoverflow.com/questions/1630320/what-is-the-pythonic-way-to-detect-the-last-element-in-a-for-loop
        first = True
        for fullName in self.data:
            if first:
                first = False
            else:
                string += "\n"
            string += fullName.title()
        return string

    def addMember(self):
        index = helpers.getIndex(len(self)+1)
        newName = input("Give me the new name: ")
        self.insert(index, newName.upper())

    def editMember(self):
        try:
            index = index = helpers.getIndex(len(self))
            oldVal = input("What value do you want to change: ")
            newVal = input("What do you want to change it to: ")
            self[index] = self[index].replace(oldVal.upper(), newVal.upper())
        except ValueError:
            print("Your list is empty.")

    def searchSubstring(self):
        searchString = input("Give me a string to search for: ")
        counter = 0
        for name in self:
            if searchString.upper() in name:
                counter += 1
        print(f"{searchString} appears in {counter} names.")

    def searchFullName(self):
        searchName = input("Give me a full name to search for: ")            
        print(f"There are {self.count(searchName.upper())} instances of {searchName}.")

    def removeMemberByIndex(self):
        try:
            index = helpers.getIndex(len(self))
            self.pop(index)
        except ValueError:
            print("Your list is empty.")

    def removeMemberByString(self):
        deleteString = input("Give me a full name to remove: ")
        try:
            self.remove(deleteString.upper())
        except ValueError:
            print(f"There is no {deleteString} in your list.")