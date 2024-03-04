#include <iostream>
#include <vector>
#include <algorithm>

class Movie {
public:
    std::string Title;
    double Rating;

    Movie(std::string title, double rating) : Title(title), Rating(rating) {}
};

std::vector<Movie> movies;

void AddMovies() {
    std::cout << "Enter movie titles (up to 10, separated by commas): ";
    std::string inputStr;
    std::getline(std::cin, inputStr);
    std::vector<std::string> movieTitles;
    size_t pos = 0;
    while ((pos = inputStr.find(", ")) != std::string::npos) {
        std::string title = inputStr.substr(0, pos);
        movieTitles.push_back(title);
        inputStr.erase(0, pos + 2);
    }
    if (!inputStr.empty()) {
        movieTitles.push_back(inputStr);
    }

    for (const auto& title : movieTitles) {
        Movie newMovie(title, 0);
        movies.push_back(newMovie);
        std::cout << "Movie '" << title << "' added." << std::endl;
    }
}

void RateMovies() {
    if (movies.empty()) {
        std::cout << "No movies to rate. Please add movies first." << std::endl;
        return;
    }

    for (auto& movie : movies) {
        std::cout << "Rate '" << movie.Title << "' (0-10): ";
        double rating;
        std::cin >> rating;
        if (rating >= 0 && rating <= 10) {
            movie.Rating = rating;
            std::cout << "Rating for '" << movie.Title << "' updated successfully." << std::endl;
        } else {
            std::cout << "Invalid rating. Ratings should be between 0 and 10." << std::endl;
        }
    }
}

void ListMoviesByRating() {
    if (movies.empty()) {
        std::cout << "No rated movies to display." << std::endl;
        return;
    }

    std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
        return a.Rating > b.Rating;
    });

    std::cout << "\nMovies Ranked by Ratings you've given:" << std::endl;
    for (const auto& movie : movies) {
        std::cout << "Title: " << movie.Title << ", Rating: " << movie.Rating << std::endl;
    }
}

int main() {
    while (true) {
        std::cout << "ZBZ | Movie Rating Program" << std::endl;
        std::cout << "\n1. Add Movies" << std::endl;
        std::cout << "2. Rate Movies" << std::endl;
        std::cout << "3. See Ranking of your movies" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cout << "\nEnter your choice: ";
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            AddMovies();
        } else if (choice == "2") {
            RateMovies();
        } else if (choice == "3") {
            ListMoviesByRating();
        } else if (choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}