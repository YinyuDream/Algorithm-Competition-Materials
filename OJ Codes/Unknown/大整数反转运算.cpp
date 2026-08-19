struct Bignum{
	int len,num[510];
	Bignum(){
		len=0;
		memset(num,0,sizeof num);
	}
	Bignum(int x){
		len=0;
		memset(num,0,sizeof num); 
		while(x){
			num[++len]=x%10;
			x/=10;
		}
	}
	void rev()
	{
		for(int i=1;i<=len/2;i++)
			swap(num[i],num[len-i+1]);
	}
	void print(){
		if(!len)printf("0");
		for(int i=len;i>=1;i--)
		printf("%d",num[i]);
	}
	Bignum operator=(int y)
	{
		len=0;
		memset(num,0,sizeof num); 
		while(y){
			num[++len]=y%10;
			y/=10;
		}
		return *this;
	}
	Bignum operator+(const Bignum &y)
	{
		Bignum c;
		c.len=max(len,y.len);
		for(int i=1;i<=c.len;i++){
			c.num[i]+=num[i]+y.num[i];
			c.num[i+1]+=c.num[i]/10;
			c.num[i]%=10;
		}
		if(c.num[c.len+1])c.len++;
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
	Bignum operator-(const Bignum &y)
	{
		Bignum c;
		c.len=max(len,y.len);
		for(int i=1;i<=c.len;i++){
			c.num[i]=num[i]-y.num[i];
			if(c.num[i]<0){
				c.num[i]+=10;
				num[i+1]--;
			}
		}
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
	Bignum operator*(const Bignum &y)
	{
		Bignum c;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=y.len;j++){
				c.num[i+j-1]+=num[i]*y.num[j];
				c.num[i+j]+=c.num[i+j-1]/10;
				c.num[i+j-1]%=10;
			}
		}
		c.len=len+y.len;
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
};
