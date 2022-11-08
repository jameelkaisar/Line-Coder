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
        int plotter = 0;
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
        string filename = get_filename();
        int fileformat = get_fileformat();
        execute_plotter(bits, filename, fileformat);
    }

    void execute_encoder(vector<int> bits, int decoder, bool scrambling, int scrambler, bool plotting, int plotter) {
        cout << "Execute Encoder" << endl;
        cout << endl;
    }

    void execute_decoder(vector<int> bits, int decoder, bool unscrambling, int unscrambler) {
        cout << "Execute Decoder" << endl;
        cout << endl;
    }

    void execute_plotter(vector<int> bits, string filename, int fileformat) {
        Plotter p;
        string fullname = filename + "." + plotter_formats[fileformat];
        p.plot(bits, fullname);
        cout << "Plot saved successfully!" << endl;
    }

    vector<int> get_bits() {
        cout << "Get Bits" << endl;
        cout << endl;
        return {};
    }

    int get_encoder() {
        cout << "Get Encoder" << endl;
        cout << endl;
        return 0;
    }

    int get_decoder() {
        cout << "Get Decoder" << endl;
        cout << endl;
        return 0;
    }

    bool do_scrambling() {
        cout << "Do Scrambling" << endl;
        cout << endl;
        return false;
    }

    int get_scrambler() {
        cout << "Get Scrambler" << endl;
        cout << endl;
        return 0;
    }

    bool do_unscrambling() {
        cout << "Do Unscrambling" << endl;
        cout << endl;
        return false;
    }

    int get_unscrambler() {
        cout << "Get Unscrambler" << endl;
        cout << endl;
        return 0;
    }

    bool do_plotting() {
        cout << "Do Plotting" << endl;
        cout << endl;
        return false;
    }

    int get_plotter() {
        cout << "Get Plotter" << endl;
        cout << endl;
        return 0;
    }

    string get_filename() {
        cout << "Get Filename" << endl;
        cout << endl;
        return "";
    }

    int get_fileformat() {
        cout << "Get Fileformat" << endl;
        cout << endl;
        return 0;
    }
};
