import  helpers
from    classes import NameList
import  sys

def main():
    filename = sys.argv[0]
    print(f"This is a {filename.rsplit('.')[1]} presentation.")

    friendCount = helpers.getInt("How many friends do you have: ")
    FriendList = NameList.newList(friendCount)

    ## ChatGPT did not supply the idea/code of using a dict for the menu with (legend, funct)
    ### tuples, but it did assist in the syntax requirements for the implementation
    ## Grok supplied the idea for lambda functions
    menuOptions = {
        1: ("Print your friend list",               lambda: print(f"Your friends are:\n{FriendList}")),
        2: ("Sort your friend list A-Z",            FriendList.sort),
        3: ("Sort your friend list Z-A",            FriendList.reverse),
        4: ("Search your friend list by substring", FriendList.searchSubstring),
        5: ("Search your friend list by full name", FriendList.searchFullName),
        6: ("Add a friend",                         FriendList.addMember),
        7: ("Edit a friend's name",                 FriendList.editMember),
        8: ("Remove a friend by index",             FriendList.removeMemberByIndex),
        9: ("Remove a friend by full name",         FriendList.removeMemberByString),
        0: ("Exit",                                 lambda: None)
    }

    while True:
        print("\nOptions:")
        for key, (legend, _) in menuOptions.items():
            print(f"{key}: {legend}")
        userChoice = helpers.getInt("\nInput: ")

        if userChoice in menuOptions:
            if userChoice == 0:
                break
            else:
                _, funct = menuOptions[userChoice]
                funct()

if __name__ == "__main__":
    main()
