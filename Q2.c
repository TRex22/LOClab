#include <stdlib.h>
#include <stdio.h>

struct _stack{
	char letter;
	struct _stack *next;
};

typedef struct _stack stack;

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
	exit(0);
}

void reject()
{
	//cout << "Rejected" << endl;
	printf("Rejected\n");
	exit(1);
}

void push (stack *Stack, char letter)
{
	stack *NL;
	stack *temp = Stack;
	
	NL = (stack*)malloc(1*sizeof(stack));
	NL -> letter = letter;
	NL -> next = Stack;
	
	Stack = NL;
	//Stack->next = NL;
	
}

char pop (stack *Stack)
{
	stack *temp = Stack;
	
	Stack = Stack -> next;
	return temp -> letter;	
	
}

void main()
{
	const char *filename = "Q2Acc.txt";
	//const char *filename = "Q2Rej.txt";
	FILE *file = fopen(filename, "r");
	if (file == NULL) exit(0);
	
	stack *Stack;
	
	int state = 0;
	char str; //=ReadChar(file);
	while ((str = fgetc(file)) != EOF) {

        printf("C: %c\n",str);
		if (str == 'a' || str == 'b')
		{
			push(Stack, str);
			stack *temp = Stack;
			printf("*** Stack trace: ***\n");
			if (temp != NULL)
			{
					printf("Letter: %c\n", temp -> letter);
					temp = temp -> next;
			}
			while (temp!= NULL)
			{
				printf("Letter: %c\n", temp -> letter);
				temp = temp -> next;
			}
			printf ("done.\n\n");
		}
		else if (str == 'X')
		{
			while ((str = fgetc(file)) != EOF) {
				printf("Current letter: %c\n", str);
				if (str == 'a')
				{
					str = pop(Stack);
					printf("Current letter: %c\n", str);
					if (str=='b')
					{
						reject();
					}
					else if (str=='a')
					{
						
					}
					else
					{
						reject();
					}
				}
				else if (str == 'b')
				{
					str = pop(Stack);
					printf("Current letter: %c\n", str);
					if (str=='a')
					{
						reject();
					}
					else if (str=='b')
					{
						
					}
					else
					{
						reject();
					}
				}
				else
				{
					str = pop(Stack);
					printf("Current letter: %c\n", str);
					if (str=='a' || str=='b')
					{
						reject();
					}
					else
					{
						accept();
					}
				}
			}
		}
		else
		{
			reject();
			//break;
		}
		
	}
	
	/*switch (state)
	{
		case 0: accept();
			break;
		case 3: accept();
			break;
		default: reject();
			break;
	}*/
	system("pause");
	fclose(file);
}
