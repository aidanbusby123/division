#include<stdio.h>
#include<string.h>
#define MAXLEN 100


int divd[MAXLEN/2];
int divs[MAXLEN/2];
char divdc[MAXLEN/2];
char divsc[MAXLEN/2];

int q[MAXLEN];
int m[MAXLEN/2];
int tempm[MAXLEN/2];
int temp[MAXLEN/2];
int p;
int msz;
int divdsz;
int divssz;
int div;
int i;
int n;

int main(){
	char c;
	printf("ENTER DIVIDEND: ");
	while ((c = getchar())!='\n'){
		divdc[i] = c;
		i++;
	}
	i = 0;
	printf("ENTER DIVISOR: ");
	while ((c = getchar())!='\n'){
		divsc[i] = c;
		i++;
	}
	i = 0;
	printf("what the hey");
	divdsz = strlen(divdc);
	divssz = strlen(divsc);
	msz = divssz;
	printf("processing");
	for (i = 0; i < strlen(divdc) - 1; i++){
		divd[i+MAXLEN/2-divdsz-1] = divdc[i] - '0';
	}
	for (i = 0; i < strlen(divsc) - 1; i++){
		divs[i+MAXLEN/2-divssz-1] = divsc[i] - '0';
	}
	for (i = MAXLEN/2-1; i > MAXLEN/2-msz-1; i--){
		m[i] += divs[i];
	}
	while (n < 100){
		printf("nihao");	
		while (msz > p){
			for (i = MAXLEN/2-p-1; i < MAXLEN/2-1; i++){ // Shift dividend place value to left ('add' a zero) 
				temp[i-1] = divd[i];
				if (i == MAXLEN/2-1){
					temp[i] = 0;
				}
			}
			for (i = MAXLEN/2-p; i < MAXLEN/2-1; i++){
				divd[i] = temp[i];
			}
			p++;
			if (p == msz){
	       			for(i = p; i > 0; i--){
					if (m[i] > divd[i]){
						p++;
						break;
					}
				}	
			}

		}

	
		printf("hola");
		while (msz <= p){ // Multiply m by divisor until it is greater than dividend

			for (i = MAXLEN/2-1; i > MAXLEN/2-msz-1; i--){
				tempm[i] += divs[i];
			}
			for (i = MAXLEN/2-1; i > MAXLEN/2-msz-1; i--){ // Place value operations with multiplier array. Takes care of double digit array spaces
				if (tempm[i] / 10 > 0){
					tempm[i-1] +=tempm[i]/10;
					if (i == MAXLEN/2-msz){
						msz++;
					}
				}
			}
			if (p == msz){
				int breaker;
	       			for(i = p; i > 0; i--){
					if (tempm[i] > divd[i]){
						p++;
						breaker = 1;
						break;
					}					
				}
				if (breaker == 1){
					for (i = MAXLEN/2-1; i > MAXLEN/2-divdsz-1; i--){
						divd[i] -= m[i];
						if (divd[i] < 0){
							divd[i-1] -= 1;
							divd[i] += 10;
						}
					}
	
					break;
				}	
			}
			for (i = MAXLEN/2-1; i > MAXLEN/2-msz-1; i--){
				m[i] = tempm[i];
			}
			q[p-divssz-1]++;

		
		
		}
	n++;
	}

	for (i = 99; i >= 0; i--){
		printf("%d", &q[i]);
	}
	return(0);
}
