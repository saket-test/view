# TODO
height = "0"
while height < "1" or height > "8":
    height = input("Height: ")
h = int(height)
for i in range(h):
    print(" " * (h - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))
