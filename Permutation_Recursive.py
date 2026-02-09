def permutation(string):
    
    if len(string) <= 1:
        return [string]
        
    all_per = []
    
    for i in range(len(string)):
        char = string[i]
        
        remain = string[:i] + string[i+1:]
        
        for p in permutation(remain):
            all_per.append(char + p)
          
    return all_per  

text = input("Enter a string to find the different permutations of its characters : ")
print(permutation(text))