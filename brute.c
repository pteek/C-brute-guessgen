/* Call with the current guess or a empty string to get the next guess. printable sould be a string containing all the characters that need to be enumerated.
Include string.h or write your own strlen and strchr functions.
No checking of any type. Make sure all pointers are valid and buffers plenty. I didn't have thread saftety problems. YMMV.*/

char* generator(char *curr, char *printable){
	char* itr = curr;
  	
	if (*curr == '\0'){
		curr[0] = printable[0];
		curr[1] = '\0';
		return curr;
	}
	
	while (1){
		if (*itr == printable[strlen(printable)-1]){
			if (*(itr+1) == '\0'){
				*itr = printable[0];
				*(itr+1) = printable[0]; 
				*(itr+2) = '\0';
				return curr;
			}
			*itr = printable[0];
			itr++;
			continue;
		}
		else{
			*itr = *(strchr(printable,*itr)+1);
			return curr;
		}
	}
}

