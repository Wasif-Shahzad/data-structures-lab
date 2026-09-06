#include <iostream>
using namespace std;

class PlaylistManager {
private:
    int** customPlaylists;
    int* playlistCapacities;
    int playlistCount;

public:
    PlaylistManager(int count) {
        playlistCount = count;
        customPlaylists = new int*[playlistCount];
        playlistCapacities = new int[playlistCount];
        for (int p = 0; p < playlistCount; p++) {
            playlistCapacities[p] = 0;
            customPlaylists[p] = nullptr;
        }
    }

    PlaylistManager(const PlaylistManager& other) {
        playlistCount = other.playlistCount;
        customPlaylists = new int*[playlistCount];
        playlistCapacities = new int[playlistCount];
        for (int p = 0; p < playlistCount; p++) {
            playlistCapacities[p] = other.playlistCapacities[p];
            customPlaylists[p] = new int[playlistCapacities[p]];
            for (int t = 0; t < playlistCapacities[p]; t++) {
                customPlaylists[p][t] = other.customPlaylists[p][t];
            }
        }
    }

    ~PlaylistManager() {
        for (int p = 0; p < playlistCount; p++) {
            delete[] customPlaylists[p];
        }
        delete[] customPlaylists;
        delete[] playlistCapacities;
    }

    void addTrack(int playlist, int trackID) {
        if (playlist < 0 || playlist >= playlistCount) {
            cout << "Invalid playlist index." << endl;
            return;
        }
        int newSize = playlistCapacities[playlist] + 1;
        int* newPlaylist = new int[newSize];
        for (int t = 0; t < playlistCapacities[playlist]; t++) {
            newPlaylist[t] = customPlaylists[playlist][t];
        }
        newPlaylist[newSize - 1] = trackID;
        delete[] customPlaylists[playlist];
        customPlaylists[playlist] = newPlaylist;
        playlistCapacities[playlist] = newSize;
    }

    void play(int playlist, int track) {
        if (playlist < 0 || playlist >= playlistCount ||
            track < 0 || track >= playlistCapacities[playlist]) {
            cout << "Invalid playlist or track index." << endl;
            return;
        }
        cout << "Playing track " << customPlaylists[playlist][track]
             << " from playlist " << playlist << endl;
    }

    void display() {
        for (int p = 0; p < playlistCount; p++) {
            cout << "Playlist " << p << ": ";
            for (int t = 0; t < playlistCapacities[p]; t++) {
                cout << customPlaylists[p][t] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    PlaylistManager manager(3);

    manager.addTrack(0, 101);
    manager.addTrack(0, 202);
    manager.addTrack(1, 303);
    manager.addTrack(1, 404);
    manager.addTrack(1, 505);

    cout << "Original playlists:" << endl;
    manager.display();

    PlaylistManager backup(manager);

    backup.addTrack(0, 999);

    cout << "Backup after adding to playlist 0:" << endl;
    backup.display();
    cout << "Original (unchanged):" << endl;
    manager.display();

    manager.play(0, 1);
    manager.play(2, 5);
    manager.play(1, 3);
}