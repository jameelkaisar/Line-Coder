#include "plotter.h"

#include <bits/stdc++.h>

using namespace std;

int main() {
    Plotter p;

    vector<int> y = {1, 0, 1, -1, -1, 0, 1, 0, -1, 0, 1, 0};

    p.plot(y, "plotter.pdf");
    p.plot(y, "plotter.svg");
    p.plot(y, "plotter.png");
    p.plot(y, "plotter.jpeg");

    return 0;
}
