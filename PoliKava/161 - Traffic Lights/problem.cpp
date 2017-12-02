#include <iostream>
#include <algorithm>

#define MAX_SIGNALS 100 + 1
#define TIMEOUT_SECONDS 18000

using namespace std;

// max line 100 chars
// 10 <= cycle time <= 90
// 2 <= signals <= 100

struct p_time
{
	int hours;
	int minutes;
	int seconds;
};

int cycles[MAX_SIGNALS], vlen;

p_time secondsToTime(int s)
{
	p_time t = {0,0,0};

	t.hours += s/(60*60);
	s %= (60*60);
	t.minutes += s/60;
	s %= 60;
	t.seconds = s;

	return t;
}

inline bool isGreen(int index, int time_elapsed)
{
	//cout << "\n  - Traffic light master" << cycles[index] << ": " << cycles[index]/2-5 << "  -  " << time_elapsed%cycles[index];
	return time_elapsed % cycles[index] < ((cycles[index]/2) - 5)? true: false;
}

p_time process()
{
	p_time nope = {-1,0,0};
	int elapsed = cycles[0];

	while (1)
	{
		bool ok = true;

		if (isGreen(vlen-1, elapsed))
		{
			//cout << "\nTraffic light master(" << cycles[vlen-1] << ") is green with time " << elapsed;
			for(int i=vlen-2; i >= 0; i--)
			{
				if (!isGreen(i, elapsed))
				{
					//cout << "\n  > Traffic light (" << cycles[i] << ") is RED with time " << elapsed;
					ok = false;
					break;
				}
				else
				{
					//cout << "\n  > Traffic light (" << cycles[i] << ") is green with time " << elapsed;
				}
			}
			if (ok)
				return secondsToTime(elapsed);
		}

		elapsed++;

		if (elapsed > TIMEOUT_SECONDS)
			return nope;
	}
}

int main()
{
	int n1,n2,n3;
	p_time result;

	while (scanf("%d%d%d", &n1, &n2, &n3)) // 2 signals + terminating 0
	{
		if (!n1 && !n2 && !n3)
			break;

		fill(cycles, cycles+MAX_SIGNALS, -1);

		if (!n3) // 2 signals
		{
			vlen = 2;
			cycles[0] = n1*2;
			cycles[1] = n2*2;
		}
		else
		{
			int tempN;
			vlen = 3;

			cycles[0] = n1*2;
			cycles[1] = n2*2;
			cycles[2] = n3*2;

			while(1)
			{
				scanf("%d", &tempN);
				if (tempN)
				{
					cycles[vlen] = tempN*2;
					vlen++;
				}
				else
					break;
			}
		}

		// data is ready, start processing

		sort(cycles, cycles+vlen);
		result = process();
		if (result.hours == -1)
			printf("Signals fail to synchronise in 5 hours\n");
		else
			printf("%02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);
	}

	return EXIT_SUCCESS;
}