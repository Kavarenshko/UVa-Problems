#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int T,P,S;
vector<string> v;
vector<string> csol;
map<string, set<string> > forbidden;

struct less_than_key
{
    inline bool operator() (const string& s1, const string& s2)
    {
        if (s1.size() > s2.size())
        	return true;
        else if (s1.size() == s2.size())
        {
        	for(unsigned i=0; i < s1.size(); i++)
        	{
        		if (s1[i] < s2[i])
        			return true;
        		else if (s1[i] > s2[i])
        			return false;
        	}
        }
        return false;
    }
};

void walk(int index, int remaining)
{
	for(unsigned i=index; i < v.size(); i++)
	{
		if (forbidden.find(v[i]) != forbidden.end())
		{
			// check if compatible with current solution
			bool compatible = true;
			for(auto &cs : csol)
			{
				if (forbidden[v[i]].find(cs) != forbidden[v[i]].end())
				{
					//print("\nString %s not compatible with string %s, skipping.", v[i].c_str(), cs.c_str());
					compatible = false;
					break;
				}
			}
			if (!compatible)
				continue;
		}

		if (remaining == 1)
		{
			for(auto &psol : csol)
				printf("%s ", psol.c_str());
			printf("%s\n", v[i].c_str());
		}
		else
		{
			csol.push_back(v[i]);
			//print("\nAdding %s to csol", v[i].c_str());
			walk(i+1, remaining-1);
			//print("\nRemoving %s from csol", v.back().c_str());
			csol.pop_back();
		}
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		scanf("%d %d %d", &T, &P, &S);
		getchar();

		printf("Set %d:\n", tc+1);
		v.clear();
		forbidden.clear();

		FOR(i, T)
		{
			string current;
			getline(cin, current);
			for(auto &c : current)
			{
				if (c >= 'a' && c <= 'z')
					c -= 32;
			}
			v.push_back(current);
		}
		FOR(i, P)
		{
			string s1,s2;
			cin >> s1 >> s2;
			//print("%s %s\n", s1.c_str(), s2.c_str());

			for(auto &c : s1)
			{
				if (c >= 'a' && c <= 'z')
					c -= 32;
			}
			for(auto &c : s2)
			{
				if (c >= 'a' && c <= 'z')
					c -= 32;
			}

			if (forbidden.find(s1) == forbidden.end())
			{
				set<string> nset;
				nset.insert(s2);
				forbidden[s1] = nset;
			}
			else
				forbidden[s1].insert(s2);

			if (forbidden.find(s2) == forbidden.end())
			{
				set<string> nset;
				nset.insert(s1);
				forbidden[s2] = nset;
			}
			else
				forbidden[s2].insert(s1);
		}
		sort(v.begin(), v.end(), less_than_key());

		if (S == 1)
		{
			for(auto &t : v)
				printf("%s\n", t.c_str());
			printf("\n");
			continue;
		}

		for(unsigned i=0; i < v.size(); i++)
		{
			csol.clear();
			csol.push_back(v[i]);
			walk(i+1, S-1);
		}

		printf("\n");
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