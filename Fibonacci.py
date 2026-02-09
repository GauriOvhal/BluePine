n = int(input("How many fibonacci terms do you want ? "))

n1 , n2 = 0, 1

count = 0

if n < 0:
    print("Invalid ! Enter positive integers for terms of fibonacci series")
    
elif n == 1:
    print(f"Fibonacci sequence : {n1}")
    
else:
    print("Fibonacci series : ")
    while count < n:
        print(n1 , end = " ")
        next = n1 + n2
        n1 = n2
        n2 = next
        count += 1