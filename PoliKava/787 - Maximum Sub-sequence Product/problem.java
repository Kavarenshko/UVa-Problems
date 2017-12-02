import java.util.Scanner;
import java.math.BigInteger;

class Pair
{
	public BigInteger first;
	public BigInteger second;

	public Pair()
	{
		this.first = new BigInteger(Integer.toString(0));
		this.second = new BigInteger(Integer.toString(0));
	}
}

class Main
{
	public static void main(String[] args)
	{
		int ind;
		BigInteger[] v = new BigInteger[100];
		Pair[] dp = new Pair[100];

		Scanner in = new Scanner(System.in);

		while(true)
		{
			if (!in.hasNextInt())
				break;

			ind = 0;
			while(true)
			{
				int t = in.nextInt();
				if (t == -999999)
					break;
				v[ind] = new BigInteger(Integer.toString(t));
				ind += 1;
			}

			for(int i=0; i < ind; i++)
				dp[i] = new Pair();

			//System.out.println(dp[ind-1].first);
			dp[ind-1].first = BigInteger.ZERO;
			dp[ind-1].second = v[ind-1];
			for(int i=ind-2; i >= 0; i--)
			{
				dp[i].first = v[i].min((v[i].multiply(dp[i+1].first)).min((v[i].multiply(dp[i+1].second))));
				dp[i].second = v[i].max((v[i].multiply(dp[i+1].first)).max((v[i].multiply(dp[i+1].second))));
			}

			BigInteger m = dp[0].second;
			for(int i=1; i < ind; i++)
				m = m.max(dp[i].second);
			System.out.println(m);
		}
	}
}