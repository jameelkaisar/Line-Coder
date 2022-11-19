#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "./../decoder/decoder.h"
#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"
#include "./../plotter/plotter.h"
#include "./../scrambler/scrambler.h"
#include "./../unscrambler/unscrambler.h"

typedef std::vector<int> (Encoder::*FnPtrEncoder)(std::vector<int>);
typedef std::vector<int> (Decoder::*FnPtrDecoder)(std::vector<int>);
typedef std::vector<int> (Scrambler::*FnPtrScrambler)(std::vector<int>);
typedef std::vector<int> (Unscrambler::*FnPtrUnscrambler)(std::vector<int>);
typedef std::vector<int> (Generator::*FnPtrGenerator)(int, int);
typedef std::vector<int> (Plotter::*FnPtrPlotter)(std::vector<int>);

class Prompt {
   private:
    std::map<int, std::pair<std::string, FnPtrEncoder>> encoding_scheme;
    std::map<int, std::pair<std::string, FnPtrDecoder>> decoding_scheme;
    std::map<int, std::pair<std::string, FnPtrScrambler>> scrambling_scheme;
    std::map<int, std::pair<std::string, FnPtrUnscrambler>> unscrambling_scheme;
    std::map<int, std::pair<std::string, FnPtrGenerator>> generating_scheme;
    std::map<int, std::string> plotter_formats;

    void handle_run();
    void handle_main();
    int get_main();
    void handle_encoder();
    void handle_decoder(std::vector<int> input = {});
    std::vector<int> handle_generate(bool print = true);
    void handle_plotter(std::vector<int> bits = {});
    std::vector<int> execute_encoder(std::vector<int> bits, int encoder, bool scrambling, int scrambler, int plotting, std::pair<std::string, int> plotter);
    void execute_decoder(std::vector<int> bits, int decoder, bool unscrambling, int unscrambler);
    std::vector<int> execute_generator(int generator, int nbits, int consecutive, bool print);
    void execute_plotter(std::vector<int> bits, int plotting, std::pair<std::string, int> plotter);
    bool get_custom();
    std::vector<int> get_bits();
    int get_encoder();
    int get_decoder();
    bool do_scrambling();
    int get_scrambler();
    bool do_unscrambling();
    int get_unscrambler();
    int get_generator();
    int get_nbits();
    int get_consecutive(int n);
    int do_plotting(bool required = false);
    bool do_decoding();
    std::pair<std::string, int> get_plotter();
    std::string get_filename();
    int get_fileformat();

   public:
    Prompt() {
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
        generating_scheme = {
            {1, {"Random", &Generator::getRandom}},
            {2, {"Random with Zeros", &Generator::getRandomWithZeros}},
            {3, {"Random with Ones", &Generator::getRandomWithOnes}}};
        plotter_formats = {
            {1, "pdf"},
            {2, "svg"},
            {3, "png"},
            {4, "jpeg"}};
    }

    void run() {
        handle_run();
    }
};

void Prompt::handle_run() {
    std::cout << "Digital Data Encoder, Decoder and Scrambler with Data Generator and Graph Plotter:" << std::endl
              << std::endl;
    handle_main();
    std::cout << "Thanks for using this tool!" << std::endl;
}

void Prompt::handle_main() {
    int choice;
    while (true) {
        choice = get_main();
        std::cout << std::endl;
        if (choice == 0) return;
        if (choice == 1) handle_encoder();
        if (choice == 2) handle_decoder();
        if (choice == 3) handle_generate();
        if (choice == 4) handle_plotter();
        std::cout << std::endl;
    }
}

