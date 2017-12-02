#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

llu N;

inline llu customExp10(int e) { return (e < 1)? 1 : ((e == 1) ? 10 : 10 * customExp10(e-1)); }

int main()
{
	while(1)
	{
		scanf("%llu", &N);
		if (!N)
			break;

		if (N <= 9)
		{
			printf("%llu\n", N);
			continue;
		}

		int digits;
		llu sum = 0;
		for(digits=1; digits < INF; digits++)
		{
			print("\nDigits: %d, starting from %llu palindromes", digits, sum);
			llu val = 9LL * customExp10((digits+1)/2-1);
			sum += val;
			if (N <= sum)
			{
				sum -= val;
				break;
			}
		}

		print("\n  > palindrome %llu will have %d digits and starting from %llu", N, digits, sum);

		llu num = 1;
		int cdigits = 1;
		if (digits % 2 == 0)
		{
			while(cdigits < digits/2)
			{
				num *= 10;
				cdigits += 1;
			}
		}
		else
		{
			while(cdigits < digits/2+1)
			{
				num *= 10;
				cdigits += 1;
			}
		}

		sum += 1;
		while(sum < N)
		{
			num += 1;
			sum += 1;
		}

		string s = to_string(num);
		printf("%s", s.c_str());
		reverse(s.begin(),s.end());
		if (digits % 2 == 0)
			printf("%s\n", s.c_str());
		else
			printf("%s\n", s.substr(1).c_str());

		//print("\n*%s*\n", num.c_str());
	}
	return EXIT_SUCCESS;
}

void print(const char* msg, ...)
{
	#ifndef ONLINE_JUDGE
		va_list argptr;
		va_start(argptr, msg);
		vfprintf(stderr, msg, argptr);
		va_end(argptr);
	#endif
}