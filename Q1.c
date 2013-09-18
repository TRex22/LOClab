#include <stdlib.h>
#include <stdio.h>

//question 1
//finite automaton.
//read a string from a file
	//one character at a time
//accpet or reject a string
//Alphabet is a,b 

//using namespace std;

char ReadChar (FILE *file)
{
	char *c;
	//fscanf(file, "%c ", &c);
	//fgets(c, 1, file);
	//*c = fgetc(file);
	//do {
      //*c = fgetc (file);
      
    //} while (*c != EOF);
    while ((*c = fgetc(file)) != EOF) {

        // now do something with each character, c.
		return *c;
    }
	return  '\n';
}

void accept()
{
	//cout << "Accpeted" << endl;
	printf("Accepted\n");
}

void reject()
{
	//cout << "Rejected" << endl;
	printf("Rejected\n");
}

int q0(char c)
{
	//printf("\n%c\n",c);
	/*switch (c)
		{
			case 'a': 
				//stay
				return 0;
				break;
			case 'b': 
				return 1;
				break;
			default: return -2;//end
				break;
		}*/
		if (c == 'a')
		{
			printf("*** state 0 ***\n");
			return 0;
		}
		else if (c == 'b')
		{
			return 1;
		}
		
}

int q1(char c)
{
	
		
		if (c == 'a')
		{
			printf("*** state 1 ***\n");
			return 2;
		}	
		else if (c == 'b')
		{
			return 3;
		}
		
}

int q2(char c)
{
	
		if (c == 'a')
		{
			printf("*** state 2 ***\n");
			return 1;
		}	
		else if (c == 'b')
		{
			return 0;
		}
		
}

int q3(char c)
{
	
		if (c == 'a')
		{
			printf("*** state 3 ***\n");
			return 2;
		}
		else if (c == 'b')
		{
			return 3;
		}
		
}

int main()
{
	const char *filename = "Q1Acc.txt";
	//const char *filename = "Q1Rej.txt";
	FILE *file = fopen(filename, "r");
	if (file == NULL) exit(0);
	
	int state = 0;
	char str; //=ReadChar(file);
	while ((str = fgetc(file)) != EOF) {

        printf("C: %c\n",str);
		//printf("\n%c state: %d\n", str, state);
		switch (state)
		{
			case 0: state = q0(str);
				break;
			case 1: state = q1(str);
				break;
			case 2: state = q2(str);
				break;
			case 3: state = q3(str);
				break;
			case -2: printf("Error\n");
				break;
			default: printf("hello\n");
				break;
		}
		//char str = ReadChar(file);
		//printf("Ping!!\n");
	}//while(str != '\n');
	
	switch (state)
	{
		case 0: accept();
			break;
		case 3: accept();
			break;
		default: reject();
			break;
	}
	
	fclose(file);
	return 0;
}
