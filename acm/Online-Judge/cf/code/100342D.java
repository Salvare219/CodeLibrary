import java.util.*;
import java.math.*;
import java.io.*;


public class Main {
        private static BigInteger z;
        
	public static void main(String args[]) throws IOException
        {
		Scanner cin = new Scanner(new BufferedReader(new FileReader("dinner.in")));
		PrintWriter out = new PrintWriter("dinner.out");
                BigInteger dp[][] = new BigInteger[200][200];
                int m = cin.nextInt(), n = cin.nextInt();
                for (int i=0; i<200; i++)
                    for (int j=0; j<200; j++)
                        dp[i][j] = BigInteger.ZERO;
                dp[0][0] = BigInteger.ONE;
                for (int i=0; i<n; i++)
                {
                    for (int j=0; j<=m; j++)
                    {
                        dp[i+1][j] = dp[i+1][j].add(dp[i][j].multiply(BigInteger.valueOf(j)));
                        dp[i+1][j+1] = dp[i+1][j+1].add(dp[i][j].multiply(BigInteger.valueOf(m-j)));
                    }
                }
                out.println(dp[n][m]);
		cin.close();
		out.flush();
		out.close();
	}
}
