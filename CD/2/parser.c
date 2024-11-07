#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAILED 0

int E(), Edash(), T(), Tdash(), F();

const char *cursor;
char string[64];

int main() {
	printf("Enter the string : ");
	scanf("%s", string); 
	cursor = string;
	printf("\nInput		 Action\n--------------------------------\n");

	if (E() && *cursor == '\0') { 
		printf("--------------------------------\nString is successfully parsed\n");
		return 0;
	} 
	else {
		printf("--------------------------------\nError in parsing String\n");
		return 1;
	}
}


int E() {
	printf("%-16s E -> T E'\n", cursor);
	if (T()) {
		if (Edash()) 
			return SUCCESS;
		else
			return FAILED;
	} 
	else
		return FAILED;
}

//  E' -> + T E' | e
int Edash() {
	if (*cursor == '+') {
		printf("%-16s E' -> + T E'\n", cursor);
		cursor++;
		if (T()) { 
			if (Edash()) 
				return SUCCESS;
			else
				return FAILED;
		} 
		else
			return FAILED;
	}
    if (*cursor == '-') {
		printf("%-16s E' -> - T E'\n", cursor);
		cursor++;
		if (T()) { 
			if (Edash()) 
				return SUCCESS;
			else
				return FAILED;
		} 
		else
			return FAILED;
	}
	else {
		printf("%-16s E' -> e\n", cursor);
		return SUCCESS;
	}
}

// T -> F T'
int T() {
	printf("%-16s T -> F T'\n", cursor);
	if (F()) { 
		if (Tdash()) 
			return SUCCESS;
		else
			return FAILED;
	} 
	else
		return FAILED;
}

// T' -> * F T' | e
int Tdash() {
	if (*cursor == '*') {
		printf("%-16s T' -> * F T'\n", cursor);
		cursor++;
		if (F()) { 
			if (Tdash())
				return SUCCESS;
			else
				return FAILED;
		} 
		else
			return FAILED;
	}
    if (*cursor == '/') {
		printf("%-16s T' -> / F T'\n", cursor);
		cursor++;
		if (F()) { 
			if (Tdash()) 
				return SUCCESS;
			else
				return FAILED;
		} 
		else
			return FAILED;
	} 
	else {
		printf("%-16s T' -> e\n", cursor);
		return SUCCESS;
	}
}

//  F -> ( E ) | i
int F() {
	if (*cursor == '(') {
		printf("%-16s F -> ( E )\n", cursor);
		cursor++;
		if (E()) { 
			if (*cursor == ')') {
				cursor++;
				return SUCCESS;
			} 
			else
				return FAILED;
		} 
		else
			return FAILED;
	} 
	else if (*cursor == 'i') {
		printf("%-16s F -> i\n", cursor);
		cursor++;
		return SUCCESS;
	} 
	else
		return FAILED;
}
