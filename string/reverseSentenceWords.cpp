// Given a sentence, reverse the order of words.

#include <iostream>
#include <stdio.h>

void reverse(char* s, int len) {
    if (s != nullptr && len > 1) {
        char* start = s;
        char* end = s + len - 1;
        char temp;
        while (start < end) {
            std::cout << "swap: " << *start << ' ' << *end << '\n';
            // temp = *start;
            // *start = *end;
            // *end = temp;
            std::swap(*start, *end);
            start++;
            end--;
        }
    }
}

void reverse_sentence_words(char* s) {
    if (s == nullptr) {
        return;
    }
    int len = strlen(s);
    std::cout << "len of sentence " << len << '\n';
    reverse(s, len);

    char* start = s;
    char* end = s;
    // Iterate the sentence to reverse each word
    while (start != nullptr && *start != '\0') {
        std::cout << "loop\n";
        while (start && *start != '\0' && *start == ' ') {
            ++start;
        }
        end = start + 1;

        while (end && *end != '\0' && *end != ' ') {
            ++end;
        }
        len = end - start;
        std::cout << len << '\n';
        if (end != nullptr) {
            reverse(start, len);
        }
        start = end;

    }

}

int main() {
    
    char* a = new char[20];
    
    strcpy (a, "Hello World!");
    reverse_sentence_words (a);
    std::cout << a << '\n';

    // strcpy (a, "Quick brown fox jumped over the lazy dog   ");
    // reverse_sentence_words (a);
    // std::cout << a << '\n';
}