#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int T,book;
string s1[maxn],s2[maxn],a1,a2;
int main(){
    s1[1]="Lunar"; s2[1]="Lobster";
    s1[2]="Kinetic"; s2[2]="Kudu";
    s1[3]="Jammy"; s2[3]="Jellyfish";
    s1[4]="Impish"; s2[4]="Indri";
    s1[5]="Hirsute"; s2[5]="Hippo";
    s1[6]="Groovy"; s2[6]="Gorilla";
    s1[7]="Focal"; s2[7]="Fossa";
    s1[8]="Eoan"; s2[8]="Ermine";
    s1[9]="Disco"; s2[9]="Dingo";
    s1[10]="Cosmic"; s2[10]="Cuttlefish";
    s1[11]="Bionic"; s2[11]="Beaver";
    s1[12]="Artful"; s2[12]="Aardvark";
    s1[13]="Zesty"; s2[13]="Zapus";
    s1[14]="Yakkety"; s2[14]="Yak";
    s1[15]="Xenial"; s2[15]="Xerus";
    s1[16]="Wily"; s2[16]="Werewolf";
    s1[17]="Vivid"; s2[17]="Vervet";
    s1[18]="Utopic"; s2[18]="Unicorn";
    s1[19]="Trusty"; s2[19]="Tahr";
    s1[20]="Saucy"; s2[20]="Salamander";
    cin>>T;
    while(T--){
        book=0;
        cin>>a1>>a2;
        if(a1[0]>='a'&&a1[0]<='z')
            a1[0]=a1[0]-'a'+'A';
        if(a2[0]>='a'&&a2[0]<='z')
            a2[0]=a2[0]-'a'+'A';
        if(a1[0]==a2[0])book=1;
        if(book==1)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}