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
        int n = y.size();
        float mini = *min_element(y.begin(), y.end());
        float maxi = *max_element(y.begin(), y.end());

        Plot2D plot;

        plot.xlabel("Time");
        plot.ylabel("Voltage");
        plot.legend().hide();

        float x_min = 0;
        float x_max = n;
        float y_min = mini - 0.1;
        float y_max = maxi + 0.1;
        plot.xrange(x_min, x_max);
        plot.yrange(y_min, y_max);

        Vec base_x = linspace(x_min, x_max, 1);
        Vec base_y = linspace(0, 0, 1);
        plot.drawCurve(base_x, base_y).lineColor("grey");

        vector<float> x(n, 0.5);
        for (int i = 0; i < n; i++)
            x[i] += i;

        plot.drawStepsHistogram(x, y).lineColor("red");

        Figure fig = {{plot}};
        Canvas canvas = {{fig}};
        if (width != -1 && height != -1)
            canvas.size(width, height);
        canvas.save(filename);
    }
};
