#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
using namespace std;
const int Size = 4000005;
// text length <=4 000 000
// N <= 4 000 000
// there are two pos in this array Left 0 Right 1
// it means which is being operating
// 这道题用链表
// move Insert Delete reverse show
/*
struct tree
{
	char le;
	tree* next[2]; // 0 for left 1 for right
	tree(char letter = '')
	{
		le = letter;
		next[0] = next[1] = NULL;
	}
};
tree* root = NULL;*/
int lasor[2];// 0 for left    1 for right
char q[3*Size];
class Stack
{
private:
	char ch[2*Size];
	int p;
public:
	Stack()
	{
		memset(ch,sizeof(ch),0);
		p = -1;
	}
	void show(int num)
	{
		if(num == 0)
		{
			for(int i=0;i<=p;++i)
				printf("%c",ch[i] );
		}
		else
		{
			for(int i=2*Size-1;i>=p;--i)
				printf("%c",ch[i]);
		}
	}
	char pop()
	{
		if(p<0)
			return -1;// 
		return ch[p--];
	}
	
	void push(const char letter)
	{
		ch[++p] = letter;
	}
	bool Empty()
	{
		return (p < 0);
	}
	
	~Stack()
	{
		delete ch;
	}
};


Stack s[2];// 0 for left 1 for roght
bool reved = 0;
bool cuoguo = 0;
/*
0 0   pop
0 1   push
1 0		push
1 1	   pop


aim = 0   rev = 0 -1
aim = 1 rev = 0 1
0 1 1
1 1 -1




lasor[0] is pointing at the 
*/
void begin()
{
	lasor[1] = lasor[0] = Size;
	char temp = getchar();
	while(temp!='\n')
	{
		q[lasor[1]] = temp;
		temp = getchar();
		++lasor[1];
	}
	--lasor[1];
}
void move(int aim,int wlas)// -1 left 0 left lesor       
{
	if(aim == wlas) // pop
	{

	if(cuoguo == 0)
	{
		if(s[wlas].Empty())
		{
			printf("F\n");
			return;
		}
		printf("T\n");
		q[lasor[wlas] + (aim*2 - 1)*((-2)*reved + 1)] = s[wlas].pop();
		lasor[wlas] = lasor[wlas] + (aim*2 - 1)*((-2)*reved + 1);
		return;
	}
	else
	{

	}
	}
	//push
	else
	{
		if(cuoguo)
		{
			if(s[(wlas+1)%2].Empty())
			{
				printf("F\n");
				return;
			}
			printf("T\n");
			q[lasor[wlas] + (aim*2-1)] = s[(wlas+1)%2].pop();
			lasor[wlas] = lasor[wlas] + (aim*2-1);
		}
		else
		{
		s[wlas].push(q[lasor[wlas]]);
		lasor[wlas] += (aim * 2 -1)*(reved*(-2)+1);//left to right aim*2 -1
		if(lasor[0]<lasor[1])
		{
			cuoguo  = !cuoguo; 
		}		
		printf("T\n");
	
		}	
	}
	}
	else
	{
		
		else
		{
			s[(wlas+1)%2].push(q[lasor[wlas]]);
			lasor[wlas] += (aim*2 -1);
			if(lasor[0] == lasor[1])
			{
				cuoguo = 0;
			}
		}
	}

	
}
void Delete(int wlas)
{
	if(wlas)// right
	{
		if(s[1].Empty())
		{
			printf("F\n");
			return;
		}
		s[1].pop();
	}
	++lasor[0];
}
void Insert(int wlas,char letter)
{
	printf("T\n");
	if(!wlas)// left
	{
		s[0].push(letter);
		return;
	}
	//right
	q[++lasor[1]] = letter;
	return;
}
void show()
{
	s[1].show(0);
	for(int i=lasor[0];i<=lasor[1];++i)
		printf("%c",q[i] );
	s[2].show(1);
	return;
}
void reverse()
{
	if(cuoguo)
	{
		printf("F\n");
		return;
	}
	printf("F\n");
	reved = !reved;
	swap(lasor[1],lasor[0]);
	return;
}
void init()
{
    char s=getchar();
    if(s == '<')
    {
    	s = getchar();
    	s = getchar();
    	if(s=='L')
    		move(0,0);
    	else
    		move(0,1);
    	return;
    }
    if(s == '>')
    {
    	s = getchar();
    	s = getchar();
    	if(s=='L')
    		move(1,0);
    	else
    		move(1,1);
    	return;	
    }
    if(s == 'I')
    {
    	getchar();
    	s = getchar();
    	getchar();
    	char t = getchar();
    	if(s=='L')
    	{
    		Insert(0,t);
    	}
    	else
    		Insert(1,t);
    	
    	return;
    }
    if(s == 'D')
    {
    	getchar();
    	s = getchar();
    	if(s=='L')
    	{
    		Delete(0);
    	}
    	else
    		Delete(1);
    	return;
    }
    if(s == 'R')
    {	reverse();return;}
	if(s == 'S')
		{show();return;}

    
    
    return;
}
int main()
{
	printf("dasda\n");
	return 0;
}


