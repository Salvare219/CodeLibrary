import java.io.*;
import java.lang.*;
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
    public static void main(String[] args)
    {
        //Scanner cin = new Scanner ( System.in );
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        long T=in.nextInt();
        int cas = 0;
        while(T-->0)
        {
            long t = in.nextLong();
            BigInteger n = BigInteger.valueOf(t);
            BigInteger nn = n.multiply(n);
            BigInteger e=BigInteger.valueOf(8);
            BigInteger s=BigInteger.valueOf(7);
            BigInteger o=BigInteger.ONE;
            cas++;
            out.print("Case #");
            out.print(cas);
            out.print(": ");
            out.println(e.multiply(nn).subtract(s.multiply(n)).add(o));
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