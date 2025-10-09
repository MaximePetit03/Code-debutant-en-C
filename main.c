#include "library.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void create_line(int size, int red, int green, int blue) {
	for( int i = 0; i < size ; i ++ ) {
		create_square(red, green , blue);
	}
}

int main() {
    int limit;
	
	printf("Donne la taille du carré : ");
	scanf("%d", &limit);

	for (int i = 0; i < limit+1; i++){
			create_square(255, 0, 0);
	}
	new_line();
	create_square(255, 0, 0);
	for(int i = 0; i < limit; i++){
	for(int i = 0; i < limit-1; i++){
			create_square(0, 255, 0);
			}
		create_square(255, 0, 0);
		new_line();
		create_square(255, 0, 0);
	}
	for(int i = 0; i < limit; i++){
			create_square(255, 0, 0);
	}
	draw();
    return 0;
}
