#include "library.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void create_line(int size, int red, int green, int blue) {
	for( int i = 0; i < size ; i ++ ) {
		create_square(red, green , blue);
	}
}
void random_square(){
	srand(time(NULL));
	int i = 0, n = 0;

	for(i = 0; i < 10; i++){
		int random_nbr1 = rand() % 256;
		int random_nbr2 = rand() % 256;
		int random_nbr3 = rand() % 256;
		create_square(random_nbr1, random_nbr2, random_nbr3);
		for(n = 0; n < 10; n++){
			int random_nbr1 = rand() % 256;
			int random_nbr2 = rand() % 256;
			int random_nbr3 = rand() % 256;
		create_square(random_nbr1, random_nbr2, random_nbr3);
		}
		new_line();
	}
}
int main() {
    random_square();
	draw();
    return 0;
}
