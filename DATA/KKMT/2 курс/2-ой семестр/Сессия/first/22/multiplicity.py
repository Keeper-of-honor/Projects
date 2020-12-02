string_set = {"Nicholas", "Michelle", "John", "Mercy"}  
print(string_set)

A = {1, 2, 3}
A = set('qwerty')
print(A)

a = {1, 2, 3}
b = {3, 2, 3, 1}
print(a == b)   #Выводит True, так как == это оператор сравнения

a = {1, 2, 3}
b = {3, 2, 3, 1, 4}
print(a == b)

primes = {2, 3, 5, 7, 11}
for num in primes:
    print(num)

A = {1, 2, 3}
print(1 in A, 4 not in A)
A.add(4)

print(1 in A, 4 not in A)
A.add(4)

months = set(["Jan", "Feb", "March", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"])
 
for m in months:  
    print(m)


months = set(["Jan", "Feb", "March", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"])
 
print("May" in months) # находится ли стока в можестве 

