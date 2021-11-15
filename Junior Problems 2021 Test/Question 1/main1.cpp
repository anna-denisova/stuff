#include "std_lib_facilities.h"

//Takes temperature of when water boils -> atmospheric pressure & sea level
//-1 below sea level
//  0 at sea level
//   1 above sea level

int main(){

    int atmospheric_pressure;
    int boiling_temp;
    int land_level;

    cin>>boiling_temp;

    atmospheric_pressure = 5*boiling_temp-400;

    if (atmospheric_pressure == 100){
        land_level = 0;
    }else if (atmospheric_pressure > 100){
        land_level = -1;
    }else{
        land_level = 1;
    }

    cout<<atmospheric_pressure<<"\n"<<land_level;
}

