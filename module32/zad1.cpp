#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct artist {
    std::string artistName;
    std::string character;
};

class Movie {
    public:
    std::string movieName;
    std::string country;
    int year;
    std::string studio;
    std::string story;
    std::string directed;
    std::string produced;
    std::vector<artist> stars;
};

int main() {
    Movie DarkKnight;
    DarkKnight.movieName = "Dark Knight";
    DarkKnight.country = "USA";
    DarkKnight.year = 2008;
    DarkKnight.directed = "Christopher Nolan";
    DarkKnight.produced = "Christopher Nolan";
    DarkKnight.studio = "Warner Brothers";
    DarkKnight.story = "Christopher Nolan";
    artist artists[3];
    artists[0].artistName = "Christian Bale";
    artists[0].character = "Batman";
    artists[1].artistName = "Michael Caine";
    artists[1].character = "Alfred";
    artists[2].artistName = "Heath Ledger";
    artists[2].character = "Joker";
    DarkKnight.stars.push_back(artists[0]);
    DarkKnight.stars.push_back(artists[1]);
    DarkKnight.stars.push_back(artists[2]);
    std::ofstream file("film.json");
    file << "{" << 
        "{" << "\"film name\": " << DarkKnight.movieName << 
         ", \"country\": " << DarkKnight.country <<
         ", \"year\": " << DarkKnight.year <<
         ", \"directed\": " << DarkKnight.directed <<
         ", \"produced\": " << DarkKnight.produced <<
         ", \"studio\": " << DarkKnight.studio <<
         ", \"story\": " << DarkKnight.story <<
         ", \"artists\": \n" << DarkKnight.stars[0].artistName << " - " << DarkKnight.stars[0].character << "\n" <<
         DarkKnight.stars[1].artistName << " - " << DarkKnight.stars[1].character << "\n" <<
         DarkKnight.stars[2].artistName << " - " << DarkKnight.stars[2].character << "\n" <<
         "}" << 
         "{" << 
         "\"film name\": " << DarkKnight.movieName << 
         ", \"country\": " << DarkKnight.country <<
         ", \"year\": " << DarkKnight.year <<
         ", \"directed\": " << DarkKnight.directed <<
         ", \"produced\": " << DarkKnight.produced <<
         ", \"studio\": " << DarkKnight.studio <<
         ", \"story\": " << DarkKnight.story <<
         ", \"artists\": \n" << DarkKnight.stars[0].artistName << " - " << DarkKnight.stars[0].character << "\n" <<
         DarkKnight.stars[1].artistName << " - " << DarkKnight.stars[1].character << "\n" <<
         DarkKnight.stars[2].artistName << " - " << DarkKnight.stars[2].character << "\n" <<
         "}" <<
         "}";

}
