#include<iostream>
#include"namesp.h"
void other(void);
void another(void);
int main(void)
{
	using debts::Debt;
	using debts::showDebt;
	Debt golf={{"Benny","Goatsniff"},120.0};
	showDebt(golf);
	other();
	another();
	return 0;
}
void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg={"Dooles","Glister"};
	showPerson(dg);
	Debt zippy[3];
	int i;
	for(i=0;i<3;i++)
		getDebt(zippy[i]);
	for(int j=0;j<3;j++)
		showDebt(zippy[j]);
	cout<<"Total debt: $"<<sumDebts(zippy,3)<<endl;
	return;
}
void another(void)
{
	using pers::Person;
	Person collector={"Milo","Rightshift"};
	pers::showPerson(collector);
	std::cout<<std::endl;
}

