#include <stdio.h>

int num (char c){
	if(c >= '0' && c <= '9'){
		return 1;
	}
	else return 0;
}

int letra (char c){
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
		return 1;
	}
	else return 0;
}

int main() {

	char c, prev = 0;
	int n = 0, v = 0;

  while (c != '\n') {
	
	scanf("%c", &c);
	
	if (!(letra(c)) && !(num(c))){
		if (letra(prev)){
			n++;
		}
		
		if (num(prev)){
			if (v == 0 && ((c != ',') || (c != '.'))){			
				n++;			
				v = 0;
			}
			
			while (v == 1){
				if ((num(c)) && ((prev == ',') || (prev == '.'))){
					n++;			
				}
				
				if ((num(c)) && (num(prev))){
					n++;
				}
				else v = 0;
			}	
		}	
	}	

	if ((num(prev)) && ((c == ',') || (c == '.')) && (v == 0)){
		v = 1;	
	}
	
	prev = c;
	
  }
	
  	printf ("%d\n", n);
	return 0;
}
