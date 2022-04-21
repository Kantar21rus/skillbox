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

    std::string& findSubStr(std::string& str, std::string& findStr, std::string& field) {
        int posStart = (str.find(findStr) + findStr.length());
        for (int i=posStart; str[i] != '\"'; ++i) {
            field += str[i];
        }
        field.pop_back();
        field.pop_back();
        
        return field;
    }

    void findMovieName(std::string& str) {
        std::string tmpStr = "\"film name\": ";
        movieName = "";
        findSubStr(str, tmpStr, movieName);
    }

    void findCountry(std::string& str) {
        std::string tmpStr = "\"country\": ";
        country = "";
        findSubStr(str, tmpStr, country);
    }

    void findYear(std::string& str) {
        std::string tmpStr = "\"year\": ";
        std::string yearStr = "";
        findSubStr(str, tmpStr, yearStr);
        year = std::stoi(yearStr);
    }

    void findStudio(std::string& str) {
        std::string tmpStr = "\"studio\": ";
        studio = "";
        findSubStr(str, tmpStr, studio);
    }

    void findDirected(std::string& str) {
        std::string tmpStr = "\"directed\": ";
        directed = "";
        findSubStr(str, tmpStr, directed);
    }

    void findProduced(std::string& str) {
        std::string tmpStr = "\"produced\": ";
        produced = "";
        findSubStr(str, tmpStr, produced);
    }

    void findStory(std::string& str) {
        std::string tmpStr = "\"story\": ";
        story = "";
        findSubStr(str, tmpStr, story);
    }

    void findCharacter(std::string& str, artist& tmpArtist) {
        int nameStart, nameFinish, nameTmp = 0;
        int characterStart, characterFinish, characterTmp = 0;
        int pos = str.find('-');
        for (int i=pos;; --i) {
            if (str[i] == '\'') {
                ++nameTmp;
                if (nameTmp == 1) {
                    nameFinish = i;
                }
            } 
            if (nameTmp == 2) {
                nameStart = i;
                break;
            }
        }
        for (int i=pos;; ++i) {
            if (str[i] == '\'') {
                ++characterTmp;
                if (characterTmp == 1) {
                    characterStart = i;
                }
            } 
            if (characterTmp == 2) {
                characterFinish = i;
                break;
            }
        }
        tmpArtist.artistName = str.substr(nameStart+1, nameFinish - nameStart-1);
        tmpArtist.character = str.substr(characterStart+1, characterFinish - characterStart -1);
        str.erase(nameStart, characterFinish - nameStart);
    }

    void findArtist(std::string& str) {
        std::string findStr = "\"artists\":";
        std::string tmpStr = "";
        artist tmpArtist;
        int countCharacters = 0;
        int posStart = (str.find(findStr) + findStr.length());
        for (int i=posStart; str[i] != '}'; ++i) {
            tmpStr += str[i];
            if ( str[i] == '-') {
                ++countCharacters;
            }
        }
        for (int i=0; i < countCharacters; ++i) {
            findCharacter(tmpStr, tmpArtist);
            stars.push_back(tmpArtist);
        }
    }

    
};

void fillMovie(std::string& str, std::vector<Movie>& movies) {
    Movie tmp;
    tmp.findMovieName(str);
    tmp.findCountry(str);
    tmp.findYear(str);
    tmp.findStudio(str);
    tmp.findDirected(str);
    tmp.findProduced(str);
    tmp.findStory(str);
    tmp.findArtist(str);
    movies.push_back(tmp);
}

void parcingOnFilms(std::string& inputStr, std::vector<Movie>& movies) {
    int posStart = 0;
    int posFinish = 0;
    int posCount = 0;
    for (int i=0; i < inputStr.size(); ++i) {
        if (inputStr[i] == '{') {
            posStart = i;
            if (posCount != 0) {
                posCount = 0;
            }
            posCount++;
        }
        if (inputStr[i] == '}') {
            posFinish = i;
            posCount++;
        }
        if (posCount == 2) {
            std::string substr = inputStr.substr(posStart, (posFinish-posStart+1));
            posCount = 0;
            fillMovie(substr, movies);
        }

    } 
}

void findArtistOnName(std::string& name, std::vector<Movie>& movies) {
    bool itsFind = false;
    for (Movie& film : movies) {
        for (artist& artist : film.stars) {
            if (artist.artistName.find(name) != std::string::npos) {
                itsFind = true;
                std::cout << "Artist Full name:\t\t" << artist.artistName << "\n" 
                    << "Film name:\t" <<film.movieName << "\n"
                    << "Character in film:\t" << artist.character << "\n";
            };
        }
    }
    if (!itsFind) {
        std::cout << "Not found\n";
    }
}

int main() {
    std::vector<Movie> movies;
    std::ifstream file("film2.json");
    if (!file.is_open()) {
        std::cout << "Not open!\n";
        return 1;
    }
    std::string input = "";
    int countOpen = 1;
    int countClose = 0;
    char tmpChar = file.get();
    input += tmpChar;
    while (countOpen != countClose) {
        tmpChar = file.get();
        if (tmpChar == '{') ++countOpen;
        if (tmpChar == '}') ++countClose;
        input += tmpChar;
    }
    parcingOnFilms(input, movies);
    std::cout << "Insert name or surname artist: ";
    std::string nameStr;
    std::getline(std::cin, nameStr);
    findArtistOnName(nameStr, movies);
}
