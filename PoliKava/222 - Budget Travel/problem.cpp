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

int petrol_stations;
double sd_distance, capacity, mpg, start_cost;
double minPrice, currPrice; // in cents
vector< pair<double, double> > v;

double fuelRemaining(int s1, int s2, double cfuel)
{
	/*
	   How much fuel does remain if I travel from station 1
	   to station 2 with the current fuel?
	*/

	double d = v[s2].first - v[s1].first; // miles
	double g = d / mpg; // gallons needed
	return cfuel - g; // if < 0 we must refuel
}

void walk(int station, double money, double fuel)
{
	//print("\n\nCurrently in station %d, having spent %.2lf cents and having %.2lf gallons of fuel remaining.", station, money, fuel);
	if (station == petrol_stations+1) // destination reached
	{
		minPrice = min(minPrice, money);
		//print("\n  > last station, min is now %.2lf.", minPrice);
		return;
	}

	if (money > minPrice) // prune, doesn't make sense to go on
	{
		//print("\n  > pruning this solution since %.2lf is greater than %.2lf", money, minPrice);
		return;
	}

	double g = fuelRemaining(station, station+1, fuel);
	//print("\n  > getting to the next station would leave us with %.2lf gallons", g);
	if (g >= 0.0) // can advance without refilling
	{
		//print(", don't refill");
		walk(station+1, money, g);
		if (fuel > capacity/2) // more than half, won't refill
		{
			//print("OEILA");
			return;
		}
	}

	money += 200.0; // snacks
	money += round((capacity - fuel) * v[station].second);
	walk(station+1, money, capacity-((v[station+1].first - v[station].first) / mpg));
}

int main()
{
	FOR1(tc, INF)
	{
		scanf("%lf", &sd_distance);
		if (sd_distance < 0.0)
			break;

		printf("Data Set #%d\n", tc);
		scanf("%lf %lf %lf %d", &capacity, &mpg, &start_cost, &petrol_stations);

		v.clear();
		minPrice = numeric_limits<double>::max();

		v.push_back({0.0, start_cost});
		FOR(i, petrol_stations)
		{
			pair<double, double> p;
			scanf("%lf %lf", &p.first, &p.second); // miles, cents
			v.push_back(p);
		}
		v.push_back({sd_distance, -1.0}); // don't have to refuel at the last station

		walk(0, start_cost*100, capacity); // fill the tank when starting
		printf("minimum cost = $%.2lf\n", minPrice/100.0);
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