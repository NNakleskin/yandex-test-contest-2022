n_m = input().split()
tmp = input().split()
n = int(n_m[0])
m = int(n_m[1])
array = list()
array = [int(numeric_string) for numeric_string in tmp]


sum_boka = 0
sum_joka = 0
indicate = 0
count = int(n_m[0]) - 1
while(count >= 0):
    if(indicate == 0):
        for i in range(m):
            if(count <= 0):
                break
            if(array[i] >= 0):
                sum_boka += array[i]
                array.remove(array[i])
                count -= 1
            indicate = 1

    else:
        for i in range(m):
            if(count <= 0):
                break
            if(array[i] >= 0):
                sum_boka += array[i]
                array.remove(array[i])
                count -= 1
            indicate = 0

if(sum_boka > sum_joka):
    print(1)
else:
    print(0)