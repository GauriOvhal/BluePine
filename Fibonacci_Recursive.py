def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


num = int(input("How many terms do you want in the fibonacci series ? "))

if num <= 0:
    print("Please enter a positive integer")
else:
    print(f"Fibonacci sequence up to the {num}-th term:")
    for i in range(num):
        print(fibonacci(i))
