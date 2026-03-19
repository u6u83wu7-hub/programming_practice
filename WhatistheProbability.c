
/*公式： Pi => p 是中的機率，q是一整輪全部失敗的機率= (1-p)*N， N是人數， i是第幾個人 
			=  (1-p)^(i-1)*p+ q*(1-p)^(i-1)*p+ q^2*(1-p)^(i-1)*p+  ....
			=  (1-p)^(i-1)*p*(1+q+q^2+q^3...)
			=  (1-p)^(i-1)*p*(1/1-q)因為0<q<1 
			=   pi = (1-p)^(i-1)*p/1-(1-p)^N
*/
#include <stdio.h>
#include <math.h>

int main() {
    int num;
    double p;
    int who;
    int i, n;
	scanf("%d", &n);
    for (i = 0; i<n; i++) {
    	scanf("%d %lf %d", &num, &p, &who);
    	if (p == 0) {
            printf("0.0000\n");
        }else {
	        double q = pow(1 - p, num);
	        double pi = pow(1 - p, who - 1) * p / (1 - q);
	
	        printf("%.4lf\n", pi);
        } 
    }

    return 0;
}
		
