#include <stdio.h>

int main(void){
	int N;
	double total = 1.0;
    int input;
    int MAX = -1;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%f", &input);
		
		total *= input;
		if (total > MAX)
			MAX = total;
		if (total < 1.0)
			total = 1.0;
	}
    
	printf("%.3lf", total);
	return 0;
}