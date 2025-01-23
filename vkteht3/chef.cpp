#include "chef.h"


Chef::Chef(string s){
    chefName = s;
    cout << "Chef created: " << chefName << endl;
}

Chef::~Chef()
{
    cout << "Chef destroyed: " << chefName << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int aines)
{
    int aineksetpersalaatti = 5;
    int annos = aines / aineksetpersalaatti;
    cout << "Chef Gordon with " << aines << " items ";
    return annos;
}

int Chef::makeSoup(int aines)
{
    int aineksetperkeitto = 3;
    int annos = aines / aineksetperkeitto;
    cout << "Chef Gordon with " << aines << " items ";
    return annos;

}
