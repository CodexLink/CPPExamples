from os import system
from typing import Optional
system("clear")

device_name: Optional[str] = "" # PEP-8 please.

with open("devices.txt", "a") as IOWriter: # Use a instead of w+ or w.
    while True:
        device_name = input("Enter device name to append: ")

        if device_name in ["exit", "e"]:
            break

        IOWriter.write(device_name + "\n") # IO doesn't add '\n'.
    print("Done")

exit(0) # Explicitly declared.