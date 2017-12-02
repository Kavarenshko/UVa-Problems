#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

class ComparisonClass
{
public:
    bool operator() (pair<int, ii> a, pair<int, ii> b)
    {
        if (a.first < b.first)
        	return false;
        else if (a.first > b.first)
        	return true;

        if (a.second.first < b.second.first)
        	return false;
        return true;
    }
};

int main()
{
	int K;
	string current;
	priority_queue< pair<int, ii>, vector< pair<int, ii> >, ComparisonClass > pq;
	while(1)
	{
		getline(cin, current);
		if (current[0] == '#')
			break;
		pair<int, ii> c_pair;
		sscanf(current.c_str(), "Register %d %d", &c_pair.second.first, &c_pair.first);
		c_pair.second.second = c_pair.first;
		pq.push(c_pair);
	}
	scanf("%d", &K);
	while(K--) // { current, { id, original } }
	{
		pair<int, ii> c_pair = pq.top(); pq.pop();
		//print("\nAnalyzing id %d with value %d (original is %d).", c_pair.second.first, c_pair.first, c_pair.second.second);
		printf("%d\n", c_pair.second.first);
		pq.push( { c_pair.first + c_pair.second.second, c_pair.second } );
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