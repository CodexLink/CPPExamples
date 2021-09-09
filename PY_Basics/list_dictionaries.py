hostnames = ["Rtr_Manila", "Rtr_QC", "Rtr_Pasig", "Rtr_Marikina"]

print(hostnames)
print(len(hostnames))
print(hostnames[0])
print(hostnames[-1])

print("List of Routers")
for host in hostnames:
    print(host)

ipAddress = {"Rtr_Manila": "192.168.0.1", "Rtr_QC": "192.168.1.1"}
print(ipAddress)
print(ipAddress["Rtr_Manila"])
ipAddress["Rtr_Pasig"] = "192.168.2.1"
print(ipAddress)
ipAddress["Rtr_Manila"] = ["192.168.0.1", "10.0.0.1"]
print(ipAddress)

print("List of Routers and Assigned IP Addresses.")

for ip in ipAddress:
    print(ip, ipAddress[ip])