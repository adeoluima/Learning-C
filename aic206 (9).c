/* aic206
 * assessment 1
 */

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main() {
    float v, a, t;
    double time;
    printf("Please input the initial velocity of the projectile: \n");
    scanf("%f", &v);
    while(v < 0){
        printf("The velocity must be greater than 0. What is the velocity of the projectile?\n");
        scanf("%f", &v);
    }
    
    printf("Please input the launching angle of the projectile: \n");
    scanf("%f", &a);
    
    
    // Sanity check for angle units
    int number;
    printf("Did you give the angle in radians or degrees?\n Type 1 for radians and 2 for degrees.\n");
    scanf("%i", &number);
    switch(number){
        case 1:
            a = M_PI*a/180; //convert degrees to radians
            while(a < 0 || a > 90){ // Sanity check for angle - must be between 0 and 90 degrees
                printf("Your angle must be between 0 and pi/2 radians. Please input another angle.\n");
                scanf("%f", &a);
                a=a;
            }
            break;
        case 2:
            while(a < 0 || a > 90){ // Sanity check for angle - must be between 0 and 90 degrees
                printf("Your angle must be between 0 and 90 degrees. Please input another angle in degrees.\n");
                scanf("%f", &a);
                a = a;
            }
            a=a;
            break;
    }
    
    
    //calculate the time of flight
    t = v*sinf(a)/9.81;
    time = 2*t;
    printf("The total flight time is %g seconds, therefore...\n", time);
    
    //calculate horizontal distance
    float d;
    d = v*time*cosf(a);
    printf("The horizontal distance travelled by the projectile is: %f metres.\n", d);
    
    //calculate vertical distance
    float h;
    h = v*t*sinf(a) - 0.5*9.81*powf(t, 2);
    printf("The maximum vertical distance travelled by the projectile is: %f metres.\n", h);
    
    return 0;
}
