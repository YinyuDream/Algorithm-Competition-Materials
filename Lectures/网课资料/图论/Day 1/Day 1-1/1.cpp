struct edge
{
	int e,next;
}ed[maxm];

int en,first[maxn];

void add_edge(int s,int e)
{
	en++;
	ed[en].next = first[s];
	first[s]=en;
	ed[en].e = e;
}

for (int p=first[1];p!=0;p=ed[p].next)
	ed[p].e;