int Prompt::get_main() {
    std::set<int> valid = {0, 1, 2, 3, 4};
    int choice;
    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Encode" << std::endl;
        std::cout << "2. Decode" << std::endl;
        std::cout << "3. Generate" << std::endl;
        std::cout << "4. Plot" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (valid.find(choice) != valid.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    return choice;
}

void Prompt::handle_encoder() {
    std::vector<int> bits;
    bool custom = get_custom();
    if (custom) {
        bits = get_bits();
    } else {
        bits = handle_generate(false);
    }
    int encoder = get_encoder();
    bool scrambling = false;
    int scrambler = 0;
    if (encoding_scheme[encoder].first == "AMI") {
        scrambling = do_scrambling();
        if (scrambling)
            scrambler = get_scrambler();
    }
    int plotting = do_plotting();
    std::pair<std::string, int> plotter = {"", 0};
    if (plotting == 2 || plotting == 3)
        plotter = get_plotter();
    std::vector<int> output_bits = execute_encoder(bits, encoder, scrambling, scrambler, plotting, plotter);
    bool decoding = do_decoding();
    if (decoding) {
        std::cout << std::endl;
        handle_decoder(output_bits);
    }
}

void Prompt::handle_decoder(std::vector<int> input) {
    std::vector<int> bits;
    if (input.size() == 0)
        bits = get_bits();
    else
        bits = input;
    int decoder = get_decoder();
    bool unscrambling = false;
    int unscrambler = 0;
    if (decoding_scheme[decoder].first == "AMI") {
        unscrambling = do_unscrambling();
        if (unscrambling)
            unscrambler = get_unscrambler();
    }
    execute_decoder(bits, decoder, unscrambling, unscrambler);
}

std::vector<int> Prompt::handle_generate(bool print) {
    int generator = get_generator();
    int nbits = get_nbits();
    int consecutive = 0;
    if (generator != 1)
        consecutive = get_consecutive(nbits);
    return execute_generator(generator, nbits, consecutive, print);
}

void Prompt::handle_plotter(std::vector<int> bits) {
    if (bits.size() == 0)
        bits = get_bits();
    int plotting = do_plotting(true);
    std::pair<std::string, int> plotter = {"", 0};
    if (plotting == 2 || plotting == 3)
        plotter = get_plotter();
    execute_plotter(bits, plotting, plotter);
}

std::vector<int> Prompt::execute_encoder(std::vector<int> bits, int encoder, bool scrambling, int scrambler, int plotting, std::pair<std::string, int> plotter) {
    Encoder e;
    Scrambler s;
    std::cout << "Encoder Result:" << std::endl;
    std::cout << "Input Bits: " << to_stringv(bits, " ") << std::endl;
    std::vector<int> output_bits;
    if (!scrambling)
        output_bits = (e.*encoding_scheme[encoder].second)(bits);
    else
        output_bits = (s.*scrambling_scheme[scrambler].second)(bits);
    std::cout << "Encoded Bits: " << to_stringv(output_bits, " ") << std::endl;
    std::cout << "Longest Palindrome: " << to_stringv(getLongestPallindrome(output_bits), " ") << std::endl;
    execute_plotter(output_bits, plotting, plotter);
    std::cout << std::endl;
    return output_bits;
}

void Prompt::execute_decoder(std::vector<int> bits, int decoder, bool unscrambling, int unscrambler) {
    Decoder d;
    Unscrambler u;
    std::cout << "Decoder Result:" << std::endl;
    std::cout << "Input Bits: " << to_stringv(bits, " ") << std::endl;
    std::vector<int> output_bits;
    if (!unscrambling)
        output_bits = (d.*decoding_scheme[decoder].second)(bits);
    else
        output_bits = (u.*unscrambling_scheme[unscrambler].second)(bits);
    std::cout << "Decoded Bits: " << to_stringv(output_bits, " ") << std::endl;
    std::cout << "Longest Palindrome: " << to_stringv(getLongestPallindrome(output_bits), " ") << std::endl;
}

std::vector<int> Prompt::execute_generator(int generator, int nbits, int consecutive, bool print) {
    Generator g;
    std::vector<int> bits = (g.*generating_scheme[generator].second)(nbits, consecutive);
    if (print) {
        std::cout << "Generator Result:" << std::endl;
        std::cout << "Generated Bits: " << to_stringv(bits, " ") << std::endl;
        std::cout << "Longest Palindrome: " << to_stringv(getLongestPallindrome(bits), " ") << std::endl;
    }
    return bits;
}

void Prompt::execute_plotter(std::vector<int> bits, int plotting, std::pair<std::string, int> plotter) {
    Plotter p;
    std::string fullname = plotter.first + "." + plotter_formats[plotter.second];
    if (plotting == 1 || plotting == 3)
        p.plot(bits, true);
    if (plotting == 2 || plotting == 3)
        p.plot(bits, false, fullname);
    std::cout << "Plotting operation success!" << std::endl;
}

bool Prompt::get_custom() {
    int choice;
    while (true) {
        std::cout << "Choose the input data source?" << std::endl;
        std::cout << "1. Custom" << std::endl;
        std::cout << "2. Generator" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice == 1;
}

std::vector<int> Prompt::get_bits() {
    int n;
    while (true) {
        std::cout << "Enter No. of Values (n):" << std::endl;
        std::cout << ">> ";
        std::cin >> n;
        if (n > 0) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::vector<int> v;
    while (n--) {
        int x;
        std::cout << "    >> ";
        std::cin >> x;
        v.push_back(x);
    }
    std::cout << std::endl;
    return v;
}

int Prompt::get_encoder() {
    int choice;
    while (true) {
        std::cout << "Choose an encoder:" << std::endl;
        for (auto x : encoding_scheme) {
            std::cout << x.first << ". " << x.second.first << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (encoding_scheme.find(choice) != encoding_scheme.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

int Prompt::get_decoder() {
    int choice;
    while (true) {
        std::cout << "Choose a decoder:" << std::endl;
        for (auto x : decoding_scheme) {
            std::cout << x.first << ". " << x.second.first << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (decoding_scheme.find(choice) != decoding_scheme.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

bool Prompt::do_scrambling() {
    int choice;
    while (true) {
        std::cout << "Do you want to scramble the data?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice == 1;
}

int Prompt::get_scrambler() {
    int choice;
    while (true) {
        std::cout << "Choose a scrambler:" << std::endl;
        for (auto x : scrambling_scheme) {
            std::cout << x.first << ". " << x.second.first << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (scrambling_scheme.find(choice) != scrambling_scheme.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

bool Prompt::do_unscrambling() {
    int choice;
    while (true) {
        std::cout << "Is the data scrambled?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice == 1;
}

int Prompt::get_unscrambler() {
    int choice;
    while (true) {
        std::cout << "Choose an unscrambler:" << std::endl;
        for (auto x : unscrambling_scheme) {
            std::cout << x.first << ". " << x.second.first << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (unscrambling_scheme.find(choice) != unscrambling_scheme.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

int Prompt::get_generator() {
    int choice;
    while (true) {
        std::cout << "Choose a generator:" << std::endl;
        for (auto x : generating_scheme) {
            std::cout << x.first << ". " << x.second.first << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (generating_scheme.find(choice) != generating_scheme.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

int Prompt::get_nbits() {
    int n;
    while (true) {
        std::cout << "Enter No. of Values (n):" << std::endl;
        std::cout << ">> ";
        std::cin >> n;
        if (n > 0) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return n;
}

int Prompt::get_consecutive(int n) {
    int consecutive;
    while (true) {
        std::cout << "Enter No. of Consecutive Values:" << std::endl;
        std::cout << ">> ";
        std::cin >> consecutive;
        if (consecutive > 0 && consecutive <= n) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return consecutive;
}

int Prompt::do_plotting(bool required) {
    int choice;
    while (true) {
        std::cout << "Choose an option to plot the data?" << std::endl;
        std::cout << "1. Show only" << std::endl;
        std::cout << "2. Save only" << std::endl;
        std::cout << "3. Show and save" << std::endl;
        if (!required) std::cout << "4. Skip plotting" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3 || (!required && choice == 4)) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}

bool Prompt::do_decoding() {
    int choice;
    while (true) {
        std::cout << "Do you want to decode the output data?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;
        if (choice == 1 || choice == 2) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    return choice == 1;
}

std::pair<std::string, int> Prompt::get_plotter() {
    std::string filename = get_filename();
    int fileformat = get_fileformat();
    return {filename, fileformat};
}

std::string Prompt::get_filename() {
    std::string filename;
    std::cin.ignore();
    while (true) {
        std::cout << "Enter a filename:" << std::endl;
        std::cout << ">> ";
        getline(std::cin, filename);
        if (filename.size() > 0) break;
        std::cout << "Enter a valid filename!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return filename;
}

int Prompt::get_fileformat() {
    int choice;
    while (true) {
        std::cout << "Choose an output format:" << std::endl;
        for (auto x : plotter_formats) {
            std::cout << x.first << ". " << x.second << std::endl;
        }
        std::cout << ">> ";
        std::cin >> choice;
        if (plotter_formats.find(choice) != plotter_formats.end()) break;
        std::cout << "Enter a valid choice!" << std::endl
                  << std::endl;
    }
    std::cout << std::endl;
    return choice;
}
