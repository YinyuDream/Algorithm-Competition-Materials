for(int i=1;i<=n;i++)//枚举当前选择前i个物品
{
	for(int j=V;j>=1;j--)//枚举背包体积
	{
		if(j>=c[i])
		f[j]=max(f[j],f[j-c[i]]+w[i]);
	} 
} //01背包 

for(int j=1;j<=V;j++)
f[j]=-1;
//f[0]=0,f[i]=-1.
for(int i=1;i<=n;i++)
{
	for(int j=V;j>=1;j--)
	{
		if(j>=c[i]&&f[j-c[i]]!=-1)
		f[j]=max(f[j],f[j-c[i]]+w[i]);
	}
}//01背包一维 刚好放入 

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=V;j++)
	{
		if(j>=c[i])
		{
			f[i][j]=max(f[i][j-c[i]]+w[i],f[i-1][j]);
		}
		else
		f[i][j]=f[i-1][j];
	}
}//完全背包二维

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=V;j++)
	{
		if(j>=c[i])
		f[j]=max(f[j],f[j-c[i]]+w[i]);
	}
} 
