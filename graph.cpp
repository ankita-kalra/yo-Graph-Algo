#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
int c = 0;
struct adj_list{
    int dest;
    adj_list *next;

}*np = NULL, *np1 = NULL, *p = NULL, *q = NULL;

struct Graph
{   int v;
    adj_list *ptr;
}array[1];

void addReverseEdge(int src,int dest)
{
   np1 = new adj_list;
   np1->dest = src;
   np1->next = NULL;
   if (array[dest].ptr == NULL)
   {
     array[dest].ptr = np1;
     q = array[dest].ptr;
     q->next = NULL;
   }
   else
   {
    q = array[dest].ptr;
    while (q->next != NULL)
     {
      q = q->next;
     }
     q->next = np1;
    }
}
void addEdge(int src,int dest)
{
    np = new adj_list;
    np->dest = dest;
    np->next = NULL;
    if (array[src].ptr == NULL)
    {
        array[src].ptr = np;
        p = array[src].ptr;
        p->next = NULL;
    }
    else
    {
        p = array[src].ptr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = np;
    }
    //addReverseEdge(src,dest);
}

void print_graph(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<array[i].v<<":";
        while (array[i].ptr != NULL)
        {
            cout<<(array[i].ptr)->dest<<"->";
            array[i].ptr = (array[i].ptr)->next;
        }
        cout<<"NULL"<<endl;
    }
}

void createGraph(int n)
{
   for (int i = 0; i < n; i++)
    {
        array[i].v = i+1;
        array[i].ptr = NULL;
    }
  int d=0;
  for(int i=0;i<n;i++)
    {
     cin >> d;
     while(d!=-1)
     {

      addEdge(i,d);
      cin >> d;
     }
    }
    cout << "Graph Created" << endl;
    print_graph(n);
}

int main()
{
    int n;
    cout<<"Enter the no of vertices\n";
    cin>>n;
    createGraph(n);
    getch();
}
