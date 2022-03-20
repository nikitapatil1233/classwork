def num_series(n):
    if n <= 0:
        print("Invalid Input")
    else:
        sum = 0
        for i in range(1, n):
            sum = sum + i
            print(i, end="+")
        print(n,'=', sum+n, sep='') 

num_series(int(input("Enter the number: ")))


