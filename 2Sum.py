def find_2sum( numbers , target ):
    list = []
    for i in range(len(numbers)):
        
        for j in range( i+1 , len(numbers)):
            if numbers[i] + numbers[j] == target:
                list.append([numbers[i] , numbers[j]])
    return list
    
    
arr = input("Enter numbers / array separated by spaces : ")

nums = [int(x) for x in arr.split(" ")]

target = int(input("Enter the target sum : "))

sum = find_2sum(nums , target)

if sum:
    print(sum)
else:
    print("No two numbers found that add up to the target")