vlan_num = int(input("What is your vlan number?"))

if vlan_num >= 1006 and vlan_num<=4096:
    print("Extended VLAN")

elif vlan_num >=1002 and vlan_num <= 1005:
    print("Token and FDDI VLAN")

elif vlan_num >= 2 and vlan_num <= 1001:
    print("Normal VLAN")

elif vlan_num == 1:
    print("Normal and Default VLAN")

else:
    print("Invalid VLAN")