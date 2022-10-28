#include<cstdio>
#include<iostream>
using namespace std;
#define size 100
char alphabet[size],s[size],sequence_vertex[size],ch;
int graph[size][size]={0},count_sequence_vertex=-1;
int vertex,top=-1;
int leaf=0;

void visit(char ch)
{
    count_sequence_vertex++;
    sequence_vertex[count_sequence_vertex]=ch;
}

int is_visit(char ch)
{
    int i;
    for(i=0;i<=count_sequence_vertex;i++)
    {
        if(sequence_vertex[i]==ch)
            return 1;
    }
    return 0;
}

void display(int x)
{
    char c = alphabet[x];
    int i;
    for(i=0;i<=count_sequence_vertex;i++)
    {
        if(leaf==1){
            if(c!=sequence_vertex[i]){
                printf("%c ",sequence_vertex[i]);
            }
        }
        else{
            printf("%c ",sequence_vertex[i]);
        }
    }
}

void push(char ch)
{
    if(top+1!=size)
    {

        top++;
        s[top]=ch;
        //printf("%d",a[top]);
    }
    else
    {
        return;
    }
}
int pop()
{
    if(top!=-1)
    {
        ch=s[top];
        s[top]=0;
        top--;
        return ch;
    }
}


void check_adjacency(char ch)
{
    int i,j,flag;
    for(i=0;i<vertex;i++)
    {
        if(alphabet[i]==ch)
        {
            for(j=0;j<vertex;j++)
            {
                if (graph[i][j]==1)
                {
                    flag=is_visit(alphabet[j]);
                    if(flag==0)
                        push(alphabet[j]);
                }
            }
        }
    }
}

void create_graph()
{
    int i,j;
    for(i=0;i<26;i++)alphabet[i]=i+65;

    printf("\nEnter vertex number: ");
    scanf("%d",&vertex);

    for(i=0;i<vertex;i++)
    {
        for(j=i;j<vertex;j++)
        {
            if(i!=j)
            {
                printf("\n[%c][%c]=> ",alphabet[i],alphabet[j]);
                scanf("%d",&graph[i][j]);
                graph[j][i]=graph[i][j];
            }
        }
    }

    printf("\nEdges:");
    for(i=0;i<vertex;i++)
    {
        for(j=i;j<vertex;j++)
        {
            if(graph[i][j]==1)printf("%c%c ",alphabet[i],alphabet[j]);
        }
    }

    printf("\nAdjacency List:\n");
    for(i=0;i<vertex;i++)
    {
        printf("%c-> ",alphabet[i]);
        for(j=0;j<vertex;j++)
        {
            if(graph[i][j]==1)
                printf("%c,",alphabet[j]);
        }
        printf("\n");
    }

}

void DFS()
{
    int flag;
    push(alphabet[0]);
    while(top!=-1)
    {
        ch=pop();
        flag=is_visit(ch);
        if(flag==0)
        {
            visit(ch);
            check_adjacency(ch);
        }
    }
}

void customAdjacency(char ch)
{
    int i,j,flag;
    for(i=0;i<vertex;i++)
    {
        if(alphabet[i]==ch)
        {
            for(j=0;j<vertex;j++)
            {
                if (graph[i][j]==1)
                {
                    flag=is_visit(alphabet[j]);
                    if(flag==1)leaf=1;
                    else leaf=0;
                }
            }
        }
    }
}


int customDFS(int x)
{
    char c = alphabet[x];
    int flag;
    cout << c << endl;
    push(alphabet[0]);
    while(top!=-1)
    {
        ch=pop();
        flag=is_visit(ch);
        customAdjacency(c);
        cout << "leaf: " << leaf << endl;
        if(flag==0)
        {
            visit(ch);
            check_adjacency(ch);
        }
    }
}
//1 1 0 0 0 0 1 0 0 1 1 0 1 0 1
int main()
{
    create_graph();
    //DFS();
    int nodeX;
    cout << "Enter the value of node(x): " << endl;
    cin >> nodeX;
    customDFS(nodeX);
    display(nodeX);

    //cout << "leaf " << leaf << endl;
    return 0;
}
