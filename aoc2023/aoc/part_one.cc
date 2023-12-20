module;
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

export module part_one;

export namespace part_one {
char convertStringToCharOfNumber(string input) {
  if (input == "one") {
    return '1';
  }
  if (input == "two") {
    return '2';
  }
  if (input == "three") {
    return '3';
  }
  if (input == "four") {
    return '4';
  }
  if (input == "five") {
    return '5';
  }
  if (input == "six") {
    return '6';
  }
  if (input == "seven") {
    return '7';
  }
  if (input == "eight") {
    return '8';
  }
  if (input == "nine") {
    return '9';
  }
  // null value
  return '0';
};

int64_t calibration() {
  fstream new_file;

  // open a file to perform read operation using file object.
  new_file.open("puzzle_day1.txt", ios::in);

  const char *numbers[9] = {"one", "two",   "three", "four", "five",
                            "six", "seven", "eight", "nine"};

  int total = 0;
  // Checking whether the file is open.
  if (new_file.is_open()) {
    string line;
    // Read data from the file object and put it into a string.
    while (getline(new_file, line)) {

      // search for first number
      size_t foundFirstIndex =
          line.find_first_of("123456789"); // 2 || max unsigned
      size_t foundLastIndex =
          line.find_last_of("123456789"); // 2 || max unsigned
      unsigned long long foundWordSmallestIndex =
          18446744073709551615U;        // 2 || max unsigned
      size_t foundWordLargestIndex = 0; // 2 || 0
      string foundFirstWord = "";
      string foundLastWord = "";

      // check if any words are earlier or later than the number check
      for (const string &num : numbers) {
        // cout << "print number test: " << num << endl;
        size_t foundLocFirst = line.find(num);
        size_t foundLocLast = line.rfind(num);
        if (foundLocFirst == 18446744073709551615U) {
          // skip if we didnt find it
          continue;
        }
        if (foundLocFirst < foundWordSmallestIndex) {
          foundWordSmallestIndex = foundLocFirst;
          // cout << "found new first word: " << num << endl;
          foundFirstWord = num;
        }
        if (foundLocLast >= foundWordLargestIndex) {
          // cout << "found new last word: " << num << endl;
          foundWordLargestIndex = foundLocLast;
          foundLastWord = num;
        }
      }

      //   cout << "Debuggin: "
      //        << part_one::convertStringToCharOfNumber(foundLastWord) << endl;

      string tempS;
      // combine the chars to a string so we can concat

      tempS += foundFirstIndex < foundWordSmallestIndex
                   ? line[foundFirstIndex]
                   : convertStringToCharOfNumber(foundFirstWord);
      tempS += (foundLastIndex >= foundWordLargestIndex &&
                foundLastIndex != 18446744073709551615U)
                   ? line[foundLastIndex]
                   : convertStringToCharOfNumber(foundLastWord);

      // Convert to int.
      int combined = stoi(tempS);
      cout << "Found combined value: " << combined << endl;

      total = total + combined;
      // debug current number
      std::cout << total << "\n";
    }

    // Close the file object.
    new_file.close();
  }
  return total;
}

}; // namespace part_one