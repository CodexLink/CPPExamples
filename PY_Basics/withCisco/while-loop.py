from os import system
from typing import Union
# system("clear") Disabled for demo purposes.

x: Union[int, str] = input("Enter a number to count to: ")
y: int = 1 # This is not a constant on runtime.

while True:
    if x == "q" or x == "quit":
        break
    
    x = int(x)
    while True:
        print(y)
        y += 1 # Optimization Added.

        if y > x:
            break

    break # Add this or inf loop.
exit(0) # explicitly declared.