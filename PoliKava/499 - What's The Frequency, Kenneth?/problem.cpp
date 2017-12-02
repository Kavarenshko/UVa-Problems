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

int main()
{
	while(1)
	{
		if (cin.eof())
			break;

		string s;
		getline(cin, s);

		if (s == "")
			break;

		map<char, int> m;

		for(auto c : s)
			m[c] += 1;
		
		int lower_record = 0;
		int upper_record = 0;
		vector<char> lower_vector;
		vector<char> upper_vector;

		for(auto kv : m)
		{
			if (kv.first >= 'A' && kv.first <= 'Z')
			{
				if (kv.second > upper_record)
				{
					upper_vector.clear();
					upper_vector.push_back(kv.first);
					upper_record = kv.second;
				}
				else if (kv.second == upper_record)
				{
					upper_vector.push_back(kv.first);
				}
			}

			if (kv.first >= 'a' && kv.first <= 'z')
			{
				if (kv.second > lower_record)
				{
					lower_vector.clear();
					lower_vector.push_back(kv.first);
					lower_record = kv.second;
				}
				else if (kv.second == lower_record)
				{
					lower_vector.push_back(kv.first);
				}
			}
		}

		if (lower_record > upper_record)
		{
			for(auto c : lower_vector)
				printf("%c", c);
			printf(" %d\n", lower_record);
		}
		else if (upper_record > lower_record)
		{
			for(auto c : upper_vector)
				printf("%c", c);
			printf(" %d\n", upper_record);
		}
		else
		{
			for(auto c : upper_vector)
				printf("%c", c);
			for(auto c : lower_vector)
				printf("%c", c);
			printf(" %d\n", upper_record);
		}
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