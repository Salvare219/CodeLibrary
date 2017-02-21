import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner ( System.in );
        BigInteger ans,temp;
        BigInteger fac[]=new BigInteger[10002];
        fac[1]=BigInteger.ONE;fac[2]=BigInteger.valueOf(3);
        for(int i=3;i<10001;i++)
            fac[i]=fac[i-1].add(fac[i-2]);
        int n;
        while(cin.hasNext())
        {
            n=cin.nextInt();
            System.out.println(fac[n]);
        }
    }
}