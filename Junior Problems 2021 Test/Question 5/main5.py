
# rows
m = int(input())
# cols
n = int(input())

list = []
list_row = []

i = 0
while i < n:
    list_row.append("B")
    i += 1

i = 0
while i < m:
    list.append(list_row.copy())
    i += 1

# amount of following steps
k = int(input())

i = 0
# stores steps
steps = []
while i < k:
    steps.append(input())
    i += 1


for x in steps:
    temp_str = str(x)

    # row
    if temp_str[:1] == "R":
        # row index
        y = int(temp_str[1:])-1

        i = 0
        while i < n:

            # every col index because : (e.g. row 2)
            # 1 2 3 4 5
            # 2 r r r r
            # 3
            # 4
            # 5

            # if black -> gold, else gold -> black
            if list[y][i] == "B":
                list[y][i] = "G"
            else:
                list[y][i] = "B"

            i += 1

    # col
    if temp_str[:1] == "C":

        # col index
        x = int(temp_str[1:])-1

        i = 0
        while i < m:

            # every row index because : (e.g. col 2)
            # 1 2 3 4 5
            # 2 c
            # 3 c
            # 4 c
            # 5 c

            # if black -> gold, else gold -> black

            if list[i][x] == "B":
                list[i][x] = "G"
            else:
                list[i][x] = "B"

            i += 1


total_gold = 0
i = 0

# goes through whole list. If cell is gold, add 1 to total gold.
for a in range(len(list)):
    for b in range(len(list[a])):
        if list[a][b] == "G":
            total_gold += 1


# End output
print(total_gold)
