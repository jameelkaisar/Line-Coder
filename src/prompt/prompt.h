#include <bits/stdc++.h>

#include "./../decoder/decoder.h"
#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"
#include "./../plotter/plotter.h"
#include "./../scrambler/scrambler.h"
#include "./../unscrambler/unscrambler.h"

using namespace std;

typedef vector<int> (Generator::*FnPtrGenerator)(int, int);
typedef vector<int> (Encoder::*FnPtrEncoder)(vector<int>);
typedef vector<int> (Decoder::*FnPtrDecoder)(vector<int>);
typedef vector<int> (Scrambler::*FnPtrScrambler)(vector<int>);
typedef vector<int> (Unscrambler::*FnPtrUnscrambler)(vector<int>);
typedef vector<int> (Plotter::*FnPtrPlotter)(vector<int>);

class Prompt {
   private:
    map<int, pair<string, FnPtrGenerator>> generating_scheme;
    map<int, pair<string, FnPtrEncoder>> encoding_scheme;
    map<int, pair<string, FnPtrDecoder>> decoding_scheme;
    map<int, pair<string, FnPtrScrambler>> scrambling_scheme;
    map<int, pair<string, FnPtrUnscrambler>> unscrambling_scheme;
    map<int, string> plotter_formats;

   public:
    Prompt() {
        generating_scheme = {
            {2, {"getRandom", &Generator::getRandom}},
            {3, {"getRandomWithZeros", &Generator::getRandomWithZeros}},
            {4, {"getRandomWithOnes", &Generator::getRandomWithOnes}}};
        encoding_scheme = {
            {1, {"NRZ_L", &Encoder::NRZ_L}},
            {2, {"NRZ_I", &Encoder::NRZ_I}},
            {3, {"Manchester", &Encoder::Manchester}},
            {4, {"Differential_Manchester", &Encoder::Differential_Manchester}},
            {5, {"AMI", &Encoder::AMI}}};
        decoding_scheme = {
            {1, {"NRZ_L", &Decoder::NRZ_L}},
            {2, {"NRZ_I", &Decoder::NRZ_I}},
            {3, {"Manchester", &Decoder::Manchester}},
            {4, {"Differential_Manchester", &Decoder::Differential_Manchester}},
            {5, {"AMI", &Decoder::AMI}}};
        scrambling_scheme = {
            {1, {"HDB3", &Scrambler::HDB3}},
            {2, {"B8ZS", &Scrambler::B8ZS}}};
        unscrambling_scheme = {
            {1, {"HDB3", &Unscrambler::HDB3}},
            {2, {"B8ZS", &Unscrambler::B8ZS}}};
        plotter_formats = {
            {1, "pdf"},
            {2, "svg"},
            {3, "png"},
            {4, "jpeg"}};
    }

    void run() {
        cout << "Digital Data Encoder, Decoder and Scrambler with Data Generator and Graph Plotter:" << endl
             << endl;
        handle_main();
        cout << "Thanks for using this tool!" << endl;
    }

    void handle_main() {
        int choice;
        while (true) {
            choice = get_main();
            cout << endl;
            if (choice == 0) return;
            if (choice == 1) handle_encoder();
            if (choice == 2) handle_decoder();
            if (choice == 3) handle_plotter();
        }
    }

