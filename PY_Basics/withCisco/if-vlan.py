from os import system
from typing import Final
system("clear")

nativeVLAN : Final[int] = 1
dataVLAN : Final[int] = 1 # ! This was changed!

if nativeVLAN == dataVLAN:
    print("The native VLAN and the data VLAN are the same.")
else:
    print("The native VLAN and the data VLAN are different.")

exit(0) # explicitly declared.