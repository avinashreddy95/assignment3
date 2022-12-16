#include<iostream>
using namespace std;

struct node
{
	int row, col;
	int val;
	node *next;
};

node *sparse[100];

int main()
{

	int a[100][100];
	int n, i, j;
	int count=0;
	cout<<"Enter the size of the matrix: ";
	cin>>n;
	cout<<"Enter the elements of the matrix: ";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				count++;
			}
		}
	}
	if(count<=(n*n)/2)
	{
		node *temp;
		node *last;
		int k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=0)
				{
					temp=new node;
					temp->row=i;
					temp->col=j;
					temp->val=a[i][j];
					temp->next=NULL;
					if(sparse[k]==NULL)
					{
						sparse[k]=temp;
						last=temp;
					}
					else
					{
						last->next=temp;
						last=temp;
					}
				}
			}
			k++;
		}

		k=0;
		cout<<"The sparse matrix is: \n";
		while(sparse[k]!=NULL)
		{
			temp=sparse[k];
			while(temp!=NULL)
			{
				cout<<temp->row<<" "<<temp->col<<" "<<temp->val<<"\n";
				temp=temp->next;
			}
			k++;
		}
	}
	else
	{
		cout<<"The matrix is not a sparse matrix";
	}
	return 0;
}
