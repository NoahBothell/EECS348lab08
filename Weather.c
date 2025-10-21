//Noah Bothell
//KUID: 3179068
//EECS 348 lab 8
//date created: 10/19/2025
//outputs temperature "analysis" based on the temp the user puts in
#include <stdio.h>
#include <stdlib.h>

//converts Celsius to Kelvin
float CtoK(float temp){
    return temp + 273.15;
}

//converts Celsius to fahrenheit
float CtoF(float temp){
    return (9*temp)/5 + 32;
}

//converts kelvin to Celsius
float KtoC(float temp){
    return temp - 273.15;
}

//converts fahrenheit to celsius
float FtoC(float temp){
    return (5*(temp - 32))/9;
}

int main(){
    //temp is the current temperature number, scale is the current temperature scale, newscale is the one i want to convert to
    //tempcat is the category of the temperature, and advice is for the weather advisory.
    float temp = 0;
    char scale;
    char newscale;
    char c;

    //getting input
    printf("Please input the temperature:");
    scanf("%f", &temp);
    c = getchar();

    printf("Please enter original scale (F, C, or K):");
    scanf("%c", &scale);
    c = getchar();

    //valid input check
    while (scale != 'F' && scale !='C' && scale != 'K'){
        printf("Please ensure your measurement scale is one of the following:F, C, or K:");
        scanf("%c", &scale);
        c = getchar();

    }
    
    //getting the temp to convert to
    printf("What temperature would you like to swith to (F, C, or K)?:");
    scanf("%c", &newscale);
    c = getchar();

    //valid input check
    while (newscale != 'F' && newscale !='C' && newscale != 'K'){
        printf("Please ensure your measurement scale is one of the following:F, C, or K:");
        scanf("%c", &newscale);
    }

    //converting to celcius to have a standard to work off of
    if (scale == 'F'){
        temp = FtoC(temp);
    }
    else if (scale == 'K'){
        temp = KtoC(temp);
    }
    scale = 'C';

    //using my defined functions to output a desired temperature conversion
    if(newscale == 'C'){
        printf("Converted temperature: %f C\n", temp);
    }
    else if(newscale == 'F'){
        printf("Converted temperature: %f F\n", CtoF(temp));
    }
    else if(newscale == 'K'){
        printf("Converted temperature: %f K\n", CtoK(temp));
    }

    //printing a weather "advisory" based on the temperature in Celcius
    if (temp < 0){
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: stay indoors\n");
    }
    else if(temp >= 0 && temp < 10){
        printf("Temperature category: Cold\n");
        printf("Weather advisory: put on a coat\n");
    }
    else if(temp >= 10 && temp < 25){
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: enjoy the weather!\n");
    }
    else if(temp >= 25 && temp < 35){
        printf("Temperature category: Hot\n");
        printf("Weather advisory: turn on the fan\n");
    }
    else{
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: stay indoors\n");
    }
    return 0;
}