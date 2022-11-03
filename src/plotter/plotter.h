#include <bits/stdc++.h>

#include <sciplot/sciplot.hpp>

using namespace std;
using namespace sciplot;

class Plotter {
   private:
   public:
    Plotter() {
    }

    void plot(vector<int> y, string filename, int width = -1, int height = -1) {
        vector<float> yf(y.begin(), y.end());
        plot(yf, filename, width, height);
    }

    void plot(vector<float> y, string filename, int width = -1, int height = -1) {
    }
};
