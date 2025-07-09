#include<bits/stdc++.h>
using namespace std;
int main(){
    char AB,AC,BC;
    cin>>AB>>AC>>BC;
    if(AB=='<'&&BC=='<'){
        cout<<'B';
        return 0;
    }
    if(AB=='>'&&BC=='>'){
        cout<<'B';
        return 0;
    }
    if(AB=='<'&&AC=='>'){
        cout<<'A';
        return 0;
    }
    if(AB=='>'&&AC=='<'){
        cout<<'A';
        return 0;
    }
    if(AC=='<'&&BC=='>'){
        cout<<'C';
        return 0;
    }
    if(AC=='>'&&BC=='<'){
        cout<<'C';
        return 0;
    }
    return 0;
}