#include<iostream>
#include<string>

using namespace std;

//bool keep[10010];
//int lastp[129];
int cnt[128];
bool use[128];

//int range[30][2],cnt;
string work(string s) 
{
	string res;
	int n=s.size();
	for (int a='a';a<='z';a++)
		use[a]=false,cnt[a]=0;
	for (int a=0;a<n;a++)
		cnt[s[a]]++;
	int p=0;
	for (int a=0;a<n;a++)
	{
		if (use[s[a]]) continue;
		if (s[a]<s[p]) p=a;
		cnt[s[a]]--;
		if (!cnt[s[a]])
		{
			res = res + s[p];
			for (int b=p+1;b<=a;b++)
				cnt[s[b]]++;
			use[s[p]]=true;
			while (p<n && use[s[p]])
				p++;
			a=p-1;
		}
	}
	return res;
	/*string res;
	  int n=s.size();
	  for (int a='a';a<='z';a++)
	  lastp[a]=-1;
	  for (int a=0;a<n;a++)
	  {
	  lastp[s[a]] = a;
	  keep[a]=false;
	  }
	  cnt=1;
	  range[1][0]=0;range[1][1]=n-1;
	  for (int a='a';a<='z';a++)
	  {
	  if (lastp[a]==-1) continue;
	  int pos=-1;
	  for (int b=1;b<=cnt;b++)
	  {
	  int l=range[b][0],r=range[b][1];
	  int v=-1;
	  for (int c=a+1;c<='z';c++)
	  if (lastp[c]>=l && lastp[c]<=r) v=max(v,lastp[c]);
	  int p=l;
	  while (p<=r && s[p]!=a)
	  p++;
	  if (a=='l') 
	  {
	  cout << p << " " << v << endl;
	  cout << l << " " << r << endl; 
	  if (v!=-1) cout << s[p] << " " << s[v] << endl;
	  }
	  if (p<=r && p<v)
	  {
	  pos=p;
	  break;
	  }
	  }
	  if (pos==-1)
	  {
	  int p=lastp[a];
	  while (p>=0 && !keep[p])
	  {
	  if (s[p]==a) pos=p;
	  p--;
	  }
	  }

	  for (int b=1;b<=cnt;b++)
	  if (pos>=range[b][0] && pos<=range[b][1])
	  {
	  int l=range[b][0],r=range[b][1];
	  cnt++;
	  for (int d=cnt;d>b;d--)
	  range[d][0]=range[d-1][0],range[d][1]=range[d-1][1];
	  range[b][0]=l;range[b][1]=pos-1;
	  range[b+1][0]=pos+1;range[b+1][1]=r;
	  keep[pos]=true;
	  break;
	  }

	  }
	  for (int a=0;a<n;a++)
	  if (keep[a]) res=res+s[a];
	  return res;*/
}

int main()
{
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << work(s) << endl;

	return 0;
}
