
import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin=new Scanner(System.in);
        int t=cin.nextInt();
        for(int i=0;i<t;i++)
        {
            BigInteger n=cin.nextBigInteger();
            BigInteger b=n.divide(BigInteger.valueOf(2));
            if(n.testBit(0)) System.out.println(b);
            else if(n.testBit(1)) System.out.println(b.add(BigInteger.valueOf(-2)));
            else System.out.println(b.add(BigInteger.valueOf(-1)));
            if(i!=t-1) System.out.println();
        }
    }
}