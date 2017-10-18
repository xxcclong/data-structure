#include <iostream>
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
int reved = 0;
int q[4*Size];
int init()
{
    char s=getchar();
    if(s == '<')
    {
    	s = getchar();
    	s = getchar();
    	if(s=='L')
    		move(-1,0);
    	else
    		move(-1,1);
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

    
    
    return 0;
}

class Stack()
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
		delete[] ch;
	}
}


Stack s[2];// 0 for left 1 for roght
bool reved = 0;
void move(int aim,int wlas)// -1 left 0 left lesor       
/*
0 0   pop
0 1   push
1 0		push
1 1	   pop


aim = 0   rev = 0 -1
aim = 1 rev = 0 1
0 1 1
1 1 -1
*/
{
	if(aim == wlas) // pop
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
	//push
	
}
void Insert(int wlas,char letter)
{
	printf("T\n");

}
int main()
{
	
}


