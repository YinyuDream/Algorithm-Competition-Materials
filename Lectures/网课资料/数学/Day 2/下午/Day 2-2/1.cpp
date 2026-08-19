
bool is_prime[2333]; not_prime[i] = false;

not_prime[1] = true;
for (int a=2;a<=n;a++)
	for (int b=a+a;b<=n;b+=a)
		not_prime[b] = true;


not_prime[1] = true;
for (int a=2;a<=n;a++)
	if (not_prime[a] == false)
		for (int b=a+a;b<=n;b+=a)
			not_prime[b] = true;

