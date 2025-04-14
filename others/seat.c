#include<stdio.h>
#include <stdlib.h> 
#include<time.h>

void change();
void ran_num();

int main(){
	
	int mod;
	char con = '\0';
	while(1){
		printf("©‚≈“or¥´Æy¶Ï(0/1):"); 
		scanf("%d", &mod);
		if(mod == 0){
			ran_num();
		}
		else{
			change();
		}
		printf("\n\nƒ~ƒÚ(0/any key):");
		scanf(" %c", &con);
		if(con == '0'){
			break;
		}
		system("cls");
	}
	
	return 0;
} 

void change() {
    int spe, seat[36], r = 0;
    srand(time(NULL));
    for(int i = 0; i < sizeof(seat)/sizeof(seat[0]); i++){
        seat[i] = i + 1;
    }
    printf("´¸©w¶Ï∏m?(0/1):");
    scanf("%d", &spe);
    if(spe == 0){
    	printf("===============================\n");
        for(int i = 0; i < 6; i++){
            r = 0;
            while(r < 6){
                int ran = rand() % 36;
                if(seat[ran] != 0){
                    printf("| %02d ", ran + 1);
                    seat[ran] = 0;
                    r++;
                }
            }
            printf("|\n===============================\n");
        }        
    } else {
        int row, Seat[6][6] = {0};
        printf("¶≥¥X¶C≠n´¸©w:");
        scanf("%d", &row);
        int ROW[row];
        printf("´¸©w™∫¶C:\n");
        for(int i = 0; i < row; i++){
            scanf("%d", &ROW[i]);
            ROW[i]--;
        }
        printf("øÈ§J¶C™∫´¸©wÆy∏π(•¥∫°6ÆÊ,∏ıπLøÈ§J0,™≈ÆÊπj∂},ª›∑”≠Ë≠ËøÈ§J™∫∂∂ß«):\n");
        for(int i = 0; i < row; i++){
            scanf("%d %d %d %d %d %d", &Seat[ROW[i]][0], &Seat[ROW[i]][1], &Seat[ROW[i]][2], &Seat[ROW[i]][3], &Seat[ROW[i]][4], &Seat[ROW[i]][5]);
        }
        for(int i = 0; i < 6; i++){
            for(int l = 0; l < 6; l++){
                for(int k = 0; k < sizeof(seat)/sizeof(seat[0]); k++){
                    if(seat[k] == Seat[i][l]){
                        seat[k] = 0;
                    }
                }
            }
        }
        printf("===============================\n");
        for(int i = 0; i < 6; i++){
            r = 0;
            while(r < 6){
                if(Seat[i][r] != 0){
                    printf("| %02d ", Seat[i][r]);
                    r++;
                } else {
                    int ran = rand() % 36;
                    if(seat[ran] != 0){
                        printf("| %02d ", seat[ran]);
                        seat[ran] = 0;
                        r++;
                    }
                }
            }
            printf("|\n===============================\n");
        }
    }
}

void ran_num() {
    int person, random_num, mode;
    printf("©‚™∫§Hº∆:");
    scanf("%d", &person);
    printf("≠´Ω∆?(0/1):");
    scanf("%d", &mode);
    srand(time(NULL));
    if (mode == 1) {
        for (int i = 0; i < person; i++) {
            printf("%d\n", rand() % 36 + 1);
        }
    } else {
        int list[36] = {0};
        for (int i = 0; i < person; i++) {
            do {
                random_num = rand() % 36 + 1;
            }
			while (list[random_num - 1] != 0);
            list[random_num - 1] = 1;
            printf("%d\n", random_num);
        }
    }
}
