[12:55 p.m.] Everill,James

#include <iostream>
bool is_palindrome(std::string input) {
    auto input_length = input.length();
    for (int i = 0; i < input_length; i++) {
        // since input_length starts at 1 we need to -1 in order to access elements correctly
        if (input[i] != input[(input_length - i) - 1]) {
            return false;
        }
    }
    // after all characters have been tested
    return true;
}
int main() {
    std::string user_input;
    std::cout << "Enter a word: ";
    std::getline(std::cin,user_input);
    if (is_palindrome(user_input)) {
        std::cout << "This is a palindrome";
    }
    else {
        std::cout << "This is not a palindrome";
    }
    return 0;
}


[1:01 p.m.] Kinsman,Zack
#include <iostream>
#include <string>
class Palindrome {
 private:
    std::string word;
 public:
    void readWord() {
        std::cout << "Enter a word: ";
        std::cin >> word;
    }
    bool isPalindrome() {
        int length = word.size();
        for (int i = 0; i < length / 2; i++) {
            if (word[i] != word[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void printResult() {
        if (isPalindrome()) {
            std::cout << word << " is a palindrome." << std::endl;
        } else {
            std::cout << word << " is not a palindrome." << std::endl;
        }
    }
};
int main() {
    Palindrome palindrome;
    palindrome.readWord();
    palindrome.printResult();
    return 0;
}

[1:03 p.m.] Halbert,Robert
#include <iostream>
bool is_palindrome(std::string word){
    int length = word.length() - 1;
    for (int i = 0; i < length; i++) {
        if (word[i] != word[length - i]) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string word;
    std::cout<< "Enter a word: " << std::endl;
    std::cin >> word;
    if (is_palindrome(word)) {
        std::cout << "Is a palindrome!." << std::endl;
    } else {
        std::cout << "Is not a palindrome!." << std::endl;
    }
    return 0;
}

[1:07 p.m.] Lee,Haengwoo
#include <iostream>
#include <vector>
#include <string>
bool is_palindrome(const std::vector<char>& characters) {
    std::vector<char> reversed_characters;
    for (int i = characters.size() - 1; i >= 0; --i) {
        reversed_characters.push_back(characters[i]);
    }
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i] != reversed_characters[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string userInput;
    std::cout << "Enter a string to check if it is a palindrome: ";
    std::getline(std::cin, userInput);
    std::vector<char> characters(userInput.begin(), userInput.end());

    bool result = is_palindrome(characters);
    if (result) {
        std::cout << "\"" << userInput << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << userInput << "\" is not a palindrome." << std::endl;
    }
    return 0;
}

[1:08 p.m.] McNutt,Jason
#include <iostream>
#include <vector>
using namespace std;
class Palindrome {
 public:
    bool check_palindrome(string phrase) {
        vector<char> all_letters(phrase.begin(), phrase.end());
        int smaller_index = 0;
        int bigger_index = all_letters.size() - 1;
        while (bigger_index > smaller_index) {
            if (all_letters[smaller_index] != all_letters[bigger_index]) {
                return false;
            }
            else {
                smaller_index++;
                bigger_index--;
            }
        }
        return true;
    }
};
int main() {
    string entered_phrase = "racecar";

    Palindrome program;

    bool is_palindrome = program.check_palindrome(entered_phrase);

    if (is_palindrome) {
        cout << "'" << entered_phrase << "' is a palindrome!" << endl;
    }
    else {
        cout << "'" << entered_phrase << "' is not a palindrome!" << endl;
    }
    return 0;
}

#include <iostream>

bool is_palindrome(const std::string& word);

int main() {

    std::string word;
    std::cout << "Enter a word: " << std::endl;
    std::getline(std::cin, word);

    if (is_palindrome(word)) {
        std::cout << "This is a palindrome!" << std::endl;
    } else {
        std::cout << "This is not a palindrome." << std::endl;
    }
    return 0;
}

bool is_palindrome(const std::string& word) {
    for (int i = 0; i < word.length() / 2; i++) {
        if (word[i] != word[word.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}
