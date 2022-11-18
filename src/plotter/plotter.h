#include <sciplot/sciplot.hpp>
#include <string>
#include <vector>

class Plotter {
   public:
    void plot(std::vector<int> y, bool show=true, std::string filename="", int width = -1, int height = -1);
    void plot(std::vector<float> y, bool show=true, std::string filename="", int width = -1, int height = -1);
};

void Plotter::plot(std::vector<int> y, bool show, std::string filename, int width, int height) {
    std::vector<float> yf(y.begin(), y.end());
    plot(yf, show, filename, width, height);
}

void Plotter::plot(std::vector<float> y, bool show, std::string filename, int width, int height) {
    int n = y.size();
    float mini = *min_element(y.begin(), y.end());
    float maxi = *max_element(y.begin(), y.end());

    sciplot::Plot2D plot;

    plot.xlabel("Time");
    plot.ylabel("Voltage");
    plot.legend().hide();

    float x_min = 0;
    float x_max = n;
    float y_min = mini - 0.1;
    float y_max = maxi + 0.1;
    plot.xrange(x_min, x_max);
    plot.yrange(y_min, y_max);

    sciplot::Vec base_x = sciplot::linspace(x_min, x_max, 1);
    sciplot::Vec base_y = sciplot::linspace(0, 0, 1);
    plot.drawCurve(base_x, base_y).lineColor("grey");

    std::vector<float> x(n, 0.5);
    for (int i = 0; i < n; i++)
        x[i] += i;

    plot.drawStepsHistogram(x, y).lineColor("red");

    sciplot::Figure fig = {{plot}};
    sciplot::Canvas canvas = {{fig}};
    width = width == -1 ? 500 + 300 * y.size() : width;
    height = height == -1 ? 500 : height;
    canvas.size(width, height);
    if (show) canvas.show();
    else canvas.save(filename);
}
