n = int(input())
first = 1
last = n

mid = int(n/2)

sum_first_n = mid*(mid+1)

if n%2==1:
    sum_first_n+=mid+1
print(sum_first_n)
