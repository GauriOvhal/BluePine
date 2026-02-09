def backtrack(chars, start, end):
    if start == end:
        print("".join(chars))
    else:
        for i in range(start, end + 1):
            chars[start], chars[i] = chars[i], chars[start]
            
            backtrack(chars, start + 1, end)
            
            chars[start], chars[i] = chars[i], chars[start]

s = input("Enter a string to find all the permutations of the characters in it : ")

chars_list = list(s)

backtrack(chars_list, 0, len(s) - 1)