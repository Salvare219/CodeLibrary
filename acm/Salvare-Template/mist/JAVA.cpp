import java.util.*;
import java.math.*;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
public class Main
{
    public static BigInteger gcd(BigInteger a, BigInteger b)
    {
        if(b.compareTo(BigInteger.ZERO) == 0)
            return a;
        return gcd(b, a.mod(b));
    }
    public static void main(String args[])
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        long T=in.nextInt();
        int cas = 0;
        while(T-->0)
        {
            long n = in.nextInt();
            long ans = -7 * n + 1;
            BigInteger nn = BigInteger.valueOf(n);
            nn = nn.multiply(nn);
            cas++;
            out.print("Case #");
            out.print(cas);
            out.print(": ");
            out.println(nn.multiply(BigInteger.valueOf(8)).add(BigInteger.valueOf(ans)));
        }
        out.close();
    }
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
}
	
	
	
	
