#include <bits/stdc++.h>

#include "./plotter/plotter.h"

using namespace std;

class Prompt {
   private:
   public:
    Prompt() {
    }

    void run() {
        cout << "Digital Data Encoder, Decoder and Scrambler with Data Generator and Graph Plotter:" << endl
             << endl;
        int choice;
        while (true) {
            choice = get_main();
            if (choice == 0) {
                cout << "Thanks for using this tool!" << endl;
                break;
            }
            get_bits(choice);
            cout << endl;
        }
    }

    int get_main() {
        cout << "Choose an option:" << endl;
        cout << "1. Encode" << endl;
        cout << "2. Decode" << endl;
        cout << "3. Plot" << endl;
        cout << "0. Exit" << endl;
        cout << ">> ";
        int choice;
        cin >> choice;
        return choice;
    }

    void get_bits(int choice) {
        set<int> valid = {1, 2, 3};
        if (valid.find(choice) == valid.end()) {
            cout << "Enter a valid choice!" << endl;
            return;
        }
        int n;
        cout << endl;
        cout << "Enter No. of Values (n):" << endl;
        cout << ">> ";
        cin >> n;
        vector<float> v;
        while (n--) {
            float x;
            cout << "    >> ";
            cin >> x;
            v.push_back(x);
        }
        if (choice == 1) {
            cout << "Encoder!!!" << endl;
        } else if (choice == 2) {
            cout << "Decoder!!!" << endl;
        } else if (choice == 3) {
            string filename;
            map<int, string> formats = {
                {1, "pdf"},
                {2, "svg"},
                {3, "png"},
                {4, "jpeg"},
                {0, "back"},
            };
            int format = -1;
            cout << endl;
            cout << "Enter filename:" << endl;
            cout << ">> ";
            cin.ignore();
            getline(cin, filename);
            while (true) {
                cout << endl;
                cout << "Choose a format:" << endl;
                for (int i = 1; i < formats.size(); i++)
                    cout << i << ". " << formats[i] << endl;
                cout << "0. Back" << endl;
                cout << ">> ";
                cin >> format;
                if (formats.find(format) != formats.end())
                    break;
                cout << "Enter a valid choice!" << endl;
            }
            if (format == 0) return;
            handle_plot(v, filename + "." + formats[format]);
        }
    }

    void handle_plot(vector<float> y, string filename) {
        Plotter p;
        p.plot(y, filename);
        cout << "Plot saved successfully!" << endl;
    }
};
