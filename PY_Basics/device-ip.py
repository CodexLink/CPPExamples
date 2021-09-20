# python3
# # Introduction to Devnet Quiz by Janrey Tuazon Licas. | Created on 09/03/2021 — 10:12pm

if __name__ == "__main__":

    from os import system  # Add Clear Screen before the Demo.
    from typing import Final, List

    system("CLS")  # ignore subprocess instead of os.system.

    # # What we can do here is basically pack it in tuple since the statement says respectively, so it has to be pair.
    # # But at the same time, is in the list.
    # *  					  RouterName, RouterIPAddress
    DEV_ROUTERS_IP: Final[List[tuple[str, str]]] = [
        ("R1", "10.0.0.1"),
        ("R2", "10.0.0.2"),
        ("R3", "10.0.0.3"),
    ]

    for each_dev in DEV_ROUTERS_IP:
        print( # We cannot do one-liner here.
            "The device router `%s` has an assigned IP address of %s."
            % (each_dev[0], each_dev[1])
        )

raise SystemExit("Created by Janrey Licas | CPE028-CPE41S3")
