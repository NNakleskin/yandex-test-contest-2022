#include <iostream>
#include <cstdlib>

using namespace std;

enum Constants { SIZE_ARRAY = 1000 };

int main() {
    int *array = (int*) malloc(SIZE_ARRAY * sizeof(int));
    long long count = 0;
    while(scanf("%d", &array[count]) != EOF) {
        count++;
        if(count >= SIZE_ARRAY) {
            long long unsigned int size = (count / SIZE_ARRAY) * SIZE_ARRAY;
            array = (int*)realloc(array, size * sizeof(int));
        }
    }
	if(count < 2) {
        return 0;
    }
    long long min_day = 0, max_day = 1, delta = array[1] - array[0];
    for(long long i = 0; i < count - 1; i++) {
        for(long long j = i + 1; j < count; j++) {
            long long tmp_delta = array[j] - array[i];
            if(tmp_delta > delta) {
                delta = tmp_delta;
                min_day = i;
                max_day = j;
            } else if(tmp_delta == delta) {
                long long delta_day = j - i;
                long long delta_day_prew = max_day - min_day;
                if(delta_day < delta_day_prew) {
                    delta = tmp_delta;
                    min_day = i;
                    max_day = j;
                } else if(max_day > j && delta_day == delta_day_prew) {
                    delta = tmp_delta;
                    min_day = i;
                    max_day = j;
                }
            }
        }
    }
    printf("%d %d %d\n", delta, min_day, max_day);
    fflush(stdout);
}


