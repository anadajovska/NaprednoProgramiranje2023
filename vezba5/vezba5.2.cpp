#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[]="No broken hearts - Bebe Rexha";
	int n=strlen(s);
	char *poc=s;
	cout<<"Cela pesna : "<<poc<<endl<<"pocetna pozicija na pokazuvacot : "<<*poc<<"\nAdresa na pocetok : "<<&poc;
	int i,k=1;
	for(i=0;i<n;i++)
	{
		k=k+1;
		if(s[i]=='-')
		break;
	}
	poc+=k;
	cout<<"\npomestuvanje do ime na izveduvac\nsodrzina po premesten pocetok : "<<poc<<"\nAdresa od koja pocnuva segasnata sodrzina "<<(&poc+k);
	return 0;
}
