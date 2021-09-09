from os import system
from typing import List, Optional
from io import TextIOWrapper

system("clear") # Clearing terminal output before demo.

file: TextIOWrapper = open("devices.txt", "r") # ! Typed.
devices: List[Optional[str]] = []

for item in file:
    item = item.strip()
    devices.append(item) # Added.
file.close()

print(devices)

exit(0) # Explicitly declared.