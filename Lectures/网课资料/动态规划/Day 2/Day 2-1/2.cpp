struct edge
{
	int e,next;
}ed[maxm];

int first[maxn];

void add_edge(int s,int e)
{
	en++;
	ed[en].next = first[s];
	first[s] = en;
	ed[en].e=e;
}

for (int p=first[s];p!=0;p = ed[p].next)
	ed[p].e;
