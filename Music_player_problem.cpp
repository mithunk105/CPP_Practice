// Music Player implementation using Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    
   
    std::cout << "You implement this function"<< std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for ( auto &pl : playlist )
        {
        std::cout << pl << std::endl;
        }
    std::cout<<"\nCurrent Song:"<<std::endl;
    std::cout << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    std::cout << "To be implemented" << std::endl;
    // Your program logic goes here
    display_playlist(playlist, *current_song);
    char selection{};
    display_menu();
    std::cin>>selection;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    while ( selection != 'Q' && selection != 'q' ) {
        switch ( selection ){

            case 'F':
            case 'f':
                current_song = playlist.begin();
                std::cout << "Playing first song" <<std::endl;
                std::cout << "Playing:" <<std::endl;
                std::cout << *current_song << std::endl;
                break;

            case 'N':
            case 'n':
                std::cout << "Playing next song" <<std::endl;
                if ( *current_song == playlist.back() ) {
                    current_song = playlist.begin();
                    std::cout << "Wrapping start of playlist" << std::endl;
                }
                else{
                    current_song++;
                }
                std::cout << "Playing:" <<std::endl;
                std::cout << *current_song << std::endl;
                break;

            case 'P':
            case 'p':
                std::cout << "Playing previous song" <<std::endl;
                if ( *current_song == playlist.front() ) {
                    current_song = playlist.end();
                    current_song--;
                    std::cout << "Wrapping end of playlist" << std::endl;
                }
                else{
                    current_song--;
                }
                std::cout << "Playing:" <<std::endl;
                std::cout << *current_song << std::endl;
                break;

            case 'A':
            case 'a':
                {
                std::cout << "Adding and Playing new song" <<std::endl;
                std::string name_s;
                std::string artist_s;
                int rating_s;
                std::cout << "Enter song name:" <<std::endl;
                std::getline(std::cin, name_s);
                std::cout << "Enter song artist:" <<std::endl;
                std::getline(std::cin, artist_s);
                std::cout << "Enter your rating(1-5):" <<std::endl;
                std::cin>>rating_s;
                playlist.emplace( current_song, name_s, artist_s, rating_s );
                current_song--;
                std::cout << "Playing:" <<std::endl;
                std::cout << *current_song << std::endl;
                break;
                }

            case 'L':
            case 'l':
                display_playlist(playlist, *current_song);
                break;

            default:
                break;
        }
    display_menu();
    std::cin >> selection;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}

Output:

To be implemented
God's Plan          Drake                         5 
Never Be The Same   Camila Cabello                5 
Pray For Me         The Weekend and K. Lamar      4 
The Middle          Zedd, Maren Morris & Grey     5 
Wait                Maroone 5                     4 
Whatever It Takes   Imagine Dragons               3 

Current Song:
God's Plan          Drake                         5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
p
Playing previous song
Wrapping end of playlist
Playing:
Whatever It Takes   Imagine Dragons               3 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
n
Playing next song
Wrapping start of playlist
Playing:
God's Plan          Drake                         5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
n
Playing next song
Playing:
Never Be The Same   Camila Cabello                5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 


a
Adding and Playing new song
Enter song name:
In the end
Enter song artist:
Linkin Park
Enter your rating(1-5):
5
Playing:
In the end          Linkin Park                   5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
l
God's Plan          Drake                         5 
In the end          Linkin Park                   5 
Never Be The Same   Camila Cabello                5 
Pray For Me         The Weekend and K. Lamar      4 
The Middle          Zedd, Maren Morris & Grey     5 
Wait                Maroone 5                     4 
Whatever It Takes   Imagine Dragons               3 

Current Song:
In the end          Linkin Park                   5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
n
Playing next song
Playing:
Never Be The Same   Camila Cabello                5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
f
Playing first song
Playing:
God's Plan          Drake                         5 

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
===============================================
Enter a selection (Q to quit): 
q
Thanks for listening!


** Process exited - Return Code: 0 **