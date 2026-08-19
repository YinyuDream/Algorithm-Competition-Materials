
int a[maxn];
int l=0,r=0;//l指向开头，r指向，末尾 
for(int i=1;i<=m;i++)
{
	scanf("%d",&opt);
	if(opt==1)//插入操作
	{
		scanf("%d",&x);
		r++;
		a[r]=x;
		sum[r]=sum[r-1]+x;
	}
	else if(opt==2)//删除操作
	{
		l++;
	}
	else if(opt==3)
	{
		r--
	} 
	else
	{
		scanf("%d",&x);
		printf("%d\n",sum[1+x-1]-sum[l-1]);
	} 
}

struct node
{
	int id;
	int s;
}a[maxn];
int l=0,r=0;//用l,r来维护队列
int k=1;//用k来维护当前数组第一个元素 
for(int i=1;i<=n;i++)
{
	scanf("%d",&opt);
	if(opt==1)
	{
		scanf("%d",&x);
		while(l!=r&&a[r].s<=x)
		r--;
		a[++r].s=x;
		a[r].id=i;
	}
	else if(opt==2)
	{
		if(k==a[l].id)
			l++;
		k++;
	}
	else if(opt==3)
	printf("%d\n",a[l].s);
}
