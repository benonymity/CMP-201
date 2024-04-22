//
// By Benjamin Bassett (benonymity) on 4.16.24
//
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::tuple<std::string, double, int>> movies;
    std::vector<std::tuple<std::string, double>> ratings;
    std::ifstream file("movies.txt");
    std::string line;
    std::string line2;
    int rating;
    bool update{false};

    std::cout
        << "\n  .-.            ___                                           "
           "___                                \n /    \\    .-.  (   )        "
           "                                 (   )      .-.                    "
           "  \n | .`. ;  ( __)  | |   ___ .-. .-.        ___ .-.      .---.   "
           "| |_     ( __)  ___ .-.     .--.   \n | |(___) (\'\'\")  | |  (   "
           ")   \'   \\      (   )   \\    / .-, \\ (   __)   (\'\'\") (   )   "
           "\\   /    \\  \n | |_      | |   | |   |  .-.  .-. ;      | \' .-. "
           ";  (__) ; |  | |       | |   |  .-. .  ;  ,-. \' \n(   __)    | |  "
           " | |   | |  | |  | |      |  / (___)   .\'`  |  | | ___   | |   | "
           "|  | |  | |  | | \n | |       | |   | |   | |  | |  | |      | |   "
           "      / .\'| |  | |(   )  | |   | |  | |  | |  | | \n | |       | "
           "|   | |   | |  | |  | |      | |        | /  | |  | | | |   | |   "
           "| |  | |  | |  | | \n | |       | |   | |   | |  | |  | |      | | "
           "       ; |  ; |  | \' | |   | |   | |  | |  | \'  | | \n | |       "
           "| |   | |   | |  | |  | |      | |        \' `-\'  |  \' `-\' ;   "
           "| |   | |  | |  \'  `-\' | \n(___)     (___) (___) (___)(___)(___) "
           "   (___)       `.__.\'_.   `.__.   (___) (___)(___)  `.__. | \n    "
           "                                                                   "
           "                   ( `-\' ; \n                                     "
           "                                                      `.__.  \n\n";

    // Save the first line as an int
    int num_ratings = 0;
    if (getline(file, line)) {
        num_ratings = std::stoi(line);
    }

    // Iterate through all the remaining lines, saving each pair as tuples
    while (getline(file, line2) && getline(file, line)) {
        rating = std::stoi(line);
        ratings.push_back(std::make_tuple(line2, rating));
    }

    // Consolidate and average the ratings for each movie
    for (auto rating : ratings) {
        for (auto& movie : movies) {
            if (std::get<0>(rating) == std::get<0>(movie)) {
                std::get<1>(movie) =
                    ((std::get<1>(movie) * std::get<2>(movie)) +
                     std::get<1>(rating)) /
                    (std::get<2>(movie) + 1);
                std::get<2>(movie) += 1;
                update = true;
                break;
            }
        }
        if (!update) {
            movies.push_back(
                std::make_tuple(std::get<0>(rating), std::get<1>(rating), 1));
        }
        update = false;
    }

    // Sort the movies by rating
    std::sort(movies.begin(), movies.end(),
              [](const std::tuple<std::string, double, int>& a,
                 const std::tuple<std::string, double, int>& b) {
                  return std::get<1>(a) > std::get<1>(b);
              });

    // Print the results
    for (auto movie : movies) {
        std::cout << std::get<0>(movie) << ": ";
        for (int i = 0; i < round(std::get<1>(movie)); i++) {
            std::cout << "★";
        }

        for (int i = 0; i < (5 - round(std::get<1>(movie))); i++) {
            std::cout << "✩";
        }

        std::cout << " (" << std::get<1>(movie) << " stars from "
                  << std::get<2>(movie) << " rating"
                  << (std::get<2>(movie) > 1 ? "s" : "") << ")" << std::endl;
    }
}