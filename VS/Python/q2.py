from colorama import Fore, Back, Style

def check_password(in_str):
    if len(in_str) >= 4:
        if True in [x.isdigit() for x in in_str]:
            if True in [x.isupper() for x in in_str]:
                if not(' ' in in_str) and not('/' in in_str):
                    if not in_str[0].isdigit():
                        return True
                    else:
                        print("First character cannot be a number")
                else:
                    print("Password should not contain SPACE or SLASH")
            else:
                print("Password must contain a capital letter")
        else:
            print("Password must contain a digit")
    else:
        print("Password must have more than 4 characters")    
    return False

in_str = input("Enter Password : ")

while (not check_password(in_str)):
    print(Fore.RED + "Invalid password. Please Retry "+Fore.WHITE)
    in_str = input("Enter Password : ")

print(Fore.GREEN + "Valid Password" +Fore.WHITE)

