temp_array = input().split()

min_day = 0
max_day = 0
delta = 0
for i in range(len(temp_array)):
    for j in range(i + 1, len(temp_array)):
        a = int(temp_array[j])
        b = int(temp_array[i])
        tmp_delta = a - b
        if(tmp_delta > int(delta)):
            delta = int(tmp_delta)
            min_day = (i)
            max_day = (j)
        elif tmp_delta == int(delta):
            delta_day = j - i
            a = int(max_day)
            b = int(min_day)
            delta_day_prew = a - b
            if(delta_day < delta_day_prew):
                delta = int(tmp_delta)
                min_day = (i)
                max_day = (j)
print(delta, min_day, max_day)