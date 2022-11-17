#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

enum Constants {
    SIZE_ARRAY = 50000,
    My_NaN = 2000
 };

int main() {
    int *array = (int*) malloc(SIZE_ARRAY * sizeof(int));
    int n, m;
    scanf("%d%d", &n, &m);
    int count = 0;
    while(scanf("%d", &array[count]) != EOF) {
        count++;
        if(count >= SIZE_ARRAY) {
            int size = (count / SIZE_ARRAY) * SIZE_ARRAY;
            array = (int*)realloc(array, size * sizeof(int));
        }
    }
    short indicate = 1;
    int count_2 = count;
    int sum_b = 0, sum_j = 0;
    int m_tmp = m;
    while(count_2 > 0) {
        if(indicate) {
            int max = INT32_MIN;
            int max_num = 0;
            int one_indicate = 1;
            for(int i = 0; (i < m_tmp); i++) {
                if(i >= count || count_2 <= 0) { break; }
                if(array[i] == My_NaN) {
                    m_tmp++;
                    continue;
                }
                if(array[i] >= 0) {
                    sum_b += array[i];
                    array[i] = My_NaN;
                    count_2--;
                    one_indicate = 0;
                }
                if(max < array[i] && array[i] != My_NaN) {
                    max = array[i];
                    max_num = i;
                }
            }
            if(one_indicate) {
                sum_b += array[max_num];
                array[max_num] = My_NaN;
                count_2--;
            }
            indicate = 0;
        } else {
            int max = INT32_MIN;
            int max_num = 0;
            int one_indicate = 1;
            int m_tmp = m;
            for(int i = 0; (i < m_tmp); i++) {
                if(i >= count || count_2 <= 0) { break; }
                if(array[i] == My_NaN) {
                    m_tmp++;
                    continue;
                }
                if(array[i] >= 0) {
                    sum_j += array[i];
                    array[i] = My_NaN;
                    count_2--;
                    one_indicate = 0;
                }
                if(max < array[i] && array[i] != My_NaN) {
                    max = array[i];
                    max_num = i;
                }
            }
            if(one_indicate) {
                sum_j += array[max_num];
                array[max_num] = My_NaN;
                count_2--;
            }
            indicate = 1;
        }
    }
    if(sum_b > sum_j) {
        printf("1\n");
        fflush(stdout);
    } else {
        printf("0\n");
        fflush(stdout);
    }
}






