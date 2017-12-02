#include <iostream>

using namespace std;

typedef unsigned long long ull;

inline ull gcd(ull a, ull b) { return b == 0? a: gcd(b, a%b); }
inline ull lcm(ull a, ull b) { return a * (b / gcd(a, b)); }

struct fraction
{
	ull num;
	ull den;

	struct fraction operator+(struct fraction& b)
	{
		ull newDen = lcm(den, b.den);
		ull newNum = ((newDen/den)*num) + ((newDen/b.den)*b.num);
		struct fraction t = {newNum, newDen};
		return t;
	}
};

int main()
{
	struct fraction f1,f2,res;
	ull v1,d1,v2,d2;
	long double t1,t2;

	for(int tc=1; ;tc++)
	{
		scanf("%llu %llu %llu %llu\n", &v1, &d1, &v2, &d2);

		if (!v1 && !d1 && !v2 && !d2)
			break;

		printf("Case #%d: ", tc);

		t1 = ((long double)d1)/v1;
		t2 = ((long double)d2)/v2;

		if (t1 < t2)
			printf("You owe me a beer!");
		else
			printf("No beer for the captain.");

		printf("\nAvg. arrival time: ");

		f1.num = d1;
		f1.den = v1;

		f2.num = d2;
		f2.den = v2;

		res = f1 + f2;
		if (res.num % 2 == 0)
			res.num /= 2;
		else
			res.den *= 2;

		if (res.num % res.den == 0)
              {
                     if(res.den == 1)
                       printf("%llu\n", res.num);
                     else
			  printf("%llu\n", res.num/res.den);
              }
		else
		{
			while (1)
			{
				ull gcd_nums = gcd(res.num, res.den);
				if (gcd_nums == 1)
				{
                                  if(res.den == 1)
                                      printf("%llu\n", res.num);
                                  else
			                 printf("%llu/%llu\n", res.num, res.den);
					break;
				}
				else
				{
					res.num /= gcd_nums;
					res.den /= gcd_nums;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}