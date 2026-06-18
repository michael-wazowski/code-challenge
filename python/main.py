print("Loading and processing test.data")

# read lines from test.data into list obj
with open("test.data", "r+") as f:
    lines = f.readlines()
f.close()

# prune commented and empty lines
data = []
for line in lines:
    if line.startswith("#") or line == "\n":
        continue
    data.append(line.replace("\n",""))

# process data into "table" keyed by name - will use dict
table = {}
for d in data:
    obj = d.split(",")
    # clean up white space from values
    for value in range(len(obj)):
        obj[value] = obj[value].strip()

    # create table entry and remove from source
    table[obj[1]] = {"dob":obj[0]}
    if len(obj) < 5:
        if obj[2] in ("y", "n"):
            table[obj[1]]["colour"] = None
            table[obj[1]]["likes-peas"] = obj[2]
            table[obj[1]]["dogs-or-cats"] = obj[3]
    else:
        table[obj[1]]["colour"] = obj[2] if obj[2] != "" else None
        table[obj[1]]["likes-peas"] = obj[3] if obj[3] != "" else None
        table[obj[1]]["dogs-or-cats"] = obj[4] if obj[4] != "" else None

# sort data by key
table = dict(sorted(table.items()))

print("test.data loaded and processed, printing to stdout the requested information\n")

# print data to stdout
for name, data in table.items():
    print("Name: %s" % name)
    for key, value in data.items():
        print("%s: %s" % (key, str(value)))
    print()

# print pea-lovers names
for name in table:
    if table[name]["likes-peas"] == "y":
        print(name)
print()

# take user input to get info by name
run = True
while run: # loop to run until user stops
    target = input("Enter a name to get the data for: ")

    # check if exit conditions are met
    if target.lower() == "exit" or len(target) == 0:
        run = False
        continue
    
    # look for target name in table
    # alternatively could use raise to throw an exception and no loop
    if target in table:
        print("Name: %s" % target)
        for key, value in table[target].items():
            print("%s: %s" % (key, str(value)))
    else:    
        print("Name not found in data, please try again")
    print()
    