    int get_main() {
        set<int> valid = {0, 1, 2, 3};
        int choice;
        while (true) {
            cout << "Choose an option:" << endl;
            cout << "1. Encode" << endl;
            cout << "2. Decode" << endl;
            cout << "3. Plot" << endl;
            cout << "0. Exit" << endl;
            cout << ">> ";
            cin >> choice;
            if (valid.find(choice) != valid.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        return choice;
    }

    void handle_encoder() {
        vector<int> bits = get_bits();
        int encoder = get_encoder();
        bool scrambling = do_scrambling();
        int scrambler = 0;
        if (scrambling)
            scrambler = get_scrambler();
        bool plotting = do_plotting();
        pair<string, int> plotter = {"", 0};
        if (plotting)
            plotter = get_plotter();
        execute_encoder(bits, encoder, scrambling, scrambler, plotting, plotter);
    }

    void handle_decoder() {
        vector<int> bits = get_bits();
        int decoder = get_decoder();
        bool unscrambling = do_unscrambling();
        int unscrambler = 0;
        if (unscrambling)
            unscrambler = get_unscrambler();
        execute_decoder(bits, decoder, unscrambling, unscrambler);
    }

    void handle_plotter(vector<int> bits = {}) {
        if (bits.size() == 0)
            bits = get_bits();
        pair<string, int> plotter = get_plotter();
        execute_plotter(bits, plotter);
    }

    void execute_encoder(vector<int> bits, int decoder, bool scrambling, int scrambler, bool plotting, pair<string, int> plotter) {
        cout << "Execute Encoder" << endl;
        cout << endl;
    }

    void execute_decoder(vector<int> bits, int decoder, bool unscrambling, int unscrambler) {
        cout << "Execute Decoder" << endl;
        cout << endl;
    }

    void execute_plotter(vector<int> bits, pair<string, int> plotter) {
        Plotter p;
        string fullname = plotter.first + "." + plotter_formats[plotter.second];
        p.plot(bits, fullname);
        cout << "Plot saved successfully!" << endl;
        cout << endl;
    }

    vector<int> get_bits() {
        cout << endl;
        int n;
        while (true) {
            cout << "Enter No. of Values (n):" << endl;
            cout << ">> ";
            cin >> n;
            if (n > 0) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        vector<int> v;
        while (n--) {
            int x;
            cout << "    >> ";
            cin >> x;
            v.push_back(x);
        }
        cout << endl;
        return v;
    }

    int get_encoder() {
        int choice;
        while (true) {
            cout << "Choose an encoder:" << endl;
            for (auto x : encoding_scheme) {
                cout << x.first << ". " << x.second.first << endl;
            }
            cout << ">> ";
            cin >> choice;
            if (encoding_scheme.find(choice) != encoding_scheme.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice;
    }

    int get_decoder() {
        int choice;
        while (true) {
            cout << "Choose a decoder:" << endl;
            for (auto x : decoding_scheme) {
                cout << x.first << ". " << x.second.first << endl;
            }
            cout << ">> ";
            cin >> choice;
            if (decoding_scheme.find(choice) != decoding_scheme.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice;
    }

    bool do_scrambling() {
        int choice;
        while (true) {
            cout << "Do you want to scramble the data?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << ">> ";
            cin >> choice;
            if (choice == 1 || choice == 2) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice == 1;
    }

    int get_scrambler() {
        int choice;
        while (true) {
            cout << "Choose a scrambler:" << endl;
            for (auto x : scrambling_scheme) {
                cout << x.first << ". " << x.second.first << endl;
            }
            cout << ">> ";
            cin >> choice;
            if (scrambling_scheme.find(choice) != scrambling_scheme.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice;
    }

    bool do_unscrambling() {
        int choice;
        while (true) {
            cout << "Do you want to unscramble the data?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << ">> ";
            cin >> choice;
            if (choice == 1 || choice == 2) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice == 1;
    }

    int get_unscrambler() {
        int choice;
        while (true) {
            cout << "Choose an unscrambler:" << endl;
            for (auto x : unscrambling_scheme) {
                cout << x.first << ". " << x.second.first << endl;
            }
            cout << ">> ";
            cin >> choice;
            if (unscrambling_scheme.find(choice) != unscrambling_scheme.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice;
    }

    bool do_plotting() {
        int choice;
        while (true) {
            cout << "Do you want to plot the data?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << ">> ";
            cin >> choice;
            if (choice == 1 || choice == 2) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice == 1;
    }

    pair<string, int> get_plotter() {
        string filename = get_filename();
        int fileformat = get_fileformat();
        return {filename, fileformat};
    }

    string get_filename() {
        string filename;
        cin.ignore();
        while (true) {
            cout << "Enter a filename:" << endl;
            cout << ">> ";
            getline(cin, filename);
            if (filename.size() > 0) break;
            cout << "Enter a valid filename!" << endl
                 << endl;
        }
        cout << endl;
        return filename;
    }

    int get_fileformat() {
        int choice;
        while (true) {
            cout << "Choose an output format:" << endl;
            for (auto x : plotter_formats) {
                cout << x.first << ". " << x.second << endl;
            }
            cout << ">> ";
            cin >> choice;
            if (plotter_formats.find(choice) != plotter_formats.end()) break;
            cout << "Enter a valid choice!" << endl
                 << endl;
        }
        cout << endl;
        return choice;
    }
};
