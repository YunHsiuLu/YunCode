#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, G, B;
    cin >> R >> G >> B;
    float r=R/255., g=G/255., b=B/255.;
    float max = fmax(r, fmax(g, b));
    float min = fmin(r, fmin(g, b));
    float l = (max+min)/2.;
    float h, s;
    if (max==min) h = 0.;
    else {
        if ((max == r) && (g >= b)) h = 60*(g-b)/(max-min);
        else if ((max == r) && (g < b)) h = 60*(g-b)/(max-min) + 360;
        else if ((max == g) && (max != r)) h = 60*(b-r)/(max-min) + 120;
        else if ((max == b) && (max != g) && (max != r)) h = 60*(r-g)/(max-min) + 240;
    }

    if ((l == 0) || (max==min)) s = 0;
    else if ((l > 0) && (l <= 0.5)) s = (max-min)/2/l;
    else if ((l > 0.5)) s = (max-min)/(2-2*l);

    s *= 255;
    l *= 255;
    cout << (int)round(h) << " " << (int)round(s) << " " << (int)round(l) << endl;
    
	return 0;
}

