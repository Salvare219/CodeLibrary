
//(pi^(n/2)*r^n)/gama(n/2);

double V(int n,double r)
{
    return pow(pi,n/2.0)*pow(r,n)/tgamma(n/2.0+1);
}