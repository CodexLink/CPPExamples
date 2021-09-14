from os import system
system("clear")

firstName: str = input("What is your first name? ")
lastName: str = input("What is your last name? ")
location: str = input("What is your location? ")
userAge: int = input("What is your age? ")

print(f"Hi {firstName} {lastName}! Your location is {location} and you are {userAge} years old.")

exit(0) # explicitly declared.