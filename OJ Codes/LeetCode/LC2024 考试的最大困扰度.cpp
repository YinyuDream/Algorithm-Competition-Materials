class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        vector<int> cnt(n);
        cnt[0]=(answerKey[0]=='T');
        for(int i=1;i<n;i++)
            cnt[i]=cnt[i-1]+(answerKey[i]=='T');
        int l=1,r=n;
        auto check=[&](int len){
            bool can=false;
            for(int i=0;i+len-1<n;i++){
                int cnt_0=cnt[i+len-1]-cnt[i]+(answerKey[i]=='T');
                int cnt_1=len-cnt_0;
                if(min(cnt_0,cnt_1)<=k)
                    can=true;
            }
            return can;
        };
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};